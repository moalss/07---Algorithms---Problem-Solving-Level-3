#include <string>
#include <iostream>
#include <vector>
using namespace std;

string ReadText()
{
    string Ch1;
    cout << "\nPlease Enter a Text?\n";
    getline(cin, Ch1);
    return Ch1;
}

vector <string> SplitString(string S1, string delim )
{

short Counter = 0;
short pos = 0;
string sWord;
vector <string>vWords;
while ((pos = S1.find(delim)) != std::string::npos)
{
sWord = S1.substr(0, pos); // store the word
if (sWord != "")
{
vWords.push_back(sWord);
}
//erase() until positon and move to next word.
S1.erase(0, pos + delim.length());
}
if (S1 != "")
{
vWords.push_back(sWord);
}
return vWords;
}

int main()
{

    string text = "Hello a@iumnsdv sdasdasd sdasd";
   vector <string> vWord=SplitString(text," ");
   cout <<"Tokens: "<< vWord.size()<<endl;
    for(string & v : vWord){
    cout << v<<endl;
    }
    

    return 0;
}