#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>

typedef struct node_t{
    int data;
    struct node_t *next;
}
node_t;

typedef struct queue_t{
    node_t *front;
    node_t *back;
}
queue_t;


// Function Declarations

// Function Definitions (Implementation)
node_t *initNode(int data);

queue_t *initQueue();

// returns 1 if true, returns 0 if false
int empty(queue_t *queue);

// adds value at a position at the tail
void enqueue(queue_t *queue, int data);

// returns value and removes least recently added element (front)
int dequeue(queue_t *queue);

void printQueue(queue_t *queue);



#endif