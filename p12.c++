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


int SumOfMatrix(int arr[3][3],int rows , int cols ){
int sum=0;

        for (int i = 0; i < cols; i++) {
            for (int j = 0; j < rows; j++) {
           sum+= arr[i][j];
        }
    }
      
    return sum;
    
}
bool AreEqualMatrices(int arr1[3][3],int arr2[3][3],int rows , int cols ){

return (SumOfMatrix(arr1,3,3) == SumOfMatrix(arr1,3,3));

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

if(AreEqualMatrices(arr1,arr2,3,3))
cout << "The Matrices are equal";
else
    cout << "The Matrices are not equal";


    return 0;
}