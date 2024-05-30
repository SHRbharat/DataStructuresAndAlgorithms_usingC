#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Stack_t {
  char arr[MAX_SIZE];
  int top;
};

typedef struct Stack_t *Stack;

int isEmpty(Stack ps) {
  return (ps->top == -1);
}

int isFull(Stack ps) {
  return (ps->top == MAX_SIZE - 1); 
}

void push(Stack ps, char item) {
  if (isFull(ps)) {
    printf("Error: Stack Overflow\n");
    return;
  }
  (ps->top)++;
  ps->arr[ps->top] = item;
}

char pop(Stack ps) {
  if (isEmpty(ps)) {
    printf("Error: Stack Underflow\n");
    return '\0'; 
  }
  char item = ps->arr[ps->top]; 
  (ps->top)--;
  return item;
}

Stack createStack() {
  Stack m = (Stack)malloc(sizeof(struct Stack_t));
  if (m == NULL) { 
    printf("Error: Memory Allocation Failed\n");
    exit(1);
  }
  m->top = -1;
  return m;
}
