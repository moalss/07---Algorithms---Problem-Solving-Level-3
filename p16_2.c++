#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <iomanip>
#include <cmath>
using namespace std;




short CountOfNumber(int arr[3][3],int rows , int cols,short checkNumber ){
   
    
    short count=0;
        for (int i = 0; i < cols; i++)
        {
         
           for (int j = 0; j < rows; j++)
           {
            
            if (arr[i][j]==checkNumber){ 
                count++;
            }
        }
            
    }
   return count;
}



bool IsSparseMatrix(int arr[3][3],int rows , int cols){

    short matrixSize=rows*cols;
    return (CountOfNumber(arr,rows,cols,0)>=ceil((float)matrixSize/2));
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

    int Matrix1[3][3] = { {0,0,12},{9,9,1},{0,0,9} };
    PrintMatrix(Matrix1,3,3);
    
    if(IsSparseMatrix(Matrix1,3,3)){
        cout  <<"The Matrix is Sparse ";

    }else
    cout  <<"The Matrix is not Sparse ";

    return 0;
}