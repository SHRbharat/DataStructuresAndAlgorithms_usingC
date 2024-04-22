#include <stdio.h>


//the value pointed by pointer is passed by reference 
//but the pointer itself is passed as a value (pointer is local to the function)
//changes in the value of pointed location will only be visible outside the function
void point1(int* ptr){
    int c = 20;
    int *cpt = &c;
    ptr = cpt;
    
    printf("\tin point1 : %d",*ptr);    
    //value of pointer is changing locally , not the value stored at the location 
    //pointed by the pointer 
    //value  : *ptr
    //pointer : ptr
}

void point2(int* ptr){
    *ptr = 20;
    //value at the location pointed by the ptr is changing
}


int main()
{   
    int a =10;
    int *ptr = &a;
    
    
    printf("before point1 : %d",*ptr);
    point1(ptr);
    printf("\tafter point1 : %d\n",*ptr);
    

    printf("\nbefore point2 : %d",*ptr);
    point2(ptr);
    printf("\tafter point2 : %d",*ptr);

    return 0;
}