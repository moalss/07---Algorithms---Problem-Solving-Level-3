#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <iomanip>

using namespace std;




short CountOfNumbersWithoutZeros(int arr[3][3],int rows , int cols ){
   
    
    short count=0;
        for (int i = 0; i < cols; i++)
        {
         
           for (int j = 0; j < rows; j++)
           {
            
            if ((arr[i][j]!=0)){ 
                count++;
            }
        }
            
    }
   return count;
}

short CountOfZeros(int arr[3][3],int rows , int cols ){
   
    
    short count=0;
        for (int i = 0; i < cols; i++)
        {
         
           for (int j = 0; j < rows; j++)
           {
            
            if ((arr[i][j]==0)){ 
                count++;
            }
        }
            
    }
   return count;
}

bool checkSparseMatrix(int arr[3][3],int rows , int cols){

    return CountOfZeros( arr,rows,cols) > CountOfNumbersWithoutZeros( arr,rows,cols);
}


void PrintMatrix(int arr[3][3],int rows , int cols) {
    cout << "The following array is a 3x3 random Matrix" << endl;

    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            //cout <<left<< setw(5)<< arr[i][j];
            printf(" %*d ",2,arr[i][j]);
        }
        cout << endl;
    }
}

int main() {
    srand(time(0));

    int arr[3][3]={
    {9,9,9},
    {0,9,0},
    {0,0,9}};

    
    PrintMatrix(arr,3,3);
    
    if(checkSparseMatrix(arr,3,3)){
        cout  <<"The Matrix is Sparce ";

    }else
    cout  <<"The Matrix is not Sparce ";

    return 0;
}