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


    //`````````````````````````````
    int x = 10;
    
    int* px = &x;
    int** pxx = &px;
    
    printf("\n-----------\n");
    //pxx--> px --> x
    printf("%d \n",*px);    //value pointed by px , ie value of x
    printf("%p \n",px);     //address stored at px , ie address of x
    
    printf("%p \n",*pxx);   //value pointed by pxx , ie value of px ==> address stored in px ie. address of x
    
    
    printf("%d \n",**pxx);  //value pointed by *(*pxx) , ie value stored in x
    printf("%p \n",pxx);    //address stored in pxx , ie address of px

    return 0;
}