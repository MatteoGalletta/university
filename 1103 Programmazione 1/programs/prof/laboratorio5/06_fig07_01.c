// fig07_01.c
// Using the & and * pointer operators.
#include <stdio.h>

int main(void) {
   int a = 7;
   int *aPtr = &a; // set aPtr to the address of a

   printf("Address of a is %p\nValue of aPtr is %p\n\n", &a, aPtr);
   printf("Value of a is %d\nValue of *aPtr is %d\n\n", a, *aPtr);
   printf("Showing that * and & are complements of each other\n");
   printf("&*aPtr = %p\n*&aPtr = %p\n", &*aPtr, *&aPtr);

   a = 8;

   printf("What's the value of *aPtr? %d\n", *aPtr);

   *aPtr = 10;
   //aPtr = 10; //this would be a mistake (aPtr is the address, not the value!)

   printf("What's the value of a? %d\n", a);

   int b = 12;

   aPtr = &b;
   //*aPtr = &b; //this would be a logical mistake (*aPtr is the value, not the address!)
   //aPtr = b; //this would be a mistake (aPtr is an address, while b is a value!)

   printf("What's the value of *aPtr? %d\n", *aPtr);

   int x[3] = {1,2,3};

   printf("An array is a pointer to the first element of the array.\n");
   printf("&x[0] == x: %p == %p\n", &x[0], x);

   *x = 18;
   printf("Value of x[0]: %d\n", x[0]);

   int *xPtr = x;
   printf("Value of xPtr: %p\n", xPtr);

   *xPtr = -1;
   printf("Value of x[0]: %d\n", x[0]);
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
