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


void PrintClientData( sClient c){

    //left  → Text links, Leerzeichen rechts
   //right → Text rechts, Leerzeichen links

     cout<<"| "<<left<<setw(16)<<c.accountNumber; 
     cout << "| "<<setw(10)<<left<<c.pinCode;
     cout << "| "<<setw(28)<<left<<c.name ;
     cout << "| "<<setw(14)<<left<<c.phone;
     cout << "| "<<c.accountBalamce<<endl ;
}

void PrintAllClientsData(vector <sClient> clients){

    cout << "\n\t\t\t\t\t"<<"Client List ("<< (clients.size()) <<") client(s)"<<endl;

    cout<<"----------------------------------------------------------------------------------------------\n"<<
    "| Account Number  | Pin Code  | Client Name                 | Phone         | Balance         |      \n"

    "----------------------------------------------------------------------------------------------\n";

    for (sClient &c : clients)
    {
       PrintClientData(c);

    }
    

}

int main(){


    PrintAllClientsData(LoadClientDataFromFile(fileName));
    return 0;

}