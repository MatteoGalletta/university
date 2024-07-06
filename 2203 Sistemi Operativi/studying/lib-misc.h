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

#ifndef LIB_OSLAB_MISC_H
#define LIB_OSLAB_MISC_H

#ifdef __linux__
#define _POSIX_C_SOURCE 200809L
#endif

#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* esce con un exit code di errore visualizzando un prefisso a scelta `s`
 * seguito dal messaggio di errore standard associato all'attuale codice in
 * `errno` */
#define exit_with_sys_err(s)                                                   \
    do {                                                                       \
        perror((s));                                                           \
        exit(EXIT_FAILURE);                                                    \
    } while (0)

/* esce con un exit code di errore visualizzando un prefisso a scelta `s`
 * seguito dal messaggio di errore standard associato al codice di errore
 * passato (utile per le funzione delle pthread che non usano `errno`) */
#define exit_with_err(s, e)                                                    \
    do {                                                                       \
        fprintf(stderr, "%s: %s\n", (s), strerror((e)));                       \
        exit(EXIT_FAILURE);                                                    \
    } while (0)

/* esce con un exit code di errore visualizzando un messaggio a scelta con le
 * convenzioni del printf */
#define exit_with_err_msg(...)                                                 \
    do {                                                                       \
        fprintf(stderr, __VA_ARGS__);                                          \
        exit(EXIT_FAILURE);                                                    \
    } while (0)

/* PS: il costrutto `do {} while (0)` nella macro serve per forzare il
 * compilatore a trattarlo come una vera e propria funzione (ad esempio
 * obbligando l'uso del punto-e-virgola subito dopo) */

#ifdef __APPLE__

/* layer di compatibilità degli esempi per Mac OS */

#include <pthread.h>
#include <semaphore.h>

typedef struct {
    pthread_mutex_t count_lock;
    pthread_cond_t count_bump;
    unsigned count;
} mac_sem_t;

int mac_sem_init(mac_sem_t *psem, int flags, unsigned count);
int mac_sem_destroy(mac_sem_t *psem);
int mac_sem_post(mac_sem_t *psem);
int mac_sem_trywait(mac_sem_t *psem);
int mac_sem_wait(mac_sem_t *psem);
int mac_sem_timedwait(mac_sem_t *psem, const struct timespec *abstim);
int mac_sem_getvalue(mac_sem_t *sem, int *sval);

#undef sem_t
#define sem_t mac_sem_t

#undef sem_init
#define sem_init mac_sem_init

#undef sem_destroy
#define sem_destroy mac_sem_destroy

#undef sem_post
#define sem_post mac_sem_post

#undef sem_wait
#define sem_wait mac_sem_wait

#undef sem_trywait
#define sem_trywait mac_sem_trywait

#undef sem_timedwait
#define sem_timedwait mac_sem_timedwait

#undef sem_getvalue
#define sem_getvalue mac_sem_getvalue

#ifndef PTHREAD_BARRIER_SERIAL_THREAD
#define PTHREAD_BARRIER_SERIAL_THREAD -1
#endif

typedef pthread_mutexattr_t mac_pthread_barrierattr_t;

typedef struct {
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    unsigned count;
    unsigned left;
    unsigned round;
} mac_pthread_barrier_t;

int mac_pthread_barrier_init(mac_pthread_barrier_t *__restrict barrier,
                             const mac_pthread_barrierattr_t *__restrict attr,
                             unsigned count);
int mac_pthread_barrier_destroy(mac_pthread_barrier_t *barrier);
int mac_pthread_barrier_wait(mac_pthread_barrier_t *barrier);
int mac_pthread_barrierattr_init(mac_pthread_barrierattr_t *attr);
int mac_pthread_barrierattr_destroy(mac_pthread_barrierattr_t *attr);
int mac_pthread_barrierattr_getpshared(
    const mac_pthread_barrierattr_t *__restrict attr, int *__restrict pshared);
int mac_pthread_barrierattr_setpshared(mac_pthread_barrierattr_t *attr,
                                       int pshared);

#undef pthread_barrierattr_t
#define pthread_barrierattr_t mac_pthread_mutexattr_t

#undef pthread_barrier_t
#define pthread_barrier_t mac_pthread_barrier_t

#undef pthread_barrier_init
#define pthread_barrier_init mac_pthread_barrier_init

#undef pthread_barrier_destroy
#define pthread_barrier_destroy mac_pthread_barrier_destroy

#undef pthread_barrier_wait
#define pthread_barrier_wait mac_pthread_barrier_wait

#undef pthread_barrierattr_init
#define pthread_barrierattr_init mac_pthread_barrierattr_init

#undef pthread_barrierattr_destroy
#define pthread_barrierattr_destroy mac_pthread_barrierattr_destroy

#undef pthread_barrierattr_getpshared
#define pthread_barrierattr_getpshared mac_pthread_barrierattr_getpshared

#undef pthread_barrierattr_setpshared
#define pthread_barrierattr_setpshared mac_pthread_barrierattr_setpshared

#endif

#endif /* LIB_OSLAB_MISC_H */