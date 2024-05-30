#include "stack3.h"

int main() {
    Stack st = createStack();
    push(st, 'A');
    push(st, 'B');
    push(st, 'C');

    printf("%c\n", pop(st));
    printf("%c\n", pop(st));
    printf("%c\n", pop(st));
    printf("%c\n", pop(st));
    return 0;
}