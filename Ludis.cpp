#include<iostream>
#include<cctype>

using namespace std;

int main(){
    // variables
    int total_numbers = 100; // total number of accounts
    int count = 1; // number of accounts that have been created?
    int logged_in_user = -1; // the index of logged in user
    char transaction;
    int login_acc,login_pin = 0,my_acc,new_acc,new_balance = -1;
    int manager_password = 1234, manager_account = 1001000, manager_balance = 0, system_constant = 1001;


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
            if (count < total_numbers){
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

            }else{
                cout<<"A maximum number of accounts has been reached. You can't create a new account now.\n";
            }
        }else{
            if (logged_in_user < 0){
                cout<<"You are not logged in\n"<<"Enter your account number : "<<system_constant;
                cin>>login_acc;
            }else{
                login_acc = account[logged_in_user][0] - manager_account;
                cout<<"Your account : "<<account[logged_in_user][0]<<endl;
            }
            cout<<"Enter your pin :";
            cin>>login_pin;
            my_acc = manager_account + login_acc;


            // logging in
            for (int i = 0; i < total_numbers; i++){
                if (account[i][0] == my_acc && account[i][1] == login_pin){
                    cout<<"Logged in successfully!\n";
                    cout<<"Your account number : "<<account[i][0]<<endl;
                    break;
                }else{
                    cout<<"Invalid Pin Code!\n";
                    break;
                }
            }

            // transactions
            if (transaction == 'B'){

            }

            
            
        }
        
    }

    return 0;
}