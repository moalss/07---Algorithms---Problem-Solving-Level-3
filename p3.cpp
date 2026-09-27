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


int SumColm(int arr[3][3],int rows , int cols){

    
    int sum=0;
            for (int j = 0; j < rows; j++) {
           sum+= arr[j][cols];
        }
       
        
    
return sum;
}


void PrintColsSumMatrix (int ergArr[3],int rows ){

    for (int i = 0; i < rows; i++)
    {
        cout << "Colum "<< i +1 << " "<<ergArr[i]<< " "<<endl;
    }
    
}

void SumMatrixColsIArray(int arr[3][3],int ergArr[3],int rows , int cols){

    for (int i = 0; i < cols; i++)
    {
        ergArr[i]=SumColm(arr,rows,i);
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
int ergArr[3];
    FillMatrix(arr,3,3);
    PrintMatrix(arr,3,3);
    
    SumMatrixColsIArray(arr,ergArr,3,3);
    PrintColsSumMatrix(ergArr,3);
    return 0;
}