int linearSearch(int* arr,int size,int key){
    for(int i=0;i<size;i++){
        if(arr[i] == key){
            return i;
        }
    }

    return -1;
}

int linearSearch_i(int* arr,int size,int key,int start){
    for(int i=start;i<size;i++){
        if(arr[i] == key){
            return i;
        }
    }

    return -1;
}
