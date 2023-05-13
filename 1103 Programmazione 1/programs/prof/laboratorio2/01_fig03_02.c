/* 
Scrivere un programma che permetta di calcolare la media dei voti di una classe. Il programma permette all’utente di inserire 10 voti (sotto forma di numeri interi) e stampa a schermo la media dei 10 voti inseriti (anch’essa sotto forma di numero intero).

Descrizione top-down:

> Prendi in input 10 numeri interi, calcolane la media e stampala a schermo.

Raffinamento successivo:

> Inizializza le variabili.
> Leggi i dieci voti dell’esame e sommane i valori.
> Dividi il totale per il numero di voti e stampa il risultato a schermo.

Raffinamento successivo:

> Inizializza la variabile (accumulatore) "total" a zero.
> Inizializza il contatore "counter" a uno.

> Finché il contatore è minore o uguale a dieci
>   Leggi il risultato successivo dell’esame
>   Somma il risultato a "total"
>   Incrementa il contatore di una unità

> Inizializza la variabile "average" con il valore di "total" diviso per 10
> Stampa il valore di "average"
*/

// fig03_02.c
// Class average program with counter-controlled iteration.
#include <stdio.h>

// function main begins program execution
int main(void) {
   // initialization phase
   int total = 0; // initialize total of grades to 0
   int counter = 1; // number of the grade to be entered next

   /*
   counter  |  total |  grade | average
   1        |  0     |  /
   2        |  5     |  5
   3        |  7     |  2
   4        |  10    |  3
   5        |  16    |  6
   6        |  25    |  9
   7        |  35    |  10
   8        |  37    |  2
   9        |  42    |  5
   10       |  44    |  2
   11       |  50    |  6     
            |        |     |  5
   */

   // processing phase
   while (counter <= 10) { // loop 10 times
      printf("%s", "Enter grade: "); // prompt for input
      int grade = 0; // grade value
      scanf("%d", &grade); // read grade from user
      total = total + grade; // add grade to total
      counter = counter + 1; // increment counter
   } // end while

   // termination phase
   int average = total / 10; // integer division
   printf("Class average is %d\n", average); // display result
} // end function main



/**************************************************************************
 * (C) Copyright 1992-2021 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 *************************************************************************/

