#include <stdio.h>
#include <stdlib.h>

// Include your linked list header file if you have one
#include "list.h" 

int main() {
    // Create an empty list
    list_t *list = initList();
    printf("List initialized.\n");

    // Test push_front
    push_front(list, 10);
    printList(list);

    push_front(list, 20);
    printList(list);

    push_front(list, 30);
    printList(list);

    // Test push_back
    push_back(list, 40);
    push_back(list, 50);
    printf("After push_back operations: ");
    printList(list);



    // Test pop_front
    int popped_front = pop_front(list);
    printf("pop_front: Removed %d, new front: %d\n", popped_front, front(list));
    printList(list);

    // Test pop_back
    int popped_back = pop_back(list);
    printf("pop_back: Removed %d, new back: %d\n", popped_back, back(list));
    printList(list);

    // Test size
    printf("Current size of list: %d\n", size(list));

    // Test value_at
    printf("Element at index 1: %d\n", value_at(list, 1));
    printList(list);

    // Test insert
    insert(list, 1, 25);
    printf("After insert at index 1 (25): %d -> %d -> %d -> %d\n", front(list), value_at(list, 1), value_at(list, 2), back(list));
    printList(list);
    
    // Test erase
    erase(list, 3);
    printf("After erase at index 3: %d -> %d -> %d\n", front(list), value_at(list, 1), back(list));
    printList(list);

    // Test reverse
    reverse(list);
    printf("After reversing the list: Front: %d, Back: %d\n", front(list), back(list));
    printList(list);
    
    // Check if list is empty
    printf("Is list empty? %s\n", empty(list) ? "Yes" : "No");

    return 0;
}