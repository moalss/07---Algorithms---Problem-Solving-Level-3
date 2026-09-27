#include <iostream>
#include <string>


using namespace std;


short Fibonacci(short i){

if(i==0){
return 0;
}
if(i==1){
return 1;
}
return Fibonacci(i-1) + Fibonacci(i-2);
}


void Fibo(short num, short prev1, short prev2){
    int febNumber=0;
    if(num>0){
        febNumber= prev1+prev2;
        prev1=prev2;
        prev2=febNumber;
        cout << febNumber<<" ";

         Fibo(num-1,prev1,prev2);

    }
}

int main(){



Fibo(10,0,1);
}