#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next; 
};
typedef struct Node* nodeptr;

nodeptr getNode(int val){
    nodeptr newNode = (nodeptr)malloc(sizeof(nodeptr));
    if(newNode == NULL){
        printf("Error : Unable to create new node\n");
        exit(101);
    }
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


void insert_front(nodeptr* list , int val){
    nodeptr newNode = getNode(val);
    if(*list == NULL){
        //if list is empty
        *list = newNode;
    }else{
        newNode->next = *list;
        *list = newNode;
    }
}

void insert_end(nodeptr* list , int val){
    nodeptr newNode = getNode(val);

    if(*list == NULL){
        //list is empty
        *list = newNode;
        return;
    }

    //pointer to traverse list
    nodeptr current = *list;
    //traverse the list and stop at the last node
    while(current->next != NULL){
        current = current->next;
    }
    current->next = newNode;
}

void insert_before(nodeptr* list, nodeptr node, int newNodeVal) {
    if (*list == NULL || node == NULL) {
        // If the list is empty, nothing to insert before
        printf("Error: List is empty or node is null.\n");
        return;
    }

    // If the node to insert before is the first node
    if (*list == node) {
        insert_front(list, newNodeVal);
        return;
    }

    // Find the node before 'node'
    nodeptr prevNode = *list;
    while (prevNode->next != node) {
        prevNode = prevNode->next;
        // If we reach the end of the list without finding 'node'
        if (prevNode == NULL) {
            printf("Error: Node not found in the list.\n");
            return;
        }
    }

    // Create the new node
    nodeptr newNode = getNode(newNodeVal);
    // Insert the new node before 'node'
    newNode->next = node;
    prevNode->next = newNode;
}

void insert_after(nodeptr* list, nodeptr node, int newNodeVal) {
    if (*list == NULL) {
        // If the list is empty, nothing to insert after
        printf("Error: List is empty.\n");
        return;
    }

    // Find the node in the list
    nodeptr currentNode = *list;
    while (currentNode != NULL && currentNode != node) {
        currentNode = currentNode->next;
    }

    if (currentNode == NULL) {
        // If the node is not found in the list
        printf("Error: Node not found in the list.\n");
        return;
    }

    // Create the new node
    nodeptr newNode = getNode(newNodeVal);
    // Insert the new node after 'node'
    newNode->next = currentNode->next;
    currentNode->next = newNode;
}


void delete_front(nodeptr* list) {
    if (*list == NULL) {
        // If the list is already empty
        return;
    }

    // Store the first node temporarily
    nodeptr temp = *list;
    // Move the list pointer to the next node
    *list = (*list)->next;
    // Free the memory of the first node
    free(temp);
}

void delete_end(nodeptr* list) {
    if (*list == NULL) {
        // If the list is empty
        return;
    }
    if ((*list)->next == NULL) {
        // If there's only one node, delete it and make the list empty
        free(*list);
        *list = NULL;
        return;
    }

    // Traverse to the second-to-last node
    nodeptr current = *list; //fast pointer 
    nodeptr prev = NULL;     //slow pointer
    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }

    // 'current' now points to the last node, 'prev' to the second-to-last
    // Update 'prev' to point to NULL, removing the last node
    prev->next = NULL;
    free(current);
}

void delete_before(nodeptr* list, nodeptr node) {
    if (*list == NULL || node == NULL || (*list)->next == NULL || *list == node) {
        // If the list is empty, the given node is NULL, or the list has only one node
        printf("Error: Invalid operation.\n");
        return;
    }

    //if two or more nodes in the ll
    // Initialize slow and fast pointers
    nodeptr slow = NULL;
    nodeptr fast = *list;

    // Traverse the list until fast pointer reaches the one-before the given node
    while (fast->next != NULL && fast->next != node) {
        slow = fast;
        fast = fast->next;
    }
    // If the given node is not found
    if (fast->next == NULL) {
        printf("Error: Node not found in the list.\n");
        return;
    }else if(slow == NULL){
        //node to be deleted is first node
        nodeptr toDelete = fast;
        *list = fast->next;
        free(toDelete);
    }else{
        // Store the node to be deleted
        nodeptr toDelete = slow->next;
        // Adjust the pointers to skip the node to be deleted
        slow->next = node;
        free(toDelete);
    }
}

void delete_after(nodeptr* list, nodeptr node) {
    if (*list == NULL || node == NULL || (*list)->next == NULL) {
        // If the list is empty or the given node is NULL or list has single node
        printf("Error: Invalid operation.\n");
        return;
    }

    // Store the node to be deleted
    nodeptr toDelete = node->next;
    // Adjust the pointers to skip the node to be deleted
    node->next = toDelete->next;
    free(toDelete);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void printList(nodeptr list){
    if(list == NULL){
        printf("List is empty\n");
        return;
    }
    while(list != NULL){
        printf("%d -> ", list->data);
        list = list->next;
    }
    printf("NULL\n");
}

int length(nodeptr list){
    int len = 0;
    if(list == NULL){
        return 0;
    }

    while(list != NULL){
        len++;
        list = list->next;
    }

    return len;
}

nodeptr find_node(nodeptr list, int val) {
    while (list != NULL) {
        if (list->data == val) {
            return list;
        }
        list = list->next;
    }
    return NULL;
}

void empty_list(nodeptr* list) {
    nodeptr current = *list;
    nodeptr next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    // Set the list pointer to NULL to indicate an empty list
    *list = NULL;
}