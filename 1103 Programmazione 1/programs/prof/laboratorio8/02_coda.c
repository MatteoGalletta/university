#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

struct queueNode {
    char *data;
    struct queueNode *next;
};

typedef struct queueNode QueueNode;

char* myStringCopy(char* inputString) {
    // allochiamo un array di caratteri di dimensione
    // lunghezza delle stringa +1 (prevediamo il carattere di terminazione)
    char* out = calloc(strlen(inputString)+1, sizeof(char)); // dovremo ricordarci di liberare questa memoria!

    if(out) { // controllo che la memoria sia stata allocata correttamente
        // copio i caratteri dalla stringa di input
        // a quella di output
        strcpy(out, inputString);
    }
    return out; // restituisco il puntatore
}

// Controlla se la coda è vuota
bool isEmpty(QueueNode *head) {
    return head==NULL;
}

// Inserisce nella queue nodo in coda
bool enqueue(QueueNode **head, QueueNode **tail, char* data) {
    // Crea nuovo nodo
    QueueNode *newNode = malloc(sizeof(QueueNode));

    // se l'allocazione non è andata a buon fine
    if(newNode == NULL)
        return false; //restituisci false

    // Copia la stringa all'interno del nodo
    newNode->data = myStringCopy(data);
    newNode->next = NULL; // Imposta next a NULL

    // Se la pila è vuota
    if(isEmpty(*head)) {
        *head = newNode; //il nodo è la nuova testa
    } else {
        (*tail)->next = newNode; //altrimenti aggiungi un nodo in coda
    }

    // in entrambi i casi, la nuova coda sarà il nuovo nodo
    *tail = newNode;

    return true; //enqeue andato a buon fine
}

// Elimina dala queue un elemento dalla testa
char* dequeue(QueueNode **head, QueueNode **tail) {
    // se la pila è vuota
    if(isEmpty(*head))
        return NULL; //non si può rimuovere dalla coda

    // prendi il riferimento alla stringa
    char* data = (*head)->data;
    QueueNode *tmp = *head; // nodo temporaneo che pongo uguale alla head

    *head = (*head)->next; //faccio avanzare la testa di una posizione

    if(*head==NULL) //se la nuova head è NULL
        *tail = NULL; //la coda è vuota e anche la coda deve diventare NULL

    free(tmp); //libero memoria
    return data; //restituisco la stringa
}

int main() {
    printf("Inserisci i nomi delle persone in fila per l'ascensore:\n");
    printf("Termina inserimento con EOF.\n");

    QueueNode* head = NULL;
    QueueNode* tail = NULL;

    char name[255] = "";

    // continua a leggere finché non raggiungiamo EOF
    bool reachEnd = false;
    while(!reachEnd) {
        scanf("%s", name);
        if(!feof(stdin)) { //se non abbiamo letto EOF
            enqueue(&head, &tail, name); //facciamo push
        } else {
            reachEnd = true; //altrimenti abbiamo raggiunto la fine dell'input
        }
    }

    // Effettuiamo diversi pop finché la pila non diventa vuota
    printf("\nOrdine di ingresso in ascensore:\n");

    while(!isEmpty(head)) { //iteriamo finché la pila non è vuota
        char* string = dequeue(&head, &tail);
        printf("%s\n", string);
        free(string); //libero la memoria occupata dalla stringa
    }
}