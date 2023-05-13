#include <stdio.h>
#include <stdlib.h>

struct data
{
    int number;
};

struct node
{
    struct data nodeData;
    struct node *nextNode;
};

void insertNode(struct data *newData, struct node **head);
void deleteNode(struct data *d, struct node **head);
void printList(struct node *head);

int main()
{
    struct node *head = NULL; // una lista vuota
    // insertNode(, &head)

    struct data node1 = {.number = 6};
    struct data node2 = {.number = 5};
    struct data node3 = {.number = 4};

    insertNode(&node1, &head);
    printList(head);
    insertNode(&node2, &head);
    printList(head);
    insertNode(&node3, &head);
    printList(head);

    deleteNode(&node3, &head);
    printList(head);
}

void insertNode(struct data *newData, struct node **head)
{
    // verificare se esiste la lista (head != NULL)
    struct node *tempNode = (struct node *)malloc(sizeof(struct node));
    if (*head == NULL || (*head)->nodeData.number >= newData->number)
    {
        tempNode->nextNode = *head;
        tempNode->nodeData = *newData;
        *head = tempNode;
        return;
    }

    // Si scorre la lista finché non si verifica una delle due condizioni:
    // - Arriviamo a fine lista
    // - Troviamo un nodo cui numero è maggiore rispetto a quello da inserire
    struct node *tempHead = *head;
    while (tempHead->nextNode != NULL && tempHead->nextNode->nodeData.number < newData->number)
    {
        tempHead = tempHead->nextNode;
    }

    tempNode->nextNode = tempHead->nextNode;
    tempNode->nodeData = *newData;
    tempHead->nextNode = tempNode;
}

// elimina il primo nodo della lista cui numero del dato corrisponde a quello specificato
void deleteNode(struct data *d, struct node **head)
{
    if (*head == NULL)
        return;

    struct node *tempHead = *head;

    if ((*head)->nodeData.number == d->number) {
        *head = (*head)->nextNode;
        free(tempHead);
        return;
    }

    while (tempHead->nextNode != NULL && tempHead->nextNode->nodeData.number != d->number)
    {
        tempHead = tempHead->nextNode;
    }

    struct node *toDeleteNode = tempHead->nextNode;
    if (toDeleteNode == NULL)
        return;

    tempHead->nextNode = toDeleteNode->nextNode;
    free(toDeleteNode);

    /*
    eliminare 3

    1 2 3 4
        |
    */
}

void printList(struct node *head)
{
    if (isEmpty(head)) return;

    struct node *temp = head;
    while (temp != NULL)
    {
        printDato(&temp->nodeData);
        temp = temp->nextNode;
    }
    printf("\n");
}

// come strcpm() => confronta due dati
int confrontaDati(struct data *d1,struct data *d2) {
    if (d1->number > d2->number)
        return 1;
    if (d1->number < d2->number)
        return -1;
    return 0;
}

// stampa dato
void printDato(struct data *d){
    printf("%d ", d->number);
}

int isEmpty(struct node* head){
    return head == NULL;
}