#include <string>
#include <iostream>
#include <vector>
using namespace std;

string TrimLeft(string s){

    for (short i = 0; i < s.length(); i++)
    {
        if(s[i]!=' '){
            return s.substr(i,s.length());
        }
    }
    return "";
    
}

string TrimRight(string s){

    for (short i = s.length()-1; i >= 0; i--)
    {
        if(s[i]!=' '){
            return s.substr(0,i+1); // substr(0,6) Mohame -> i+1 -> Mohamed 
        }
    }
    return "";
    
}

string Trim(string s){
    return TrimLeft(TrimRight(s));
}

int main()
{
string S1 = "  Mohamed Issa  ";
cout << "\nString = " << S1;
cout << "\n\nTrim Left = " << TrimLeft(S1);
cout << "\nTrim Right = " << TrimRight(S1);
cout << "\nTrim = " << Trim(S1);
system("pause>0");
}