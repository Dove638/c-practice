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


// returns 1 if true, returns 0 if false
int empty(queue_t *queue){
    if (queue->front){
        return 0;
    }
    return 1;
}


// adds value at a position at the tail
void enqueue(queue_t *queue, int data){
    node_t *newNode = initNode(data);

    //Empty Queue
    if (empty(queue) == 1){
        queue->front = newNode;
        queue->back = newNode;
    }
    // Non-empty queue
    else{
        queue->back->next = newNode;
        queue->back = newNode;
    }

}  

// returns value and removes least recently added element (front)
int dequeue(queue_t *queue){

    // Check if queue is empty;
    if (empty(queue) == 1){
        fprintf(stderr, "Queue is empty");
        exit(EXIT_FAILURE);
    }

    node_t *temp = queue->front;
    int value = temp->data;
    queue->front = queue->front->next;

    temp->next = NULL;
    free(temp);

    return value;
}


void printQueue(queue_t *queue){
    node_t *temp = queue->front;
    printf("Queue: ");
    while (temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


