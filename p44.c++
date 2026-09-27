#include <string>
#include <iostream>
#include <vector>
using namespace std;


bool IsPunctuation(char pun){

   if((pun >=33 &&pun<=47)|| (pun >=58 &&pun<=64) || (pun >=91 &&pun<=96)|| (pun >=123 &&pun<=126) ){
return true;
   }
      return false;
}

string RemovePunctuationFromString(string text ){
    string newText="";
    for (short i = 0; i < text.length(); i++)
    {
       
        if(!IsPunctuation(text[i])){

        newText+=text[i];
        
        }
       
        
    }
    return newText;
    
        
    }
    
int main()
{
    string text = "Hello, World! How are you?";

    cout << RemovePunctuationFromString(text);

    return 0;
}