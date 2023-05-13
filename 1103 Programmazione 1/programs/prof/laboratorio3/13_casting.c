#include<stdio.h>
#include<math.h>

int main() {
    // Gli operatori di casting permettono di
    // convertire un valore da un tipo a un altro

    float x = 2.2; //valore in virgola mobile
    int y = (int) x; //conversione in intero (parte intera)
    printf("%d\n", y);

    // Il casting può essere effettuato anche "al volo"
    // Esso è molto utile se vogliamo assicurarci che la divisione sia in virgola mobile
    int a = 1;
    int b = 3;
    printf("%f\n", a / (float) b);

    // La conversione a intero non effettua nessun arrotondamento
    // Se vogliamo effettuarlo, possiamo sommare 0.5 e poi effettuare il casting
    printf("\n%d\n",(int)(2.8)); //2, non 3
    printf("%d\n",(int)(0.3)); //0
    printf("%d\n",(int)(8.9)); //8, non 9

    printf("\n%d\n",(int)(2.8 + 0.5)); //2, non 3
    printf("%d\n",(int)(0.3 + 0.5)); //0
    printf("%d\n",(int)(8.9 + 0.5)); //8, non 9

    // In alternativa, possiamo usare la funzione "round" di math.h
    // Il risultato sarà comunque un double
    printf("\n%f\n", round(3.3));

    // Possiamo ottenere un int con un casting
    printf("\n%d\n", (int) round(3.3));

}
