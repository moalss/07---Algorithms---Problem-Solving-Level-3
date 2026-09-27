#include <iostream>
#include <string>
#include <string>

using namespace std;

char TOUpperCase(char letter){
    if( letter >= 'A' && letter <='Z'){//
        return letter;
    }
    return letter + 'A' -'a'; // 'A'  - 'a' = 32
}

string PrintFirstLatter( string text){
    bool firestLetter = true;

    for (int i =0; i< text.length(); i++){
        if(text[i] != ' ' && firestLetter){
          text[i]= TOUpperCase(text[i]);
        }
    firestLetter=(text[i]==' '? true : false);
    }
    return text;
}

int main(){
cout <<PrintFirstLatter("hello world");

    return 0;
}