#include "list.h"
#include "node.h"
#include "data.h"

#include <stdio.h>
#include <stdlib.h>

void printList(struct nodo *head)
{
    struct nodo *temp = head;
    while (temp != NULL)
    {
        printDato(&temp->d);
        // printf("\n%d", temp->d.value);
        temp = temp->next;
    }
}

void insertNode(struct dato *d, struct nodo **head)
{
    struct nodo *newNodo = (struct nodo*) malloc(sizeof(struct nodo*));
    printf("1");

    newNodo->d.value = d->value;
    newNodo->next = (*head)->next;

    printf("2");

    if((*head) == NULL){
    printf("3");
        (*head)->next = newNodo;
    printf("4");

    }
    else{
    printf("5");
        newNodo->next = (*head)->next;
    printf("6");
        (*head)->next = newNodo;
    printf("7");
    }
}