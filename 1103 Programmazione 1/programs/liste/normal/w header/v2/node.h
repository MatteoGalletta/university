#ifndef NODE_H
    #define NODE_H
    #include "data.h"
    struct nodo{
        struct dato d; // data.h
        struct nodo *next;   
    };
#endif
