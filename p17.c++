#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <iomanip>

using namespace std;




bool IsNumberInMatrix(int arr[3][3],int rows , int cols ,short number){
   
    
    
        for (int i = 0; i < cols; i++)
        {
         
           for (int j = 0; j < rows; j++)
           {
            
            if (arr[i][j]==number){ 
                return true;
            }
        }
            
    }
   return false;
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
    

    int arr[3][3]={
    {9,1,2},
    {6,10,8},
    {22,11,5}};

    
    PrintMatrix(arr,3,3);
    int number=0;
    cout <<"Plase Enter the number to look for in matrix: "<<endl;
    cin >> number;

    if(IsNumberInMatrix(arr,3,3,number)){
        cout  <<"Yes it is exist ";

    }else
    cout  <<"No it is not exist ";

    return 0;
}