#include "stack2.h"

int main() {
    struct Stack st;
    int size = 10; // Example size of the stack

    // Initialize the stack
    initializeStack(&st, size);

    push(&st, 'a', size);
    push(&st, 'b', size);
    push(&st, 'c', size);

    printf("Popped element: %c\n", pop(&st)); // Should print 'c'
    printf("Popped element: %c\n", pop(&st)); // Should print 'b'
    printf("Popped element: %c\n", pop(&st)); // Should print 'a'
    printf("Popped element: %c\n", pop(&st)); // error :underflow

    push(&st,'z',size);
    printf("Popped element: %c\n", pop(&st)); //Should print 'z'

    // Destroy the stack to free allocated memory
    destroyStack(&st);

    return 0;
}