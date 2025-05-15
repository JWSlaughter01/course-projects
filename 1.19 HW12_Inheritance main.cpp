/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

//links
#include <iostream>
#include <iomanip>
#include <sstream>
#include "Account.h"
#include "RegularAccount.h"
#include "PremiumAccount.h"

using namespace std;
//prototype functions
void printMenu();
double amountSetter();
Date getDate();
//global variable
const int MAX_NUM_ACCOUNTS = 5;

int main() {
   //initializing account
    Account* accountArr[MAX_NUM_ACCOUNTS] = {nullptr};
    int choice, accountNum;
    string name;
    double amount;
    Date date;
    bool flagLoop = true; //having a loop so that it can exit when prompted
    
    while (flagLoop) {
       //made this into its own function for simplicity
        printMenu();
        cin >> choice; //prompt 1-6
        
        //if creating an account
        if (choice == 1 || choice == 2) {
            if (Account::getNumberAccounts() >= MAX_NUM_ACCOUNTS) {
                cout << "Max number of accounts reached, cannot add a new account" << endl;
                continue;
            }
            
            cout << "Enter owner's name: ";
            cin >> name;
            cin.ignore();
            date = getDate();
            amount = amountSetter();
            if (amount < 0) {
               cout << "Amount cannot be negative, account creation not executed" << endl;
               continue;
            } else if (choice == 2 && amount < 1000.0) {
               cout << "Insufficient amount, you need at least 1000.00 Galactic units to open a premium account" << endl;
               continue;
            }
            int currentIndex = Account::getNumberAccounts();
            if (choice == 1) {
                accountArr[currentIndex] = new RegularAccount(name, amount, date);
                cout << "Account created: " << endl;
                accountArr[currentIndex]->print();
            } else {
                accountArr[currentIndex] = new PremiumAccount(name, amount, date);
                cout << "Account created: \n";
                accountArr[currentIndex]->print();
            }
         //if depositing or withdrawing from an account
        } else if (choice == 3 || choice == 4) {
            cout << "Enter account number: ";
            cin >> accountNum;
            bool found = false;
            bool result;
            for (int i = 0; i < MAX_NUM_ACCOUNTS; i++) {
                if (accountArr[i] && accountArr[i]->getAccountNumber() == accountNum) {
                    found = true;
                    cin.ignore();
                    date = getDate();
                    amount = amountSetter();
                    if (amount < 0) {
                    if (choice == 3) {
                     cout << "Amount cannot be negative, deposit not executed" << endl;
                  } else {
                     cout << "Amount cannot be negative, withdraw not executed" << endl;
                  }
                  continue;
                  }
                    if (choice == 3) {
                        result = accountArr[i]->deposit(amount, date);
                    } else {
                        result = accountArr[i]->withdraw(amount, date);
                    }
                    if (result && choice == 3) {
                        cout << "Deposit executed: " << endl;
                        accountArr[i]->print();
                    } else if (result && choice == 4) {
                        cout << "Withdraw executed: " << endl;
                        accountArr[i]->print();
                    } else {
                        if (choice == 4) {
                           cout << "Insufficient balance, withdrawal not executed" << endl;
                        } else {
                           cout << "Error: Transaction could not be completed." << endl;
                        }
                    }
                    break;
                }
            }
            if (!found) {
                    cout << "No such account" << endl;
                }
         //print actions, extra credit work
        } else if (choice == 5) {
            cout << "Accounts" << endl;
            cout << "========" << endl << endl;
            //function to go through each account and print all of their actions before going to the next
            for (int i = 0; i < MAX_NUM_ACCOUNTS; i++) {
                   if (accountArr[i]) {
                        accountArr[i] -> print();
                        cout << "Transaction history:" << endl;
                        cout << "-------------------" << endl;
                        accountArr[i] -> printTransactions();
                        if (i < MAX_NUM_ACCOUNTS - 1) {
                           cout << endl;
                        }
                   }
                    
            }
         //exit program
        } else if (choice == 6) {
            //cout << "exiting program" << endl;
            return 0;
        } else {
            cout << "Invalid input" << endl;
        }
    }
}
//function for printing the menu. made so that its easier to look at main
void printMenu() {
    cout << "\n1->Create regular accnt, 2->Create premium accnt, 3->Deposit to accnt\n";
    cout << "4->Withdraw from accnt, 5->Print info accnts, 6->Quit\n";
}

//function for getting the amount, less redundancy
double amountSetter() {
    double amount;
    cout << "Enter amount: ";
    cin >> amount;
    return amount;
}

//function for getting the date, less redundancy
Date getDate() {
    int m, d, y, h;
    string dateHolder;
    Date date;
    char sl1, sl2, sl3;
    cout << "Enter date, in the mm/dd/yyyy/hh format: ";
    getline(cin, dateHolder);
        istringstream iss(dateHolder);
        iss >> m >> sl1 >> d >> sl2 >> y >> sl3 >> h;
        if (sl1 != '/' || sl2 != '/' || sl3 != '/') {
           cout << "Invalid date format";
           return getDate();
        }
        date.set(m, d, y, h);
    return date;
}
