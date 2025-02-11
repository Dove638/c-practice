#include <stdlib.h>
#include <stdio.h>

#include "vector.h"

// Function Definition
vector_t *initVector(size_t initial_capacity){
    // create a new vector abstract data type and malloc the needed memory for it on the heap
    vector_t *new_vector = (vector_t*)malloc(sizeof(vector_t));
    if (!new_vector) {
        perror("Failed to allocate vector");
        exit(EXIT_FAILURE);
    }

    // malloc the "data" in the vector to be a dyanmically sized array and allocate the initial capacity of it
    new_vector->data = (int*)malloc(sizeof(int) * initial_capacity);
    if (!new_vector->data) {
        free(new_vector);
        perror("Failed to allocate vector data");
        exit(EXIT_FAILURE);
    }

    new_vector->size = 0;
    new_vector->capacity = initial_capacity;
    
    return new_vector;
}

// Returns the number of items in the vector
size_t size(vector_t* vector){
    return vector->size;
}

// Returns the total capacity of the vector
size_t capacity(vector_t *vector){
    return vector->capacity;
}  

// Checks if the vector is empty (returns 1 if empty, 0 otherwise)
int is_empty(vector_t *vector){
    if (vector->size == 0){
        return 1;
    }
    return 0;
}


int at(vector_t *vector, int index){
    if (index >= vector->size || index < 0){ // need to watch out for negative index inputs which are invalid
        fprintf(stderr, "Index %d out of bounds\n", index);
        exit(EXIT_FAILURE);
    }
    return vector->data[index];
}





// Pushes an item to the end of the vector
void push(vector_t* vector, int* item){
    if (vector->size >= vector->capacity){
        resize(vector, vector->capacity * 2); //double the capacity size
    }
    vector->data[vector->size] = *item;
    vector->size++;
}


void insert(vector_t* vector, int index, int *item){
    // check first whether the input for index is within bounds
    if (index > vector->size || index < 0) {
        fprintf(stderr, "Index %d out of bounds for insert\n", index);
        exit(EXIT_FAILURE);
    }
    // since we want to shift all the elements to the right by one, we need to ensure that there is atleast
    // one space left in array
    if (vector->size == vector->capacity) {
        resize(vector, vector->capacity * 2);
    }
    // beginning from the very last element, we increment down towards (including) the index position
    for (int i = vector->size; i > index; i--){
        vector->data[i] = vector->data[i-1];
    }

    vector->data[index] = *item;
    vector->size++;
} // insert(index, item): inserts item at index, shifts that index's value and trailing elements to the right


// adding an element to the beginning is the same as inserting at index 0
void prepend(vector_t *vector, int *item){
    insert(vector, 0, item);
}  


//remove from end, return value
int* pop(vector_t* vector){
    int* item = (int*)malloc(sizeof(int));
    *item = vector->data[vector->size];
    vector->size--;
    return item;
}


// Deletes an item at a given index, shifting elements left
void delete(vector_t* vector, int index) {
    if (index >= vector->size || index < 0) {
        fprintf(stderr, "Index %d out of bounds for delete\n", index);
        exit(EXIT_FAILURE);
    }
    for (int i = index; i < vector->size - 1; i++) {
        vector->data[i] = vector->data[i + 1];
    }
    vector->size--;
}


// Removes all occurrences of an item from the vector
void remove_item(vector_t* vector, int* item) {
    size_t i = 0;
    while (i < vector->size) {
        if (vector->data[i] == *item) {
            delete(vector, i);
        } else {
            i++;
        }
    }
}

// Finds the index of the first occurrence of an item, returns -1 if not found
int find(vector_t* vector, int* item) {
    for (size_t i = 0; i < vector->size; i++) {
        if (vector->data[i] == *item) {
            return i;
        }
    }
    return -1;
}

void resize(vector_t *vector, size_t new_capacity){
    vector->data = (int*)realloc(vector->data, new_capacity * sizeof(int));
    if (!vector->data) {
        perror("Failed to reallocate vector data");
        exit(EXIT_FAILURE);
    }
    vector->capacity = new_capacity;
}

// Frees the allocated memory for the vector
void free_vector(vector_t* vector) {
    free(vector->data);
    free(vector);
}








