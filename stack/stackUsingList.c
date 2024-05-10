#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Stack structure using a linked list
struct Stack {
    struct Node* top;
};

// Function to check if the stack is empty
int isEmpty(struct Stack* st) {
    return (st->top == NULL);
}

// Function to push an element onto the stack
void push(struct Stack* st, int item) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Error: Unable to create new node\n");
        exit(101);
    }

    // Set the data and next pointer of the new node
    newNode->data = item;
    newNode->next = st->top;

    // Update the top pointer to point to the new node
    st->top = newNode;
}

// Function to pop an element from the stack
int pop(struct Stack* st) {
    // Check for underflow
    if (isEmpty(st)) {
        printf("Error: Stack Underflow\n");
        exit(102);
    }

    // Store the top node and its data
    struct Node* temp = st->top;
    int data = temp->data;

    // Update the top pointer to point to the next node
    st->top = st->top->next;

    // Free the memory of the popped node
    free(temp);

    return data;
}

// Function to initialize a stack
void initializeStack(struct Stack* st) {
    st->top = NULL;
}

// Function to destroy the stack and free memory
void destroyStack(struct Stack* st) {
    while (!isEmpty(st)) {
        pop(st);
    }
}

int main() {
    // Example usage of the stack
    struct Stack st;
    initializeStack(&st);

    push(&st, 10);
    push(&st, 20);
    push(&st, 30);

    printf("Popped element: %d\n", pop(&st)); // Should print '30'
    printf("Popped element: %d\n", pop(&st)); // Should print '20'
    printf("Popped element: %d\n", pop(&st)); // Should print '10'
    printf("Popped element: %d\n", pop(&st)); // error : underflow

    destroyStack(&st);

    return 0;
}
