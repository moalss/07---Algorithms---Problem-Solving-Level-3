#include <string>
#include <iostream>
#include <vector>
using namespace std;

vector <string> SplitWord(string word, string delim){

vector <string> vword;
string sWord="";
short pos;

while ( (pos=word.find(delim))!= string::npos)
{
    sWord=word.substr(0,pos);
if(!sWord.empty()){

    vword.push_back(sWord);
}
    word.erase(0,pos+delim.length());
}

if(word!=""){
     vword.push_back(word);
}
return vword;
}


string JoinString(vector<string> vString, string Delim)
{
string S1;
for (string& s : vString)
{
S1 = S1 + s + Delim;
}
return S1.substr(0, S1.length() - Delim.length());

}

string ToLowerCase(string word ){
 
 
 for (int i = 0; i < word.length(); i++)
 {
   word[i]=tolower(word[i]);
 }
 
 return word;
}


string ReplaceWordInStringUsingSplit(string text,string oldWord, string newWorld, bool matchCase =true){

vector <string> vSWord=SplitWord(text," ");

for (string &word : vSWord)
{
    if(matchCase){ // lower case
        if(word==oldWord){
            word= newWorld;
        }
    }else {

        if(ToLowerCase(word)==ToLowerCase(oldWord)){
            word=newWorld;
        }
    }
}

return JoinString( vSWord," ");

}

int main()
{
string S1 = "Welcome to Jordan , Jordan is a nice country";
string StringToReplace = "jordan";
string ReplaceTo = "USA";
cout << "\nOriginal String:\n" << S1;
cout << "\n\nReplace with match case: ";
cout << "\n" << ReplaceWordInStringUsingSplit(S1,
StringToReplace, ReplaceTo);
cout << "\n\nReplace with dont match case: ";
cout << "\n" << ReplaceWordInStringUsingSplit(S1,
StringToReplace, ReplaceTo, false);
return 0;
}