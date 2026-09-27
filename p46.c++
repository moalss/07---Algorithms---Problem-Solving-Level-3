#include <string>
#include <iostream>
#include <vector>
using namespace std;

struct sClient{
    string accountNumber;
    string pinCode;
    string name;
    string phone;
    double accountBalamce;
};

vector <string> SplitString(string clientRecord,string delim){
vector <string> vClient{};
    string word="";
    short pos;
    while((pos=clientRecord.find(delim))!=string::npos){

        word=clientRecord.substr(0,pos);
        if(word!=""){
            vClient.push_back(word);
        }

        clientRecord.erase(0,pos+delim.length());
    }
    if(clientRecord!=""){
         vClient.push_back(clientRecord);
    }
return vClient;
}


sClient ConvertLineToRecord(string text,string sperator="#//#"){
    sClient client;
vector <string> vClient = SplitString(text,sperator);
    client.accountNumber=vClient[0];
    client.pinCode=vClient[1];
    client.name=vClient[2];
    client.phone=vClient[3];
    client.accountBalamce=stod(vClient[4]);
    

return client;
}


void PrintClientRecord(sClient Client)
{
cout << "\n\nThe following is the extracted client record:\n";
cout << "\nAccout Number: " << Client.accountNumber;
cout << "\nPin Code : " << Client.pinCode;
cout << "\nName : " << Client.name;
cout << "\nPhone : " << Client.phone;
cout << "\nAccount Balance: " << Client.accountBalamce;
}


int main()
{
string stLine = "A150#//#1234#//#Mohammed Abu-Hadhoud#//#079999#//#5270.000000";
cout << "\nLine Record is:\n";
cout << stLine;
sClient Client = ConvertLineToRecord(stLine);
    PrintClientRecord(Client);

    return 0;
};