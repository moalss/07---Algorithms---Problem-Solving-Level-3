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
    bool isRemove=false;
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

    client.accountNumber = vClient.at(0);
    client.pinCode = vClient.at(1);
    client.name = vClient.at(2);
    client.phone = vClient.at(3);
    client.accountBalamce = stod(vClient.at(4));

    return client;
}


string ConvertRecordToLine(sClient& client,string sperater="#//#"){
    cout<< "Client Record for Saving is: "<<endl;
    string record=client.accountNumber+sperater
    +client.pinCode+sperater
    +client.name+sperater+
    client.phone+sperater+
    to_string(client.accountBalamce);
return record;
}

vector <sClient> LoadClientDataFromFile(string fileName){

    fstream MyFile;
    vector <sClient> vsClient;
     
    MyFile.open(fileName, ios::in);

    if (MyFile.is_open()){
        
        string line;
         

        while (getline(MyFile,line))
        {
             if (line.empty())
                continue;
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





void SaveRecordToFile(string fileName, vector <sClient>& vClient){

fstream MyFile;
string dataLine;
MyFile.open(fileName, ios::out );

if(MyFile.is_open()){

for (sClient &c : vClient)
{
    if(c.isRemove==false){
        dataLine = ConvertRecordToLine(c);
        MyFile<< dataLine<<endl;
       
    }
    
}
MyFile.close();

}

}

bool FindClientByAccountNumber(sClient& client, string accountNumber,vector <sClient> vclient ){

   
    for (sClient &c : vclient)
    {
        if (c.accountNumber==accountNumber)
        {
            
           client= c;
          return true;
        }
        
    }
    return false;

}

bool MarkClientForDeleteAccount(vector  <sClient>& vClient ,string accountNumber ){

    for (sClient &c : vClient)
    {
        if (c.accountNumber==accountNumber)
        {
            c.isRemove=true;
            return true;
        }
        
        
    }
    return false;
    
}

bool RemoveClientFromFile(vector  <sClient>& vClient, string accountNumber){
char remove='n';
sClient client;

if(FindClientByAccountNumber(client,accountNumber,vClient)){

    PrintClientData(client);
     cout<<"\nAre you sure to delete this client? y/n? ";
        cin >> remove;
        
        if (remove=='y'){
            MarkClientForDeleteAccount(vClient, accountNumber);
            
            SaveRecordToFile(fileName,vClient);
            vClient=LoadClientDataFromFile(fileName);
             cout<< "Client Deleted Succssesfully.";
            }
            return true;
}
else{
       cout << "Client with account Number is not found ("<< accountNumber<<")"<<endl;
   
        }

        return false;
        
}


int main(){

string number =EnterAccountNumber();
sClient client;
vector <sClient> vClient=LoadClientDataFromFile(fileName);
RemoveClientFromFile(vClient,number);
    return 0;

}