#include<iostream>
#include<cctype>

using namespace std;

int main(){
    // variables
    int total_numbers = 100; // total number of accounts
    int count = 0; // number of accounts that have been created?
    int logged_in_user = -1; // the index of logged in user
    char transaction;
    int login;
    int manager_password = 1234, manager_account = 1001000, manager_balance = 0;


    // array of account
    int account[total_numbers][2] = {
        {manager_account,manager_password},
    }; // first for account number and second for pin code
    int balance[total_numbers] = {{manager_balance}};


    while(true){
        cout<<"*******************************************\n";
        cout<<"**                                       **\n";
        cout<<"**                 Help                  **\n";
        cout<<"**       Enter O to open new account     **\n";
        cout<<"**       Enter B for balance inquiry     **\n";
        cout<<"**       Enter D to deposit              **\n";
        cout<<"**       Enter W to withdraw             **\n";
        cout<<"**       Enter C to close account        **\n";
        cout<<"**       Enter S if you are a manager    **\n";
        cout<<"**                                       **\n";
        cout<<"*******************************************\n";
        cout<<"\nEnter any command ->";
        cin>>transaction;
        transaction = toupper(transaction);
        
        if (transaction == 'O'){

        }else{
            if (logged_in_user < 0){
                cout<<"You are not logged in\n"<<"Enter your account number : 1001";
                cin>>login;
            }
        }
        
    }

    return 0;
}