#include <stdio.h>
#include "linearSearch.h"

int main(){
    int arr[] = {10,12,43,12,34,12,14,19,15,67};
    int key = 12;

    //linear search starting at index 0
    int index = linearSearch(arr,sizeof(arr)/sizeof(arr[0]),key);
    if(index >= 0){
        printf("element is found at index : %d \n",index);
    }else{
        printf("element is not found in the array \n");
    }

    //linear search starting at specified index
    int start = 4;
    index = linearSearch_i(arr,sizeof(arr)/sizeof(arr[0]),key,start);
    if(index >= 0){
        printf("element is found at index : %d after index %d\n",index,start);
    }else{
        printf("element is not found in the array starting from index %d \n",start);
    }

    return 0;
}