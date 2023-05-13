#include "list.h"
#include "data.h"
#include "node.h"
#include <stdio.h>
#include <stdlib.h>

int main(){

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


    struct nodo *head = &n1;

    printList(head);
}