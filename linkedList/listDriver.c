#include "list.h"

int main(){
    nodeptr myList = NULL; // Initialize an empty list
    
    // Test insert_front
    printf("Inserting elements at the front:\n");
    insert_front(&myList, 10);
    insert_front(&myList, 20);
    insert_front(&myList, 30);
    printf("List after inserting at the front: ");
    printList(myList);
    printf("Length of list: %d\n", length(myList));
    
    // Test insert_end
    printf("\nInserting elements at the end:\n");
    insert_end(&myList, 40);
    insert_end(&myList, 50);
    insert_end(&myList, 60);
    printf("List after inserting at the end: ");
    printList(myList);
    printf("Length of list: %d\n", length(myList));

    // Test delete_front
    printf("\nDeleting elements from the front:\n");
    delete_front(&myList);
    delete_front(&myList);
    printf("List after deleting from the front: ");
    printList(myList);
    printf("Length of list: %d\n", length(myList));

    // Test delete_end
    printf("\nDeleting elements from the end:\n");
    delete_end(&myList);
    delete_end(&myList);
    printf("List after deleting from the end: ");
    printList(myList);
    printf("Length of list: %d\n", length(myList));


    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    //test insert_before
    nodeptr myList2 = NULL;
    printf("\nInserting before a given node :\n");

    printf(">>>> in empty list\t: \n");
    insert_before(&myList2,NULL,101); //empty list
    insert_end(&myList2, 40);
    printList(myList2);

    printf(">>>> single node list\t: \n");
    insert_before(&myList2,find_node(myList2,50),102); //single node , without match
    printList(myList2);

    printf(">>>> single node list\t: \n");
    insert_before(&myList2,find_node(myList2,40),50); //single node , with match | 50->40->null
    printList(myList2);

    printf(">>>> last node match\t: \n");
    insert_before(&myList2,find_node(myList2,40),100); //last node matched | 50->100->40->null
    printList(myList2);

    printf(">>>> general case\t: \n");
    insert_before(&myList2,find_node(myList2,100),200); //general case | 50->200->100->40->null
    printList(myList2);

    printf(">>>> no match\t: \n");
    insert_before(&myList2,find_node(myList2,1000),300); //no node matched
    printList(myList2);

    printf(">>>> first node matched\t: \n");
    insert_before(&myList2,find_node(myList2,50),500); //first node matched
    printList(myList2);
    printf("Length of list: %d\n", length(myList2));

    empty_list(&myList2);
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    //test insert_after
    printf("\nInserting after a given node :\n");

    printf(">>>> in empty list\t: \n");
    insert_after(&myList2,NULL,101); //empty list
    insert_end(&myList2, 40);
    printList(myList2);

    printf(">>>> single node list\t: \n");
    insert_after(&myList2,find_node(myList2,50),102); //single node , without match
    printList(myList2);

    printf(">>>> single node list\t: \n");
    insert_after(&myList2,find_node(myList2,40),50); //single node , with match | 40->50->null
    printList(myList2);

    printf(">>>> last node match\t: \n");
    insert_after(&myList2,find_node(myList2,50),100); //last node matched | 40->50->100->null
    printList(myList2);

    printf(">>>> general case\t: \n");
    insert_after(&myList2,find_node(myList2,50),200); //general case | 40->50->200->100->null
    printList(myList2);

    printf(">>>> no match\t: \n");
    insert_after(&myList2,find_node(myList2,1000),300); //no node matched
    printList(myList2);

    printf(">>>> first node matched\t: \n");
    insert_after(&myList2,find_node(myList2,40),300); //first node matched | 40->300->50->200->100->null
    printList(myList2);
    printf("Length of list: %d\n", length(myList2));

    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    //test delete_before
    printf("\ndeleting before a given node :\n");

    printf(">>>> general case\t: \n");
    delete_before(&myList2,find_node(myList2,200)); //general case | 40->300->200->100->null
    printList(myList2);

    printf(">>>> no match\t: \n");
    delete_before(&myList2,find_node(myList2,1000)); //no node matched
    printList(myList2);

    printf(">>>> last node match\t: \n");
    delete_before(&myList2,find_node(myList2,100)); //last node matched | 40->300->100->null
    printList(myList2);
   
    printf(">>>> first node matched\t: \n");
    delete_before(&myList2,find_node(myList2,40)); //first node matched 
    printList(myList2);

    delete_before(&myList2,find_node(myList2,100)); // 40->100->null
    delete_before(&myList2,find_node(myList2,100)); // 100->null
    printList(myList2);

    printf(">>>> single node list\t: \n");
    delete_before(&myList2,find_node(myList2,50)); //single node , without match
    printList(myList2);

    printf(">>>> single node list\t: \n");
    delete_before(&myList2,find_node(myList2,100)); //single node , with match | 
    printList(myList2);
    
    empty_list(&myList2);
    printf(">>>> in empty list\t: \n");
    delete_before(&myList2,NULL); //empty list
    printList(myList2);
    printf("Length of list: %d\n", length(myList2));

    
    
    // Clean up memory
    while (myList != NULL) {
        nodeptr temp = myList;
        myList = myList->next;
        free(temp);
    }
    
    return 0;
}
