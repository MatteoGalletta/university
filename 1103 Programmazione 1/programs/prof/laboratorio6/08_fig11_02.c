// fig11_02.c
// Reading and printing a sequential file
#include <stdio.h>

int main(void) {
   FILE *cfPtr = NULL; // cfPtr = clients.txt file pointer

   // fopen opens file; exits program if file cannot be opened 
   if ((cfPtr = fopen("clients.txt", "r")) == NULL) { // stavolta leggiamo in sola lettura specificando il flag "r"
      puts("File could not be opened");
   } 
   else { // read account, name and balance from file
      int account = 0; // account number   
      char name[30] = ""; // account name
      double balance = 0.0; // account balance  

      printf("%-10s%-13s%s\n", "Account", "Name", "Balance");
      // il - nel formato serve ad allineare a sinistra

      // fscanf si comporta come fprintf e funziona come scanf
      // ma permette di specificare lo stream di input (il file)
      fscanf(cfPtr, "%d%29s%lf", &account, name, &balance);

      // while not end of file
      while (!feof(cfPtr)) { // verifico se sono alla fine del file
         // stampo quanto letto da file
         printf("%-10d%-13s%7.2f\n", account, name, balance);
         fscanf(cfPtr, "%d%29s%lf", &account, name, &balance);
      } 

      fclose(cfPtr); // fclose closes the file   
   } 
} 

 

/**************************************************************************
 * (C) Copyright 1992-2015 by Deitel & Associates, Inc. and               *
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