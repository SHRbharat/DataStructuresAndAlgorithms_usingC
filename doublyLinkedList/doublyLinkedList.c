#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next; 
    struct Node* prev;
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
    newNode->prev = NULL;
    return newNode;
}

void deleteNode(nodeptr node){
    free(node);
}

struct list{
    nodeptr head;
    nodeptr tail;
    int size;
};

void printList(struct list dll){
    nodeptr current = dll.head;
    while(current != NULL){
        printf("%d",current->data);
        printf("<->");
        current = current->next;
    }
    printf("NULL\n");
}

nodeptr returnNode(struct list dll, int val){
    if(dll.head == NULL){
        return NULL;
    }else{
        nodeptr current = dll.head;
        while(current->data != val){
            current = current->next;
            if(current == NULL){
                return NULL;
            }
        }
        return current;
    }
}

void insert_front(struct list* dll , int val){
    nodeptr newNode = getNode(val);
    if (dll->head == NULL) {
        dll->head = newNode;
        dll->tail = newNode;
    } else {
        newNode->next = dll->head;
        dll->head->prev = newNode;
        dll->head = newNode;
    }
    dll->size++;
}

void insert_end(struct list* dll,int val){
    nodeptr newNode = getNode(val);
    if (dll->head == NULL) {
        dll->head = newNode;
        dll->tail = newNode;
    } else {
        newNode->prev = dll->tail;
        dll->tail->next = newNode;
        dll->tail = newNode;
    }
    dll->size++;
}

void insert_before(struct list* dll, nodeptr node, int val){
    if (dll->head == NULL) {
        return;
    }
    if (node == dll->head) {
        insert_front(dll, val);
        return;
    }
    nodeptr newNode = getNode(val);
    newNode->prev = node->prev;
    newNode->next = node;
    node->prev->next = newNode;
    node->prev = newNode;
    dll->size++;
}

void insert_after(struct list* dll, nodeptr node, int val){
    if (dll->head == NULL) {
        return;
    }
    if (node == dll->tail) {
        insert_end(dll, val);
        return;
    }
    nodeptr newNode = getNode(val);
    newNode->next = node->next;
    newNode->prev = node;
    node->next->prev = newNode;
    node->next = newNode;
    dll->size++;
}

void delete_beg(struct list* dll) {
    if (dll->head == NULL) {
        return;
    }
    nodeptr temp = dll->head;
    dll->head = dll->head->next;
    if (dll->head != NULL) {
        dll->head->prev = NULL;
    } else {
        dll->tail = NULL;
    }
    free(temp);
    dll->size--;
}

void delete_end(struct list* dll) {
    if (dll->head == NULL) {
        return;
    }
    nodeptr temp = dll->tail;
    if (dll->head == dll->tail) {
        dll->head = NULL;
        dll->tail = NULL;
    } else {
        dll->tail = dll->tail->prev;
        dll->tail->next = NULL;
    }
    free(temp);
    dll->size--;
}

int main() {
    struct list dll;
    dll.head = NULL;
    dll.tail = NULL;
    dll.size = 0;

    insert_end(&dll, 1);
    insert_end(&dll, 2);
    insert_end(&dll, 3);
    insert_front(&dll, 0);
    printList(dll);

    delete_beg(&dll);
    delete_end(&dll);
    printList(dll);

    nodeptr node = returnNode(dll, 2);
    if (node != NULL) {
        insert_before(&dll, node, 10);
        insert_after(&dll, node, 20);
    }
    printList(dll);

    return 0;
}
