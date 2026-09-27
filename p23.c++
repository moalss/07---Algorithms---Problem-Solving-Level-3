#include <iostream>
#include <string>
#include <string>

using namespace std;

void PrintFirstLatter( string text){

bool firestLetter = true;


    for (int i = 0; i < text.length(); i++)
    {
        if(text[i] != ' ' && firestLetter){
            cout << text[i]<< endl;;
            
        }
        firestLetter =(text[i] == ' ' ? true : false);
        
    }

}


int main(){

   PrintFirstLatter(" He llo World");

   return 0;
       
    

}