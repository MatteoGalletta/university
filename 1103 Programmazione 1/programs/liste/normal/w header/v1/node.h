#ifndef NODE_H

    #define NODE_H
    #include "data.h"

    // dobbiamo creare la struttura nodo

    // struct dato - struct nodo
    struct nodo
    {
        struct dato d;
        struct nodo *next;
    };

#endif