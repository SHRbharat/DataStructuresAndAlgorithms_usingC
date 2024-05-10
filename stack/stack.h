#include <stdio.h>

#define MAX_SIZE 200

struct Stack{
    char arr[MAX_SIZE];
    int top;
};

//true = 1 (+ve) , false = 0

// Function to check if the st is empty
int isEmpty(struct Stack* st) {
    return (st->top <= -1);
}

// Function to check if the st is full
int isFull(struct Stack* st) {
    return (st->top >= MAX_SIZE - 1);
}

// Function to push an element onto the st
void push(struct Stack* st, char item) {
    //check for overflow
    if (isFull(st)) {
        printf("Error : stack Overflow\n");
        return;
    }

    //increment the top
    (st->top)++;

    //insert the item
    st->arr[st->top] = item;
}

// Function to pop an element from the st
char pop(struct Stack* st) {
    //check for underflow
    if (isEmpty(st)) {
        printf("Error : Stack Underflow\n");
        return '\0';
    }

    //store the element
    int ret = st->arr[(st->top)];

    //decrement the top
    (st->top)--;

    return ret; 
}

