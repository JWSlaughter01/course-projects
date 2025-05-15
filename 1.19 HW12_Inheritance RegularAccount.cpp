#include "RegularAccount.h"
#include <iostream>
#include <iomanip>
using namespace std;

RegularAccount::RegularAccount(string name, double amount, Date d)
    : Account(name, amount, d) {}
    
void RegularAccount::print() const {
    cout << "Regular account, #: ";
    Account::print();
}
