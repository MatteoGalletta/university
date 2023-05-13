#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

struct stackNode {
    char* name;
    struct stackNode *next;
};

typedef struct stackNode StackNode;

char* myStringCopy(char* inputString) {
    // allochiamo un array di caratteri di dimensione
    // lunghezza delle stringa +1 (prevediamo il carattere di terminazione)
    char* out = calloc(strlen(inputString)+1, sizeof(char)); // dovremo ricordarci di liberare questa memoria!

    if(out) { // controllo che la memoria sia stata allocata correttamente
        // copio i caratteri dalla stringa di input
        // a quella di output
        strcpy(out, inputString);
        //out[strlen(inputString)] = 0;
    }
    return out; // restituisco il puntatore
}

// Effettua push nello stack
bool push(StackNode **top, char* name) {
    // Nuovo nodo
    StackNode *newNode = malloc(sizeof(StackNode));

    // se non siamo riusciti ad allocare memoria
    if(newNode==NULL)
        return false; // restituisco false

    // copio la stringa in name e imposto la vecchia cima come next
    newNode->name = myStringCopy(name);
    newNode->next = *top;

    // top deve puntare alla nuova cima
    *top = newNode;

    return true;
}

// effettua il pop
char* pop(StackNode **top) {
    // teniamo un riferimento alla cima corrente
    StackNode *tmp = *top;
    // prendiamo un riferimento alla stringa dentro la cima corrente
    char* data = tmp->name;
    // scorriamo la cima al prossimo nodo
    *top = tmp->next;
    free(tmp); // liberiamo la memoria occupata dal nodo
    // da notare che non facciamo free(data) perché la stringa la vogliamo restituire al chiamante
    return data; //restituiamo la stringa
}

// Una funzione che controlla se la pila è vuota
bool isEmpty(StackNode *top) {
    return top==NULL;
}

int main() {
    printf("Inserisci i nomi delle persone che entrano in ascensore.\n");
    printf("Usa EOF per terminare l'inserimento.\n");

    StackNode* stack = NULL;

    char name[255] = "";

    // continua a leggere finché non raggiungiamo EOF
    bool reachEnd = false;
    while(!reachEnd) {
        scanf("%s", name);
        if(!feof(stdin)) { //se non abbiamo letto EOF
            push(&stack, name); //facciamo push
        } else {
            reachEnd = true; //altrimenti abbiamo raggiunto la fine dell'input
        }
    }

    // Effettuiamo diversi pop finché la pila non diventa vuota
    printf("\nOrdine di uscita:\n");

    while(!isEmpty(stack)) { //iteriamo finché la pila non è vuota
        char* string = pop(&stack);
        printf("%s\n", string);
        free(string);
    }
}