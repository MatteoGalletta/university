#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int value = 0;
    int min;
    bool init = false; //non ho inizializzato
    printf("Inserire 5 valori interi.\n");
    for(int i = 0; i<5; i++) {
        printf("Inserire valore: ");
        scanf("%d", &value);
        
        if(init == false) { // se non ho ancora inizializzato
            min = value;
            init = true;
        }
        
        // Alternativamente: inizializza solo nella prima iterazione
        /*if(i==0)
            min = value;*/
        
        if(value<min)
            min = value;
    }

    printf("Il minimo è: %d\n", min);
}