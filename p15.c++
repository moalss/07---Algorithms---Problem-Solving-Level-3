#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <iomanip>

using namespace std;




short CountOfANumber(int arr[3][3],int rows , int cols ,int checkNumber){
   
    
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
    {9,0,0},
    {0,9,0},
    {0,0,9}};

    
    PrintMatrix(arr,3,3);
    int checkNumber=0;
    cout << "Enter the Number to count in matrix? ";
    cin>> checkNumber;
 cout <<"Number " << checkNumber<< " count in matrix is "<< CountOfANumber(arr,3,3,checkNumber);
    return 0;
}