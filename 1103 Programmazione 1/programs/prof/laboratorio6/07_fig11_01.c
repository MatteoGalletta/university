// fig11_01.c
// Creating a sequential file
#include <stdio.h>

int main(void){
   // Creiamo un puntatore a file e lo inizializziamo a NULL
   FILE *cfPtr = NULL; // cfPtr = clients.txt file pointer   

   // fopen opens the file. Exit the program if unable to create the file 
   if ((cfPtr = fopen("clients.txt", "w")) == NULL) { // Apriamo il file in scrittura (flag "w")
      fprintf(stderr, "File could not be opened"); // Se il file non può essere aperto (ad esempio non abbiamo i permessi) scriviamo sullo standard error
   } 
   else { // Altrimenti, chiediamo di inserire i dettagli dell'account
      puts("Enter the account, name, and balance.");
      puts("Enter EOF to end input."); //CTRL + D in Linux/Mac, CTRL + Z in Windows
      printf("%s", "? ");

      int account = 0; // account number
      char name[30] = ""; // account name
      double balance = 0.0; // account balance

      scanf("%d%s%lf", &account, name, &balance); // formato: 1234 John 12.5

      // write account, name and balance into file with fprintf
      // feof permette di verificare se siamo a fine stream
      // la fine dello stream viene indicata dal marcatore di EOF
      // che viene specificato dall'utente con la combinazione CTRL + D o CTRL + Z
      while (!feof(stdin)) { 
         // fprintf permette di scegliere lo stream su cui scrivere, in questo caso il file
         fprintf(cfPtr, "%d %s %.2f\n", account, name, balance);
         printf("%s", "? ");
         scanf("%d%29s%lf", &account, name, &balance); //leggiamo i prossimi valori da input
      } 
      
      fclose(cfPtr); // fclose closes file   
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
