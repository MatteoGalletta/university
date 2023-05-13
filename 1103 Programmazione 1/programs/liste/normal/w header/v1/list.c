#include <stdio.h>
#include "list.h"
#include "node.h"
#include "data.h"

// void insertNode(struct dato *d, struct nodo **head)
// {
//     struct nodo newNodo = {
//         d->value,
//         NULL
//     };

//     (*head)->next = &newNodo;
// }
    void printList(struct nodo* head)
{
    struct nodo *temp = NULL;
    temp->next = &head->next;
    while(temp != NULL){
        printf("%d", temp->d.value);
        temp->next = &temp->next;
    }
}