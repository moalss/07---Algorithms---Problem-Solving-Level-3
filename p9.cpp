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
            arr[i][j] = RandomNumber(1, 10);
        }
    }
}

void PrintMiddleRowOfMatrix(int arr[3][3],int rows , int cols ){
int middle=rows/2;

        for (int j = 0; j < cols; j++) {

               cout << arr[middle][j]<<" ";
            }
        
    
}


void PrintMiddleColOfMatrix(int arr[3][3],int rows , int cols ){


  
   int middle=rows/2;

        for (int j = 0; j < cols; j++) {

               cout << arr[j][middle]<<" ";
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

    int arr[3][3];

    FillMatrix(arr,3,3);

    PrintMatrix(arr,3,3);


    PrintMiddleRowOfMatrix(arr,3,3);
     cout<<endl;
    PrintMiddleColOfMatrix(arr,3,3);
    return 0;
}