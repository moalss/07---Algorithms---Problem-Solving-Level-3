#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <iomanip>

using namespace std;




bool IsScalerMatrix(int arr[3][3],int rows , int cols ){
   
    int firstDiagElement=arr[0][0];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
          //check for diagonals element
            if(i==j && arr[i][j]!=firstDiagElement){ 
                    return false;
            }
            //check for rest elements
            else if(i!=j && arr[i][j]!=0){ 
                    return false;
            }
            
            
        }
        
    }
    return true;
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

    int arr1[3][3]={
    {9,0,0},
    {0,9,0},
    {0,0,9}};

    
    PrintMatrix(arr1,3,3);


if(IsScalerMatrix(arr1,3,3))
cout << "The Matrix are Scalar";
else
    cout << "The Matrix are not Scalar";


    return 0;
}