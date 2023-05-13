// Scriviamo adesso un programma che apre il file in lettura
#include <stdio.h>

// Definiamo una struttura che contenga 
// i valori sui nostri clienti

// clientData structure definition          
struct clientData {    
   int account; //identificativo del conto
   char lastName[12];  // stringa che contiene il cognome
   char firstName[10]; // stringa che contiene il nome 
   double balance; // saldo sul conto
};                     
 
int main(void) {
    FILE *cfPtr = NULL; // accounts.dat file pointer

    // numeri di record
    int numrecords = 0;

    // fopen opens the file; exits if file cannot be opened
    if ((cfPtr = fopen("accounts.dat", "rb+")) == NULL) { //apriamo in lettura e come file binario con i flag "rb"
    // il + indica che vogliamo anche aggiornare il file (non solo leggere)
        puts("File could not be opened.");
    } 
    else { 
        printf("%-6s%-30s%-30s%10s\n", "Acct", "Last Name",
         "First Name", "Balance");
        
        // leggiamo i record da file fino a EOF
        while(!feof(cfPtr)) {
            // la struct da "riempire" con i valori letti dal file
            struct clientData record = {0, "", "", 0.0};
            size_t result = fread(&record, sizeof(struct clientData), 1, cfPtr);

            if(result != 0) { // se l'ultimo record letto era valido
                printf("%-6d%-30s%-30s%5.2f\n", record.account, 
                    record.lastName, record.firstName, record.balance);
                    // ftell permette di ottenere la posizion corrente del cursore in bytes
                    // dividendo per il numero di byte in una struct
                    // possiamo capire quanti record abbiamo letto finora
                    numrecords = ftell(cfPtr)/sizeof(struct clientData)+1;
            }
        }

        // Adesso possiamo chiedere all'utente se vuole modificare un determinato account o aggiungerne uno nuovo
        
        int choice;

        do {
            printf("Cosa vuoi fare?\n");
            printf("1) Aggiornare un record\n");
            printf("2) Inserire un nuovo record\n");
            printf("0) Uscire\n");

            scanf("%d", &choice);

            switch(choice) {
                case 0:
                    printf("Arrivederci.\n");
                    break;
                case 1:
                    printf("Quale record vuoi aggiornare? ");
                    struct clientData record = {0, "", "", 0.0};
                    int r = 0;
                    scanf("%d", &r);

                    // andiamo alla posizione indicata dal numero di account mediante la funzione fseek
                    fseek(cfPtr, r*sizeof(struct clientData), SEEK_SET);
                    // dobbiamo specificare:
                    // - riferimento a struct FILE
                    // - coordinate in byte del record
                    // - da dove iniziare: SEEK_SET (inizio file), SEEK_END (fine del file), SEEK_CUR (posizione corrente dell'indicatore)

                    //A questo punto possiamo leggere il record
                    size_t result = fread(&record, sizeof(struct clientData), 1, cfPtr);

                    if(result != 0) { // se il record è valido
                        // mostriamo il record
                        printf("Valori correnti del record:\n");
                        printf("%-30s%-30s%5.2f\n", 
                            record.lastName, record.firstName, record.balance);

                        // chiediamo di inserire i nuovi valori:
                        printf("Nuovi valori:\n");
                        scanf("%s %s %lf", record.lastName, record.firstName, &record.balance);

                        // Torniamo alla posizione corretta per sovrascrivere
                        fseek(cfPtr, r*sizeof(struct clientData), SEEK_SET);

                        // Scriviamo
                        fwrite(&record, sizeof(struct clientData), 1, cfPtr);
                        printf("Record aggiornato.\n");
                    }
                    break;
                case 2:
                    // chiediamo di inserire i nuovi valori:
                    printf("Inserire cognome, nome, saldo, separati da spazi. Terminare con EOF.\n");
                    scanf("%s %s %lf", record.lastName, record.firstName, &record.balance);

                    record.account = numrecords++;

                    fseek(cfPtr, 0, SEEK_END);
                    // Scriviamo
                    fwrite(&record, sizeof(struct clientData), 1, cfPtr);
                    printf("Record inserito.\n");
                    break;
                default:
                    printf("Scelta non valida.\n");
            }


        } while(choice!=0);
        

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
