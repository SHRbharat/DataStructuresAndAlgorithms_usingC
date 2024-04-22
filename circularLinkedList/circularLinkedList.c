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

struct list{
    nodeptr head;
    int size;
};

void printList(struct list* cll){
    if (cll->head == NULL) {
        printf("Circular Linked List is empty\n");
        return;
    }

    nodeptr current = cll->head;
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != cll->head);
    printf("Head\n");
}

nodeptr returnNode(struct list* cll, int val){
    if(cll->head == NULL){
        return NULL;
    }else{
        nodeptr current = cll->head;
        do {
            if(current->data == val)
                return current;
            current = current->next;
        } while (current != cll->head);
        return NULL;
    }
}

void insert_front(struct list* cll , int val){
    nodeptr newNode = getNode(val);
    if (cll->head == NULL) {
        cll->head = newNode;
        newNode->next = newNode; // Point to itself since it's the only node
    } else {
        newNode->next = cll->head;
        nodeptr temp = cll->head;
        while (temp->next != cll->head) {
            temp = temp->next;
        }
        temp->next = newNode;
        cll->head = newNode;
    }
    cll->size++;
}

void insert_end(struct list* cll,int val){
    nodeptr newNode = getNode(val);
    if (cll->head == NULL) {
        cll->head = newNode;
        newNode->next = newNode; // Point to itself since it's the only node
    } else {
        newNode->next = cll->head;
        nodeptr temp = cll->head;
        while (temp->next != cll->head) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    cll->size++;
}

void delete_beg(struct list* cll) {
    if (cll->head == NULL) {
        return;
    }
    nodeptr temp = cll->head;
    if (temp->next == cll->head) {
        // Only one node in the list
        cll->head = NULL;
    } else {
        nodeptr lastNode = cll->head;
        while (lastNode->next != cll->head) {
            lastNode = lastNode->next;
        }
        cll->head = cll->head->next;
        lastNode->next = cll->head;
    }
    free(temp);
    cll->size--;
}

void delete_end(struct list* cll) {
    if (cll->head == NULL) {
        return;
    }
    nodeptr temp = cll->head;
    nodeptr prev = NULL;
    while (temp->next != cll->head) {
        prev = temp;
        temp = temp->next;
    }
    if (prev != NULL) {
        prev->next = cll->head;
    } else {
        cll->head = NULL;
    }
    free(temp);
    cll->size--;
}

int main() {
    struct list cll;
    cll.head = NULL;
    cll.size = 0;

    insert_end(&cll, 1);
    insert_end(&cll, 2);
    insert_end(&cll, 3);
    insert_front(&cll, 0);
    printList(&cll);

    delete_beg(&cll);
    delete_end(&cll);
    printList(&cll);

    nodeptr node = returnNode(&cll, 2);
    if (node != NULL) {
        insert_front(&cll, 10);
        insert_end(&cll, 20);
    }
    printList(&cll);

    return 0;
}
