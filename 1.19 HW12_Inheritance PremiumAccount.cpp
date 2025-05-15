#include "PremiumAccount.h"
#include <iostream>
#include <iomanip>
using namespace std;

const double PremiumAccount::MIN_BALANCE = 1000.0;

PremiumAccount::PremiumAccount(string name, double amount, Date d)
    : Account(name, amount, d) {}
    
bool PremiumAccount::withdraw(double amount, Date d) {
    if(balance - amount >= MIN_BALANCE) {
        balance -= amount;
        //recording withdrawal, i kept getting errors because i forgot to add this to this function
        Transaction t;
        t.date = d;
        t.transactionType = 2;
        t.amount = amount;
        recordTransaction(t);
        return true;
    }
    return false;
}

double PremiumAccount::getMinBalance() {
    return MIN_BALANCE;
}

void PremiumAccount::print() const{
    cout << "Premium account, #: ";
    Account::print();
}
