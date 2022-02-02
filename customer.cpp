// Matthew Manacio
// CPSC 3200: OOD
// Dr. Milkowski
// 10/10/21
// Last Updated: 10/22/21

#include "customer.h"
#include <iostream>
#include <cstring>
using namespace std;

Customer::Customer() {
        accountNum = -1;
        balance = 0.0;
}

Customer::Customer(int accountNum, float balance) {
        this->accountNum = accountNum;
        this->balance = balance;
}

bool Customer::deposit(float deposit) {
        if (deposit > 0) {
                balance += deposit;
                return true;
        }
        return false;
}

bool Customer::buyItem(float costOfItem) {
        if(costOfItem >= 0) {
                if(balance - costOfItem >= 0) {
                        balance -= costOfItem;
                        return true;
                }
        }
        return false;
}


int Customer::getAccountNum() {
        return accountNum;
}
float Customer::getBalance() {
        return balance;
}
