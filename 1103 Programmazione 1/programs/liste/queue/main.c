#include <stdio.h>
#include <stdlib.h>

struct data {
    int number;
};

struct node {
    struct data dataNode;
    struct node* nextNode;
};

struct queue {
    struct node *front, *back;
};

void dequeue(struct queue **queue);
struct data first(struct queue **queue);
void enqueue(struct queue **queue, struct data *toenqueue);
int isEmpty(struct queue **queue);
void printFirst(struct queue **queue);

int main() {

    struct queue *queue = (struct queue *) malloc(sizeof(struct queue));
    queue->back = queue->front = NULL;

    struct data data1 = {.number = 1};
    struct data data2 = {.number = 2};
    struct data data3 = {.number = 3};
    struct data data4 = {.number = 4};

    enqueue(&queue, &data1);
    printFirst(&queue);
    enqueue(&queue, &data2);
    printFirst(&queue);
    enqueue(&queue, &data3);
    printFirst(&queue);
    dequeue(&queue);
    printFirst(&queue);
    enqueue(&queue, &data4);
    printFirst(&queue);

    return 0;
}

int isEmpty(struct queue **queue) {
    return (*queue)->front == NULL;
}

void dequeue(struct queue **queue)
{
    if (*queue == NULL) return;

    if ((*queue)->back == (*queue)->front) {
        free((*queue)->back);
        (*queue)->back = (*queue)->front = NULL;
        return;
    }

    struct node *tempNode = (*queue)->back;
    while (tempNode->nextNode != (*queue)->front) {
        tempNode = tempNode->nextNode;
    }

    free((*queue)->front);
    (*queue)->front = tempNode;
}

struct data first(struct queue **queue)
{
    return (*queue)->front->dataNode;
}

void printFirst(struct queue **queue)
{
    printf("queue.first(): %d\n", first(queue).number);
}

void enqueue(struct queue **queue, struct data *toEnqueue)
{
    struct node *newNode = (struct node *) malloc(sizeof(struct node));
    newNode->nextNode = (*queue)->back;
    newNode->dataNode = *toEnqueue;
    (*queue)->back = newNode;

    if (newNode->nextNode == NULL) // 1st element
        (*queue)->front = (*queue)->back;
}