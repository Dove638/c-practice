#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

typedef struct node_t{
    int data;
    struct node_t *next;
}
node_t;


typedef struct{
    node_t *head;
}
list_t;

node_t* initNode(int data);
list_t* initList();

int size(list_t *list);
int empty(list_t *list);
int value_at(list_t *list, int index);
void  push_front(list_t *list, int data);
int pop_front(list_t *list);
void push_back(list_t *list, int data);
int pop_back(list_t *list);
int front(list_t *list);
int back(list_t *list);
void insert(list_t *list, int index, int data);
void erase(list_t *list, int index);
void reverse(list_t *list);
void printList(list_t *list);

#endif