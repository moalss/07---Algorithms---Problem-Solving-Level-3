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



void PrintEachWordInString(string s)
{
    string delim=" ";
    string word;
    short pos;

    // find() searches for the delimiter inside the string
// if the delimiter is found, find() returns its position
// if not found the element, it returns string::npos 
// continue looping while the delimiter exists
    while ((pos=s.find(delim)) != string::npos)
    {
        word=s.substr(0,pos);

        if (word!="")
        {
            cout<< word<< endl;
        }
        s.erase(0,pos + delim.length());
        
    }
    if (s!="") //empty string
    {
        cout << s;
    }
    
    
}

int main(){

string text="Hello a@iumnsdv sdasdasd sdasd ";
PrintEachWordInString(text);
return 0;
}