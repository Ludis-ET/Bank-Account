#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int BANK_CODE = 1001;
int MIN_CAPACITY = 1000000;
int USER_ID = -1;

struct Account{
    int id;
    string name;
    string password;
    double balance;
} local;


int countUsers();
void Login();
void clearTerminal();
void myChoice(int);
void createAccount();
void Message(const string&);
void mainMenu(){

    int menu;

    cout << "\t\t\tWelcome to the Bank of Somebody" << endl;
    cout << "\t\t\t\t\t\t*******************************************\n";
    cout << "\t\t\t\t\t\t**                                       **\n";
    cout << "\t\t\t\t\t\t**   --Main Menu --                      **\n";
    cout << "\t\t\t\t\t\t**                                       **\n";
    cout << "\t\t\t\t\t\t**       Enter 1 to create new account   **\n";
    cout << "\t\t\t\t\t\t**       Enter 2 for balance inquiry     **\n";
    cout << "\t\t\t\t\t\t**       Enter 3 to deposit              **\n";
    cout << "\t\t\t\t\t\t**       Enter 4 to withdraw             **\n";
    cout << "\t\t\t\t\t\t**       Enter 5 to view profile         **\n";
    cout << "\t\t\t\t\t\t**       Enter 6 to delete account       **\n";
    cout << "\t\t\t\t\t\t**       Enter 0 to exit program         **\n";
    cout << "\t\t\t\t\t\t**       Enter 7 if you are a manager    **\n";
    cout << "\t\t\t\t\t\t**                                       **\n";
    cout << "\t\t\t\t\t\t*******************************************\n";

    cout << "\t\t\tEnter Your Choice here ->";
    cin >> menu;
    myChoice(menu);
}


int main(){
    mainMenu();
    return 0;
}

void myChoice(int menu){
    if (menu < 0 || menu > 7){
        clearTerminal();
        Message("Invalid Choice");
        mainMenu();
    }else if (menu == 0){
        clearTerminal();
        Message("Logout successful. Thank you for using our service.");
    }else if (menu == 1){
        clearTerminal();
        Message("Create New Account");
        createAccount();
    }else{
        if (USER_ID < 0){
            clearTerminal();
            Message("Please Login to your account first.");
            Login();
        }else{
            switch (menu){
                case 2:
                    clearTerminal();
                    Message(local.name + "'s Balance -> $" + to_string(local.balance));
                    mainMenu();
                case 3:
                    clearTerminal();
                    int new_balance;
                    cout << "Enter deposit ammount (0 <)";
                    cin >> new_balance;

                    if (new_balance <= 0){
                        Message("Invalid Ammount.");
                        mainMenu();
                    }else{
                        
                    }
            }
        }
    }
}


void createAccount() {
    fstream database("database.txt", ios::out | ios::app);
    if (!database.is_open()) {
        clearTerminal();
        Message("Database not found");
        mainMenu();
        return;
    }

    Account newAccount;
    double balance;

    newAccount.id = (BANK_CODE * MIN_CAPACITY) + (countUsers() + 1);

    cout << "Enter your full name: ";
    cin.ignore();
    getline(cin, newAccount.name);
    cout << "Enter your password: ";
    getline(cin, newAccount.password);
    cout << "Enter your intial deposit: ";  
    cin >> balance; 
    newAccount.balance = balance;

    database << newAccount.id << " " << newAccount.name << " " << newAccount.password << " " << newAccount.balance << endl;
    database.close();

    clearTerminal();
    Message("Account created successfully! Your account ID is " + to_string(newAccount.id));
    mainMenu();
}


void Message(const string& message){
    cout << "\t\t\t\t*******************************************************************\n";
    cout << "\t\t\t\t\t" << message << endl;
    cout << "\t\t\t\t*******************************************************************\n";
}


void clearTerminal() {
    system("cls");
}


int countUsers() {
    fstream database("database.txt", ios::in);
    if (!database.is_open()) {
        return 0;
    }

    int count = 0;
    string line;
    while (getline(database, line)) {
        if (!line.empty()) {
            count++;
        }
    }
    database.close();
    return count;
}


void Login() {
    fstream database("database.txt", ios::in);

    if (!database.is_open()) {
        clearTerminal();
        Message("Database not found");
        mainMenu();
    }

    int loginID;
    string password;

    cout << "Enter your account ID: ";
    cin >> loginID;
    cout << "Enter your password: ";
    cin.ignore();
    getline(cin, password);

    Account account;
    while (database >> account.id >> account.name >> account.password >> account.balance) {
        if (account.id == loginID && account.password == password) {
            USER_ID = (loginID) - (BANK_CODE * MIN_CAPACITY);
            clearTerminal();
            Message("Logged in successfuly. Welcome, " + account.name + "!");

            local.id = account.id;
            local.name = account.name;
            local.balance = account.balance;
            local.password = account.password;

            mainMenu();
        }
    }
    database.close();
    clearTerminal();
    Message("Login failed. Invalid account ID or password.");
    mainMenu();

}

