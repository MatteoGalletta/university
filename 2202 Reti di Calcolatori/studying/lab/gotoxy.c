#include <stdio.h>
#include <stdlib.h>

void gotoxy(int x,int y)
{
    printf("%c[%d;%df",0x1B,y,x);
}

int main(void)
{
    gotoxy(10,10);
    printf("hello world");
    return 0;
} 

