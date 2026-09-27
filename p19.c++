#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <iomanip>

using namespace std;





short MaxNumberInMatrix( int arr[3][3] ,int rows , int cols){
   
    
    int maxNum=arr[0][0];
        for (int i = 0; i < rows; i++)
        {
         
           for (int j = 0; j < cols; j++)
           {
            
            if (maxNum<arr[i][j]){ 
               maxNum=arr[i][j];
            }
        }
            
    }
    return maxNum;
}

short MinNumberInMatrix( int arr[3][3] ,int rows , int cols){
   
    
    int minNum=arr[0][0];
        for (int i = 0; i < rows; i++)
        {
         
           for (int j = 0; j < cols; j++)
           {
            
            if (minNum>arr[i][j]){ 
               minNum=arr[i][j];
            }
        }
            
    }
    return minNum;
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
    {9,0,2},
    {6,10,8},
    {22,11,5}};

    

    cout <<"Matrix 1"<<endl;
    PrintMatrix(arr1,3,3);


cout << "Minimum Number is: "<< MinNumberInMatrix(arr1,3,3)<<endl;
cout << "Maximum Number is: "<< MaxNumberInMatrix(arr1,3,3);
    return 0;
}