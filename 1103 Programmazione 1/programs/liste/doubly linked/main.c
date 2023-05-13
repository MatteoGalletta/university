#include <stdio.h>
#include <stdlib.h>

struct data {
    int number;
};

struct node {
    struct data data;
    struct node* next;
    struct node* prev;
};


void push(struct node **head, struct data *toInsertData);
void append(struct node **head, struct data *toInsertData);
void printList(struct node* head);

int main(){
    struct node *head = NULL; // una lista vuota
    // insertNode(, &head)

    struct data node1 = {.number = 6};
    struct data node2 = {.number = 5};
    struct data node3 = {.number = 4};

    append(&head, &node1);
    printList(head);
    append(&head, &node2);
    printList(head);
    push(&head, &node3);
    printList(head);
}

void push(struct node **head, struct data *toInsertData) {
    struct node *newNode = malloc(sizeof (struct node));
    newNode->data = *toInsertData;
    newNode->prev = NULL;
    newNode->next = *head;
    if (*head != NULL)
        *head = (*head)->prev = newNode;
    else
        *head = newNode;
}

void append(struct node **head, struct data *toInsertData) {
    
    struct node *current = *head;
    if (current != NULL)
        while (current->next != NULL)
            current = current->next;

    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = *toInsertData;
    newNode->prev = current;
    newNode->next = NULL;
    
    if (current != NULL)
        current->next = newNode;
    else
        *head = newNode;
}

void printList(struct node *head) {
	if (head == NULL) {
        printf("<empty>\n");
        return;
    }

    printf("[");
    while (head != NULL) {
        printf("%d", head->data.number);
        if (head->next != NULL)
            printf(", ");
        head = head->next;
    }
    printf("]\n");
}
