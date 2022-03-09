#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

const int SIZE = 3;

bool loShu(int array[][SIZE]);
void printSquare(int array[][SIZE]);



int main(){


    int array1[3][3] = { 4,9,2,
                               3,5,7,
                               8,1,6 };  

    int array2[3][3] = { 1,2,3,
                               4,5,6,
                               7,8,9};  

    int checkArr[9] ={0};
    int array[3][3];
    int number = 0;
    time_t t;
    srand((unsigned) time(&t));
    int totalSquares = 0;

    
    do {
        for(int row = 0; row < SIZE;row++){
    
            for(int col = 0; col < SIZE; col++ ){
                number = rand () % 9 + 1;

             } 
       
        }    

    }
    while (!loShu(array));





    bool ans = loShu(array2);
    printf("%s\n", ans ? "True": "False");
    printSquare(array1);


    return 0;
}

void printSquare(int array[][SIZE]){
    for(int row = 0; row < SIZE;row++){
        printf("[");
        for(int col = 0; col < SIZE; col++ ){
            printf("%d ",array[row][col]);

        } 
        printf("]\n");
    }       
    
}
bool loShu(int array[][SIZE]){
    bool cond1,cond2,cond3;
    int target = 0;
    int rowSum = 0, colSum = 0, diagSum1 =0, diagSum2 = 0;

    for(int row = 0; row < SIZE;row++){
        rowSum = 0;
        colSum = 0;
        diagSum1 =0;
        diagSum2 = 0;
        for(int col = 0; col < SIZE; col++ ){
            if (row == 0){
                target += array[row][col];
                
            }

            if (row == 1){
                diagSum1 += array[col][col];
                diagSum2 += array[SIZE -1 - col][col];
                colSum = diagSum1;
                rowSum = diagSum2;

            }
            else{
            colSum += array[col][row];
            rowSum += array[row][col];
            diagSum1 = colSum;
            diagSum2 = rowSum;
            }

         
        }

        //printf("Target:%d  row:%d  col:%d  d1:%d  d2:%d \n", target, rowSum, colSum, diagSum1,diagSum2);
        if (target != rowSum || target != colSum || target != diagSum1 || target != diagSum2){
            return false;
        }



        
    }

    return true;

}