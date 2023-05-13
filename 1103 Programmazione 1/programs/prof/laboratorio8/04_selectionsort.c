#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 10
#define MAX 100

void printArray(int a[], int n) {
    for(int i=0; i<n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void selectionSort(int a[], int n) {
    // Fa n-1 passate
    // Ad ogni passata, seleziona il minimo
    // della sequenza che va dall'indice pass alla fine
    // e scambia l'elemento all'indice pass con il minomo
    for(int pass = 0; pass < n-1; pass++) {
        // inizializziamo l'indice del minimo
        int idx_min = pass;
        for(int i = pass+1; i<n; i++) { //una semplice ricerca del minimo
            // in cui conserviamo l'indice del minimo
            if(a[i]<a[idx_min])
                idx_min = i;
        }
        // scambiamo i valori agli indici
        // pass e idx_min

        printf("\n\n");
        printArray(a, n);
        printf("Scambio %d con %d\n", a[pass], a[idx_min]);
        int tmp = a[pass];
        a[pass] = a[idx_min];
        a[idx_min] = tmp;
    }
}

int main() {
    int array[SIZE];

    srand(time(NULL));

    for(int i=0; i<SIZE; i++) {
        array[i] = rand()%(MAX+1);
    }

    printf("Array non ordinato:\n");
    printArray(array, SIZE);

    selectionSort(array, SIZE);

    printf("\nArray ordinato:\n");
    printArray(array, SIZE);
}