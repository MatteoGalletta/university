#include<stdio.h>
#include<stdbool.h>

int main() {
    //conversione implicita da double a int
    int x = 2.0;
    printf("%d\n",x);

    //conversione implicita da intero a float
    float y = 12;
    printf("%.2f\n",y);

    //conversione implicita da intero a bool
    bool b = 5;
    printf("%d\n",b);

    int z = 8.9; // effettua la conversione implicita rimuovendo la parte decimale ma dà un warning
    printf("%d\n",z);
}
