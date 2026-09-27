#include <string>
#include <iostream>
using namespace std;


string ReadText()
{
    string Ch1;
    cout << "\nPlease Enter a Text?\n";
    getline(cin,Ch1);
    return Ch1;
}

bool IsVowel(char Ch1)
{
Ch1 = tolower(Ch1);
return ((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'i') || (Ch1
== 'o') || (Ch1 == 'u'));
}

void PrintVowelLetters(string text){


    for (short i = 0; i < text.length(); i++)
    {
        if(IsVowel(text[i])){
            cout<< text[i] <<" "; 

        }
    }
    
    
}

int main(){

string text="Hello a«iumnsdv";
PrintVowelLetters(text);
return 0;
}