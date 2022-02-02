// Matthew Manacio
// CPSC 3200: OOD
// Dr. Milkowski
// 10/10/21
// Last Updated: 10/22/21

/* interface invar:
 * - buyItem() kept abstract, only utilizes the cost
 * class invar:
 * - negative deposits are caught and will return false in deposit()
 * - customer cannot buy item that are greater in price than their balance
 */

#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
using namespace std;

class Customer {
private:
float balance;
int accountNum;

public:
Customer();
Customer(int, float);

//Pre: positive float is passed
//Post: balance will increase by passed float
bool deposit(float);

//Pre: positive float is passed
//Post: balance will decrease by passed float
bool buyItem(float);

int getAccountNum();
float getBalance();

};

/* implementation invar:
 * - variables are private for encapsulation of attributes that could potentially set state unstable
 * - balances and account #'s can be negative
 */

#endif
