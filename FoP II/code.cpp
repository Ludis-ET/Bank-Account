#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

const int BANK_CODE = 1001;
const int MIN_CAPACITY = 1000000;

struct Account {
    int id;
    string name;
    string password;
    double balance;
};

class BankSystem {
private:
    int userID = -1;
    Account local;

public:
    void mainMenu() {
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
        cin.clear();
        cin >> menu;
        myChoice(menu);
    }

    void myChoice(int menu) {
        if (menu < 0 || menu > 7) {
            clearTerminal();
            Message("Invalid Choice");
            mainMenu();
        } else if (menu == 0) {
            clearTerminal();
            Message("Logout successful. Thank you for using our service.");
        } else if (menu == 1) {
            clearTerminal();
            Message("Create New Account");
            createAccount();
        } else {
            if (userID < 0) {
                clearTerminal();
                Message("Please Login to your account first.");
                Login();
            } else {
                switch (menu) {
                    case 2:
                        clearTerminal();
                        Message(local.name + "'s Balance -> $" + to_string(local.balance));
                        mainMenu();
                        break;
                    case 3:
                        clearTerminal();
                        double depositAmount;
                        Message(local.name + "'s Balance -> $" + to_string(local.balance));
                        cout << "\t\t\tDeposit amount ( > 0) -> ";
                        cin >> depositAmount;
                        if (depositAmount <= 0) {
                            Message("Invalid Amount!");
                            mainMenu();
                        } else {
                            handleTransaction(depositAmount);
                        }
                        break;
                    case 4:
                        clearTerminal();
                        double withdrawAmount;
                        Message(local.name + "'s Balance -> $" + to_string(local.balance));
                        cout << "\t\t\tWithdrawal amount ( > 0) -> ";
                        cin >> withdrawAmount;
                        if (withdrawAmount <= 0 || withdrawAmount > local.balance) {
                            Message("Invalid Amount!");
                            mainMenu();
                        } else {
                            handleTransaction(-withdrawAmount);
                        }
                        break;
                    case 5:
                        clearTerminal();
                        myprofile();
                }
            }
        }
    }

    void myprofile(){
        clearTerminal();
        cout << "\t\t\t\t\t\t*******************************************\n";
        cout << "\t\t\t\t\t\t**                                       \n";
        cout << "\t\t\t\t\t\t**   --" << local.name << "'s Profile --   \n";
        cout << "\t\t\t\t\t\t**                                       \n";
        cout << "\t\t\t\t\t\t**       Balance: $" << local.balance << endl;
        cout << "\t\t\t\t\t\t**       Password: "; for (int i = 0; i < local.password.length(); ++ i) cout << "#";
        cout << "\n\t\t\t\t\t\t*******************************************\n";

        int th;
        cout << "\n\t\t\t\t\t Enter 13 to update your account, any other number to main menu =>";
        cin >> th;
        if (th != 13){
            clearTerminal();
            mainMenu();
        } else {
            cout << "\t\t\t\tEnter 1 to update your Name, 3 to update your password =>";
            cin >> th;
            if (th == 1) {
                cout << "\t\t\t\tEnter your new name =>";
                cin >> local.name;
                updateProfileInDatabase();
            } else if (th == 3){
                string old_password;
                cout << "\t\t\t\tEnter your old password =>";
                cin.ignore();
                getline(cin, old_password);

                if (old_password == local.password){
                    cout << "\t\t\t\tEnter your new password =>";
                    getline(cin, local.password);
                    updateProfileInDatabase();       
                } else {
                    myprofile();
                }
            } else {
                myprofile();
            }
        }
    }

    void updateProfileInDatabase() {
        fstream database("database.txt", ios::in | ios::out);
        if (!database.is_open()) {
            clearTerminal();
            Message("Database not found");
            mainMenu();
            return;
        }

        Account account;
        bool found = false;

        while (database >> account.id >> account.name >> account.password >> account.balance) {
            if (account.id == local.id) {
                account.name = local.name;
                account.password = local.password;
                database.seekp(database.tellg());
                database << account.id << " " << account.name << " " << account.password << " " << account.balance << endl;
                found = true;
                break;
            }
        }

        database.close();

        if (found) {
            clearTerminal();
            Message("Profile updated successfully!");
        } else {
            clearTerminal();
            Message("User not found in the database.");
        }

        mainMenu();
    }

    void handleTransaction(double amount) {
        clearTerminal();
        fstream database("database.txt", ios::in | ios::out);

        if (!database.is_open()) {
            clearTerminal();
            Message("Database not found");
            mainMenu();
            return;
        }

        vector<Account> accounts;
        Account account;

        while (database >> account.id >> account.name >> account.password >> account.balance) {
            if (account.id == local.id) {
                account.balance += amount;
                local.balance += amount;
            }
            accounts.push_back(account);
        }

        database.close();

        database.open("database.txt", ios::out | ios::trunc);
        if (!database.is_open()) {
            clearTerminal();
            Message("Error opening database for writing");
            mainMenu();
            return;
        }

        for (const auto& acc : accounts) {
            database << acc.id << " " << acc.name << " " << acc.password << " " << acc.balance << endl;
        }

        database.close();

        if (amount > 0) {
            Message("$" + to_string(amount) + " was deposited to your account. New balance: $" + to_string(local.balance));
        } else {
            Message("$" + to_string(-amount) + " was withdrawn from your account. New balance: $" + to_string(local.balance));
        }

        mainMenu();
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
        cout << "Enter your initial deposit: ";  
        cin >> balance; 
        newAccount.balance = balance;

        database << newAccount.id << " " << newAccount.name << " " << newAccount.password << " " << newAccount.balance << endl;
        database.close();

        clearTerminal();
        Message("Account created successfully! Your account ID is " + to_string(newAccount.id));
        mainMenu();
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
        cout <<"Enter your password: ";
        cin.ignore();
        getline(cin, password);

        Account account;
        while (database >> account.id >> account.name >> account.password >> account.balance) {
            if (account.id == loginID && account.password == password) {
                userID = (loginID) - (BANK_CODE * MIN_CAPACITY);
                clearTerminal();
                Message("Logged in successfully. Welcome, " + account.name + "!");

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

    void Message(const string& message) {
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
};

int main() {
    BankSystem bankSystem;
    bankSystem.mainMenu();
    return 0;
}

