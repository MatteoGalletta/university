/*
 * libreria di servizio ufficiosa per:
 * - fornire utili macro per funzionalità ricorrenti come la gestione
 *   dell'uscita su errore su chiamate di sistema e di libreria
 * - forzatura dell'uso di chiamate POSIX compatibili anche su Linux (dove di
 *   default sono attive diverse estensioni GNU)
 * - fornire un layer di compatibilità (leggi "hack") per i sistemi Apple per
 *   supplire al mancato supporto di alcune chiamate POSIX (semafori numerici
 *   e barriere)
 */

#include "lib-misc.h"

/* una reimplemntazione (non del tutto pulita) dei semafori numerici e delle
 * barriere: strumenti POSIX che però non sono supportati dal sistema operativo
 * Apple Mac OS. Il codice è un riadattamento di codice preesistente con minimi
 * riadattamenti.
 * - https://github.com/stanislaw/posix-macos-addons
 * - https://github.com/isotes/pthread-barrier-macos
 */

#ifdef __APPLE__

pthread_once_t mac_comp_layer_warning = PTHREAD_ONCE_INIT;

void mac_comp_layer_warning_function(void) {
    fprintf(stderr,
            "ATTENZIONE: è stato attivato una layer di compatibilità per i "
            "sistemi Apple per supplire alla mancanza di alcune funzionalità "
            "della libreria POSIX pthread (semafori numerici e barriere). "
            "Questo potrebbe causare dei malfunzionamenti!\n");
}

int mac_sem_init(mac_sem_t *psem, int flags, unsigned count) {
    int result;

    pthread_once(&mac_comp_layer_warning, mac_comp_layer_warning_function);

    if (psem == NULL) {
        return -1;
    }
    result = pthread_mutex_init(&psem->count_lock, NULL);
    if (result != 0) {
        return result;
    }
    result = pthread_cond_init(&psem->count_bump, NULL);
    if (result != 0) {
        pthread_mutex_destroy(&psem->count_lock);
        return result;
    }
    psem->count = count;
    return 0;
}

int mac_sem_destroy(mac_sem_t *psem) {
    mac_sem_t *poldsem;

    if (!psem) {
        return EINVAL;
    }
    poldsem = (mac_sem_t *)psem;

    pthread_mutex_destroy(&poldsem->count_lock);
    pthread_cond_destroy(&poldsem->count_bump);
    return 0;
}

int mac_sem_post(mac_sem_t *psem) {
    mac_sem_t *pxsem;
    int result, xresult;

    if (!psem) {
        return EINVAL;
    }
    pxsem = (mac_sem_t *)psem;

    result = pthread_mutex_lock(&pxsem->count_lock);
    if (result) {
        return result;
    }
    pxsem->count = pxsem->count + 1;

    xresult = pthread_cond_signal(&pxsem->count_bump);

    result = pthread_mutex_unlock(&pxsem->count_lock);
    if (result) {
        return result;
    }
    if (xresult) {
        errno = xresult;
        return -1;
    }
    return 0;
}

int mac_sem_trywait(mac_sem_t *psem) {
    mac_sem_t *pxsem;
    int result, xresult;

    if (!psem) {
        return EINVAL;
    }
    pxsem = (mac_sem_t *)psem;

    result = pthread_mutex_lock(&pxsem->count_lock);
    if (result) {
        return result;
    }
    xresult = 0;

    if (pxsem->count > 0) {
        pxsem->count--;
    } else {
        xresult = EAGAIN;
    }
    result = pthread_mutex_unlock(&pxsem->count_lock);
    if (result) {
        return result;
    }
    if (xresult) {
        errno = xresult;
        return -1;
    }
    return 0;
}

int mac_sem_wait(mac_sem_t *psem) {
    mac_sem_t *pxsem;
    int result, xresult;

    if (!psem) {
        return EINVAL;
    }
    pxsem = (mac_sem_t *)psem;

    result = pthread_mutex_lock(&pxsem->count_lock);
    if (result) {
        return result;
    }
    xresult = 0;

    if (pxsem->count == 0) {
        xresult = pthread_cond_wait(&pxsem->count_bump, &pxsem->count_lock);
    }
    if (!xresult) {
        if (pxsem->count > 0) {
            pxsem->count--;
        }
    }
    result = pthread_mutex_unlock(&pxsem->count_lock);
    if (result) {
        return result;
    }
    if (xresult) {
        errno = xresult;
        return -1;
    }
    return 0;
}

int mac_sem_timedwait(mac_sem_t *psem, const struct timespec *abstim) {
    mac_sem_t *pxsem;
    int result, xresult;

    if (psem == NULL) {
        return EINVAL;
    }
    pxsem = (mac_sem_t *)psem;

    result = pthread_mutex_lock(&pxsem->count_lock);
    if (result) {
        return result;
    }
    xresult = 0;

    if (pxsem->count == 0) {
        xresult = pthread_cond_timedwait(&pxsem->count_bump, &pxsem->count_lock,
                                         abstim);
    }
    if (xresult == 0) {
        if (pxsem->count > 0) {
            pxsem->count--;
        }
    }
    result = pthread_mutex_unlock(&pxsem->count_lock);
    if (result) {
        return result;
    }
    if (xresult) {
        errno = xresult;
        return -1;
    }
    return 0;
}

int mac_sem_getvalue(mac_sem_t *sem, int *sval) {
    assert(sval);

    int value;

    assert(pthread_mutex_lock(&sem->count_lock) == 0);

    value = sem->count;

    assert(pthread_mutex_unlock(&sem->count_lock) == 0);

    *sval = value;

    return 0;
}

int mac_pthread_barrier_init(mac_pthread_barrier_t *__restrict barrier,
                             const mac_pthread_barrierattr_t *__restrict attr,
                             unsigned count) {

    pthread_once(&mac_comp_layer_warning, mac_comp_layer_warning_function);

    if (count == 0) {
        return EINVAL;
    }

    int ret;

    pthread_condattr_t condattr;
    pthread_condattr_init(&condattr);
    if (attr) {
        int pshared;
        ret = pthread_barrierattr_getpshared(attr, &pshared);
        if (ret) {
            return ret;
        }
        ret = pthread_condattr_setpshared(&condattr, pshared);
        if (ret) {
            return ret;
        }
    }

    ret = pthread_mutex_init(&barrier->mutex, attr);
    if (ret) {
        return ret;
    }

    ret = pthread_cond_init(&barrier->cond, &condattr);
    if (ret) {
        pthread_mutex_destroy(&barrier->mutex);
        return ret;
    }

    barrier->count = count;
    barrier->left = count;
    barrier->round = 0;

    return 0;
}

int mac_pthread_barrier_destroy(mac_pthread_barrier_t *barrier) {
    if (barrier->count == 0) {
        return EINVAL;
    }

    barrier->count = 0;
    int rm = pthread_mutex_destroy(&barrier->mutex);
    int rc = pthread_cond_destroy(&barrier->cond);
    return rm ? rm : rc;
}

int mac_pthread_barrier_wait(mac_pthread_barrier_t *barrier) {
    pthread_mutex_lock(&barrier->mutex);
    if (--barrier->left) {
        unsigned round = barrier->round;
        do {
            pthread_cond_wait(&barrier->cond, &barrier->mutex);
        } while (round == barrier->round);
        pthread_mutex_unlock(&barrier->mutex);
        return 0;
    } else {
        barrier->round += 1;
        barrier->left = barrier->count;
        pthread_cond_broadcast(&barrier->cond);
        pthread_mutex_unlock(&barrier->mutex);
        return PTHREAD_BARRIER_SERIAL_THREAD;
    }
}

int mac_pthread_barrierattr_init(mac_pthread_barrierattr_t *attr) {
    return pthread_mutexattr_init(attr);
}

int mac_pthread_barrierattr_destroy(mac_pthread_barrierattr_t *attr) {
    return pthread_mutexattr_destroy(attr);
}

int mac_pthread_barrierattr_getpshared(
    const mac_pthread_barrierattr_t *__restrict attr, int *__restrict pshared) {
    return pthread_mutexattr_getpshared(attr, pshared);
}

int mac_pthread_barrierattr_setpshared(mac_pthread_barrierattr_t *attr,
                                       int pshared) {
    return pthread_mutexattr_setpshared(attr, pshared);
}

#endif