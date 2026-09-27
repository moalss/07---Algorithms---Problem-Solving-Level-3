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

void MultaplyTowMatrix(int arr1[3][3],int arr2[3][3],int ergArr[3][3],int rows , int cols ){

for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
        ergArr[i][j] = arr1[i][j]*arr2[i][j];
        }
    }
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
    int ergArr[3][3];
    FillMatrix(arr1,3,3);
    FillMatrix(arr2,3,3);

    PrintMatrix(arr1,3,3);
    PrintMatrix(arr2,3,3);
    MultaplyTowMatrix(arr1,arr2,ergArr,3,3);
    PrintMatrix(ergArr,3,3);

    return 0;
}