#include <stdio.h>
#include <stdlib.h> //to use malloc

// Alcune note su allocazione della memoria in C: https://www.gnu.org/software/libc/manual/html_node/Memory-Allocation-and-C.html

// Prototipi delle funzioni
// Le implementazioni commentate si trovano dopo il main
void printArray(const int x[], size_t size);
void printAutomaticArray2D(int x[2][2]);
void printDynamicArray2D(int **x, size_t m, size_t n);
int* returnArray(int n);

// Allocazione STATICA (nel segmento data)
int y[5] = {0};

float f = 2.5; // Allocazione STATICA
// Tutto ciò che viene allocato "fuori dal main" o da un'altra funzione
// è una variabile globale e viene allocata staticamente

int main() {
    // Allocazione AUTOMATICA (nello stack)
    int sx;
    // Verrà deallocata automaticamente alla fine dell'esecuzione della funzione (il main in questo caso)
    // In generale, le variabili locali (es. dentro una funzione o un blocco di codice - es. dentro un if - vengono allocate AUTOMATICAMENTE)
    

    static int y = 5; //Allocata STATICAMENTE (nel segmento DATA)

    // Allocazione DINAMICA (nello heap)
    int *dx = malloc(sizeof(int));

    // assignment
    sx = 2;
    *dx = 3; // Questo è un puntatore, per cui l'operatore * è necessario qui

    printf("Value of sx: %d\n", sx);
    printf("Value of dx: %p\n", dx);
    printf("Value pointed by dx: %d\n", *dx);

    // Allocazione AUTOMATICA dell'array (sullo stack)
    int sa[3] = {1,2,3};

    // Allocazione DINAMICA dell'array (nello heap)
    int *da = malloc(3 * sizeof(int)); //Allochiamo tre volte la dimensione di un intero in memoria

    // Alternativamente:
    // int *da = calloc(3, sizeof(int));

    // Inseriamo dei valori
    da[0] = 1;
    da[1] = 2;
    da[2] = 3;

    printArray(sa, 3);
    printArray(da, 3);

    printf("da[0]=%d\n", da[0]);

    // Dopo aver usato da, dobbiamo liberare la memoria
    // A differenza di quanto avviene per le variabili allocate automaticamente
    // La memoria allocata automaticamente verrà liberata solo alla terminazione del programma
    // Liberare la memoria allocata dinamicamente è importante soprattutto quando
    // L'allocazione viene effettuata in cicli o funzioni in quanto diverse iterazioni
    // O chiamate a funzioni possono causare dei memory leak
    free(da);
    da = NULL; // dopo aver liberato la memoria, mettiamo il puntatore a NULL
    // per evitare di cercare di accedere a quell'aria di memoria nuovamente

    // È buona norma controllare se il puntatore è nullo prima di
    // dereferenziare con da[0] o *da
    // Se da è NULL e proviamo a dereferenziare con da[0],
    // otterremo un errore di segmentazione
    if(da) // alternativamente if(da!=NULL)
        printf("da[0]=%d\n", da[0]);

    int *p = NULL;

    for(int i=0; i<10; i++) {
        p = malloc(sizeof(int)); //allocazione dinamica all'interno di un ciclo for
        *p=2;
        free(p); //non liberare la memoria causerebbe un memory leak
    }

    //Se abbiamo allocato della memoria
    int *da2 = malloc(5 * sizeof(int));

    // E vogliamo cambiare la dimensione, mantenendo la stessa variabile
    // possiamo usare realloc:
    da2 = realloc(da2, 3 * sizeof(int));

    free(da2);

    int *da3 = calloc(5, sizeof(int));
    free(da3);

    // Allocazione AUTOMATICA di un array
    int a2d[2][2] = {1,2,3,4};

    // Allocazione AUTOMATICA di un array 2D
    int **d2d = calloc(2, sizeof(int*));
    for(int i=0; i<2; i++)
        d2d[i] = calloc(2,sizeof(int));

    /* equivalente C++ (rilevante solo per chi già conosce C++)
    int** d2d = new int*[2];
    for (int i=0; i<2; i++)
        d2d[i] = new int[2];
        */

    d2d[0][0] = 1;
    d2d[0][1] = 2;
    d2d[1][0] = 3;
    d2d[1][1] = 4;

    printf("d2d:\n");
    printAutomaticArray2D(a2d);

    printDynamicArray2D(d2d, 2, 2);

    int *r = returnArray(10);

    printArray(r, 10);

    int aa[5][5] = {0};
}

/*
La notazione int x[] è equivalente a int* x in questo contesto

Quindi il prototipo della funzione potrebbe essere
equivalentemente:

void printArray(const int* x, size_t size);

Il parametro attuale x può essere in allocazione AUTOMATICA, STATICA o DINAMICA
*/
void printArray(const int x[], size_t size) {
    for(size_t i = 0; i<size; i++)
        printf("%d\t", x[i]);
    printf("\n");
}

/*
Potrei scrivere equivalentemente
void printAutomaticArray2D(int (*x)[2])

In questo caso x non può essere allocato dinamicamente, ma deve essere in allocazione AUTOMATICA o STATICA
*/
void printAutomaticArray2D(int x[2][2]) {
    for(size_t i = 0; i<2; i++) {
        for(size_t j=0; j<2; j++)
            printf("%d\t", x[i][j]);
        printf("\n");
    }
    printf("\n");
}

/*
In questo caso x deve essere in allocazione DINAMICA
Non è possibile passare un array in allocazione STATICA o AUTOMATICA (es. int x[2][2]={0};)
*/
void printDynamicArray2D(int **x, size_t m, size_t n) {
    for(size_t i = 0; i<m; i++) {
        for(size_t j=0; j<n; j++)
            printf("%d\t", x[i][j]);
        printf("\n");
    }
    printf("\n");
}

int* returnArray(int n) {
    //this needs to be dynamic
    //a static array would be deallocated
    //after the execution and the
    //return value would be lost!

    int *x = calloc(n, sizeof(int)); //Allocazione DINAMICA
    // non verrà deallocata alla fine dell'esecuzione del programma

    int count = 10; // Allocazione AUTOMATICA
    // Qui ha senso usare l'allocazione automatica:
    // Questa variabile resterà locale e può essere deallocata
    // alla fine dell'esecuzione della funzione

    for(int i=0; i<n; i++) {
        x[i] = count;
        count += 2;
    }
    return x;
}

// ERRATO -> restituisce un warning
// Non posso restituire un array in allocazione AUTOMATICA
/*
int* returnArray2() {
    int x[3] = {1,2,3}; //allocazione AUTOMATICA
    return x;
}*/