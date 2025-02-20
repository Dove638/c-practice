#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

// Enqueue: Adds an element to the circular queue
void enqueueCircle(int *circleQueue, int data, int *front, int *back, int capacity);

// Dequeue: Removes an element from the circular queue
int dequeueCircle(int *circleQueue, int *front, int *back, int capacity);

// Check if the queue is empty
int isEmptyCircleQ(int *circleQueue, int *front, int *back);

// Check if the queue is full
int isCircleQFull(int *circleQueue, int *front, int *back, int capacity);

// Print the queue contents for debugging
void printCQueue(int *circleQueue, int front, int back, int capacity);

int main(int argc, char *argv[]){
    queue_t *queue1 = initQueue();
    printf("Is queue empty? %d.\n", empty(queue1));

    enqueue(queue1, 1);
    printf("Added element to queue\n");
    printf("Is queue empty? %d.\n", empty(queue1));

    enqueue(queue1, 2);
    enqueue(queue1, 3);
    enqueue(queue1, 4);
    printQueue(queue1);


    dequeue(queue1);
    printf("Removed element from queue\n");
    dequeue(queue1);
    printf("Removed element from queue\n");
    printQueue(queue1);


    enqueue(queue1, 5);
    enqueue(queue1, 6);

    printQueue(queue1);

    // Fixed array circular queue

    int capacity = 6;                      // Capacity includes buffer slot
    int circeQueue[6] = {0};               // Initialize queue array
    int front = 0, back = 0;               // Front and back pointers

    printf("Testing Circular Queue Implementation\n");

    // Check if queue is initially empty
    printf("Is queue empty? %s\n", isEmptyCircleQ(circeQueue, &front, &back) ? "Yes" : "No");

    // Enqueue elements
    enqueueCircle(circeQueue, 10, &front, &back, capacity);
    enqueueCircle(circeQueue, 20, &front, &back, capacity);
    enqueueCircle(circeQueue, 30, &front, &back, capacity);
    enqueueCircle(circeQueue, 40, &front, &back, capacity);
    enqueueCircle(circeQueue, 50, &front, &back, capacity); // Should fill up to buffer

    printCQueue(circeQueue, front, back, capacity);

    // Attempt to enqueue when full
    enqueueCircle(circeQueue, 60, &front, &back, capacity); // Should print "Queue is full"

    // Dequeue some elements
    dequeueCircle(circeQueue, &front, &back, capacity);
    dequeueCircle(circeQueue, &front, &back, capacity);

    printCQueue(circeQueue, front, back, capacity);

    // Enqueue after dequeuing to test wrap-around
    enqueueCircle(circeQueue, 60, &front, &back, capacity);
    enqueueCircle(circeQueue, 70, &front, &back, capacity);

    printCQueue(circeQueue, front, back, capacity);

    // Check full and empty states
    printf("Is queue full? %s\n", isCircleQFull(circeQueue, &front, &back, capacity) ? "Yes" : "No");
    printf("Is queue empty? %s\n", isEmptyCircleQ(circeQueue, &front, &back) ? "Yes" : "No");

    // Dequeue all elements to empty the queue
    while (!isEmptyCircleQ(circeQueue, &front, &back)) {
        dequeueCircle(circeQueue, &front, &back, capacity);
    }

    printf("Queue emptied.\n");
    printf("Is queue empty? %s\n", isEmptyCircleQ(circeQueue, &front, &back) ? "Yes" : "No");







    return 0;
}


// Enqueue: Adds an element to the circular queue
void enqueueCircle(int *circleQueue, int data, int *front, int *back, int capacity) {
    int nextBack = (*back + 1) % capacity;

    if (nextBack == *front) {
        printf("Queue is full\n");
        return;
    }

    circleQueue[*back] = data;
    *back = nextBack;
    printf("Enqueued: %d\n", data);
}

// Dequeue: Removes an element from the circular queue
int dequeueCircle(int *circleQueue, int *front, int *back, int capacity) {
    if (*front == *back) {
        fprintf(stderr, "Queue is empty\n");
        exit(EXIT_FAILURE);
    }

    int data = circleQueue[*front];
    *front = (*front + 1) % capacity;
    printf("Dequeued: %d\n", data);
    return data;
}

// Check if the queue is empty
int isEmptyCircleQ(int *circleQueue, int *front, int *back) {
    return *front == *back;
}

// Check if the queue is full
int isCircleQFull(int *circleQueue, int *front, int *back, int capacity) {
    return ((*back + 1) % capacity) == *front;
}

// Print the queue contents for debugging
void printCQueue(int *circleQueue, int front, int back, int capacity) {
    printf("Queue: ");
    int i = front;
    while (i != back) {
        printf("%d ", circleQueue[i]);
        i = (i + 1) % capacity;
    }
    printf("\n");
}