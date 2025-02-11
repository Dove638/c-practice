#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>

// Define the vector structure
typedef struct {
    int *data;       // Pointer to dynamic array
    size_t size;     // Number of elements in the vector
    size_t capacity; // Maximum capacity before resizing
} vector_t;

// Function declarations
vector_t* initVector(size_t initial_capacity);
size_t size(vector_t* vector);
size_t capacity(vector_t* vector);
int is_empty(vector_t* vector);
int at(vector_t* vector, int index);
void push(vector_t* vector, int* item);
void insert(vector_t* vector, int index, int* item);
void prepend(vector_t* vector, int* item);
int* pop(vector_t* vector);
void delete(vector_t* vector, int index);
void remove_item(vector_t* vector, int* item);
int find(vector_t* vector, int* item);
void resize(vector_t* vector, size_t new_capacity);
void free_vector(vector_t* vector);

#endif