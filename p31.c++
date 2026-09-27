#include <string>
#include <iostream>
using namespace std;

string ReadString()
{
    string S1;
    cout << "\nPlease Enter Your String?\n";
    getline(cin, S1);
    return S1;
}
char ReadChar()
{
    char Ch1;
    cout << "\nPlease Enter a Character?\n";
    cin >> Ch1;
    return Ch1;
}

char ConverLetter(char letter){
    return islower(letter)? toupper(letter) : tolower(letter);
}




short CountUpperOrLowerLetter(string text, char letter, bool matchCase= true)
{

    short count = 0;
    for (int i = 0; i < text.length(); i++)
    {
        if(matchCase){
            if(text[i]==letter){
                count++;
            }
        }else {
        if(tolower(letter)==tolower(text[i])){
                count++;
            }
        }
    }

    return count;
}

int main()
{

    string text = ReadString();
    char letter = ReadChar();
    cout <<"Letter: "<< "\'" << letter<< "\'" <<"Count: "<< CountUpperOrLowerLetter(text, letter)<< endl;
    cout <<"Letter: "<< "\'" << letter<< "\'" <<"Or"<< "\'" << ConverLetter(letter)<< "\'" <<"Count: "<<  CountUpperOrLowerLetter(text, letter,false);
    return 0;
}