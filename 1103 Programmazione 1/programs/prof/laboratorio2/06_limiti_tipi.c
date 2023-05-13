#include <stdio.h>
#include <limits.h>
#include <float.h>

 

int main(){
    printf("TYPE\t\t\tSIZE\tMIN\t\t\tMAX\n");
    printf("----------------------------------------------------------------------------\n");
    printf("char\t\t\t%lu\t%d\t\t\t%d\n", sizeof(char), CHAR_MIN, CHAR_MAX);
    printf("unsigned char\t\t%lu\t%d\t\t\t%d\n", sizeof(unsigned char), 0, UCHAR_MAX);
    printf("----------------------------------------------------------------------------\n");
    printf("short int\t\t%lu\t%d\t\t\t%u\n", sizeof(short int), SHRT_MIN, SHRT_MAX);
    printf("unsigned short int\t%lu\t%d\t\t\t%u\n", sizeof(unsigned short int), 0, USHRT_MAX);
    printf("int\t\t\t%lu\t%d\t\t%d\n", sizeof(int), INT_MIN, INT_MAX);
    printf("unsigned int\t\t%lu\t%d\t\t\t%u\n", sizeof(unsigned int), 0, UINT_MAX);
    printf("long int\t\t%lu\t%ld\t%ld\n", sizeof(long int), LONG_MIN, LONG_MAX);
    printf("unsigned long int\t%lu\t%d\t\t\t%lu\n", sizeof(unsigned long int), 0, ULONG_MAX);
    printf("----------------------------------------------------------------------------\n");
    printf("float\t\t\t%lu\t%e\t\t%e\n", sizeof(float), FLT_MIN, FLT_MAX);
    printf("double\t\t\t%lu\t%e\t\t%e\n", sizeof(double), DBL_MIN, DBL_MAX);
    printf("long double\t\t%lu\t%Le\t\t%Le\n", sizeof(long double), LDBL_MIN, LDBL_MAX);
    printf("----------------------------------------------------------------------------\n");

}
