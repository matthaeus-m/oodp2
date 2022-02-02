// Matthew Manacio
// CPSC 3200: OOD
// Dr. Milkowski
// 10/10/21
// Last Updated: 10/22/21

/* Overview:
 * - program creates vectors of customers, vendors, and entrees
 * - entrees are added to vendors, which customers can then buy from
 * - customers can specify which entree to buy, which the vendor checks if that entree is in stock
 * - if in stock, customer pays vendor $x and their balance will reflect that purchase
 * - can also be queried to release nutrional info and attributes
 * assumptions:
 * - read-in file is formatted as a .csv file (see EntreesFile.csv)
 * - csv file in the same directory as this file
 * - all entrees have the same expirationDate when read in
 */

#include "vendor.h"
#include "customer.h"
#include "entree.h"
#include <iostream>
#include <vector>
#include <memory>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <sstream>

using namespace std;

const unsigned int VENDOR_VEC_SIZE = 10;
const unsigned int RAND_LOW_ENTRE = 1;
const unsigned int RAND_HIGH_ENTRE = 10;
const unsigned int RAND_HIGH_STOCK = 50;
const unsigned int RAND_LOW_STOCK = 10;

const unsigned int RAND_LOW_ENTRE_SELC = 1;
const unsigned int RAND_HIGH_ENTRE_SELC = 4;

const int RAND_HIGH_ACC = 9999;
const int RAND_LOW_ACC = 1000;
const int RAND_HIGH_BAL = 500;
const int RAND_LOW_BAL = 1;



void initEntree(vector<Entree> & entrees);
void loadVendorWEntre(int numOfEntre, unique_ptr<Vendor> & vendor, vector<Entree> entrerVec);
void initVendor(vector<unique_ptr<Vendor> > & uniVendorV, vector<Entree> entrerVec);
int randNumber(int high, int low);
void initCustomerVec(vector<Customer>& custs);
void testAll(vector<Customer>& customers, vector<unique_ptr<Vendor> > & uniVendorV, vector<Entree> entrees);
void testSharedPtrObj(Customer& customers, shared_ptr<Vendor> shrdPtr, vector<Entree> entrees);

int main() {
        srand(time(0));
        vector<Entree> entreeListt;
        shared_ptr<Vendor> sharedPtrVendor;
        vector<unique_ptr<Vendor> > uniqVendorVec;
        vector<Customer> customerVec;


        initCustomerVec(customerVec);

        initEntree(entreeListt);

        initVendor(uniqVendorVec, entreeListt);

        for(int i = 0; i < 3; i++) {
                testAll(customerVec, uniqVendorVec, entreeListt);
        }

        for(unsigned int i = 0; i < VENDOR_VEC_SIZE; i++) {
                sharedPtrVendor = move(uniqVendorVec[i]);
                if(!uniqVendorVec[i]) {
                        cout << endl << " ~~~~~Ownership has been changed.~~~~~" << endl << endl;
                        testSharedPtrObj(customerVec[i], sharedPtrVendor, entreeListt);
                }
        }

        shared_ptr<Vendor> secondShrPtrVendor = sharedPtrVendor;
        cout << "total reference count for shared ptr: " << sharedPtrVendor.use_count() << endl;

        return 0;
}


void initEntree(vector<Entree> & entrees) {
        string line;
        bool firstLine = false;
        ifstream csvFile;
        csvFile.open("EntreesFile.csv");
        int sepR;
        string nameF;
        float numOfServF;
        float calF;
        float totFatF;
        float satFatF;
        float transFatF;
        float cholestF;
        float sodF;
        float totCarbF;
        float fiberF;
        float totSugF;
        float protF;
        string ingreF;
        int ingredSize;
        string * ingreL;
        string contF;
        int contSize;
        string * contL;
        string expDateF;
        int refrigF;
        bool refrigB;
        int inFridgF;
        bool inFridgB;
        float priceF;


        if (csvFile)
        {
                while (getline(csvFile, line))
                {
                        if (!firstLine)
                        {
                                firstLine = true;
                        }

                        else
                        {
                                sepR = line.find_first_of(",");
                                nameF = line.substr(0, sepR);
                                line.erase(0, sepR + 1);



                                // num of serv float
                                sepR = line.find_first_of(",");
                                numOfServF = stof(line.substr(0, sepR));
                                line.erase(0, sepR + 1);


                                // cal float
                                sepR = line.find_first_of(",");
                                calF = stof(line.substr(0, sepR));
                                line.erase(0, sepR + 1);

                                // tot fat float
                                sepR = line.find_first_of(",");
                                totFatF = stof(line.substr(0, sepR));
                                line.erase(0, sepR + 1);

                                //  sat fat float
                                sepR = line.find_first_of(",");
                                satFatF = stof(line.substr(0, sepR));
                                line.erase(0, sepR + 1);

                                // transfat float
                                sepR = line.find_first_of(",");
                                transFatF = stof(line.substr(0, sepR));
                                line.erase(0, sepR + 1);

                                // cholest float
                                sepR = line.find_first_of(",");
                                cholestF = stof(line.substr(0, sepR));
                                line.erase(0, sepR + 1);

                                // sod float
                                sepR = line.find_first_of(",");
                                sodF = stof(line.substr(0, sepR));
                                line.erase(0, sepR + 1);

                                // toit carb float
                                sepR = line.find_first_of(",");
                                totCarbF = stof(line.substr(0, sepR));
                                line.erase(0, sepR + 1);

                                // fiber float
                                sepR = line.find_first_of(",");
                                fiberF = stof(line.substr(0, sepR));
                                line.erase(0, sepR + 1);

                                // tot sugar float
                                sepR = line.find_first_of(",");
                                totSugF = stof(line.substr(0, sepR));
                                line.erase(0, sepR + 1);

                                // protein float
                                sepR = line.find_first_of(",");
                                protF = stof(line.substr(0, sepR));
                                line.erase(0, sepR + 1);

                                // ingre string list
                                sepR = line.find_first_of(",");
                                ingreF = line.substr(0, sepR);
                                line.erase(0, sepR + 1);

                                if(ingreF.length() == 0) {
                                        ingredSize = 0;
                                } else {
                                        ingredSize = 1;
                                }
                                for(long unsigned int i = 0; i < ingreF.length(); i++) {
                                        if(ingreF[i] == '$') {
                                                ingredSize++;
                                        }
                                }
                                ingreL = new string[ingredSize];
                                string temp;
                                for(int i = 0; i < ingredSize; i++) {
                                        sepR = ingreF.find_first_of("$");
                                        temp = ingreF.substr(0, sepR);
                                        ingreF.erase(0, sepR + 1);
                                        ingreL[i] = temp;
                                }




                                // contians stirng list
                                sepR = line.find_first_of(",");
                                contF = line.substr(0, sepR);
                                line.erase(0, sepR + 1);


                                if(contF.length() == 0) {
                                        contSize = 0;
                                } else {
                                        contSize = 1;
                                }

                                for(long unsigned int i = 0; i < contF.length(); i++) {
                                        if(contF[i] == '$') {
                                                contSize++;
                                        }
                                }
                                contL = new string[contSize];
                                string temp2;
                                for(int i = 0; i < contSize; i++) {
                                        sepR = contF.find_first_of("$");
                                        temp2 = contF.substr(0, sepR);
                                        contF.erase(0, sepR + 1);
                                        contL[i] = temp2;
                                }




                                // exp date string
                                sepR = line.find_first_of(",");
                                expDateF = line.substr(0, sepR);
                                line.erase(0, sepR + 1);

                                // req refrig bool (int to bool) 0 -> false
                                sepR = line.find_first_of(",");
                                refrigF = stoi(line.substr(0, sepR));
                                line.erase(0, sepR + 1);
                                refrigB = refrigF != 0;

                                // in fridge bool (int to bool)
                                sepR = line.find_first_of(",");
                                inFridgF = stoi(line.substr(0, sepR));
                                line.erase(0, sepR + 1);
                                inFridgB = inFridgF != 0;

                                // price float
                                sepR = line.find_first_of(",");
                                priceF = stof(line.substr(0, sepR));
                                line.erase(0, sepR + 1);




                                Entree entreTemp(
                                        nameF,
                                        refrigB,
                                        inFridgB,
                                        expDateF,
                                        numOfServF,
                                        calF,
                                        totFatF,
                                        satFatF,
                                        transFatF,
                                        cholestF,
                                        sodF,
                                        totCarbF,
                                        fiberF,
                                        totSugF,
                                        protF,
                                        contL,
                                        ingreL,
                                        contSize,
                                        ingredSize,
                                        priceF
                                        );
                                delete[] ingreL;
                                delete[] contL;

                                entrees.push_back(entreTemp);
                        }
                }
        }

        else
        {
                cout << "Error: file cannot be opened and read" << endl;
        }
}


void initVendor(vector<unique_ptr<Vendor> > & uniVendorV, vector<Entree> entrerVec) {
        for(unsigned int i = 0; i < VENDOR_VEC_SIZE; i++) {
                int numOfEntre = randNumber(RAND_HIGH_ENTRE, RAND_LOW_ENTRE);
                // stockList = randIntList(randSize);
                // entreList = randEntreList(randSize, entrerVec);
                // vID = i;
                // unique_ptr<Vendor> oneUniPtr(new Vendor(randSize, entreList, stockList, vID));
                unique_ptr<Vendor> oneUniPtr(new Vendor(i));
                loadVendorWEntre(numOfEntre, oneUniPtr, entrerVec);
                // make a func here and pass in the unique ptr and load the vendor
                uniVendorV.push_back(move(oneUniPtr));
        }
}

void loadVendorWEntre(int numOfEntre, unique_ptr<Vendor> & vendor, vector<Entree> entrerVec) {
        for(int i = 0; i < numOfEntre; i++) {
                int randIndOfEntre = randNumber(RAND_HIGH_ENTRE_SELC, RAND_LOW_ENTRE_SELC);
                int randQuan = randNumber(RAND_HIGH_STOCK, RAND_LOW_STOCK);
                vendor->load(randQuan, entrerVec[randIndOfEntre]);
        }
}


int randNumber(int high, int low) {
        return rand() % high + low;
}

void initCustomerVec(vector<Customer> & custs) {
        int randAccNum;
        float randBalance;
        for(unsigned int i = 0; i < VENDOR_VEC_SIZE; i++) {
                randAccNum = randNumber(RAND_HIGH_ACC, RAND_LOW_ACC);
                randBalance = float(randNumber(RAND_HIGH_BAL, RAND_LOW_BAL));
                Customer temp(randAccNum, 0);
                temp.deposit(randBalance);
                custs.push_back(temp);
        }
}

void testAll(vector<Customer> &customers, vector<unique_ptr<Vendor> > & uniVendorV, vector<Entree> entrees) {
        for(unsigned int i = 0; i < VENDOR_VEC_SIZE; i++) {
                // int randCust = randNumber(RAND_HIGH_ENTRE, RAND_LOW_ENTRE);
                int randEntree = randNumber(RAND_HIGH_ENTRE, RAND_LOW_ENTRE-1);
                cout << "Customer acc num " << customers[i].getAccountNum() << " is buying "
                     << entrees[randEntree].getName() << " from vendor " << uniVendorV[i]->getID() << " which costs " << entrees[randEntree].getPrice() << " and has " << customers[i].getBalance() << " dollars." << endl;

                bool sold = uniVendorV[i]->sell(customers[i], entrees[randEntree]);
                if(sold) {
                        cout << "Customer acc num " << customers[i].getAccountNum() << " bought one "
                             << entrees[randEntree].getName() << " and has " << customers[i].getBalance() << " dollars left" << endl << endl;
                } else if(entrees[randEntree].getPrice() > customers[i].getBalance()) {
                        cout << "Customer has invalid funds" << endl << endl;
                }
                else{
                        cout << "Vendor does not hold this entree" << endl << endl;
                }
        }
        cout << endl << "Power outage occured, all vending machines have no power" << endl;

        for(unsigned int i = 0; i < VENDOR_VEC_SIZE; i++) {
                uniVendorV[i]->powerOutage();
                cout << endl << "cleaning out vendor " << i << endl << endl;
                string * cleanedArray = uniVendorV[i]->cleanStock();
                int sizeClean = stoi(cleanedArray[0]);
                for (int i = 1; i <= sizeClean; i++) {
                        cout << cleanedArray[i] << " was cleaned out" << endl;
                }
                cout << endl;
        }


        // for(unsigned int i = 0; i < VENDOR_VEC_SIZE; i++) {
        //         uniVendorV[i]->cleanStock();
        // }

        int randEntreeInd = randNumber(RAND_HIGH_ENTRE, RAND_LOW_ENTRE-1);
        for (unsigned int i = 0; i < VENDOR_VEC_SIZE; i++) {
                if(uniVendorV[i]->isStocked(entrees[randEntreeInd])) {
                        cout << "Vendor " << uniVendorV[i]->getID() << " holds " << entrees[randEntreeInd].getName() << endl;
                }
                else{
                        cout << "Vendor " << uniVendorV[i]->getID() << " does NOT hold " << entrees[randEntreeInd].getName() << endl;
                }

        }


        cout << endl << "loading vendors with random entrees" << endl << endl;

        for(unsigned int i = 0; i < VENDOR_VEC_SIZE; i++) {
                int randEntree = randNumber(RAND_HIGH_ENTRE, RAND_LOW_ENTRE-1);
                int randStock = randNumber(RAND_HIGH_STOCK, RAND_LOW_STOCK);
                cout << "vendor number " << i << " is being loaded with " << entrees[randEntree].getName() << " (" << randStock << ")." << endl;
                uniVendorV[i]->load(randStock, entrees[randEntree]);

        }
        cout << endl;

        for (unsigned int i = 0; i < VENDOR_VEC_SIZE; i++) {
                if(uniVendorV[i]->isStocked(entrees[randEntreeInd])) {
                        cout << "Vendor " << uniVendorV[i]->getID() << " holds " << entrees[randEntreeInd].getName() << endl;
                }
                else{
                        cout << "Vendor " << uniVendorV[i]->getID() << " does NOT hold " << entrees[randEntreeInd].getName() << endl;
                }

        }

        cout << endl;
        // int randEntree = randNumber(RAND_HIGH_ENTRE, RAND_LOW_ENTRE);
        // cout << entrees[randEntree].getName() << " has " << entrees[randEntree].getCalories() << " calorie(s)" << endl << endl;
}



void testSharedPtrObj(Customer& customers, shared_ptr<Vendor> shrdPtr, vector<Entree> entrees) {
        int randEntree = randNumber(RAND_HIGH_ENTRE, RAND_LOW_ENTRE-1);
        cout << "Customer acc num " << customers.getAccountNum() << " is buying "
             << entrees[randEntree].getName() << " from vendor " << shrdPtr->getID() << " which costs " << entrees[randEntree].getPrice() << " and has " << customers.getBalance() << " dollars." << endl;
        bool sold = shrdPtr->sell(customers, entrees[randEntree]);
        if(sold) {
                cout << "Customer acc num " << customers.getAccountNum() << " bought one "
                     << entrees[randEntree].getName() << " and has " << customers.getBalance() << " dollars left" << endl << endl;
        } else if(entrees[randEntree].getPrice() > customers.getBalance()) {
                cout << "Customer has invalid funds" << endl << endl;
        }
        else{
                cout << "Vendor does not hold this entree" << endl << endl;
        }


        cout << endl << "Power outage occured, all vending machines have no power" << endl;

        shrdPtr->powerOutage();

        // cleaned out entrees that are spoiled
        cout << endl << "cleaning out vendors" << endl << endl;
        string * cleanedArray = shrdPtr->cleanStock();
        int sizeClean = stoi(cleanedArray[0]);
        for (int i = 1; i <= sizeClean; i++) {
                cout << cleanedArray[i] << " was cleaned out" << endl;
        }
        cout << endl;



        int randEntreeInd = randNumber(RAND_HIGH_ENTRE, RAND_LOW_ENTRE-1);
        if(shrdPtr->isStocked(entrees[randEntreeInd])) {
                cout << "Vendor " << shrdPtr->getID() << " holds " << entrees[randEntreeInd].getName() << endl;
        }
        else{
                cout << "Vendor " << shrdPtr->getID() << " does NOT hold " << entrees[randEntreeInd].getName() << endl;
        }


        cout << endl << "loading vendors with random entrees" << endl << endl;

        randEntree = randNumber(RAND_HIGH_ENTRE, RAND_LOW_ENTRE-1);
        int randStock = randNumber(RAND_HIGH_STOCK, RAND_LOW_STOCK);
        cout << "sharedptr vendor is being loaded with " << entrees[randEntree].getName() << " (" << randStock << ")." << endl;
        shrdPtr->load(randStock, entrees[randEntree]);

        if(shrdPtr->isStocked(entrees[randEntreeInd])) {
                cout << "Vendor " << shrdPtr->getID() << " holds " << entrees[randEntreeInd].getName() << endl;
        }
        else{
                cout << "Vendor " << shrdPtr->getID() << " does NOT hold " << entrees[randEntreeInd].getName() << endl;
        }


}
