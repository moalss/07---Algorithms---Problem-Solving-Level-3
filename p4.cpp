#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <iomanip>

using namespace std;

int RandomNumber(int from, int to)
{
    return rand() % (to - from + 1) + from;
}

void FillMatrix(int arr[3][3], int rows, int cols)
{
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            arr[i][j] = RandomNumber(1, 100);
        }
    }
}

int SumColm(int arr[3][3], int rows, int cols)
{

    int sum = 0;
    for (int j = 0; j < cols; j++) // zeile spalte. [z][1]
    {
        sum += arr[rows][j];
    }

    return sum;
}

void PrintRowsSumMatrix(int ergArr[3], int rows)
{

    for (int i = 0; i < rows; i++) 
    {
        cout << "Row " << i + 1 << " " << ergArr[i] << " " << endl;
    }
}

void SumMatrixRowInArray(int arr[3][3], int ergArr[3], int rows, int cols)
{

    for (int i = 0; i < cols; i++)// zeile spalte. [z][1]
    {
        ergArr[i] = SumColm(arr, i, cols);
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
    cout << endl;
}

int main()
{
    srand(time(0));

    int arr[3][3];
    int ergArr[3];

    FillMatrix(arr, 3, 3);
    PrintMatrix(arr, 3, 3);
    SumMatrixRowInArray(arr, ergArr, 3, 3);
    PrintRowsSumMatrix(ergArr, 3);
    return 0;
}