#include<stdio.h>

int main() {
    // Le oprazioni di input/output vengono eseguite in C mediante gli stream
    // Sono disponibili tre stream principali:
    //  - stdin: standard input - la tastiera
    //  - stdout: standard output - lo schermo
    //  - stderr: standard error - lo schermo - questo viene usato per stampare messaggi di errori (e distinguerli dagli altri)
    // I sistemi operativi permettono in genere di "redirigere" questi stream in modo da permettere letture o scritture da file
    // lasciando il programma invariato

    // Scrittura su standard output
    // La possiamo effettuare con printf o puts
    printf("%s", "Scrivo su standard output\n");
    puts("Anche questo va su standard output");

    // Letttura da standard input
    // La possiamo effettuare con scanf
    printf("Inserisci un numero e premi invio: ");
    int x;
    scanf("%d", &x);

    // Scrittura su standard error
    // La otteniamo con fprintf che funziona come printf ma permette di specificare lo stream:
    if(getchar()!='\n') // se ci sono dei caratteri diversi da newline sullo standard input, allora abbiamo inserito un numero non valido
        fprintf(stderr, "Errore, il numero inserito non è valido!\n");
    else
        fprintf(stdout, "Numero inserito valido.\n"); //questo funziona esattamente come printf dato che sto specificando sdout come stream


    // SU UNIX:

    // Possiamo redirigere un file sull'input così: ./programma < input
    // Dove input è il file di input

    // Possiamo redirigere lo standard output su file così: ./programma > out
    // Possiamo redirigere lo standard error su file così: ./programma 2> out
    // Possiamo redirigere sia standard error che standard output su file così: ./programma &> out

    // Possiamo redirigere sia input che standard output così: ./programma < input > out 
    // Possiamo redirigere sia input che standard e error output così: ./programma < input &> out 
}