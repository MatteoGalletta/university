// Creiamo un file ad accesso casuale in cui scriviamo i dati in maniera sequenziale
#include <stdio.h>

// Definiamo una struttura che contenga 
// i valori sui nostri clienti

//121786487362759 
//1234 -> "1"

// clientData structure definition          
struct clientData {    
   int account; //identificativo del conto
   char lastName[12];  // stringa che contiene il cognome
   char firstName[10]; // stringa che contiene il nome
   double balance; // saldo sul conto
};                     
 
int main(void) {
    FILE *cfPtr = NULL; // accounts.dat file pointer

    // fopen opens the file; exits if file cannot be opened
    if ((cfPtr = fopen("accounts.dat", "wb")) == NULL) { //apriamo in scrittura e come file binario con i flag "wb"
        fprintf(stderr, "File could not be opened.");
    } 
    else { 
        // Chiediamo i dati in input all'utente e li scriviamo sul file

        int account_number = 0;

        printf("Inserire cognome, nome, saldo, separati da spazi. Terminare con EOF.\n");
        
        while(!feof(stdin)) {
            // Creiamo una struct vuota
            struct clientData record = {account_number++, "", "", 0.0}; //creiamo e inizializziamo la struct
            // questa inizializzazione assegnerà i valori nell'ordine in cui sono indicati
            // nella definizione della struct

            scanf("%s %s %lf", record.lastName, record.firstName, &record.balance);

            if(!feof(stdin)) // se l'ultimo carattere inserito non è EOF
                // Scriviamo il record. Parametri:
                // - indirizzo del record
                // - dimensione (la recuperiamo con sizeof)
                // - numero di record (1)
                // - struttura FILE
                fwrite(&record, sizeof(struct clientData), 1, cfPtr);
        }

        fclose (cfPtr); // fclose closes the file
        cfPtr = NULL;
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
