// fig06_12.c
// Sorting an array's values into ascending order.
#include <stdio.h>
#define SIZE 10

// function main begins program execution
int main(void) {
   int a[SIZE] = {2, 6, 4, 8, 10, 12, 89, 68, 45, 37}; 
   
   puts("Data items in original order");
   
   // output original array
   for (size_t i = 0; i < SIZE; ++i) {
      printf("%4d", a[i]);
   } 

   //    2, 6, 4, 8, 10, 12, 89, 68, 45, 37
   // pass=1) 2, 6, 4, 8, 10, 12, 89, 68, 45, 37
   //     i=0) 2, 6, 4, 8, 10, 12, 89, 68, 45, 37
   //     i=1) 2, 4, 6, 8, 10, 12, 89, 68, 45, 37
   //     i=2) 2, 4, 6, 8, 10, 12, 89, 68, 45, 37
   //     i=3) 2, 4, 6, 8, 10, 12, 89, 68, 45, 37
   //     i=4) 2, 4, 6, 8, 10, 12, 89, 68, 45, 37
   //     i=5) 2, 4, 6, 8, 10, 12, 89, 68, 45, 37
   //     i=6) 2, 4, 6, 8, 10, 12, 68, 89, 45, 37
   //     i=7) 2, 4, 6, 8, 10, 12, 68, 45, 89, 37
   //     i=8) 2, 4, 6, 8, 10, 12, 68, 45, 37, 89
   


   // bubble sort                                           
   // loop to control number of passes                      
   for (int pass = 0; pass < SIZE-1; ++pass) {  // SIZE-1 passes              
      // loop to control number of comparisons per pass     
      for (size_t i = 0; i < SIZE - 1 - pass; ++i) { //funziona anche senza -pass
         // compare adjacent elements and swap them if first
         // element is greater than second element          
         if (a[i] > a[i + 1]) {                             
            int hold = a[i];                                
            a[i] = a[i + 1];                                
            a[i + 1] = hold;                                
         }                                                  
      }                                                     
   }                                                        

   puts("\nData items in ascending order");

   // output sorted array
   for (size_t i = 0; i < SIZE; ++i) {
      printf("%4d", a[i]);
   } 

   puts("");
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

