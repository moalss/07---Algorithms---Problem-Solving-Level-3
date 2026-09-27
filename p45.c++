#include <string>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


const string fileName="ClientRecord.txt";
struct sClient{
    string accountNumber;
    string pinCode;
    string name;
    string phone;
    double accountBalamce;
};

sClient ClientRecord(){
    sClient client;
cout<< "Enter Account Number? ";
getline(cin,client.accountNumber);
cout<< "Enter Pin Code? ";
getline(cin,client.pinCode);
cout<< "Enter Name? ";
getline(cin,client.name);
cout<< "Enter Phone? ";
getline(cin,client.phone);
cout<< "Enter AccountBalance? ";
cin>>client.accountBalamce;
return client;
}


string ConvertRecordToLine(sClient& client,string sperater="#//#"){
    cout<< "Clint Record for Saving is: "<<endl;
    string record=client.accountNumber+sperater
    +client.pinCode+sperater
    +client.name+sperater+
    client.phone+sperater+
    to_string(client.accountBalamce);
return record;
}

void SaveRecordToFile(string fileName,string line){

fstream MyFile;

MyFile.open(fileName, ios::out | ios::app);

if(MyFile.is_open()){

    MyFile<< line<<endl;
MyFile.close();
}

}

int main() {

    
    sClient client= ClientRecord();
   string clientLine= ConvertRecordToLine(client);
    SaveRecordToFile(fileName,clientLine);
   
    return 0;
};