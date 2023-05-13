#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LENGTH 256

typedef struct
{
	char *inputFileName;
	char *outputFileName;
} Config;

typedef struct
{
	char *nome;
	char *cognome;
	int numeroConto;
	int annoApertura;
	float saldo;
} BankAccount;

typedef struct s_Node Node;
struct s_Node
{
	BankAccount account;
	struct s_Node *next;
};

float max(float f1, float f2)
{
	return f1 > f2 ? f1 : f2;
}
float min(float f1, float f2)
{
	return f1 < f2 ? f1 : f2;
}

bool checkFileExtensionMatch(char *fileName, char *extension);
Config readInput(int argc, char **argv);
Node *readFile(char *fileName, int *n);
void writeFile(char *fileName, Node *node);
float getSaldoMax(Node *head);
Node *getMax(Node *head, float m);
void removeAccount(Node **head, Node *toRemove);

bool insertHead(Node **node, BankAccount account);
bool insertOrdered(Node **noed, BankAccount account);

int main(int argc, char **argv)
{
	printf("prova");
	Config config = readInput(argc, argv);

	int numeroAccount;
	Node *list = readFile(config.inputFileName, &numeroAccount);

	writeFile(config.outputFileName, list);

	int saldoMax = getSaldoMax(list);
	for (int i = 0; i < numeroAccount / 2; i++)
	{
		removeAccount(&list, getMax(list, saldoMax));
	}

	writeFile(config.outputFileName, list);
	return 0;
}

Config readInput(int argc, char **argv)
{

	if (argc != 3)
	{
		fprintf(stderr, "Numero di parametri passato non valido\n");
		exit(-1);
	}

	Config config = {
		.inputFileName = argv[1],
		.outputFileName = argv[2]};

	if (!checkFileExtensionMatch(config.inputFileName, ".txt"))
	{
		fprintf(stderr, "Errore: il file di input deve avere estensione '.txt'\n");
		exit(-1);
	}

	if (!checkFileExtensionMatch(config.outputFileName, ".txt"))
	{
		fprintf(stderr, "Errore: il file di output deve avere estensione '.txt'\n");
		exit(-1);
	}

	return config;
}

Node *readFile(char *fileName, int *n)
{
	Node **list = malloc(sizeof(Node *));
	if (list == NULL)
	{
		fprintf(stderr, "Errore durante l'allocazione nell'heap: ");
		perror("");
		exit(-1);
	}

	FILE *f = fopen(fileName, "r");
	if (f == NULL)
	{
		fprintf(stderr, "Errore durante l'apertura del file: ");
		perror("");
		exit(-1);
	}

	char *s = malloc(sizeof(char) * 256),
		 *current,
		 *strtol_s = malloc(sizeof(char));
	if (s == NULL || strtol_s == NULL)
	{
		fprintf(stderr, "Errore durante l'allocazione nell'heap: ");
		perror("");
		exit(-1);
	}

	*n = 0;
	while (fgets(s, 256, f))
	{

		BankAccount account;
		account.nome = malloc(sizeof(char) * MAX_LENGTH);
		account.cognome = malloc(sizeof(char) * MAX_LENGTH);

		if (account.nome == NULL || account.cognome == NULL)
		{
			fprintf(stderr, "Errore durante l'allocazione nell'heap: ");
			perror("");
			exit(-1);
		}

		current = strtok(s, " \n");
		if (current == NULL)
		{
			fprintf(stderr, "Formato del file non valido (nome assente)");
			exit(-1);
		}
		strcpy(account.nome, current);

		current = strtok(NULL, " \n");
		if (current == NULL)
		{
			fprintf(stderr, "Formato del file non valido (cognome assente)");
			exit(-1);
		}
		strcpy(account.cognome, current);

		current = strtok(NULL, " \n");
		if (current == NULL)
		{
			fprintf(stderr, "Formato del file non valido (numero_conto assente)");
			exit(-1);
		}
		account.numeroConto = strtol(current, &strtol_s, 10);
		if (*strtol_s)
		{
			fprintf(stderr, "Formato del file non valido (numero_conto non Ã¨ valido)");
			exit(-1);
		}

		current = strtok(NULL, " \n");
		if (current == NULL)
		{
			fprintf(stderr, "Formato del file non valido (anno_apertura assente)");
			exit(-1);
		}
		account.annoApertura = strtol(current, &strtol_s, 10);
		if (*strtol_s)
		{
			fprintf(stderr, "Formato del file non valido (anno_apertura non Ã¨ valido)");
			exit(-1);
		}

		current = strtok(NULL, " \n");
		if (current == NULL)
		{
			fprintf(stderr, "Formato del file non valido (saldo assente)");
			exit(-1);
		}
		account.saldo = strtof(current, &strtol_s);
		if (*strtol_s)
		{
			fprintf(stderr, "Formato del file non valido (saldo non Ã¨ valido)");
			exit(-1);
		}

		insertHead(list, account);
		*n++;
	}

	return *list;
}

bool checkFileExtensionMatch(char *fileName, char *extension)
{
	int extensionLength = strlen(extension);
	char *pointerToExtensionInFileName = fileName + strlen(fileName) - extensionLength;
	return strcmp(pointerToExtensionInFileName, extension) == 0;
}

bool insertHead(Node **node, BankAccount account)
{

	Node *newNode = malloc(sizeof(Node *));
	if (newNode == NULL)
	{
		fprintf(stderr, "Errore nell'allocazione durante insertHead: ");
		perror("");
		return false;
	}

	newNode->account = account;
	newNode->next = *node;

	*node = newNode;

	return true;
}

float getSaldoMax(Node *head)
{
	float m = 0;
	while (head != NULL)
	{
		m = max(m, head->account.saldo);
		head = head->next;
	}
	return m;
}

Node *getMax(Node *head, float m)
{
	if (head == NULL)
		return NULL;

	float maxValue;
	Node *maxValueNode = NULL;
	while (head != NULL)
	{

		int currentValue = min((2023 - head->account.annoApertura) / 5., 1) * head->account.saldo / m;
		if (maxValue < currentValue)
		{
			maxValue = currentValue;
			maxValueNode = head;
		}

		head = head->next;
	}

	return maxValueNode;
}

void removeAccount(Node **head, Node *toRemove)
{
	if (*head == NULL)
	{
		return;
	}
	Node *prec = *head;

	Node *current = (*head)->next;
	while (current != toRemove)
	{
		prec = current;
		current = current->next;
	}

	prec->next = current->next;
	free(current);
}

void writeFile(char *fileName, Node *node)
{

	FILE *f = fopen(fileName, "w");
	if (f == NULL)
	{
		fprintf(stderr, "Errore durante l'apertura del file in scrittura: ");
		perror("");
		exit(-1);
	}

	while (node != NULL)
	{
		fprintf(f, "%s %s %d %d %f\n",
				node->account.nome,
				node->account.cognome,
				node->account.numeroConto,
				node->account.annoApertura,
				node->account.saldo);
		node = node->next;
	}
}

bool insertOrdered(Node **head, BankAccount account)
{
	if (*head == NULL)
	{
		return insertHead(head, account);
	}

	Node *newNode = malloc(sizeof(Node *));
	if (newNode == NULL)
	{
		fprintf(stderr, "Errore nell'allocazione durante insertHead: ");
		perror("");
		return false;
	}

	Node *prec = *head;

	Node *current = (*head)->next;
	while (current != NULL &&
		   current->account.annoApertura < account.annoApertura &&
		   current->account.saldo < account.saldo)
	{
		prec = current;
		current = current->next;
	}

	prec->next = newNode;
	newNode->next = current;

	return true;
}
