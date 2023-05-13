#include <stdio.h>
#include <stdlib.h>

struct data{
    int number
};

struct node{
    struct data dataNode;
    struct node* nextNode;
};

void pop(struct node **stack);
struct data top(struct node **stack);
void insert(struct node **stack, struct data *toInsert);
void printTop(struct node **stack);

int main(int argc, char** argv){

	struct node *stack = NULL;

    struct data data1 = {.number = 1};
    struct data data2 = {.number = 2};
    struct data data3 = {.number = 3};
    struct data data4 = {.number = 4};

    insert(&stack, &data1);
    printTop(&stack);
    insert(&stack, &data2);
    printTop(&stack);
    insert(&stack, &data3);
    printTop(&stack);
    pop(&stack);
    printTop(&stack);
    insert(&stack, &data4);
    printTop(&stack);

    return 0;
}

// per fare uscire l'elemento in cima alla pila
void pop(struct node **stack) {
   struct node* toDeleteNode = *stack;
   *stack = toDeleteNode->nextNode;
   free(toDeleteNode);
}

// per visualizzare l'elemento in pila
struct data top(struct node **stack)
{
    return (*stack)->dataNode;
}

void printTop(struct node **stack) {
	printf("Stack.top: %d ", top(stack).number);
}

// per aggiungere un elemento in pila
void insert(struct node **stack, struct data *toInsert)
{
    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    newNode->dataNode = *toInsert;
    newNode->nextNode = *stack;
    *stack = newNode;
}