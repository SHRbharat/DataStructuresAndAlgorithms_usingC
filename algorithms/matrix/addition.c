#include <stdio.h>
#include <stdlib.h>

void input(int** mat,int rows,int cols){
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            scanf("%d",&mat[i][j]);
        }
    }    
}

void print(int** mat,int rows,int cols){
    for(int i=0;i<rows;i++){
        for(int  j=0;j<cols;j++){
            printf("%i ",mat[i][j]);
        }
        printf("\n");
    }    
    printf("\n");
}

int** addition(int** mat1,int** mat2,int rows,int cols){
    int** result = (int **)malloc(sizeof(int*) * rows);
    for(int i=0;i<rows;i++){
        result[i] = (int*)malloc(sizeof(int)*cols);
    }
    
    
    for(int i=0;i<rows;i++){
        for(int  j=0;j<cols;j++){
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    return result;
}

int main()
{
    int rows,cols;
    printf("enter rows and cols : ");
    scanf("%d %d",&rows,&cols);
    
    int** mat1 = (int**)malloc(sizeof(int*)*rows);
    for(int i=0;i<rows;i++){
        mat1[i] = (int*)malloc(sizeof(int)*cols);
    }
    printf("enter matrix 1 \n");
    input(mat1,rows,cols);
    
    int** mat2 = (int**)malloc(sizeof(int*)*rows);
    for(int i=0;i<rows;i++){
        mat2[i] = (int*)malloc(sizeof(int)*cols);
    }
    printf("enter matrix 2 \n");
    input(mat2,rows,cols);
    
    
    int** result = addition(mat1,mat2,rows,cols);
    printf("result of addition \n");
    print(result,rows,cols);
    return 0;
}