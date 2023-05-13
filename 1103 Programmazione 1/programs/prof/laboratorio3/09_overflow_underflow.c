#include<stdio.h>
#include<limits.h>
#include<math.h>

int main() {
    // Massimo valore int
    printf("INT_MAX:\t%d\n",INT_MAX);

    // Massimo valore int meno uno
    printf("INT_MAX-1:\t%d\n",INT_MAX-1);

    // Massimo valore int più uno
    // Questa istruzione darà luogo a overflow
    printf("INT_MAX+1:\t%d\n",INT_MAX+1);

    // Massimo valore int più uno
    // In questo caso, sommiamo un letterale
    // "1L", quindi long double
    // Ciò farà sì che la somma sia anche essa
    // di tipo long double e quindi non darà 
    // luogo a overflow
    printf("INT_MAX+1:\t%li\n",INT_MAX+1L);

    // Un numero in virgola mobile molto piccolo
    // Questo numero non può essere rappresentato
    // Mediante un numero float, per cui l'istruzione
    // Genererà un underflow
    printf("\n%e\n",1e-350);

    // É possibile ottenere un overflow anche 
    // Con i numeri in virgola mobile
    // L'operazione sotto genererà un "inf" (infinito)
    float res = 10E10*10E30;
    printf("\n%f\n", res);

    // Infinito e meno infinito sono rappresentati
    // Come float in C. É anche possibile usare
    // La variabile INFINITY per rappresentare questi valori
    // INFINITY è definita in math.h
    printf("\n%f\n", +INFINITY);
    printf("%f\n", -INFINITY);

    // Un altro valore speciale definito in math.h
    // É "NAN" (Not A Number)
    // Questo valore viene restituito come risultato
    // Di una operazione matematica non definita (es. 0/0)
    printf("\n%f\n", NAN);

    // Possiamo ottenere nan e infinity anche con delle 
    // Operazioni matematiche tra numeri in virgola mobile
    printf("\n%f\n", 0.0/0);
    printf("%f\n", 1.0/0);
    printf("%f\n", (-1.0)/0);
    printf("%f\n", 1/INFINITY);
}
