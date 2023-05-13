#include<stdio.h>
#include<math.h>

int main() {
    int x;
    x = 1; // x è un valido l-value, possiamo scrivere in x

    int y = x + 1; // anche y è un valido l-value
    // nell'espressione sopra, x appare a destra dell'operatore
    // ciò è possibile perché gli r-value possono apparire
    // anche a destra degli operatori. 

    //5 = x; // non consentito, 5 non è un lvalue (non possiamo modificarne il valore!)

    int h = 1;
    int k = 0;

    //h + k = 2; // restituisce un errore, l'espressione
    // h + k non è un valido lvalue



    // sia f una funzione che restituisce un valore intero
    //f(0) = 9; // restituisce un errore, f ritorna un valore
    // che non può essere modificato. Questo sarà più chiaro quando vedremo le funzioni
}
