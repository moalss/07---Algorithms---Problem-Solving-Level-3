#include <iostream>
#include <string>
#include <string>

using namespace std;

char TOLowerCase(char letter){
    if( letter >= 'a' && letter <='z'){//
        return letter;
    }
    return letter + 'a' -'A'; // 65 + 32 = 97 - 65
}

string PrintFirstLatter( string text){
    bool firestLetter = true;

    for (int i =0; i< text.length(); i++){
        if(text[i] != ' ' && firestLetter){
          text[i]= TOLowerCase(text[i]);
        }
    firestLetter=(text[i]==' '? true : false);
    }
    return text;
}

int main(){
cout <<PrintFirstLatter("Hello World");

    return 0;
}