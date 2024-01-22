# Bro Code Bank Account Manual

## Group Project: Bro Code

**Course Information:**
- Course: Fundamental of Programming I
- Instructor: Chere Lemma

This program is a collaborative effort by the Bro Code group for the Fundamental of Programming I course. It is designed to manage a system of bank accounts, supporting various transactions, including opening an account, checking balances, making deposits and withdrawals, closing accounts, computing interest, and printing account information.

## Team Members

- **Leulseged Melaku (Organizer/Leader):**
  - Organized the team and ensured effective collaboration.
  - Implemented the main menu structure and overall program flow.
  - Added functionality for account creation, login, and logout.
  - Integrated the manager's panel and related transactions.
  - Ensured proper communication and collaboration among team members.

- **Liben Gebremedhin:**
  - Contributed to the implementation of the account creation functionality (Transaction type 'O').
  - Worked on the initial setup and structure of the program.

- **Lemesa Elias:**
  - Contributed to the balance inquiry functionality (Transaction type 'B').
  - Participated in designing and implementing user authentication and pin validation.

- **Lakemihret Getachew:**
  - Contributed to the deposit functionality (Transaction type 'D').
  - Assisted in handling deposit transactions and updating account balances.

- **Liyuneh Rstey:**
  - Contributed to the withdrawal functionality (Transaction type 'W').
  - Collaborated on the implementation of withdrawal transactions and balance updates.


## Instructions

1. **Open an Account (Transaction type: O)**
    - Initial deposit? *amount*
    - Open an account, giving the initial deposit.
    - Allowed if less than 100 accounts are open.
    - Prints the new account number.

2. **Balance Inquiry (Transaction type: B)**
    - Account number? *account_number*
    - A balance inquiry prints the account number and the balance, only allowed if the account is open.

3. **Deposit (Transaction type: D)**
    - Account number? *account_number*
    - Amount? *amount*
    - A deposit prints the account number and the new balance, only allowed if the account is open.

4. **Withdrawal (Transaction type: W)**
    - Account number? *account_number*
    - Amount? *amount*
    - A withdrawal, only allowed if the account is open and sufficient funds are available.
    - Prints the account number and the new balance.

5. **Close Account (Transaction type: C)**
    - Account number? *account_number*
    - Close the account, only allowed if the account is open.

6. **Compute Interest (Transaction type: I)**
    - Interest rate? *interest_rate*
    - Compute interest at the given percentage rate and apply it to all accounts.
    - Accessible only to managers.

7. **Print Account Information (Transaction type: P)**
    - Print all account numbers and amounts OR
    - Print the account and all corresponding transactions in tabular format.
    - Accessible only to managers.

8. **Exit Program (Transaction type: E)**
    - Close all accounts and exit the program.
    - Accessible only to managers.

9. **Manager Transactions (Transaction type: S)**
    - S: Open the bank.
    - P: Print account information.
    - I: Compute interest.
    - E: Exit program.
    - **Manager's Account Information:**
      - Manager Account Number: 1001000
      - Manager Password: 123

### Additional Features

- **Security:**
  - Pin numbers are added to the bank accounts.
  - A special pin number is assigned to the bank manager.
  - Transaction type 'S' is added to open the bank, accessible only to the manager.

- **Account Initialization:**
  - In an 'Open' transaction, the user chooses the pin number for the account.
