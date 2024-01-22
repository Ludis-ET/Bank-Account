#include<iostream>
#include<cctype>
using namespace std;
int main(){
    // variables
    int total_numbers = 100; // total number of accounts
    int count = 1; // number of accounts that have been created?
    int logged_in_user = -1; // the index of logged in user
    int manager_password = 123, manager_account = 1001000,  system_constant = 1001;
    float manager_balance = 1.5; // The manager's balance
    int login_acc,login_pin,my_acc,new_acc,new_balance = -1;
    char transaction;
    bool check_user = true,terminate=false;


    // manager variables
    float interest,temp;
    char confirm;

    // array of account
    int account[total_numbers][2] = {
        {manager_account,manager_password},
    }; // first for account number and second for pin code
    float balance[total_numbers] = {{manager_balance}};


    while(terminate == false){
        // Main menu
        cout<<"*******************************************\n";
        cout<<"**                                       **\n";
        cout<<"**   --List of Transactions--            **\n";
        cout<<"**                                       **\n";
        cout<<"**       Enter O to create new account   **\n";
        cout<<"**       Enter B for balance inquiry     **\n";
        cout<<"**       Enter D to deposit              **\n";
        cout<<"**       Enter W to withdraw             **\n";
        cout<<"**       Enter C to close account        **\n";
        cout<<"**       Enter S if you are a manager    **\n";
        cout<<"**                                       **\n";
        cout<<"*******************************************\n";
        cout<<"\n\tEnter any transaction ->";
        cin>>transaction;
        transaction = toupper(transaction);
        login_pin = 0;
        
        if (transaction == 'O'){
            if (count < total_numbers){
                if (logged_in_user >= 0){
                    cout<<"To create new account you have to log out\n";
                }else{
                    while (login_pin < 100 || login_pin >= 1000 || new_balance <= 10){
                        cout<<"Choose a 3 digit pin code that starts without 0 for your account :";
                        cin>>login_pin;
                        cout<<"Deposit money (minimum amount - $10) : $";
                        cin>>new_balance;
                    }
                    new_acc = manager_account + count;
                    cout<<"Your account is created successfully!\n"<<"Your account number is "<<new_acc<<endl;
                    account[count][0] = new_acc;
                    account[count][1] = login_pin;
                    balance[count] = new_balance;
                    logged_in_user = count;
                    count++;
                }
                

            }else{
                cout<<"The maximum number of accounts has been reached. You can't create a new account now.\n";
            }
        }else{
            if (logged_in_user < 0){
                cout<<"You are not logged in\n"<<"Complete your account number : "<<system_constant;
                cin>>login_acc;
                if (account[login_acc][0] == 0){
                    cout<<"\nNo account found please try again!\n\n";
                    continue;
                }
            }else{
                login_acc = account[logged_in_user][0] - manager_account;
                cout<<"Your account number: "<<account[logged_in_user][0]<<endl;
            }
            cout<<"Enter your pin :";
            cin>>login_pin;
            my_acc = manager_account + login_acc;

            // logging in
            if (account[login_acc][0] == my_acc && account[login_acc][1] == login_pin){
                logged_in_user = login_acc;
            }
            else{
                cout<<"Invalid Pin Code, Login denied!\n";
                continue;
            }

            // transactions
            if (logged_in_user >= 0){
                switch (transaction)
                {
                case 'B':
                    cout<<"Your account number is :"<<account[logged_in_user][0]<<endl;
                    cout<<"Your balance is: $"<<balance[logged_in_user]<<endl;
                    break;
                case 'D':
                    cout<<"Your account number is :"<<account[logged_in_user][0]<<endl;
                    cout<<"Your current balance is: $"<<balance[logged_in_user]<<endl;
                    cout<<"Deposit ammount: $";
                    cin>>new_balance;
                    if (new_balance > 0){
                        cout<<"Balance creadited successfully!\n"<<"Your new balance is :$"<<balance[logged_in_user] + new_balance<<endl;
                        balance[logged_in_user] += new_balance;
                    }else{
                        cout<<"Deposit ammount must be greator than 0\n";
                    }
                    break;
                case 'W':
                    cout<<"Your account number is :"<<account[logged_in_user][0]<<endl;
                    cout<<"Your current balance is: $"<<balance[logged_in_user]<<endl;
                    cout<<"Withdrawal ammount: $";
                    cin>>new_balance;
                    if (new_balance > 0 && new_balance <= balance[logged_in_user]){
                        cout<<"Balance debited successfully!\n"<<"Your new balance is :$"<<balance[logged_in_user] - new_balance<<endl;
                        balance[logged_in_user] -= new_balance;
                    }else{
                        cout<<"Ammount have to be less than your balance\n"<<"Your balance is :$"<<balance[logged_in_user]<<endl;
                    }
                    break;
                case 'C':

                    cout<<"Your account number is :"<<account[logged_in_user][0]<<endl;
                    cout<<"Are you sure you want to close your account?(Y/n) :";
                    char confirm;
                    cin>>confirm;
                    if (confirm == 'Y'){
                        cout<<"Logged out successfully! you can return any time you want.\n";
                        logged_in_user = -1;
                    }else{
                        cout<<"opreation cancelled!\n";
                    }
                    break;
                
                case 'S':

                    if (logged_in_user == 0){
                        do{
                            cout<<"\n\nWelcome to the managers pannel choose what you want to do.\n";
                            cout<<"\tEnter I to compute the interest.\n";
                            cout<<"\tEnter P to print all the accounts and amounts\n";
                            cout<<"\tEnter E to close all accounts and exit program\n";
                            cout<<"\tEnter any other character to get back to main menu\n";
                            cout<<"\tYour account number is: "<<account[logged_in_user][0]<<"\n";
                            cout<<"\t\tEnter transaction :";
                            cin>>transaction;
                            transaction = tolower(transaction);


                            switch(transaction){
                                case 'i':
                                    cout<<"Interest rate? (0% - 100%):";
                                    cin>>interest;
                                    if(interest >= 0 && interest <= 100){
                                        for (int i = 0; i <= total_numbers-1; i++){
                                            temp = balance[i];
                                            temp *= (interest/100);
                                            balance[i] += temp;
                                        }
                                        cout<<interest<<"% amount of money has been added to "<<count-1<<" accounts in the database.\n";
                                    }else{
                                        cout<<"Interest have to be between 0% and 100%";
                                    }
                                    break;
                                case 'p':
                                    cout<<"\n\nAll data:\n";
                                    cout<<"\t|\tno\t|\tAccount numbers\t|\tAmount\t\t|\n";
                                    cout<<"\t\t--------------------------------------------------\n";
                                    for (int i = 1; i <= total_numbers-1; i++){
                                        if (account[i][0] != 0){
                                            cout<<"\t|\t"<<i<<"\t|\t"<<account[i][0]<<"\t\t|\t$"<<balance[i]<<"\t\t|\n";
                                            cout<<"\t\t--------------------------------------------------\n";
                                        }
                                    }
                                    cout<<endl<<count-1<<" accounts found.\n";
                                    break;
                                case 'e':
                                    cout<<"Are you sure you want to close all the account?(Y/n) :";
                                    cin>>confirm;
                                    if (confirm == 'Y'){
                                        cout<<"bank opreation terminated\n";
                                        terminate = true;
                                        break;
                                    }else{
                                        cout<<"opreation cancelled!\n";
                                    }
                                    break;
                                default:
                                    cout<<"Getting out of admin pannel...\n";
                                    terminate = true;
                                    break;
                            }
                        }while(terminate = false);
                        terminate = false;
                    }else{
                        cout<<"You have no permission to access this transaction\n";
                    }
                    break;
                
                default:
                    cout<<"Invalid transaction entered please choose one from the menu.\n";
                    break;
                }
                
            }else{
                cout<<"Login first to access this page!\n";
            }

            
            
        }
        
    }
    return 0;
}