#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

const int SIZE = 3;//Define the side of the square

//Function declarion
bool loShu(int array[][SIZE]);
void printSquare(int array[][SIZE]);


int main(){
    int array_1[3][3] = { 4,9,2,
                        3,5,7,
                        8,1,6 };  

    int array_2[3][3] = { 1,2,3,
                        4,5,6,
                        7,8,9};  

    int checkArr[9] ={0}; //Array to check if 1->9 has been used or not
    int array[3][3];
    int number; //Random number
    time_t t;
    srand((unsigned) time(&t));
    int totalSquares = 0;
    
    printSquare(array_1);
    printf("%s\n\n", loShu(array_1) ? "This is a Lo Shu Square!": "This is NOT a Lo Shu Square!");
   
    printSquare(array_2);
    printf("%s\n\n", loShu(array_2) ? "This is a Lo Shu Square!": "This is NOT a Lo Shu Square!");

  
    do {
        for (int i = 0; i<9;i++){  //Reset the check array back to all 0's
            checkArr[i]=0;
        }

        for(int row = 0; row < SIZE;row++){
            for(int col = 0; col < SIZE; col++ ){
                number = rand () % 9 + 1; 

                if(checkArr[number-1] == 0){ //If the generated number hasn't found in the check array
                    checkArr[number-1] = 1;  //Set the corresponding index in check array to 1
                    array[row][col] = number;//Set current array[row][col] = generated number
                }
                else{
                    col--;//decrement column by 1 if the generated number is already used
                }
             }   
        }
        totalSquares++; 
    }
    while (!loShu(array));

    printf("The total number of squares generated and tested: %d\n",totalSquares);
    printSquare(array);  

 


    return 0;
}

void printSquare(int array[][SIZE]){
    for(int row = 0; row < SIZE;row++){
        printf("[");
        for(int col = 0; col < SIZE; col++ ){
            printf("%d",array[row][col]);
            printf("%s",col == 2 ? "": " ");

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
                target += array[row][col];//Set target = the first row
            }
            else if (row == 1){//Only calculate the diagional when row = 1          
                diagSum1 += array[col][col];
                diagSum2 += array[SIZE -1 - col][col];
            }

            colSum += array[col][row];//Calculate col at index
            rowSum += array[row][col];//Calculate row at intex
              
        }
        
        //If row =1 , check all sum of column, row, and diagonals
        if(row == 1 && (target != rowSum || target != colSum || target != diagSum1 || target != diagSum2)){ 
            return false;
        }  
        else if ((target != rowSum || target != colSum)){
            return false;   
        }  
    }
    return true;
}