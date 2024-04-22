#include <stdio.h>
#include <stdlib.h>

// Define the structure of a Node
struct Node {
    int val;
    struct Node* next;
};

// Define a pointer to Node using typedef
typedef struct Node* nodeptr;

// Function to create a new Node with given value
nodeptr createNode(int x) {
    nodeptr newNode = (nodeptr)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->val = x;
    newNode->next = NULL;
    return newNode;
}

void insertBeg(nodeptr* head, int x) {
    nodeptr newNode = createNode(x);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a Node at the end of the list
void insertEnd(nodeptr* head, int x) {
    nodeptr newNode = createNode(x);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    nodeptr current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}




// Function to print the elements of the list


//this method creates a seperate head pointer for traversal
// void printList(nodeptr head) {
//     nodeptr current = head;
//     while (current != NULL) {
//         printf("%d -> ", current->val);
//         current = current->next;
//     }
//     printf("NULL\n");
// }

//this method uses the same head pointer for traversal
//but this will not affect the output or any other behaviour
//since , modifying the pointer is local to this function only,
//modifying the pointed values will be visble outside
void printList(nodeptr head) {
    while (head != NULL) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

// Main function to test the list methods
int main() {
    nodeptr head = NULL; // Initialize an empty list

    // Insert elements at the end of the list
    insertEnd(head, 1);
    insertEnd(&head, 2);
    insertEnd(&head, 3);

    // Print the list
    printf("List: ");
    printList(head);

    insertBeg(&head, 10);
    insertEnd(&head ,20);
    printf("List: ");
    printList(head);
    // Clean up - free memory
    nodeptr temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
