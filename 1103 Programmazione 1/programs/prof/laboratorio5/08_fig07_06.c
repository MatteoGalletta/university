// fig07_06.c
// Converting a string to uppercase using a 
// non-constant pointer to non-constant data.
#include <ctype.h>
#include <stdio.h>

void convertToUppercase(char *sPtr); // prototype
void printCharacters(const char *sPtr);

int main(void) {
   char string[] = "cHaRaCters and $32.98"; // initialize char array

   printf("The string before conversion is: ");
   printCharacters(string);
   convertToUppercase(string);

   printf("\nThe string after conversion is: ");
   printCharacters(string);

   int x = 0; // define x
   int y = 0; // define y


   // ptr2 is a pointer to a constant integer. 
   // the address can be modified, but
   // the integer at that location
   // cannot be modified
   const int* ptr2 = &x; // initialization is OK
                                 
   printf("\n%d\n", *ptr2);
   //*ptr2 = 7; // error: *ptr is const; cannot assign new value 
   ptr2 = &y; // valid
   

   // ptr is a constant pointer to an integer that can be modified  
   // through ptr, but ptr always points to the same memory location
   int * const ptr = &x;                                            

   *ptr = 7; // allowed: *ptr is not const
   //ptr = &y; // error: ptr is const; cannot assign new address

   


   // ptr3 is a constant pointer to a constant integer. ptr always 
   // points to the same location; the integer at that location
   // cannot be modified
   const int *const ptr3 = &x; // initialization is OK
                                 
   printf("%d\n", *ptr3);
   //*ptr3 = 7; // error: *ptr is const; cannot assign new value 
   //ptr3 = &y; // error: ptr is const; cannot assign new address

   //An array behaves as a constant pointer to the first element of the array
   int z[3] = {1,2,3};
   //z = &y; //error!
} 

// convert string to uppercase letters
void convertToUppercase(char *sPtr) {
   while (*sPtr != '\0') { // current character is not '\0' 
      *sPtr = toupper(*sPtr); // convert to uppercase
      ++sPtr; // make sPtr point to the next character
   } 
} 

// sPtr cannot be used to modify the character to which it points,
// i.e., sPtr is a "read-only" pointer
void printCharacters(const char *sPtr) {
   // loop through entire string                       
   for (; *sPtr != '\0'; ++sPtr) { // no initialization
      //*sPtr = toupper(*sPtr); // error, the argument is const!
      printf("%c", *sPtr);                             
   }                                                   
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
