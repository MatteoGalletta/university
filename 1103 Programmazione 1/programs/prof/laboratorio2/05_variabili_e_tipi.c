#include <stdio.h>
#include <stdbool.h> //senza questa direttiva, otterremmo un errore di compilazione

 

int main(){
    // Esempi di variabili e tipi
    // Negli esempi che seguono, effettuiamo 
    // la dichiarazione e inizializzazione delle variabili insieme
    char a = 'a'; // da non confondere con "a"
    unsigned char b = 12;
    short int c = -10; // short c = -10;
    unsigned short int d = 10; // unsigned short d = 10;
    int e = -1120;
    unsigned int f = 10; // unsigned f = 10;
    long int g = -1000000; // long g = -1000000;
    unsigned long int h = 99; // unsigned long h = 99;
    float i = 2.3;
    double l = 2.00001;
    long double m = 2.333333;

    printf("NUMERICI\t\t\t %c\t%d\t%d\t%d\t%d\t%d\t%ld\t%lu\t%f\t%f\t%Lf\n",a,b,c,d,e,f,g,h,i,l,m);

    // Esempio di dichiarazione e inizializzazione disgiunte
    int x;
    x = -3; //finché non si esegue questa istruzione, il valore di x è indeterminato

    printf("INIZIALIZZAZIONE DISGIUNTA\t %d\n", x);

    // Esempio di dichiarazione senza inizializzazione (ERRORE LOGICO!)
    int y;
    printf("NON INIZIALIZZATO\t\t %d\n", y); //valore imprevedibile

    _Bool b1 = 0;
    _Bool b2 = 1;    //assegnare un valore diverso da zero a
    _Bool b3 = -100; //una variabile di tipo _Bool
    _Bool b4 = 100;  //ha l'effetto di impostare quella variabile a 1 (true)
    
    bool b5 = true; //importando stdbool possiamo usare bool, true e false

    printf("BOOLEANI\t\t\t %d\t%d\t%d\t%d\t\n",b1,b2,b3,b4);

    // le variabili booleane possono essere utilizzate per effettuare controlli
    if(b4) {
        printf("true\n");
    } else {
        printf("false\n");
    }

}
