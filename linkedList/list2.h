#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next; 
};
typedef struct Node* nodeptr;

nodeptr getNode(int val){
    nodeptr newNode = (nodeptr)malloc(sizeof(struct Node));
    if(!newNode){
        printf("Error : Unable to create node\n");
        exit(101);
    }
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void deleteNode(nodeptr node){
    free(node);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
struct list{
    nodeptr head;
    int size;
};

void printList(struct list sll){
    nodeptr head = sll.head;
    while(head != NULL){
        printf("%d",head->data);
        printf("->");
        head = head->next;
    }
    printf("NULL\n");
}

nodeptr returnNode(struct list sll,int val){
    if(sll.head == NULL){
        return NULL;
    }else{
        nodeptr head = sll.head;
        while(head->data != val){
            head = head->next;
            if(head == NULL){
                return NULL;
            }
        }
        return head;
    }
}

void insert_front(struct list* sll , int val){
    nodeptr newNode = getNode(val);
    newNode->next = sll->head;
    sll->head = newNode;
    sll->size++;
}

void insert_end(struct list* sll,int val){
    nodeptr newNode = getNode(val);
    if(sll->head == NULL){
        sll->head = newNode;
    }else{
        nodeptr head = sll->head;
        while(head->next != NULL){
            head = head->next;
        }
        head->next = newNode;
    }
    sll->size++;
}

//insert newNode before the node pointed
void insert_before(struct list* sll,nodeptr node,int val){
    if (sll->head == NULL) {
        return;
    }
    nodeptr newNode = getNode(val);

    nodeptr current = sll->head;
    nodeptr prev = NULL;
    while (current != NULL && current != node) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Node not found\n");
        free(newNode);
        return;
    }

    if (prev != NULL) {
        prev->next = newNode;
    } else {
        sll->head = newNode;
    }
    newNode->next = node;
    sll->size++;
}

//insert newNode after the node pointed
void insert_after(struct list* sll,nodeptr node,int val){
    if (sll == NULL) {
        printf("List is NULL\n");
        return;
    }
    
    // If 'node' is the last node of the list, call insert_end
    if (node->next == NULL) {
        insert_end(sll, val);
        return;
    }

    // Call insert_before with the next node of 'node'
    insert_before(sll, node->next, val);
}

// Function to delete the first node of the list
void delete_beg(struct list* sll) {
    if (sll->head == NULL) {
        return;
    }

    nodeptr temp = sll->head;
    sll->head = sll->head->next;
    free(temp);
    sll->size--;
}

// Function to delete the last node of the list
void delete_end(struct list* sll) {
    if (sll->head == NULL) {
        return;
    }

    if (sll->head->next == NULL) {
        // If the list contains only one node
        free(sll->head);
        sll->head = NULL;
    } else {
        nodeptr prev = NULL;
        nodeptr current = sll->head;
        
        while (current->next != NULL) {
            prev = current;
            current = current->next;
        }
        free(current);
        prev->next = NULL;
    }
    sll->size--;
}
