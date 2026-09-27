#include <iostream>
#include <string>


using namespace std;

int main(){

    int sum=1;
    int arr[10];
  
    arr[0]=1;
    arr[1]=1;
    for (int i = 2; i < 10; i++)
    {
        
            arr[i]= arr[i-1] +arr[i-2];
    
    }
for (int i = 0; i < 10; i++)
    {
        cout << arr[i]<<" ";

    }
int prev1=1;
int prev2=1;
int next=0;
cout << "1 ";
    for (int i = 0; i < 10; i++)
    {
        next= prev1 + prev2;
        cout << next<<" ";
        prev1= prev2;
        prev2=next;

    }
    
}