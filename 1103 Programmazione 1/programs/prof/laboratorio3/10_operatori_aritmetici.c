#include<stdio.h>

int main() {
    int x = 2;
    int y = 3;

    int somma = x+y; //somma
    int media = (x+y)/2; //media
    int prodotto = x*y; //prodotto
    int quoziente = x/y; //divisione
    int resto = y%x; //resto

    printf("%d\t%d\t%d\t%d\t%d\n\n",somma,media,prodotto,quoziente,resto);

    // Le divisioni tra due interi restituisce un numero intero
    printf("%d\n", 2/2); //divisione intera
    printf("%d\n", y/x); //divisione intera
    printf("%d\n\n", 5/2); //divisione intera

    // Se vogliamo ottenere una divisione in virgola mobile
    // Dobbiamo assicurarci che uno dei due operandi sia
    // Un numero in virgola mobile (o sia convertito come tale)
    printf("%f\n", 2.0/3);
    printf("%f\n", y/2.0);
    printf("%f\n", (x+0.0)/y);
}
