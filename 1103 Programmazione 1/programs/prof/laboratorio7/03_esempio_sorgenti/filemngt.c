#include "filemngt.h"
#include <stdio.h>
#include <stdbool.h>

bool writeToFile(char* filename, char* array[], int n){
    FILE *f = fopen(filename, "w");

    if(f == NULL)
        return false;

    for(size_t i = 0; i<n; i++) {
        fprintf(f, "%s\n", array[i]);
    }

    fclose(f);
    return true;
}