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

short CountVowelLetters(string text){

    short count=0;
    for (short i = 0; i < text.length(); i++)
    {
        if(IsVowel(text[i])){
            count++;

        }
    }
    return count;
    
}

int main(){

string text=ReadText();
cout <<"Number of vowel is "<<CountVowelLetters(text);
return 0;
}