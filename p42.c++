#include <string>
#include <iostream>
#include <vector>

using namespace std;

string ReplacWord(string text, string replacedWord, string replacTo){

int pos=text.find(replacedWord);
while (pos!=string::npos)
{
 text=  text.replace(pos,replacTo.length(),replacedWord);

 pos=text.find(replacedWord,pos+replacTo.length());
}
return text;

}


int main(){
string S1 = "Welcome to Jordan , Jordan is a nice country";
string ReplacTo = "Usa";
string StringToReplace = "Jordan";
 cout << ReplacWord(S1,StringToReplace,ReplacTo);
system("pause>0");
}