#include <string>
#include <iostream>
using namespace std;


char ReadChar()
{
    char Ch1;
    cout << "\nPlease Enter a Character?\n";
    cin >> Ch1;
    return Ch1;
}

bool IsVowel(char Ch1)
{
Ch1 = tolower(Ch1);
return ((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'i') || (Ch1
== 'o') || (Ch1 == 'u'));
}

bool CheckVowelLetter(string vowel, char letter){

for (short i = 0; i < vowel.length(); i++)
{
    if(tolower(letter) == vowel[i]){
        return true;
    }
}
 return false;

}


int main(){

    string vowel="aeiou";
    char letter;
    cout <<"Enter the letter: "<<endl;
    cin >> letter;
if (CheckVowelLetter(vowel, letter))
{
    cout << "Yes, letter '" << letter << "' is vowel";
}
else
{
    cout << "No, letter '" << letter << "' is not vowel";
}

}