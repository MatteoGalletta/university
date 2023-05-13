#include<stdio.h>
#define MAXLEN 255

int main() {
    // Vediamo diversi modi per leggere una stringa da standard input

    // allochiamo automaticamente una stringa di lunghezza (massima) MAXLEN=255
    char string[MAXLEN];

    // METODO 1: scanf
    printf("Inserisci una riga di testo: ");
    scanf("%s", string);

    printf("La stringa letta con scanf è: %s\n", string);
    // notiamo che il metodo sopra si "fermerà" quando incontra lo spazio
    // i caratteri non inseriti in string sono "in attesa" sullo standard input

    //scanf("%s", string);
    //printf("La seconda stringa letta con scanf è: %s\n", string);

    // rimuoviamoli iterando su getchar, che legge un carattere alla volta
    // potrei fare così...
    //char c2;
    //do {
    //    c2 = getchar();
    //} while (c2!='\n'); // mi fermo quando trovo il carattere di nuova riga

    //... ma questo è più pratico
    while(getchar()!='\n');

    // METODO 2: fgets
    printf("Inserisci una riga di testo: ");
    // Con fgets possiamo specificare quanti caratteri leggere
    // e da dove leggerli (stdin indica lo standard input - la tastiera)
    // leggiamo 9 caratteri dalla standard input stdin (la decima posizione è usata per il carattere di terminazione) e li mettiamo in string
    fgets(string, 10, stdin);

    printf("La stringa letta con fgets è: %s\n", string);
    // notiamo che questo metodo legge esattamente n-1 caratteri (n secondo parametro di fgets)

    while(getchar()!='\n'); // rimmuoviamo i caratteri in eccesso da stdin

    // METODO 3: getchar
    // Possiamo leggere i caratteri "manualmente" fino al massimo di caratteri che possiamo inserire nella stringa
    printf("Inserisci una riga di testo: ");
    int i = 0;
    char c;
    while((c = getchar()) != '\n' && i < MAXLEN-1)
        string[i++] = c;

    string[i] = 0; // '\0'

    printf("La stringa letta con getchar è: %s\n", string);

    // Le funzioni sprintf e sscanf funzionano come printf e scanf
    // ma invece di leggere e scrivere da standard input e output
    // leggono e scrivono da e su stringa

    // sprintf è utile per ottenere una stringa formattata a partire dai valori di altre variabili
    int x = 2;
    float y = 3.5;
    sprintf(string, "x=%d - - y=%f", x, y); // il primo parametro è la string in output
    printf("Stringa formattata: %s\n", string);

    // Analogamente sscanf permette di prelevare valori da una stringa formattata
    sscanf("i risultati sono 1 e 5.2", "i risultati sono %d e %f", &x, &y);
    printf("Il valore di x è %d\nIl valore di y è %f\n", x, y);
}