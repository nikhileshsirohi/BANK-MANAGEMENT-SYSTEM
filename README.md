# Banking Management System
This is a simple console-based banking management system implemented in C++. It allows users to perform various banking operations like creating an account, depositing, withdrawing, checking balances, modifying account details, and also have the password protection.

### Table of Contents
1.Description  
2.Usage  
3.Functions  
4.Class account  
5.Function create_account  
6.Function show_account  
7.Function modify  
8.Function dep  
9.Function draw  
10.Function report  
11.Function retacno  
12.Function retdeposit  
13.Function rettype  
14.Function retpass  
15.Function write_account  
16.Function display_sp  
17.Function modify_account  
18.Function delete_account  
19.Function display_all  
20.Function deposit_withdraw  
21.Function intro  
22.Getting Started  
23.Password Protection  
24.Author  
### Description
This banking management system simulates basic banking operations such as account creation, deposit, withdrawal, account modification, password protection and more. It uses a class account to represent individual accounts and various member functions to perform actions related to these accounts.

### Usage
Compile and run the program using a C++ compiler. The program provides a menu-driven interface for users to select operations they want to perform.

## Functions
### Class account
Function create_account
This function is used to create a new account. It prompts the user to input details like account number, account holder's name, account type, phone number, initial deposit amount, and password.

### Function show_account
Displays the details of an account, including account number, account holder's name, account type, balance amount, and phone number.

### Function modify
Allows the user to modify account details such as account holder's name, account type, and phone number.

### Function dep
Used to deposit a specified amount into an account.

### Function draw
Used to withdraw a specified amount from an account.

### Function report
Displays a summary of account details in a tabular format.

### Function retacno
Returns the account number of an account.

### Function retdeposit
Returns the balance amount of an account.

### Function rettype
Returns the account type (C - Current, S - Saving) of an account.

### Function retpass
Returns the password of an account.

### Function write_account
Writes a new account's details to a binary file.

### Function display_sp
Displays the details of a specific account based on the provided account number. Requires the user to enter a password to access account details.

### Function modify_account
Allows the user to modify account details after providing the correct password.

### Function delete_account
Deletes an account from the binary file after verifying the admin's password.
Only Admin have access to delete an account

### Function display_all
Displays details of all accounts stored in the binary file after verifying the admin's Password.
Only admin can see all account holder list.

### Function deposit_withdraw
Enables deposit and withdrawal operations, considering the account type and balance. Requires password verification for withdrawals.

### Function intro
Displays an introductory message when the program starts.

### Getting Started
Compile the code using a C++ compiler.
Run the compiled executable.
Follow the on-screen prompts to perform various banking operations.

## Security
By Default Admin Password: 12345678 to login
Only Admin can close and display all account holder list

Certainly! In the provided C++ code for the banking management system, there are aspects related to password protection to ensure the security of account information. Here's how password protection is implemented in the code:

Password Entry during Account Creation:
When a new account is being created using the create_account function, the user is prompted to enter a password. The password must be at least 6 characters long. The user is then asked to confirm the password. The code ensures that the password and its confirmation match before proceeding.

Password Verification for Access:
When the user wants to view account details using the display_sp function or perform modifications using the modify_account and delete_account functions, the program prompts the user to enter the account's password for verification. The password is compared to the stored password for the account, and access is granted only if the passwords match.

Password Storage:
The account class includes a private member conf_pass to store the confirmed password during account creation. The retpass function allows retrieval of the password for comparison during password verification.

Here's an overview of how password protection is implemented for specific functions:

create_account Function:

The user enters a new password and confirms it.
The code ensures that the password meets the length requirement and matches the confirmation.
The confirmed password is stored in the conf_pass member variable.
display_sp, modify_account, and delete_account Functions:

When these functions require access to an account's information, they prompt the user to enter the account's password.
The provided password is compared with the stored password using the retpass function.
If the passwords match, access is granted; otherwise, access is denied.
retpass Function:

This function returns the stored confirmed password.
By verifying passwords before granting access to sensitive operations, this approach adds an additional layer of security to the banking management system, ensuring that only authorized users can view or modify account information.

However, it's important to note that this approach is a simplified example for educational purposes. In real-world applications, password handling and security measures should be more robust, involving techniques like secure hashing and encryption to protect sensitive information.

### Author
This banking management system was created by Nikhilesh Sirohi, a student at Madan Mohan Malaviya University of Technology, Gorakhpur.







