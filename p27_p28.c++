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
    if( letter >= 'A' && letter <='Z'){
        return letter;
    }
    return letter + 'A' -'a'; // 'A'  - 'a' = 32
}

char ConvertLatterLowerOrUpper(char letter){
/*
    if( letter >= 'a' && letter <='z'){
        return  toupper(letter);
    } else if( letter >= 'A' && letter <='Z'){
        return  tolower(letter);
    }
    return letter;
*/
    return isupper(letter) ? tolower(letter) : toupper(letter);
}


void printLatters(string text){
    for (int  i = 0; i < text.length(); i++)
    {
       
        text[i]=ConvertLatterLowerOrUpper(text[i]);
        
    }
    cout << text;
}


void PrintLowerLatters( string text){
    bool firestLetter = true;

    for (int i =0; i< text.length(); i++){
        if(text[i] != ' ' ){
          text[i]= TOLowerCase(text[i]);
        }
    
    }
    cout << text;
}


void PrintUpperLatters( string text){
    bool firestLetter = true;

    for (int i =0; i< text.length(); i++){
        if(text[i] != ' '  ){
          text[i]= TOUpperCase(text[i]);
        }
    
    }
    cout << text;
}

int main(){

//PrintLowerLatters("Hello World") ;
//PrintUpperLatters("Hello World");
 printLatters("Hello World");

    return 0;
}