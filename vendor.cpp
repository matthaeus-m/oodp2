// Matthew Manacio
// CPSC 3200: OOD
// Dr. Milkowski
// 10/10/21
// Last Updated: 10/17/21

#include "vendor.h"
#include "entree.h"
#include "customer.h"
#include <iostream>
#include <ctime>
#include <cstring>
using namespace std;

Vendor::Vendor() {
        sizeOfVendor = -1;
        entreeList = nullptr;
        stockList = nullptr;
        vID = -1;
}

Vendor::Vendor(int id) {
        sizeOfVendor = 0;
        entreeList = nullptr;
        stockList = nullptr;
        vID = id;
}

Vendor::Vendor(int size, Entree * entrees, int * stocks, int vID) {
        sizeOfVendor = size;
        this->vID = vID;
        this->entreeList = new Entree[sizeOfVendor];
        this->stockList = new int[sizeOfVendor];
        for(int i = 0; i < sizeOfVendor; i++) {
                this->entreeList[i] = entrees[i];
                this->stockList[i] = stocks[i];
        }
}

Vendor::~Vendor() {
        delete[] entreeList;
        delete[] stockList;
}


Vendor::Vendor(const Vendor & obj) {
        sizeOfVendor = obj.sizeOfVendor;
        vID = obj.vID;
        entreeList = new Entree[sizeOfVendor];
        stockList = new int[sizeOfVendor];

        for(int i = 0; i < sizeOfVendor; i++) {
                entreeList[i] = obj.entreeList[i];
                stockList[i] = obj.stockList[i];
        }
}


Vendor &Vendor::operator=(const Vendor & obj) {
        if(this != &obj) {
                delete[] entreeList;
                delete[] stockList;

                sizeOfVendor = obj.sizeOfVendor;
                vID = obj.vID;
                entreeList = new Entree[sizeOfVendor];
                stockList = new int[sizeOfVendor];

                for(int i = 0; i < sizeOfVendor; i++) {
                        entreeList[i] = obj.entreeList[i];
                        stockList[i] = obj.stockList[i];
                }
        }
        return *this;
}

Vendor::Vendor(Vendor && obj) {
        sizeOfVendor = obj.sizeOfVendor;
        vID = obj.vID;
        entreeList = new Entree[sizeOfVendor];
        stockList = new int[sizeOfVendor];
        for(int i = 0; i < sizeOfVendor; i++) {
                entreeList[i] = obj.entreeList[i];
                stockList[i] = obj.stockList[i];
        }

        obj.sizeOfVendor = -1;
        obj.entreeList = nullptr;
        obj.stockList = nullptr;
        obj.vID = -1;
}

Vendor &Vendor::operator=(Vendor &&obj) {
        swap(sizeOfVendor, obj.sizeOfVendor);
        swap(entreeList, obj.entreeList);
        swap(stockList, obj.stockList);
        swap(vID, obj.vID);
        return *this;
}


bool Vendor::isStocked(Entree entree) {
        for(int i = 0; i < sizeOfVendor; i++) {
                if(entreeList[i].getName() == entree.getName() && stockList[i] > 0) {
                        return true;
                }
        }
        return false;
}


bool Vendor::load(int quantity, Entree entree) {

        for(int i = 0; i < sizeOfVendor; i++) {
                if(entreeList[i].getName() == entree.getName()) {
                        stockList[i] += quantity;
                        return true;
                }
        }

        sizeOfVendor++;
        Entree * temp = new Entree[sizeOfVendor];
        int * stokTemp = new int[sizeOfVendor];
        for(int i = 0; i < sizeOfVendor - 1; i++) {
                temp[i] = entreeList[i];
                stokTemp[i] = stockList[i];
        }

        temp[sizeOfVendor - 1] = entree;
        stokTemp[sizeOfVendor - 1] = quantity;

        delete[] entreeList;
        delete[] stockList;

        entreeList = temp;
        stockList = stokTemp;

        return isStocked(entree);

}


bool Vendor::sell(Customer& customer, Entree entree) {
        for(int i = 0; i < sizeOfVendor; i++) {
                if(entreeList[i].getName() == entree.getName()) {
                        if(customer.getBalance() < entree.getPrice()) {
                                return false;
                        }
                        customer.buyItem(entree.getPrice());
                        stockList[i]--;
                        return true;
                }
        }
        return false;
}

string * Vendor::cleanStock() {
        string * spoilList;
        int spoilCount = 0;
        for(int i = 0; i < sizeOfVendor; i++) {
                if(entreeList[i].isSpoiled() || entreeList[i].isExpired()) {
                        stockList[i] = 0;
                        spoilCount++;
                }
        }
        spoilList = new string[spoilCount + 1];
        spoilList[0] = to_string(spoilCount);

        int index = 1;
        for(int i = 0; i < sizeOfVendor; i++) {
                // if(entreeList[i].isSpoiled() || entreeList[i].isExpired()) {
                //         spoilList[index] = entreeList[i].getName();
                //         index++;
                // }
                if(stockList[i] == 0) {
                        spoilList[index] = entreeList[i].getName();
                        index++;
                }
        }
        return spoilList;
}


void Vendor::powerOutage() {
        for(int i = 0; i < sizeOfVendor; i++) {
                entreeList[i].powerOutage();
        }
}

int Vendor::getID(){
        return vID;
}
