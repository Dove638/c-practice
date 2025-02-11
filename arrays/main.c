#include <stdio.h>
#include "vector.h"

int main() {
    vector_t* vec = initVector(2);

    int a = 10, b = 20, c = 30, d = 40;

    push(vec, &a);
    push(vec, &b);
    push(vec, &c);

    printf("Vector size: %zu\n", size(vec));
    printf("Vector capacity: %zu\n", capacity(vec));

    printf("Element at index 1: %d\n", at(vec, 1));

    insert(vec, 1, &d);
    printf("After inserting 40 at index 1, element at 1: %d\n", at(vec, 1));

    int* popped = pop(vec);
    printf("Popped element: %d\n", *popped);
    free(popped);

    delete(vec, 1);
    printf("After deleting index 1, element at index 1: %d\n", at(vec, 1));

    free_vector(vec);
    return 0;
}