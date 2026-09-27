#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;


const string fileName="ClientRecord.txt";

struct sClient{
    string accountNumber;
    string pinCode;
    string name;
    string phone;
    double accountBalamce;
};


vector <string> SplitString(string clientRecord,string delim){
vector <string> vClient;
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

sClient ConvertLineToRecord(string text, string separator = "#//#")
{
    sClient client;

    vector<string> vClient = SplitString(text, separator);

    client.accountNumber = vClient[0];
    client.pinCode = vClient[1];
    client.name = vClient[2];
    client.phone = vClient[3];
    client.accountBalamce = stod(vClient[4]);

    return client;
}

vector <sClient> LoadClientDataFromFile(string fileName){

    fstream MyFile;
    vector <sClient> vsClient;
     
    MyFile.open(fileName, ios::in);

    if (MyFile.is_open()){
        string line;
        while (getline(MyFile,line))
        {
            sClient sclient= ConvertLineToRecord(line);
            vsClient.push_back(sclient);
            
        }
        
       MyFile.close();
        
        
    }

return vsClient;
 
}


void PrintClientData( sClient client){
cout << "\n\nThe following is the client details:\n";
cout << "\nAccout Number: " << client.accountNumber;
cout << "\nPin Code : " << client.pinCode;
cout << "\nName : " << client.name;
cout << "\nPhone : " << client.phone;
cout << "\nAccount Balance: " << client.accountBalamce;
}


string EnterAccountNumber(){
    string number;
    cout << "Please enter Accountnumber ";
   getline(cin,number);
   return number;

}

bool FindClientByAccountNumber(sClient& client, string accountNumber){

    vector <sClient> vClient = LoadClientDataFromFile(fileName);
    for (sClient &c : vClient)
    {
        if (c.accountNumber==accountNumber)
        {
           client= c;
          return true;
        }
        
    }
    return false;

}

int main(){

string number =EnterAccountNumber();
sClient client;
if(FindClientByAccountNumber(client,number)){
PrintClientData(client);
}
else{
       cout << "Client with account Number is not found ("<< number<<")"<<endl;
        }
    return 0;

}