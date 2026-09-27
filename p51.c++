#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;

const string fileName = "ClientRecord.txt";

struct sClient
{
    string accountNumber;
    string pinCode;
    string name;
    string phone;
    double accountBalamce;
   
};

sClient UpdateClientRecord(string accountNumber)
{

    sClient client;
    client.accountNumber=accountNumber;
    cout << "Enter Pin Code? ";
    getline(cin>>ws, client.pinCode);
    cout << "Enter Name? ";
    getline(cin, client.name);
    cout << "Enter Phone? ";
    getline(cin, client.phone);
    cout << "Enter AccountBalance? ";
    cin >> client.accountBalamce;
    return client;
}

vector<string> SplitString(string clientRecord, string delim)
{
    vector<string> vClient;
    string word = "";
    short pos;
    while ((pos = clientRecord.find(delim)) != string::npos)
    {

        word = clientRecord.substr(0, pos);
        if (word != "")
        {
            vClient.push_back(word);
        }

        clientRecord.erase(0, pos + delim.length());
    }
    if (clientRecord != "")
    {
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

string ConvertRecordToLine(sClient &client, string sperater = "#//#")
{
    cout << "Client Record for Saving is: " << endl;
    string record = client.accountNumber + sperater + client.pinCode + sperater + client.name + sperater +
                    client.phone + sperater +
                    to_string(client.accountBalamce);
    return record;
}

vector<sClient> LoadClientDataFromFile(string fileName)
{

    fstream MyFile;
    vector<sClient> vsClient;

    MyFile.open(fileName, ios::in);

    if (MyFile.is_open())
    {

        string line;
        while (getline(MyFile, line))
        {
            if (line.empty())
                continue;
            sClient sclient = ConvertLineToRecord(line);
            vsClient.push_back(sclient);
        }

        MyFile.close();
    }

    return vsClient;
}

void PrintClientData(sClient client)
{
    cout << "\n\nThe following is the client details:\n";
    cout << "\nAccout Number: " << client.accountNumber;
    cout << "\nPin Code : " << client.pinCode;
    cout << "\nName : " << client.name;
    cout << "\nPhone : " << client.phone;
    cout << "\nAccount Balance: " << client.accountBalamce;
}

string EnterAccountNumber()
{
    string number;
    cout << "Please enter Accountnumber ";
    getline(cin, number);
    return number;
}

void SaveRecordToFile(string fileName, sClient & sclient,vector <sClient> vClient)
{

    fstream MyFile;
    string dataLine;
    MyFile.open(fileName, ios::out);

    if (MyFile.is_open())
    {

       for (sClient &c : vClient)
       {
           dataLine = ConvertRecordToLine(c);
           MyFile << dataLine << endl;
        
       }
       
           
        
        MyFile.close();
    }
}

bool FindClientByAccountNumber(sClient &client, string accountNumber, vector<sClient> &vclient)
{

    for (sClient &c : vclient)
    {
        if (c.accountNumber == accountNumber)
        {
            client = c;
            return true;
        }
    }
    return false;
}


bool UpdateClientFromFile(vector<sClient> &vClient, string accountNumber)
{
    char update = 'n';
    sClient client;

    if (FindClientByAccountNumber(client, accountNumber, vClient))
    {

        PrintClientData(client);
        cout << "\nAre you sure to update this client? y/n? ";
        cin >> update;

        if (update == 'y' || update =='Y')
        {
            for (sClient &c: vClient)
            {
                
                if(c.accountNumber==accountNumber){

                    c= UpdateClientRecord(accountNumber);
                    break;
                }
            }
                SaveRecordToFile(fileName, client,vClient);
                vClient = LoadClientDataFromFile(fileName);
                cout << "Client update Succssesfully.";
        }
        return true;
    }
    else
    {
        cout << "Client with account Number is not found (" << accountNumber << ")" << endl;
    }

    return false;
}

int main()
{

    string number = EnterAccountNumber();
    sClient client;
    vector<sClient> vClient = LoadClientDataFromFile(fileName);
    UpdateClientFromFile(vClient, number);
    return 0;
}