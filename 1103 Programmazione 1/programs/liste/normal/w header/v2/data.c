#include "data.h"
#include <stdio.h>

int confrontaDati(struct dato *d1, struct dato *d2){
    if(d1->value < d2->value)
	return -1; 
    
    if((*d1).value > (*d2).value)
	return 1; 

    return 0;
}

void printDato(struct dato *d){
    printf(" [%d] ", d->value); 
}
