#include<stdio.h>
#include<stdbool.h>

int main() {
    bool a = true;
    bool b = false;

    // Vediamo alcuni esempi di operatori logici:
    printf("%d\n", a && b );
    printf("%d\n", a || b );
    printf("%d\n", !a );
    printf("%d\n", !b );
    printf("%d\n", a && !b );
    printf("%d\n", !a && !b );
    printf("%d\n", (a && b) || (!a) );

    // Quando si usano gli operatori logici, C valuta solo ciò che è necessario valutare da sinistra a destra, ignorando il resto. Ad esempio, quando viene valutata l’espressione ((5==5)||(3>6)), C valuterà se 5==5. Dato che il risultato è true e le espressioni true || false e true || true valutano entrambe a true, C non valuterà mai l’espressione 3>6 in quanto ciò non è necessario per trovare il valore di verità dell’espressione ((5==5)||(3>6)). Questo tipo di valutazione è detta anche valutazione a corto circuito o short-circuit evaluation.

    //Ad esempio, cosa stampa il seguente codice?
    int x = 0;
    if((a && b) && (++x)) {
        printf("true\n");
    }

    printf("\nIl valore di x è %d\n", x);

}
