#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next; 
};
typedef struct Node* nodeptr;

nodeptr getNode(int val){
    nodeptr newNode = (nodeptr)malloc(sizeof(struct Node));
    if(newNode == NULL){
        printf("Error : Can't create a new node.\n");
        exit(101);
    }
    
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}



//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


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
    }else if ((*list)->next == NULL) {
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

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


//methods to insert/delete after a node pointed by a pointer
void insert_after(nodeptr p,int val){
    if(p == NULL){
        printf("Error : pointer to node is null - insert_after()\n");   
        return;
    }
    
    nodeptr newNode = getNode(val);
    if(newNode == NULL){
        printf("Error : Unable to create a new node - insert_after()\n");
        return;
    }

    //insert the new node
    newNode->next = p->next;
    p->next = newNode;
}

void delete_after(nodeptr p){
    if(p == NULL){
        printf("Error : pointer to node is null - delete_after()\n");   
        return;
    }else if(p->next == NULL){
        printf("Error : no node available for deletion - delete_after()\n");
        return;
    }

    //delete node
    nodeptr temp = p->next;
    p->next = temp->next;
    free(temp);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//methods to delete a node pointed by a pointer and pointer to list is given
void delete(nodeptr* list,nodeptr p){
    if(p == NULL){
        printf("Error : pointer to node is null - delete()\n");   
        return;
    }else if(*list == NULL){
        printf("Error : list is empty - delete()\n");   
        return;
    }

    //Deleting the first node
    if (p == *list) {
        *list = p->next; // Update the head of the list
        free(p); 
        return;
    }

    //Deleting a node that is not the first node
    nodeptr current = *list;
    // Traverse the list until p is found
    while (current->next != NULL && current->next != p) {
        current = current->next; 
    }

    if (current->next == NULL) {
        printf("Error: Node to be deleted is not in the list - delete()\n");
        return;
    }

    // Unlink the node to be deleted
    current->next = p->next;
    free(p); // Free memory of the deleted node
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//methods to insert/delete a node before a node pointed by a pointer and pointer to the list is given
void insert_before(nodeptr* list, nodeptr node, int val) {
    if (*list == NULL) {
        printf("Error: List is empty - insert_before()\n");
        return;
    }else if (node == NULL) {
        printf("Error: pointer to node is null - insert_before()\n");
        return;
    }

    // If the node to insert before is the first node
    if (*list == node) {
        nodeptr newNode = getNode(val);

        newNode->next = *list;
        *list = newNode;
        return;
    }

    // Find the node before 'node'
    nodeptr prevNode = *list;

    //traverse till the node before the pointed node
    while (prevNode->next != node) {
        prevNode = prevNode->next;
        // If we reach the end of the list without finding 'node'
        if (prevNode == NULL) {
            printf("Error: Node not found in the list - insert_before()\n");
            return;
        }
    }

    nodeptr newNode = getNode(val);
    newNode->next = node;
    prevNode->next = newNode;
}

void delete_before(nodeptr* list, nodeptr node) {
    if (*list == NULL || node == NULL || (*list)->next == NULL || *list == node) {
        // If the list is empty, the given node is NULL,the list has only one node or the matched node is head
        printf("Error: Invalid operation - delete_before().\n");
        return;
    }

    // Initialize slow and fast pointers
    nodeptr slow = NULL;
    nodeptr fast = *list;    
    
    // Traverse the list until fast pointer reaches just one-before the given node 
    while (fast->next != node) {
        slow = fast;
        fast = fast->next;
        
        if(fast == NULL){
            printf("Error: Node not found in the list - delete_before()\n");
            return;
        }
    }

    //fast pointer = node to be deleted
    //slow pointer = node before the fast pointer
    if(slow == NULL){
        //node to be deleted is first node
        nodeptr toDelete = fast;
        *list = fast->next;
        free(toDelete);
    }else{
        // Store the node to be deleted
        nodeptr toDelete = fast;
        // Adjust the pointers to skip the node to be deleted
        slow->next = node;
        free(toDelete);
    }
}
void insSorted(nodeptr *head, int x) {
    nodeptr q,p;
    q=NULL;
    for(p=*head; p!=NULL && x>p->info;p=p->next) {
        q = p;
    }
    if (q == NULL)
    {
        insert_front(&p,x);
    } else
    {
        insert_before(&q, x);
    }
            
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

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


    //delete nodes
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    // Set the list pointer to NULL to indicate an empty list
    *list = NULL;
}

void reverse(nodeptr* list) {
    // Check if the list is empty or has only one node
    if (*list == NULL || (*list)->next == NULL) {
        return; 
    }

    nodeptr prev = NULL;
    nodeptr current = *list;
    nodeptr next = NULL;

    while (current != NULL) {
        next = current->next;   // Store the next node
        current->next = prev;   // Reverse the link
        prev = current;         // Move pointers one position ahead
        current = next;
    }

    *list = prev; // Update the head of the list
}
