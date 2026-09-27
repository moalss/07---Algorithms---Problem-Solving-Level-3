#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <iomanip>

using namespace std;





bool IsNumberInMatrix( int arr2[3][3] ,int rows , int cols,int number){
   
    
    
        for (int i = 0; i < rows; i++)
        {
         
           for (int j = 0; j < cols; j++)
           {
            
            if (number==arr2[i][j]){ 
               return true;
            }
        }
            
    }
    return false;
}

void IntersectedNumberInMatrix(int arr1[3][3],int arr2[3][3],int rows , int cols ){


        for (int i = 0; i < rows; i++)
        {
         
           for (int j = 0; j < cols; j++)
           {
            
            if (IsNumberInMatrix(arr2,rows,cols,arr1[i][j])){ 
                cout << setw(4)<<arr1[i][j];
            }
        }
            
    }

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
    {9,1,2},
    {6,10,8},
    {22,11,5}};

    int arr2[3][3]={
    {9,1,2},
    {6,0,8},
    {22,11,5}};
    int arr3[9];

    cout <<"Matrix 1"<<endl;
    PrintMatrix(arr1,3,3);

     cout <<"Matrix 2"<<endl;
    PrintMatrix(arr2,3,3);
    
    
    cout <<"Intersected Number are "<<endl;
    IntersectedNumberInMatrix(arr1,arr2,3,3);
    
    return 0;
}