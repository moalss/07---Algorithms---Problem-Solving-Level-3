#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <iomanip>

using namespace std;

int RandomNumber(int from, int to) {
    return rand() % (to - from + 1) + from;
}

void FillMatrix(int arr[3][3],int rows , int cols) {
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            arr[i][j] = RandomNumber(1, 100);
        }
    }
}

bool AreTypicalMatrices(int arr1[3][3],int arr2[3][3],int rows , int cols ){

for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
         if(arr1[i][j]!=arr2[i][j]){
             
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
            printf(" %0*d ",2,arr[i][j]);
        }
        cout << endl;
    }
}

int main() {
    srand(time(0));

    int arr1[3][3];
    int arr2[3][3];
    
    FillMatrix(arr1,3,3);
    FillMatrix(arr2,3,3);
    PrintMatrix(arr1,3,3);
    PrintMatrix(arr2,3,3);

if (AreTypicalMatrices(arr1,arr2,3,3)){
 cout << "The Matrices are typical";
}else
cout << "The Matrices are not typical";



    return 0;
}