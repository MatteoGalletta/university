#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

// Struct nodo della lista
struct node {
    int data;
    struct node* prev; //abbiamo sia un riferimento al precedente
    struct node* next; //che un riferimento al successivo
};

typedef struct node Node;

// determina se la lista è vuota
bool isEmpty(Node *head) {
    return head==NULL;
}

// Inserimento in testa
bool insertHead(Node **head, int data) {
    // allochiamo spazio per un nuovo nodo
    Node *newNode = malloc(sizeof(Node));
    
    // controlliamo che l'allocazione sia possibile
    if(newNode==NULL)
        return false;

    // inseriamo l'intero nel nodo
    newNode->data = data;

    // imposto il next del nodo alla testa
    newNode->next = *head;
    newNode->prev = NULL; // il prev va a NULL (primo elemento della lista)

    // se la head non è nulla
    if(*head != NULL) {
        (*head)->prev = newNode; //imposto il prev al nodo corrente (è la nuova testa)
    }

    // cambio l'indirizzo a cui punta la testa
    *head = newNode;

    return true;
}

// Inserimento dopo uno specifico nodo
bool insertAfter(Node *node, int data) {
    // Se il nodo passato è NULL, non possiamo inserire dopo di esso
    if(node==NULL)
        return false;

    //alloco memoria
    Node *newNode = malloc(sizeof(Node));

    if(newNode==NULL)
        return false;

    // Inserisco il dato
    newNode->data = data;

    // imposto il prev del nuovo nodo al nodo corrente
    newNode->prev = node;
    newNode->next = node->next; //imposto il next del nuovo nodo al next del vecchio nodo

    node->next = newNode; // imposto il next del vecchio nodo al nuovo nodo

    if(newNode->next != NULL) //se il nuovo nodo ha un next (se non è NULL)
        newNode->next->prev = newNode; //imposto il prev del next al nuovo nodo

    return true;
}

// Inserimento in coda
bool insertTail(Node **head, int data) {
    // se la lista è vuota
    if(isEmpty(*head))
        // facciamo un inserimento in testa
        return insertHead(head, data);

    // allochiamo memoria
    Node *newNode = malloc(sizeof(Node));

    // controlliamo che l'allocazione abbia funzionato
    if(newNode==NULL)
        return false;

    // Inseriamo il dato
    newNode->data = data;

    // uso current come cursore per scorrere la lista
    Node *current = *head;

    // scorro fino alla coda (next sarà NULL)
    while(current->next)
        current = current->next;
    
    // il next della cosa sarà il nuovo nodo
    current->next = newNode;
    newNode->prev = current; // il prev della nuova coda sarà la vecchia coda
    newNode->next = NULL; // il next della nuova coda sarà NULL
    
    return true;
}

// Inserimento ordinato
bool insertOrdered(Node **head, int data) {
    // Se vuota, faccio inserimento in testa
    if(isEmpty(*head) || (*head)->data > data)
        return insertHead(head, data);
    
    // Alloco memoria
    Node *newNode = malloc(sizeof(Node));

    // Controllo allocazione sia ok
    if(newNode==NULL)
        return false;

    // inserisco il dato
    newNode->data = data;

    // cursore
    Node *current = *head;

    // scorro finché il next è valido e finché il next è minore di data
    while(current->next && current->next->data < data)
        current = current->next;

    // Quando esco, o il next non è valido (sono in coda) o il next è il primo nodo che contiene un valore maggiore di data
    
    // In entrambi i casi, inserisco dopo il nodo corrente
    return insertAfter(current, data);
}

// Cancello un nodo
bool deleteNode(Node **head, int data) {
    // Se la lista è vuota, non posso cancellare nulla
    if(isEmpty(*head))
        return false;
    
    // Cursore
    Node *tmp = *head;

    // Scorro finché il cursore è valido e finché non trovo il dato
    while(tmp && tmp->data != data)
        tmp = tmp->next;

    // Se tmp diventa NULL, non ho trovato il dato
    if(tmp==NULL)
        return false;

    // Altrimenti, scollego il nodo dalla lista
    Node *prev = tmp->prev; // prendo riferimento a prev
    Node *next = tmp->next; // e next

    if(prev)
        prev->next = next; // il next di prev punta al next
    if(next)
        next->prev = prev; // il prev di next punta a prev

    // Se il nodo da rimuovere è la testa
    if(tmp==*head) 
        *head = next; //aggiorna il riferimento della testa

    free(tmp); // libero memoria

    return true;
}

bool printList(Node *head) { //stampiamo la lista
    if(head == NULL) //se è vuota non posso stampare
        return false;

    // cursore per scorre la lsita
    Node *currentNode = head;

    // finché il nodo corrente non è NULL
    while(currentNode) {
        // stampo account
        printf("%d\n", currentNode->data);
        // continuo a scorrere la lista
        currentNode = currentNode->next;
    }
    
    return true;
}

bool printListReverse(Node *head) { //stampiamo la lista
    if(head == NULL) //se è vuota non posso stampare
        return false;

    Node *cursor = head;
    while(cursor->next)//vado alla coda
        cursor = cursor->next; 

    // finché il nodo corrente non è NULL
    while(cursor) {
        // stampo account
        printf("%d\n", cursor->data);
        // continuo a scorrere la lista all'indietro
        cursor = cursor->prev;
    }
    
    return true;
}

int main() {
    int tipoInserimento;
    int numero = 0;
    Node *head = NULL;

    puts("Scegli un tipo di inserimento (default: coda):");
    puts(" 1 in testa");
    puts(" 2 ordinato");
    puts(" 3 in coda");
    

    scanf("%d", &tipoInserimento);

    printf("Scelto inserimento ");
    switch(tipoInserimento) {
        case 1:
            printf("in testa");
            break;
        case 2:
            printf("ordinato");
            break;
        default:
            printf("in coda");
    }
    puts("");
    puts("");

    puts("Inserire una lista di numeri interi. Terminare inserimento con -1.");

    while(numero!=-1) {
        scanf("%d", &numero);

        if(numero!=-1) {
            switch(tipoInserimento) {
                case 1:
                    insertHead(&head, numero);
                    break;
                case 2:
                    insertOrdered(&head, numero);
                    break;
                default:
                    insertTail(&head, numero);
            }
        }
    }

    puts("Numeri inseriti:");
    printList(head);
    

    printf("\nInserisci numero da cancellare: ");
    scanf("%d", &numero);

    if(deleteNode(&head, numero)) {
        puts("Nuova lista:");
        printList(head);
    } else {
        printf("Impossibile eliminare il nodo %d", numero);
    }

    puts("\nLista al contrario:");
    printListReverse(head);
}