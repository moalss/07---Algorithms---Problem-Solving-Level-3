#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <iomanip>

using namespace std;




bool CheckIdentityMatrix(int arr1[3][3],int rows , int cols ){
   
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
          
            if (i==j && arr1[i][j]!=1)
            {
               return false;
            }
            else if (i!=j && arr1[i][j]!=0)
            {
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

    int arr1[3][3]={{1,0,0},{0,1,0},{0,0,1}};

    
    PrintMatrix(arr1,3,3);


if(CheckIdentityMatrix(arr1,3,3))
cout << "The Matrix are Identity";
else
    cout << "The Matrix are not Identity";


    return 0;
}