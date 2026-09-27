#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;


void PerformTransactionMenueOption(short option);
void PerformMainMenueOption(short option);
void ShowTransactionMenue();
void DepositBalanceToClient();
const string fileName = "ClientRecord.txt";

struct sClient
{
    string accountNumber;
    string pinCode;
    string name;
    string phone;
    double accountBalamce;
    bool isRemove = false;
};

sClient ClientRecord()
{
    sClient client;
    cout << "Enter Account Number? ";
    getline(cin >> ws, client.accountNumber);
    cout << "Enter Pin Code? ";
    getline(cin, client.pinCode);
    cout << "Enter Name? ";
    getline(cin, client.name);
    cout << "Enter Phone? ";
    getline(cin, client.phone);
    cout << "Enter AccountBalance? ";
    cin >> client.accountBalamce;
    return client;
}

sClient UpdateClientRecord(string accountNumber)
{

    sClient client;
    client.accountNumber = accountNumber;
    cout << "Enter Pin Code? ";
    getline(cin >> ws, client.pinCode);
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
string ConvertRecordToLine(sClient &client, string sperater = "#//#")
{
    string record = client.accountNumber + sperater + client.pinCode + sperater + client.name + sperater +
                    client.phone + sperater +
                    to_string(client.accountBalamce);
    return record;
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

void SaveRecordToFile(string fileName, string line)
{

    fstream MyFile;

    MyFile.open(fileName, ios::out | ios::app);

    if (MyFile.is_open())
    {

        MyFile << line << endl;
        MyFile.close();
    }
}

void SaveRecordsToFile(string fileName, vector<sClient> &vClient)
{

    fstream MyFile;
    string dataLine;
    MyFile.open(fileName, ios::out);

    if (MyFile.is_open())
    {

        for (sClient &c : vClient)
        {
            if (c.isRemove == false)
            {
                dataLine = ConvertRecordToLine(c);
                MyFile << dataLine << endl;
            }
        }
        MyFile.close();
    }
}

void AddNewClient()
{
    sClient client = ClientRecord();
    string clientLine = ConvertRecordToLine(client);
    SaveRecordToFile(fileName, clientLine);
}

string EnterAccountNumber()
{
    string number;
    cout << "Please enter Accountnumber ";
    getline(cin >> ws, number);
    return number;
}

void PrintClientData(sClient c)
{

    // left  → Text links, Leerzeichen rechts
    // right → Text rechts, Leerzeichen links

    cout << "| " << left << setw(16) << c.accountNumber;
    cout << "| " << setw(10) << left << c.pinCode;
    cout << "| " << setw(28) << left << c.name;
    cout << "| " << setw(14) << left << c.phone;
    cout << "| " << c.accountBalamce << endl;
}

void PrintAllClientsData(vector<sClient> clients)
{

    cout << "\n\t\t\t\t\t" << "Client List (" << (clients.size()) << ") client(s)" << endl;

    cout << "----------------------------------------------------------------------------------------------\n"
         << "| Account Number  | Pin Code  | Client Name                 | Phone         | Balance         |      \n"

            "----------------------------------------------------------------------------------------------\n";

    for (sClient &c : clients)
    {
        PrintClientData(c);
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

        if (update == 'y' || update == 'Y')
        {
            for (sClient &c : vClient)
            {

                if (c.accountNumber == accountNumber)
                {

                    c = UpdateClientRecord(accountNumber);
                    break;
                }
            }
            SaveRecordsToFile(fileName, vClient);
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

bool MarkClientForDeleteAccount(vector<sClient> &vClient, string accountNumber)
{

    for (sClient &c : vClient)
    {
        if (c.accountNumber == accountNumber)
        {
            c.isRemove = true;
            return true;
        }
    }
    return false;
}

bool RemoveClientFromFile(vector<sClient> &vClient, string accountNumber)
{
    char remove = 'n';
    sClient client;

    if (FindClientByAccountNumber(client, accountNumber, vClient))
    {

        PrintClientData(client);
        cout << "\nAre you sure to delete this client? y/n? ";
        cin >> remove;

        if (remove == 'y')
        {
            MarkClientForDeleteAccount(vClient, accountNumber);
            SaveRecordsToFile(fileName, vClient);
            vClient = LoadClientDataFromFile(fileName);
            cout << "Client Deleted Succssesfully.";
        }
        return true;
    }
    else
    {
        cout << "Client with account Number is not found (" << accountNumber << ")" << endl;
    }

    return false;
}

short ReadMainMenueOption()
{
    cout << "\nChoose what do you want to do? [1 to 7]? ";
    short num;
    cin >> num;
    return num;
}

short ReadTransactionMenueOption()
{
    cout << "\nChoose what do you want to do? [1 to 4]? ";
    short num;
    cin >> num;
    return num;
}

void ShowMainMenue()
{

    cout << "===================================================" << endl;
    cout << "\t\t\t\t Main Menue Screen" << endl;
    cout << "===================================================" << endl;
    cout << setw(40) << left << "1: Show Client List." << endl;
    cout << setw(50) << left << "2: Add New Client." << endl;
    cout << setw(15) << left << "3: Delete Client." << endl;
    cout << setw(15) << left << "4: Update Client Info." << endl;
    cout << setw(15) << left << "5: Find Client." << endl;
    cout << setw(15) << left << "6: Transaction." << endl;
    cout << setw(15) << left << "7: Exit." << endl;
    cout << "===================================================" << endl;
    PerformMainMenueOption(ReadMainMenueOption());
}

void GoBackToMainMenue()
{
    cout << "\nPress any key to return to menu....";
    cin.ignore();
    cin.get();
    ShowMainMenue();
}

void GoBackToTransactionMenue(){
    cout<< "\nPress any key to go back to Transaction Menue ";
    cin.ignore();
    cin.get();
    ShowTransactionMenue();
}

void ShowTransactionMenue()
{
    cout << "===================================================" << endl;
    cout << "\t\t\t\t Transaction Menue Screen" << endl;
    cout << "===================================================" << endl;
    cout << setw(40) << left << "1: Deposit." << endl;
    cout << setw(50) << left << "2: Withdraw." << endl;
    cout << setw(15) << left << "3: Total Balances." << endl;
    cout << setw(15) << left << "4: Main Menue." << endl;
    cout << "===================================================" << endl;
    PerformTransactionMenueOption(ReadTransactionMenueOption());
}

void DepositBalanceToClient(vector <sClient>& vClient,string accountNumber,double newAmount ){

       for (sClient &c : vClient)
        {
            if (c.accountNumber == accountNumber)
            {

                c.accountBalamce += newAmount;
                break;
            }
        }

}


void Deposit()
{
    short newDepoist;
    char s = 'n'; 
    vector<sClient> vClient = LoadClientDataFromFile(fileName);
    sClient sclient;
    string accountNumber = EnterAccountNumber();
    while (!FindClientByAccountNumber(sclient, accountNumber, vClient))
    {
        cout << "Cliet with [" << accountNumber << "] does not exist";
        accountNumber = EnterAccountNumber();
    }
    PrintClientData(sclient);

    cout << "Please enter dopist amount: ";
    cin >> newDepoist;

    cout << "Are you sure you want perfom this transaction? y/n ";
    cin >> s;
    if (s == 'y')
    {

         DepositBalanceToClient(vClient,accountNumber,newDepoist);

        SaveRecordsToFile(fileName, vClient);
    }
}
bool CheckAmount(sClient c, double newAmount)
{

    if (c.accountBalamce > newAmount)
    {
        return true;
    }
    else
    {
        cout << " Amount exceeds the Balance, you ca withdraw up " << c.accountBalamce;
        return false;
    }
}



void Withdraw()
{

    short newAmount;
    char s = 'n';
    vector<sClient> vClient = LoadClientDataFromFile(fileName);
    sClient sclient;
    string accountNumber = EnterAccountNumber();
    while (!FindClientByAccountNumber(sclient, accountNumber, vClient))
    {
        cout << "Cliet with [" << accountNumber << "] does not exist"<<endl;
        accountNumber = EnterAccountNumber();
    }
    PrintClientData(sclient);
    do
    {

        cout << "Please enter withdraw amount: ";
        cin >> newAmount;
    } while (!CheckAmount(sclient, newAmount));

    cout << "Are you sure you want perfom this transaction? y/n ";
    cin >> s;
    if (s == 'y')
    {

     
        DepositBalanceToClient(vClient,accountNumber,newAmount*-1);
        SaveRecordsToFile(fileName, vClient);
    }
}

void SumOfAllClientsBalance()
{
    vector<sClient> vClient = LoadClientDataFromFile(fileName);
    cout << "Balance List (" << vClient.size() << " ) Client(s)";
    PrintAllClientsData(vClient);
    double totalBalances;
    for (sClient &c : vClient)
    {
        totalBalances += c.accountBalamce;
    }
    cout << "\t\t\t\t Total Balances= " << totalBalances;
}




void PerformTransactionMenueOption(short num)
{
    string accountNmuber;

    sClient sclient;

    switch (num)
    {
    case 1:
        system("cls");
        Deposit();
        GoBackToTransactionMenue();
        break;

    case 2:
        system("cls");
        Withdraw();
        GoBackToTransactionMenue();
        break;

    case 3:
        system("cls");
        SumOfAllClientsBalance();
        GoBackToTransactionMenue();
        break;

    case 4:
        system("cls");
       ShowMainMenue();
        break;

    }
}

void PerformMainMenueOption(short option)
{
    string accountNmuber;

    sClient sclient;
    vector<sClient> vClient = LoadClientDataFromFile(fileName);

    switch (option)
    {
    case 1:
        system("cls");
        PrintAllClientsData(vClient);
        GoBackToMainMenue();
        break;

    case 2:
        system("cls");
        AddNewClient();
        GoBackToMainMenue();
        break;
    case 3:
        system("cls");
        accountNmuber = EnterAccountNumber();
        RemoveClientFromFile(vClient, accountNmuber);
        GoBackToMainMenue();
        break;

    case 4:
        system("cls");
        accountNmuber = EnterAccountNumber();
        UpdateClientFromFile(vClient, accountNmuber);
        GoBackToMainMenue();
        break;
    case 5:
        system("cls");
        accountNmuber = EnterAccountNumber();
        if (FindClientByAccountNumber(sclient, accountNmuber, vClient))
        {
            PrintClientData(sclient);
        }
        else
        {
            cout << "Client with account Number is not found (" << accountNmuber << ")" << endl;
        }
        GoBackToMainMenue();
        break;

    case 6:
    {
        ShowTransactionMenue();
        break;
    }
    case 7:
    {
        cout << "\nProgram Ended.\n";

        break;
    }
    default:
    {

        cout << "Invalid option"<<endl;
        ShowMainMenue();
    }
    }
}

int main()
{
ShowMainMenue();
    return 0;
}