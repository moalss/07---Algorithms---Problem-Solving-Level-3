#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <iomanip>

using namespace std;



void FillMatrix(int arr[3][3], int rows, int cols)
{
    int c=1;
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            arr[i][j] = c++;
        }
    }
}

void ReplaceColsToRowSMatrix(int arr[3][3],int rows, int cols)
{int temp;
   
    for (int i = 0; i < cols; i++)
    {
        for (int j = i+1; j < rows; j++)
        {
            temp=arr[j][i]; //00 10 20
            arr[j][i]= arr[i][j] ;// 00 01 02
            arr[i][j]=temp; //00 01
        }
    }
}

void TransposeMatrix(int arr[3][3],int tArr[3][6],int rows, int cols)
{int temp;
   
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
           tArr[i][j]=arr[j][i]; 
        
        }
    }
}




void PrintMatrix(int arr[3][3], int rows, int cols)
{

    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            cout << left << setw(5) << arr[i][j];
        }
        cout << endl;
    }
  
}

int main()
{
    srand(time(0));

    int arr[3][3];
    int ergArr[3];

    FillMatrix(arr, 3, 3);
    ReplaceColsToRowSMatrix(arr,3,3);
    PrintMatrix(arr, 3, 3);
    return 0;
}