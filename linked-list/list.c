#include <stdlib.h>
#include <stdio.h>

#include "list.h"



node_t* initNode(int data){
    node_t *tmp = (node_t*)malloc(sizeof(node_t));
    tmp->data = data;
    tmp->next = NULL;
    return tmp;
}


list_t* initList(){
    list_t *tmp = (list_t*)malloc(sizeof(list_t));
    tmp->head = NULL;
    return tmp;
}


// returns the number of data elements in the list
int size(list_t *list){

    int size = 0;

    node_t *temp = NULL;

    if (list->head != NULL){
        temp = list->head;    
    }

    while (temp != NULL){
        size++;
        temp = temp->next;
    }

    return size;
}

//bool returns true if empty
int empty(list_t *list){
    if (list->head!=NULL){
        return 0;
    }
    return 1;
}


//returns the value of the nth item (starting at 0 for first)
int value_at(list_t *list, int index){
    node_t *tmp;
    if (list->head != NULL){
        tmp = list->head;
    }

    // check if n^th is within the bounds of the list
    if (index >= size(list)){
        fprintf(stderr, "Index %d is greater than size of list.\n", index);
        exit(EXIT_FAILURE);
    }

    /// 1 -> 2 -> 3 -> 4 find 2
    while (index != 1){
        tmp = tmp->next;
        index--;
    }
    
    tmp = tmp->next;
    return tmp->data;
}



// adds an item to the front of the list
void  push_front(list_t *list, int data){

    // create a new node with the data
    node_t *newNode = initNode(data);

    if (list->head == NULL){
        list->head = newNode;
    }
    else{
        newNode->next = list->head;
        list->head = newNode;
    }
}


// remove the front item and return its value
int pop_front(list_t *list){
    node_t *tmp = list->head;
    list->head = list->head->next;

    int value = tmp->data;
    tmp->next = NULL;
    free(tmp);
    return value;
}


// adds an item at the end
void push_back(list_t *list, int data){
    node_t *newNode = initNode(data);

    node_t *tmp = list->head;

    // We exit this while loop once we reach the final node since it has no next node
    while (tmp->next != NULL){
        tmp = tmp->next;
    }

    tmp->next = newNode;
}

// removes end item and returns its value
int pop_back(list_t *list){
    node_t *tmp = list->head;

    // We exit this while loop once we reach the second last node since it has no next node
    while (tmp->next->next != NULL){
        tmp = tmp->next;
    }

    node_t *tmp2 = tmp->next;
    int data = tmp2->data;
    tmp2->next = NULL;
    free(tmp2);

    tmp->next = NULL;

    return data;
}

// get the value of the front item
int front(list_t *list){
    return list->head->data;
}

// get the value of the end item
int back(list_t *list){
    node_t *tmp = list->head;

    while  (tmp->next != NULL){
        tmp = tmp->next;
    }

    return tmp->data;
}

// insert value at index, 
// so the current item at that index is pointed to by the new item at the index
void insert(list_t *list, int index, int data){
    node_t *newNode = initNode(data);

    node_t *tmp = list->head;

    if (index >= size(list)){
        fprintf(stderr, "Index %d is greater than size of list.\n", index);
        exit(EXIT_FAILURE);
    }

    while(index != 1){
        tmp = tmp->next;
        index--;
    }

    newNode->next = tmp->next;
    tmp->next = newNode;
}

// removes node at given index
void erase(list_t *list, int index){
    if (index >= size(list)){
        fprintf(stderr, "Index %d is greater than size of list.\n", index);
        exit(EXIT_FAILURE);
    }

    node_t *tmp = list->head;
    while (index != 1){
        tmp = tmp->next;
        index--;
    }
    
    node_t *toBeErased = tmp->next;

    tmp->next = toBeErased->next;

    toBeErased->next = NULL;
    free(toBeErased);
}


// reverses the list
void reverse(list_t *list){
    node_t *prev;
    node_t *curr;
    node_t *nextNode;

    curr = list->head->next;
    prev = list->head;
    prev->next = NULL;

    while (curr->next != NULL){
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    curr->next = prev;
    list->head = curr;
}

// prints the values in a list
void printList(list_t *list){
    node_t *tmp = list->head;

    printf("List: ");
    while (tmp != NULL){
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}

