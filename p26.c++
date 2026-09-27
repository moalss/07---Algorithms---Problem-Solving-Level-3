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

char TOUpperCase(char letter){
    if( letter >= 'A' && letter <='Z'){//
        return letter;
    }
    return letter + 'A' -'a'; // 'A'  - 'a' = 32
}


string PrintLowerLatters( string text){
    bool firestLetter = true;

    for (int i =0; i< text.length(); i++){
        if(text[i] != ' ' ){
          text[i]= TOLowerCase(text[i]);
        }
    
    }
    return text;
}


string PrintUpperLatters( string text){
    bool firestLetter = true;

    for (int i =0; i< text.length(); i++){
        if(text[i] != ' '  ){
          text[i]= TOUpperCase(text[i]);
        }
    
    }
    return text;
}
int main(){
cout <<PrintLowerLatters("Hello World") <<endl;;
cout <<PrintUpperLatters("Hello World");

    return 0;
}