#include "stringcomp.h"
#include <stdlib.h>
#include <string.h>

char* sampleString(const char* alfabeto, short k) {
    char* s = calloc(k+1,sizeof(char));
    int len = strlen(alfabeto);
    for (size_t i = 0; i<k; i++) {
        s[i] = alfabeto[sampleIndex(len)];
    }
    s[k] = 0;
    return s;
}

int sampleIndex(int max){
    return rand() % max;
}