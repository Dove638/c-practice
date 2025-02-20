#include <stdio.h>
#include <stdlib.h>


#include "queue.h"


// Function Definitions (Implementation)
node_t *initNode(int data){
    node_t *tmp = (node_t*)malloc(sizeof(node_t));
    tmp->data = data;
    tmp->next = NULL;
    return tmp;
}

queue_t *initQueue(){
    queue_t *newQueue = (queue_t*)malloc(sizeof(queue_t));
    newQueue->front = NULL;
    newQueue->back = NULL;

    return newQueue;
}


void enqueue(queue_t *queue, int data){
    
}