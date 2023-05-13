#include <stdio.h>

int main(void) {
   int aCount = 0;
   int bCount = 0; 
   int cCount = 0; 
   int dCount = 0; 
   int fCount = 0; 

   puts("Enter the letter grades.");
   puts("Enter the EOF character to end input.");
   char grade = 0; // one grade 
   
   
   do {
       printf("Enter a new grade and press enter: ");
       grade = getchar();
       getchar();
       
       switch (grade) { // switch nested in while
         case 'A': // grade was uppercase A
         case 'a': // or lowercase a
            ++aCount; 
            break; // necessary to exit switch
         case 'B': // grade was uppercase B
         case 'b': // or lowercase b
            ++bCount; 
            break; 
         case 'C': // grade was uppercase C
         case 'c': // or lowercase c
            ++cCount; 
            break;
         case 'D': // grade was uppercase D
         case 'd': // or lowercase d
            ++dCount; 
            break;
         case 'F': // grade was uppercase F
         case 'f': // or lowercase f
            ++fCount; 
            break; 
         case EOF:
            break;
         default: // catch all other characters
            printf("%s", "Incorrect letter grade entered."); 
            puts(" Enter a new grade."); 
            break; // optional; will exit switch anyway
      } // end switch 
   } while(grade != EOF);
   
   // output summary of results
   puts("\nTotals for each letter grade are:");
   printf("A: %d\n", aCount);
   printf("B: %d\n", bCount); 
   printf("C: %d\n", cCount); 
   printf("D: %d\n", dCount); 
   printf("F: %d\n", fCount); 
   
}