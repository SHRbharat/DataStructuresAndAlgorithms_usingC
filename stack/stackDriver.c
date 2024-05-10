#include "stack.h"

int main() {
    struct Stack stack;
    stack.top = -1; // Initializing stack top to -1


    push(&stack, 'A');
    push(&stack, 'B');
    push(&stack, 'C');

    printf("Popped element: %c\n", pop(&stack)); // Output: C
    printf("Popped element: %c\n", pop(&stack)); // Output: B
    printf("Popped element: %c\n", pop(&stack)); // Output: A
    printf("Popped element: %c\n", pop(&stack)); // Output: Stack Underflow

    return 0;
}