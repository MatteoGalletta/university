#include <stdio.h>
#include <stdlib.h>

int main(void) {

	char s1[] = "s1";
	char *s2 = "s2";
	char *s3 = malloc(sizeof(char) * 10);
	for (int i = 0; i < 9; i++)
		s3[i] = 'A'+i;
	s3[9] = 0;

	printf("s1: %p - &s1: %p (s1==&s1: %d)\n", s1, &s1, s1==&s1);
	printf("s2: %p - &s2: %p (s2==&s2: %d)\n", s2, &s2, s2==&s2);
	printf("s3: %p - &s3: %p (s3==&s3: %d)\n", s3, &s3, s3==&s3);

	return 0;
}