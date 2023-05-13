#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "get_random.c"

#define MAX_INPUT_SIZE 10

struct sParams {
    char* alfabeto;
    int n;
    char* output;
};
typedef struct sParams Params;

struct sNode {
    char *str;
    struct sNode* next;
};
typedef struct sNode Node;

int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }

Node *getStack(char **Q, int n);
Params decodeParameters(int argc, char **argv);
int *readInput(int n, int L);
char *sampleString(char* alfabeto, int h);
char **getStringArray(int *W, char *alfabeto, int n);
char *popFromStack(Node **P);
bool insertIntoStack(Node **P, char *str);
void writeStackToFile(Node *P, char *output);

void usageAndExit() {
    fprintf(stderr, "Parametri non validi. Specificare alfabeto (stringa tra 5 e 15 caratteri), n (intero tra 5 e 20) e output (stringa).");
    exit(-1);
}

int main(int argc, char **argv) {
    
    Params params = decodeParameters(argc, argv);
    
    int *W = readInput(params.n, strlen(params.alfabeto));
    
    char **Q = getStringArray(W, params.alfabeto, params.n);
    
    Node *P = getStack(Q, params.n);
    
    writeStackToFile(P, params.output);

    return 0;
}

void writeStackToFile(Node *P, char *output) {
    FILE *fPtr = fopen(output, "w");
    if (fPtr == NULL) {
        fprintf(stderr, "Errore durante l'apertura del file.");
        perror("");
        exit(-1);
    }

    while (P) {
        fprintf(fPtr, "%s\n", P->str);
        P = P->next;
    }

    fclose(fPtr);
}

char *popFromStack(Node **P) {
    if (*P == NULL)
        return NULL;
    
    Node *tmp = *P;
    char *str = tmp->str;
    
    *P = (*P)->next;
    free(tmp);

    return str;
}

bool insertIntoStack(Node **P, char *str) {

    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL)
        return false;

    newNode->str = str; // Non la riallochiamo
    newNode->next = *P;

    *P = newNode;

    return true;
}

Node *getStack(char **Q, int n) {
    
    Node *P = NULL;
    
    for (int i = 0; i < n; i++) {

        // Potremo decidere di non copiare str ma in questo modo ci
        // assicuriamo che l'array Q non venga modificato.
        int len = strlen(Q[i]);
        char *str = malloc(sizeof(char) * (len+1));

        if (i > 0 && (len%2 == 1)) {
            char *top = popFromStack(&P);
            int topLen = strlen(top);
            // Riallochiamo str in modo tale da farci entrare il vecchio str e il top
            str = realloc(str, sizeof(char) * (len+topLen+1));
            strcpy(str, top);
            strcat(str, Q[i]);
        }
        else {
            strcpy(str, Q[i]);
        }

        insertIntoStack(&P, str);
        //printf("P[%d]: %s (len: %d)\n", i, P->str, strlen(P->str));
    }

    return P;
}

char **getStringArray(int *W, char *alfabeto, int n) {
    
    char **Q = malloc(sizeof(char*) * n);
    for (int i = 0; i < n; i++) {
        Q[i] = sampleString(alfabeto, W[i]);
        //printf("Q[%d]: %s\n", i, Q[i]);
    }

    return Q;
}

char *sampleString(char* alfabeto, int h) {

    int alfabetoLength = strlen(alfabeto);

    char *s = malloc(sizeof(char) * (h+1));
    for (int i = 0; i < h; i++) {
        int randomIndex = get_random()%alfabetoLength;
        s[i] = alfabeto[randomIndex];
    }
    s[h] = 0;

    return s;
}

int *readInput(int n, int L) {
    
    int *W = malloc(sizeof(int) * n);
    char buff[MAX_INPUT_SIZE + 1],
        *strtol_s = NULL;

    printf("Specificare gli elementi di W separati da un invio.\n");
    for (int i = 0; i < n; i++) {
        printf("\nInserire elemento NÂ° %d: ", i+1);
        
        fgets(buff, MAX_INPUT_SIZE, stdin);
        int x = strtol(buff, &strtol_s, 10);
        // Ci assicuriamo che la stringa inserita dall'utente sia effettivamente un numero intero
        if (strtol_s != NULL && *strtol_s != '\n' && *strtol_s != 0) {
            printf("Il numero specificato non Ã¨ valido.");
            exit(-1);
        }

        W[i] = min(max(1, x), L);
        //printf("W[%d]: %d\n", i, W[i]);
    }

    return W;
}

Params decodeParameters(int argc, char **argv) {
    
    if (argc != 4)
        usageAndExit();

    Params params;

    if (strlen(argv[1]) < 5 || strlen(argv[1]) > 15)
        usageAndExit();
    params.alfabeto = argv[1]; // non serve strcpy

    char *strtol_s = NULL;
    params.n = strtol(argv[2], &strtol_s, 10);
    if (*strtol_s || params.n < 5 || params.n > 20)
        usageAndExit();
    
    params.output = argv[3]; // non serve strcpy

    return params;
}

