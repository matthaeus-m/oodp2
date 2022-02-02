// Matthew Manacio
// CPSC 3200: OOD
// Dr. Milkowski
// 10/10/21
// Last Updated: 10/22/21

#include "entree.h"
#include <iostream>
#include <ctime>
#include <cstring>
using namespace std;

const int HRS_UNTIL_SPOIL = 4;

Entree::Entree()
{
        name = "";
        refrigeration = false;
        inFridge = false;
        expirationDate = "";
        spoiled = false;
        expired = false;
        numServings = 0;
        calories = 0;
        totalFat = 0;
        satFat = 0;
        transFat = 0;
        cholesterol = 0;
        sodium = 0;
        fiber = 0;
        totSugars = 0;
        protein = 0;
        contains = nullptr;
        ingredients = nullptr;
        containsSize = 0;
        ingredSize = 0;
        price = 0;
}

Entree::Entree(string name, bool refrigeration, bool inFridge, string expirationDate,
               float numServings,float calories, float totalFat, float satFat, float transFat, float cholesterol, float sodium,
               float totCarb, float fiber, float totSugars, float protein, string* contains, string* ingredients, int containsSize, int ingredSize, float price)
{
        this->name = name;
        this->refrigeration = refrigeration;
        this->inFridge = inFridge;
        this->expirationDate = expirationDate;

        this->spoiled = false;
        this->expired = false;


        if (numServings < 0)
        {
                numServings *= -1;
        }
        this->numServings = numServings;


        if (calories < 0)
        {
                calories *= -1;
        }
        this->calories = calories;


        if (totalFat < 0)
        {
                totalFat *= -1;
        }
        this->totalFat = totalFat;


        if (satFat < 0)
        {
                satFat *= -1;
        }
        this->satFat = satFat;


        if (transFat < 0)
        {
                transFat *= -1;
        }
        this->transFat = transFat;


        if (cholesterol < 0)
        {
                cholesterol *= -1;
        }
        this->cholesterol = cholesterol;


        if (sodium < 0)
        {
                sodium *= -1;
        }
        this->sodium = sodium;


        if (totCarb < 0)
        {
                totCarb *= -1;
        }
        this->totCarb = totCarb;


        if (fiber < 0)
        {
                fiber *= -1;
        }
        this->fiber = fiber;


        if (totSugars < 0)
        {
                totSugars *= -1;
        }
        this->totSugars = totSugars;


        if (protein < 0)
        {
                protein *= -1;
        }
        this->protein = protein;

        // all if statements should be like this, we are not replacing the this-> attribute
        if (price < 0)
        {
                price *= -1;
        }
        this->price = price;



        this->containsSize = containsSize;
        this->ingredSize = ingredSize;

        this->contains = new string[containsSize];

        for(int i = 0; i < containsSize; i++)
        {
                this->contains[i] = contains [i];
        }


        this->ingredients = new string[ingredSize];
        for(int i = 0; i < ingredSize; i++)
        {
                this->ingredients[i] = ingredients [i];
        }


}

Entree::~Entree()
{
        delete[] contains;
        delete[] ingredients;
}

Entree &Entree::operator=(const Entree &obj)
{
        if(this != &obj)
        {
                name = obj.name;
                refrigeration = obj.refrigeration;
                inFridge = obj.inFridge;
                expirationDate = obj.expirationDate;
                spoiled = obj.spoiled;
                expired = obj.expired;
                numServings = obj.numServings;
                calories = obj.calories;
                totalFat = obj.totalFat;
                satFat = obj.satFat;
                transFat = obj.transFat;
                cholesterol = obj.cholesterol;
                sodium = obj.sodium;
                fiber = obj.fiber;
                totSugars = obj.totSugars;
                protein = obj.protein;
                containsSize = obj.containsSize;
                ingredSize = obj.ingredSize;
                price = obj.price;

                delete[] contains;
                contains = new string[containsSize];
                for (int i = 0; i < containsSize; i++)
                {
                        contains[i] = obj.contains[i];
                }

                delete[] ingredients;
                ingredients = new string[ingredSize];
                for (int i = 0; i < ingredSize; i++)
                {
                        ingredients[i] = obj.ingredients[i];
                }
        }
        return *this;
}

Entree::Entree(const Entree &obj)
{
        name = obj.name;
        refrigeration = obj.refrigeration;
        inFridge = obj.inFridge;
        expirationDate = obj.expirationDate;
        spoiled = obj.spoiled;
        expired = obj.expired;
        numServings = obj.numServings;
        calories = obj.calories;
        totalFat = obj.totalFat;
        satFat = obj.satFat;
        transFat = obj.transFat;
        cholesterol = obj.cholesterol;
        sodium = obj.sodium;
        fiber = obj.fiber;
        totSugars = obj.totSugars;
        protein = obj.protein;
        containsSize = obj.containsSize;
        ingredSize = obj.ingredSize;
        price = obj.price;

        contains = new string[containsSize];
        for (int i = 0; i < containsSize; i++)
        {
                contains[i] = obj.contains[i];
        }

        ingredients = new string[ingredSize];
        for (int i = 0; i < ingredSize; i++)
        {
                ingredients[i] = obj.ingredients[i];
        }
}

Entree::Entree(Entree &&obj)
{
        name = obj.name;
        refrigeration = obj.refrigeration;
        inFridge = obj.inFridge;
        expirationDate = obj.expirationDate;
        spoiled = obj.spoiled;
        expired = obj.expired;
        numServings = obj.numServings;
        calories = obj.calories;
        totalFat = obj.totalFat;
        satFat = obj.satFat;
        transFat = obj.transFat;
        cholesterol = obj.cholesterol;
        sodium = obj.sodium;
        fiber = obj.fiber;
        totSugars = obj.totSugars;
        protein = obj.protein;
        containsSize = obj.containsSize;
        ingredSize = obj.ingredSize;
        price = obj.price;

        contains = new string[containsSize];
        for (int i = 0; i < containsSize; i++)
        {
                contains[i] = obj.contains[i];
        }

        ingredients = new string[ingredSize];
        for (int i = 0; i < ingredSize; i++)
        {
                ingredients[i] = obj.ingredients[i];
        }

        obj.name = "";
        obj.refrigeration = 0;
        obj.inFridge = false;
        obj.expirationDate = "";
        obj.spoiled = false;
        obj.expired = false;
        obj.numServings = 0;
        obj.calories = 0;
        obj.totalFat = 0;
        obj.satFat = 0;
        obj.transFat = 0;
        obj.cholesterol = 0;
        obj.sodium = 0;
        obj.fiber = 0;
        obj.totSugars = 0;
        obj.protein = 0;
        obj.contains = nullptr;
        obj.ingredients = nullptr;
        obj.containsSize = 0;
        obj.ingredSize = 0;
        obj.price = 0;
}

Entree &Entree::operator=(Entree &&obj)
{
        swap(name, obj.name);
        swap(refrigeration, obj.refrigeration);
        swap(inFridge, obj.inFridge);
        swap(expirationDate, obj.expirationDate);
        swap(spoiled, obj.spoiled);
        swap(expired, obj.expired);
        swap(numServings, obj.numServings);
        swap(calories, obj.calories);
        swap(totalFat, obj.totalFat);
        swap(satFat, obj.satFat);
        swap(transFat, obj.transFat);
        swap(cholesterol, obj.cholesterol);
        swap(sodium, obj.sodium);
        swap(fiber, obj.fiber);
        swap(totSugars, obj.totSugars);
        swap(protein, obj.protein);
        swap(containsSize, obj.containsSize);
        swap(ingredSize, obj.ingredSize);
        swap(contains, obj.contains);
        swap(ingredients, obj.ingredients);
        swap(price, obj.price);

        return *this;
}

char* Entree::time_to_char_array()
{
        time_t now = time(0);
        tm *ltm = localtime(&now);
        string month;
        string day;

        if(to_string(ltm->tm_mon + 1).length() < 1) {
                month = "0" + to_string(ltm->tm_mon + 1);
        }

        if(to_string(ltm->tm_mday).length() < 1) {
                day = "0" + to_string(ltm->tm_mon + 1);
        }

        string finDate = to_string(ltm->tm_year + 1900) + "/" + month + "/" + day;

        int x = finDate.length();
        char *finDate_array = new char [x+1];

        return strcpy(finDate_array, finDate.c_str());
}

bool Entree::isExpired()
{
        int n = expirationDate.length();
        char *expDate_array = new char [n+1];
        strcpy(expDate_array, expirationDate.c_str());

        char* now_array = time_to_char_array();

        if (strcmp(expDate_array, now_array) < 0)
        {
                expired = true;
        }
        return expired;
}

bool Entree::isSpoiled()
{
        if ((refrigeration && !inFridge) || isExpired()) // hrs until spoil might change
        {
                spoiled = true;
        }
        return spoiled;
}

bool Entree::doesContain(string query)
{
        for (long unsigned int i = 0; i < query.length(); i++)
        {
                query[i] = tolower(query[i]);
        }

        for (int i = 0; i < ingredSize; i++)
        {
                string ingredLower;
                for (long unsigned int j = 0; j < ingredients[i].length(); i++)
                {
                        ingredLower[j] = tolower(ingredients[i][j]);
                }

                if (ingredLower == query)
                {
                        return true;
                }
        }


        for (int i = 0; i < containsSize; i++)
        {
                string containsLower;
                for (long unsigned int j = 0; j < contains[i].length(); i++)
                {
                        containsLower[j] = tolower(contains[i][j]);
                }

                if (containsLower == query)
                {
                        return true;
                }
        }
        return false;
}

void Entree::powerOutage() {
        if(refrigeration) {
                spoiled = true;
        }
        isSpoiled();
}

float Entree::getServings()
{
        return numServings;
}
float Entree::getCalories()
{
        return calories;
}
float Entree::getTotFat()
{
        return totalFat;
}
float Entree::getSatFat()
{
        return satFat;
}
float Entree::getTransFat()
{
        return transFat;
}
float Entree::getCholest()
{
        return cholesterol;
}
float Entree::getSod()
{
        return sodium;
}
float Entree::getTotCarb()
{
        return totCarb;
}
float Entree::getFiber()
{
        return fiber;
}
float Entree::getTotSugars()
{
        return totSugars;
}
float Entree::getProtein()
{
        return protein;
}
string Entree::getName()
{
        return name;
}
string Entree::getExpDate()
{
        return expirationDate;
}

string* Entree::getIngreds()
{
        return ingredients;
}
string* Entree::getContains()
{
        return contains;
}

float Entree::getPrice() {
        return price;
}
