// Matthew Manacio
// CPSC 3200: OOD
// Dr. Milkowski
// 10/10/21
// Last Updated: 10/22/21


/* interface invar:
 * - isStocked() goes through each entree for match
 * - sizeOfVendor and stockList should be positive ints
 * - Vendor(int) param ctor made for easier loading of entrees which one can utilize load() and effectively checks for dupes
 * class invar:
 * - powerOutage() calls entree's powerOutage() mehthod for each entree
 * - state of entree does not actively update; meaning attributes are updated when and only when cleanStock() or powerOutage()
 * is called
 */

#ifndef VENDOR_H
#define VENDOR_H
#include <iostream>
#include "entree.h"
#include "customer.h"
using namespace std;

class Vendor {
private:
int sizeOfVendor;
Entree * entreeList;
int * stockList;
int vID;

public:
Vendor();
Vendor (int);
Vendor (int, Entree*, int*, int);
~Vendor();
Vendor (const Vendor &);
Vendor &operator=(const Vendor &);
Vendor(Vendor &&);
Vendor& operator=(Vendor &&);

//Pre: positive int and vaild entree must be passed
//Post: stockList respective to entree increases by passed int
// entreeList updated if entree passed does not exists within list already
bool load(int, Entree);

//Pre: vaild entree and customer obj's must be passed
//Post: stockList respective to entree decreases by one
// entreeList updated if entree passed does not exists within list already
bool sell(Customer&, Entree);

//Pre: none
//Post: none (see Entree's powerOutage() method)
void powerOutage();

//Pre: vendor is not empty
//Post: entrees will be removed from vendor if spoiled or expired
string * cleanStock();

//Pre: valid Entree obj passed
//Post: none
bool isStocked(Entree);

int getID();

};

/* implementation invar:
 * - variables are private for encapsulation of attributes
 * - isStocked(), sell(), and load() uses name strings for matching, could be easier if ID was implemeted
 * - entreeList and stockList are directly related to each other, meaning that the indices for each are representative
 * for each other. i.e entreeList[0] which holds an Entree object has a quantity of stockList[0] which holds an int
 */

#endif
