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
    delete_end(&myList);
    printf("List after deleting from the end: ");
    printList(myList);
    printf("Length of list: %d\n", length(myList));

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~ 10->null ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    //test insert_after and delete_after
    printf("\nInserting after a given node :\n");

    printf(">>>> null node passed\t: \n");
    insert_after(NULL,101);                     //null node passed
    printList(myList);

    printf(">>>> single node list\t: \n");
    insert_after(find_node(myList,40),102);     //single node , without match
    printList(myList);

    printf(">>>> single node list\t: \n");
    insert_after(find_node(myList,10),50);      //single node , with match | 10->50->null
    printList(myList);

    insert_end(&myList,101);
    insert_end(&myList,102);                    //10->50->101->102->null

    printf(">>>> last node match\t: \n");
    insert_after(find_node(myList,102),100);    //last node matched | 10->50->101->102->100->null
    printList(myList);

    printf(">>>> general case\t: \n");
    insert_after(find_node(myList,101),200); //general case | 10->50->101->200->102->100->null
    printList(myList);

    printf(">>>> no match\t: \n");
    insert_after(find_node(myList,1000),300); //no node matched
    printList(myList);

    printf(">>>> first node matched\t: \n");
    insert_after(myList,300); //first node matched | 10->300->50->101->200->102->100->null
    printList(myList);
    printf("Length of list: %d\n", length(myList));

    printf("\nDeleting after a given node :\n");

    printf(">>>> null node passed\t: \n");
    delete_after(NULL);                     //null node passed
    printList(myList);

    printf(">>>> first node passed\t: \n");
    delete_after(myList);                     //first node passed, matched | 10->50->101->200->102->100->null
    printList(myList);

    printf(">>>> first node passed\t: \n");
    delete_after(find_node(myList,10));          //first node passed, matched | 10->101->200->102->100->null
    printList(myList);

    printf(">>>> no matches found\t: \n");
    delete_after(myList->next->next->next->next->next);  //null node, matched | 10->101->200->102->100->null
    printList(myList);

    printf(">>>> last node matched\t: \n");
    delete_after(find_node(myList,100));          // 10->101->200->102->100->null
    printList(myList);

    printf(">>>> second last node matched\t: \n");
    delete_after(find_node(myList,102));          //10->101->200->102->null
    printList(myList);

    printf(">>>> general case\t: \n");
    delete_after(find_node(myList,101));          // 10->101->102->null
    printList(myList);

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~ 10->101->102->null ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    //test delete method
    printf("\ndeleting a node pointed by pointer :\n");

    printf(">>>> null node passed\t: \n");
    delete(&myList,NULL);                     //10->101->102->null
    printList(myList);

    printf(">>>> first node\t: \n");
    delete(&myList,myList);                     //101->102->null
    printList(myList);

    insert_end(&myList,200);
    insert_end(&myList,400);                 //101->102->200->400->null

    printf(">>>> last node\t: \n");
    delete(&myList,find_node(myList,400));    //101->102->200->null
    printList(myList);

    printf(">>>> general case\t: \n");
    delete(&myList,find_node(myList,102));    //101->200->null
    printList(myList);

    nodeptr ptr = find_node(myList,200);
    empty_list(&myList);

    printf(">>>>empty list\t: \n");
    delete(&myList,ptr);                     //null
    printList(myList);


    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    //test insert_before and delete_before
    printf("\nInserting before a given node :\n");

    printf(">>>> in empty list\t: \n");
    insert_before(&myList,ptr,101); //empty list
    insert_end(&myList, 40);
    printList(myList);

    printf(">>>> single node list\t: \n");
    insert_before(&myList,myList->next,102); //no match 
    printList(myList);

    printf(">>>> single node list\t: \n");
    insert_before(&myList,myList,50); //with match | 50->40->null
    printList(myList);

    printf(">>>> last node match\t: \n");
    insert_before(&myList,find_node(myList,40),100); // 50->100->40->null
    printList(myList);

    printf(">>>> general case\t: \n");
    insert_before(&myList,find_node(myList,100),200); //50->200->100->40->null
    printList(myList);

    printf(">>>> first node matched\t: \n");
    insert_before(&myList,find_node(myList,50),500); //500->50->200->100->40->null
    printList(myList);
    printf("Length of list: %d\n", length(myList));

    //test reverse
    reverse(&myList);
    printf("\n reversed list : ");
    printList(myList);  //40->100->200->50->500->NULL

    //test delete_before
    printf("\ndeleting before a given node :\n");

    printf(">>>> general case\t: \n");
    delete_before(&myList,find_node(myList,200)); //40->200->50->500->NULL
    printList(myList);

    nodeptr ptr2= malloc(sizeof(struct Node));;
    ptr2->data = 1000;
    printf(">>>> no match\t: \n");
    delete_before(&myList,ptr2); 
    printList(myList);

    printf(">>>> last node match\t: \n");
    delete_before(&myList,find_node(myList,500)); //40->200->500->NULL
    printList(myList);

    printf(">>>> first node matched\t: \n");
    delete_before(&myList,find_node(myList,40)); 
    printList(myList);

    delete_before(&myList,find_node(myList,200)); // 200->500->null
    delete_before(&myList,find_node(myList,500)); // 500->null
    printList(myList);

    printf(">>>> single node list\t: \n");
    delete_before(&myList,find_node(myList,500)); 
    printList(myList);

    empty_list(&myList);
    printf(">>>> in empty list\t: \n");
    delete_before(&myList,ptr); //empty list
    printList(myList);
    printf("Length of list: %d\n", length(myList));

    // Clean up memory
    while (myList != NULL) {
        nodeptr temp = myList;
        myList = myList->next;
        free(temp);
    }
    
    return 0;
}
