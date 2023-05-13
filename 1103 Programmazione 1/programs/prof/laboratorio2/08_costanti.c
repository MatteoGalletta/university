#include<stdio.h>
#define NUM 4
#define NUM2 3>5

int main() {
    // una costante macro (definita sopra)
    // il preprocessore sostituisce NUM con 4
    // prima della compilazione
    printf("%d\n", NUM);

    // una costante letterale, ovvero un numero
    // inserito direttamente nel codice del programma
    printf("%d\n", 4);

    // esempio in cui l'uso di macro per definire costanti
    // può creare confusione
    printf("%d\n", NUM2);

    // esempio di variabili definite come costanti
    // mediante il modificatore const
    const float pi = 3.14;
    const int x = 0;

    printf("%f\n%d\n", pi, x);

    // Le seguenti due istruzioni danno errori di compilazione (se non commentate)
    //const double y; //non si può dichiarare una costante senza inizializzarla
    //y = 2.5; //non si può assegnare un valore a una costante
}
