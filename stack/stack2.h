#include <stdio.h>
#include <stdlib.h>

struct Stack{
    char *arr;
    int top;
};

// Function to initialize stack
void initializeStack(struct Stack* st, int size) {
    st->arr = (char *)malloc(size * sizeof(char));
    st->top = -1;
}

// Function to destroy stack
void destroyStack(struct Stack* st) {
    free(st->arr);
}

// Function to check if the stack is empty
int isEmpty(struct Stack* st) {
    return (st->top <= -1);
}

// Function to check if the stack is full
int isFull(struct Stack* st, int size) {
    return (st->top >= size - 1);
}

// Function to push an element onto the stack
void push(struct Stack* st, char item, int size) {
    // Check for overflow
    if (isFull(st, size)) {
        printf("Error : stack Overflow\n");
        return;
    }

    // Increment the top
    (st->top)++;

    // Insert the item
    st->arr[st->top] = item;
}

// Function to pop an element from the stack
char pop(struct Stack* st) {
    // Check for underflow
    if (isEmpty(st)) {
        printf("Error : Stack Underflow\n");
        return '\0';
    }

    // Store the element
    char ret = st->arr[st->top];

    // Decrement the top
    (st->top)--;

    return ret; 
}

