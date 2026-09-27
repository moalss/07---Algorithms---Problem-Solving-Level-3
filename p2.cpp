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


int SumRow(int arr[3][3],int rowNumber , int cols){

    
    int sum=0;
            for (int j = 0; j < cols; j++) {
           sum+= arr[rowNumber][j];
        }
        
    
return sum;
}


void PrintEachRowSum(int arr[3][3],int rows , int cols){

    for (int i = 0; i < rows; i++)
    {
        cout<< "Row number "<< i+1 <<": "<< SumRow(arr,i,cols)<<endl;
    }
    
}


void PrintMatrix(int arr[3][3],int rows , int cols) {
    
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            cout <<left<< setw(5)<< arr[i][j];
        }
        cout << endl;
    }
cout << endl;

}

int main() {
    srand(time(0));

    int arr[3][3];

    FillMatrix(arr,3,3);
    PrintMatrix(arr,3,3);
    
    PrintEachRowSum(arr,3,3);
    return 0;
}