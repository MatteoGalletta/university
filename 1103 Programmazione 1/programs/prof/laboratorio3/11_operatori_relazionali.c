#include<stdio.h>
#include<stdbool.h>

int main() {
    // Gli operatori relazionali permettono di restituire dei valori booleani
    printf("%d\n",(7 == 5));     // false
    printf("%d\n",(5 > 4));      // true
    printf("%d\n",(3 != 2));     // true
    printf("%d\n",(6 >= 6));     // true
    printf("%d\n\n",(5 < 5));      // false

    // É possibile unire operatori relazionali e aritmetici
    int a = 2;
    int b = 3;
    int c = 6;

    printf("%d\n",(a == 5));     //false, a non è uguale a 5
    printf("%d\n",(a*b >= c));   // true, 2*3 >= 6
    printf("%d\n",(b+4 > a*c));  // false, 3+4 < 2*6
    printf("%d\n\n",((b=2) == a)); // true. Questa istruzione assegna 2 a b e poi controlla che 2 sia uguale al valore di a (2)


    // Il risultato di un confronto
    // Può essere assegnato a una variabile booleana
    int x = 2;
    int y = 3;
    bool condition = x==y; //false
    printf("%d\n\n", condition);

    // Possiamo unire l'operatore modulo e quello di uguaglianza
    // Per verificare se un numero è multiplo di un altro numero
    printf("%d\n",3%2==0); //false, 3 non è multiplo di 2
    printf("%d\n",9%3==0); //true, 9 è multiplo di 3
    printf("%d\n",11%5==0); //false, 11 non è multiplo di 5


    // L'operatore ternario unisce gli operatori relazionali
    // A un costrutto di scelta
    int h = 5;
    int k = 7;

    // Stampiamo una stringa o un'altra a seconda del valore della condizione
    printf("\n%s\n", (h==k) ? "h==k" : "h!=k");
    printf("%s\n", (h>k) ? "h>k" : "h<=k");
    
    // Calcolo del massimo tra due numeri
    int max = h>k ? h : k;
    
    printf("max(h,k)=%d\n", max);

    // L'operatore ternario si può implementare con un if:
    if(h>k)
        max = h;
    else
        max = k;
        
    printf("\n%d\n", max);
}
