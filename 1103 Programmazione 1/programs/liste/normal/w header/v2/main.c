#include "list.h"
#include "node.h"
#include "data.h"

#include <stdio.h>

int main()
{

    // lista inizialmente vuota
    // struct node *head = NULL;

    struct nodo n3 = {
        {30},
        NULL
    };
    struct nodo n2 = {
        {20},
        &n3
    };
    struct nodo n1 = {
        {10},
        &n2
    };

    // struct nodo *head = &n1;
    struct nodo *head = NULL;

    // printf("\nLIST\n");
    // printList(head);
    
    struct dato x;
    x.value = 4;
    printf("\nINSERT %d\n", x.value);
    insertNode(&x, &head);

    printf("\nLIST\n");
    printList(head);
}
