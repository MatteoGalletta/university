// fig05_08.c
// Scoping.
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

void useLocal(void); // function prototype
void useStaticLocal(void); // function prototype
void useGlobal(void); // function prototype
int count(void);

int x = 1; // global variable

int main(void) {
   int x = 5; // local variable to main

   printf("local x in outer scope of main is %d\n", x); // 5

   { // start new scope                                    
      int x = 7; // local variable to new scope 
      int y = 2;           
                                                           
      printf("local x in inner scope of main is %d\n", x); // 7
   } // end new scope          

   //printf("%d", y); //restituisce un errore

   printf("local x in outer scope of main is %d\n", x); // 5

   useLocal(); // useLocal has automatic local x // 25, 26
   useStaticLocal(); // useStaticLocal has static local x // 50, 51
   useGlobal(); // useGlobal uses global x // 1, 10
   useLocal(); // useLocal reinitializes automatic local x //25, 26
   useStaticLocal(); // static local x retains its prior value // 51, 52
   useGlobal(); // global x also retains its value // 10, 100

   printf("\nlocal x in main is %d\n", x); //5

   srand(time(NULL));
   bool cond = true;
   while(cond) {
      int x = rand()%10;
      if(x>5)
         cond = false;
      count();
   }

   printf("Count: %d\n", count());
} 

int count(int y) {
   static int x = 0;
   return x;
}

// useLocal reinitializes local variable x during each call
void useLocal(void) {
   int x = 25; // initialized each time useLocal is called

   printf("\nlocal x in useLocal is %d after entering useLocal\n", x);
   ++x;
   printf("local x in useLocal is %d before exiting useLocal\n", x);
} 

// useStaticLocal initializes static local variable x only the first time 
// the function is called; value of x is saved between calls to this
// function
void useStaticLocal(void) {
   static int x = 50; // initialized once

   printf("\nlocal static x is %d on entering useStaticLocal\n", x); //50
   ++x;
   printf("local static x is %d on exiting useStaticLocal\n", x); //51
} 

// function useGlobal modifies global variable x during each call
void useGlobal(void) {
   printf("\nglobal x is %d on entering useGlobal\n", x); // 1
   x *= 10; 
   printf("global x is %d on exiting useGlobal\n", x); //10
} 


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
