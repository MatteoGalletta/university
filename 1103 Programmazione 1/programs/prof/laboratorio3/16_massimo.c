#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int value = 0;
    int max;
    bool init = false; //non ho inizializzato
    printf("Inserire 5 valori interi.\n");
    for(int i = 0; i<5; i++) {
        printf("Inserire valore: ");
        scanf("%d", &value);
        
        if(init == false) { // se non ho ancora inizializzato
            max = value;
            init = true;
        }
        
        // Alternativamente: inizializza solo nella prima iterazione
        /*if(i==0)
            max = value;*/
        
        if(value>max)
            max = value;
    }

    printf("Il massimo è: %d\n", max);
}