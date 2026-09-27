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


string JoinString(string delim, short length, string words[])
{

    string s="";

for(short i=0;i<length ; i++){
    s=s+words[i]+ delim;
    }

return s.substr(0,s.length()-delim.length()); 

}

string JoinString(string delim ,vector <string> vWords)
{

    string s="";

for(string & v : vWords){
    s=s+v+ delim;
    }

return s.substr(0,s.length()-delim.length()); //substr(0, 19 - 1) s = "Mohamed,Fadi,Jaser," -> 0 to 18 -> Mohamed,Fadi,Jaser

}

int main()
{

   vector  <string> text = {"Mohamed", "Fadi","Jaser"};
   string textA[3] = {"Mohamed", "Fadi","Jaser"};
  cout<< JoinString(",",text)<<endl;
  cout<< JoinString(",",3,textA);
    //g++ p39.c++ -std=c++17 -o p39 ./p39

    return 0;
}