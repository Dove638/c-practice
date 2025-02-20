#ifndef QUEUE.H
#define QUEUE.H

#include <stdlib.h>

typedef struct node_t{
    int data;
    node_t *next;
}
node_t;

typedef struct queue_t{
    node_t *front;
    node_t *back;
}
queue_t;


// Function Declarations






#endif