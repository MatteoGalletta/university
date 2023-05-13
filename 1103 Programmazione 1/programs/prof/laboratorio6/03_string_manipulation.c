#include <stdio.h>
#include <string.h> // include le librerie per la manipolazione delle stringhe
#include <stdlib.h>

#define SIZE1 25
#define SIZE2 15

char* outString() {
    //char x[] = "abc";
    char *x = malloc(4*sizeof(char));
    x = "abc";
    return x;
}

int main() {
    char x[] = "Happy Birthday to You"; // initialize char array x
    char y[SIZE1] = ""; // create char array y
    char z[SIZE2] = ""; // create char array z
   
    // copy contents of x into y
    printf("%s%s\n%s%s\n", 
       "The string in array x is: ", x,
       "The string in array y is: ", strcpy(y, x)); 

    strncpy(z, x, SIZE2 - 1); // copy first 14 characters of x into z
    z[SIZE2 - 1] = '\0'; // terminate string in z, because '\0' not copied
    printf("The string in array z is: %s\n", z);

    char s1[20] = "Happy "; // initialize char array s1
    char s2[] = "New Year "; // initialize char array s2
    char s3[40] = ""; // initialize char array s3 to empty

    printf("s1 = %s\ns2 = %s\n", s1, s2);

    //char *out = strcat(s1,s2);

    // concatenate s2 to s1
    printf("strcat(s1, s2) = %s\n", strcat(s1, s2));

    // concatenate first 6 characters of s1 to s3     
    printf("s3=strncat(s3, s1, 6) = %s\n", strncat(s3, s1, 6));

    // concatenate s1 to s3
    printf("strcat(s3, s1) = %s\n", strcat(s3, s1));


    const char *x1 = "Happy New Year"; // initialize char pointer
    const char *x2 = "Happy New Year"; // initialize char pointer
    const char *x3 = "Happy Holidays"; // initialize char pointer

    // Compara le stringhe lessicograficamente
    printf("s1 = %s\ns2 = %s\ns3 = %s\n\n%s%2d\n%s%2d\n%s%2d\n\n",
        x1, x2, x3,
        "strcmp(x1, x2) = ", strcmp(x1, x2),
        "strcmp(x1, x3) = ", strcmp(x1, x3),
        "strcmp(x3, x1) = ", strcmp(x3, x1));

    printf("%s%2d\n%s%2d\n%s%2d\n",
        "strncmp(x1, x3, 6) = ", strncmp(x1, x3, 6),
        "strncmp(x1, x3, 7) = ", strncmp(x1, x3, 7),
        "strncmp(x3, x1, 7) = ", strncmp(x3, x1, 7));

    char *y1 = "Happy New Year";
    char *y2 = "New";
    // Trovare sottostringhe con strstr
    char* substring = strstr(y1, y2);
    if (substring) // o equivalentemente if (substring!=NULL)
        printf("La stringa %s è stata trovata nella stringa %s. Ecco il valore restituito: %s. Indice del primo carattere in cui è stata trovata la sottostringa: %lu\n", y2, y1, substring, substring - y1);
    else
        printf("La stringa %s non è stata trovata nella stringa %s\n", y2, y1);

    // Tokenizzazione con strtok
    char string[] = "This is a sentence with 7 tokens";
   
    printf("\nThe string to be tokenized is:\n%s\n\n", string);
    puts("The tokens are:");
        
    char *tokenPtr = strtok(string, " "); // begin tokenizing sentence (space as separation character)

    // continue tokenizing sentence until tokenPtr becomes NULL
    while (tokenPtr != NULL) { 
        printf("%s\n", tokenPtr);
        tokenPtr = strtok(NULL, " "); // get next token
    } 

}

/**************************************************************************
 * (C) Copyright 1992-2021 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 *************************************************************************/