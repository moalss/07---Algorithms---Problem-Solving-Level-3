#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <iomanip>

using namespace std;



short IsMatrixPalandrom( int arr[3][3] ,int rows , int cols){
   
    

        for (int i = 0; i < rows; i++)
        {
         
           for (int j = 0; j < cols/2; j++) //افحص فقط نصف الصف
           {
            
            if (arr[i][j]!=arr[i][cols-j-1]){ 
               return false;
            }
        }
            
    }
    return true;
}


void PrintMatrix(int arr[3][3],int rows , int cols) {
    cout << "The following array is a 3x3 random Matrix" << endl;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            //cout <<left<< setw(5)<< arr[i][j];
            printf(" %*d ",2,arr[i][j]);
        }
        cout << endl;
    }
}

int main() {
    

    int arr1[3][3]={
    {1,0,1},
    {6,10,7},
    {2,11,2}};

    

    cout <<"Matrix 1"<<endl;
    PrintMatrix(arr1,3,3);


    if(IsMatrixPalandrom(arr1,3,3)){
       cout << "Yes the Matrix is Palindrome" <<endl; 
    }else
 cout << "No the Matrix is not Palindrome" <<endl; 

    return 0;
}