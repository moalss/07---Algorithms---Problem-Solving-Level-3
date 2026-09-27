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
    PrintMatrix(arr, 3, 3);
    return 0;
}