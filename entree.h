// Matthew Manacio
// CPSC 3200: OOD
// Dr. Milkowski
// 10/10/21
// Last Updated: 10/22/21

/* interface invar:
 * - doesContain() takes in a string and searches "contains" and "ingredients" arrays for match
 * class invar:
 * - negative floats are automatically made positive
 * - "spoiled" and "expired" are initially set to false
 * - state does not actively update; meaning attributes are updated when and only when fxns
 * isExpired() and isSpoiled() are called
 * - expirationDate is of string type, should be formatted by YYYY/MM/DD
 */

#ifndef ENTREE_H
#define ENTREE_H
#include <iostream>
#include <ctime>
using namespace std;

class Entree
{
public:
Entree();
Entree (string name, bool refrigeration, bool inFridge, string expirationDate,
        float numServings,float calories, float totalFat, float satFat, float transFat, float cholesterol, float sodium,
        float totCarb, float fiber, float totSugars, float protein, string* contains, string* ingredients, int containsSize, int ingredSize, float price);
~Entree();
Entree (const Entree &);
Entree &operator=(const Entree &);
Entree(Entree &&);
Entree& operator=(Entree &&);

//Pre: none
//Post: "expired" member is set true if expired
bool isExpired();

//Pre: none
//Post: "spoiled" member is set true if spoiled
bool isSpoiled();

//Pre: must pass valid string
//Post: none
bool doesContain(string query);

//Pre: none
//Post: updates spoiled bool and calls isSpoiled()
void powerOutage();

float getServings();
float getCalories();
float getTotFat();
float getSatFat();
float getTransFat();
float getCholest();
float getSod();
float getTotCarb();
float getFiber();
float getTotSugars();
float getProtein();
string getName();
string* getIngreds();
string* getContains();
string getExpDate();
float getPrice();



private:
string name;
bool refrigeration;
bool inFridge;
bool spoiled;
bool expired;
string expirationDate;
float numServings;
float calories;
float totalFat;
float satFat;
float transFat;
float cholesterol;
float sodium;
float totCarb;
float fiber;
float totSugars;
float protein;
string* contains;
string* ingredients;
int containsSize;
int ingredSize;
float price;

//Pre: none
//Post: none
char* time_to_char_array();

};

/* implementation invar:
 * - variables are private for encapsulation of attributes that could potentially set state unstable
 * - attributes for nutritional stats are for easier refrence though could be implemented with 2D array/dictionary
 * - dates are in of type strings for comparison during isExpired()
 * - doesContain() lowercases passed and refrenced strings for edge cases
 */



#endif
