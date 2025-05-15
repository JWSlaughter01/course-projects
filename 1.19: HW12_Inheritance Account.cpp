#include "Account.h"
#include <iostream>
#include <iomanip>
using namespace std;

int Account::numberAccounts = 0;

Account::Account(string name, double bal, Date d) {
    ownerName = name;
    balance = bal;
    accountNumber = numberAccounts + 1000;
    numberAccounts++;
    transactionHistory = nullptr;
    numberTransactions = 0;
    //cout << "Account created. Total accounts: " << Account::getNumberAccounts() << endl;
    
    //transaction stuff here
    Transaction t;
    t.date = d;
    t.transactionType = 0;
    t.amount = balance;
    recordTransaction(t);
}

bool Account::withdraw(double amount, Date d){
    if (amount <= balance) {
        balance -= amount;
        //recording withdraw action
        Transaction t;
        t.date = d;
        t.transactionType = 2;
        t.amount = amount;
        recordTransaction(t);
        return true;
    }
    return false;
}

bool Account::deposit(double amount, Date d){
    if (amount > 0) {
        balance += amount;
        //recording deposit action
        Transaction t;
        t.date = d;
        t.transactionType = 1;
        t.amount = amount;
        recordTransaction(t);
        return true;
    }
    return false;
}

int Account::getAccountNumber() const{
    return accountNumber;
}

double Account::getBalance() const{
    return balance;
}

int Account::getNumberAccounts() {
    return numberAccounts;
}
//example below for expected output
//Date: June 5, 2100, 4:00, Amount: 8011.89, type: Creation, New balance: 8011.89
#ifdef EXTRA_CREDIT
void Account::printTransactions() const{
   double currentBal = 0.0; 
   //  cout << "Transaction history:" << endl;
   //  cout << "-------------------" << endl;
    for (int i = 0; i < numberTransactions; i++) {
       cout << "Date: ";
       transactionHistory[i].date.print();
       cout << ", Amount: " << fixed << setprecision(2) << transactionHistory[i].amount;
       cout << ", type: ";
       switch(transactionHistory[i].transactionType) {
         case 0:
            cout << "Creation";
            currentBal = transactionHistory[i].amount;
            break;
         case 1:
            cout << "Deposit";
            currentBal += transactionHistory[i].amount;
            break;
         case 2:
            cout << "Withdrawal";
            currentBal -= transactionHistory[i].amount;
            break;
         default:
         break;
      }
      cout << ", New balance: " << currentBal << endl;
    }
    
    
}

#endif
void Account::print() const{
    cout << accountNumber;
    cout << ", Name: " << ownerName;
    cout << ", Balance: " << fixed << setprecision(2) << balance;
    cout << " Galactic units" << endl;
}

/* This function takes as argument a Transaction structure variable and
adds it to the transaction history. The transaction history
is implemented as an array of Transactions. A new array is dynamically allocated, 
of size equal to (size of old array) + 1, to hold the added transaction.
The values of the old array are copied into the new array, 
and the transaction to be added is copied into the last element of the new array. 
The old array is released through delete. The address returned from dynamic array allocation is assigned  to transactionHistory.
*/
void Account::recordTransaction(Transaction t)
{
   // Function body
   Transaction* temp = new Transaction[numberTransactions + 1];
   
   for (int i = 0; i < numberTransactions; i++) {
      temp[i] = transactionHistory[i];
   }
   
   temp[numberTransactions] = t;
   delete[] transactionHistory;
   
   transactionHistory = temp;
   
   numberTransactions++;

}
