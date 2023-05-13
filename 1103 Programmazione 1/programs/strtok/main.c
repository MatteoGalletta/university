#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	char s[] = "Questa è una prova della funzione \"strtok\"!";
	// E' importante che la stringa sia "mutabile" (la dichiariamo con le quadre)
	// strtok MODIFICA la stringa "s" passatogli come parametro

	char *ss = strtok(s, " ");
	while (ss != NULL)
	{
		printf("[%s]", ss);
		ss = strtok(NULL, " "); // si passa NULL per riferirsi all'ultima stringa
	}
}