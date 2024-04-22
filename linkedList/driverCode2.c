#include "list2.h"

int main()
{
    struct list newList = {NULL,0}; // create an empty list

    // 30->20->10
    insert_front(&newList, 10);
    insert_front(&newList, 20);
    insert_front(&newList, 30);

    // 12->15
    insert_end(&newList, 12);
    insert_end(&newList, 15);

    // 30->20->10->12->15
    printList(newList);
    printf("size of list : %d\n", newList.size);

    //-----------------------------------------------------------
    // insert newNode before the node pointed
    nodeptr pointerNode = returnNode(newList, 30);
    nodeptr pointerNode2 = returnNode(newList, 10);

    // 101->30->20->10->12->15
    insert_before(&newList, pointerNode, 101);
    // 101->30->20->102->10->12->15
    insert_before(&newList, pointerNode2, 102);

    // 101->30->20->102->10->12->15
    printList(newList);
    printf("size of list : %d\n", newList.size);
    //-----------------------------------------------------------

    // insert newNode before the node pointed
    pointerNode = returnNode(newList, 15);
    pointerNode2 = returnNode(newList, 101);

    //insert newNode after the node pointed
    // 101->30->20->10->12->15
    insert_after(&newList, pointerNode, 701);
    // 101->30->20->102->10->12->15
    insert_after(&newList, pointerNode2,703);

    // 101->30->20->102->10->12->15
    printList(newList);
    printf("size of list : %d\n", newList.size);

    delete_beg(&newList);
    delete_end(&newList);
    printList(newList);
    printf("size of list : %d\n", newList.size);

    return 0;
}