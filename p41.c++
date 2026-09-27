#include <string>
#include <iostream>
#include <vector>
using namespace std;

string ReadText()
{
    string text;
    cout << "Enter the Text: ";
    getline(cin, text);

    return text;
}

vector<string> SplitString(string word, string delim)
{
    vector<string> vWord;
    short pos;
    while ((pos = word.find(delim)) != string::npos)
    {
        vWord.push_back(word.substr(0, pos));
        word.erase(0, pos + delim.length());
    }

    if (word != "")
    {
        vWord.push_back(word);
    }

    return vWord;
}


string ReversWorde(string text, string delim){

vector <string> vWord;

string word="";
vWord= SplitString(text,delim);
vector <string>::iterator iter=vWord.end();

while(iter!=vWord.begin()){
    --iter;
    word+=*iter+" ";
}

word= word.substr(0,word.length()-1);
return word;

}

int main(){

string text= ReadText();
cout << "after revers Word \n";
cout << ReversWorde(text," ");

}