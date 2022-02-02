#include <iostream>
#include <ctime>
#include <cstring>
#include <bits/stdc++.h>


using namespace std;
int ingredSize = 2;
int containsSize = 0;
string ingredients[] = {"Milk", "nuts"};
string contains[] = {};
string convertToString(char* a, int size)
{
        string s = a;
        return s;
}
bool doesContain(string query)
{
        for (int i = 0; i < query.length(); i++)
        {
                query[i] = tolower(query[i]);
        }
        cout << query << endl;

        for (int i = 0; i < ingredSize; i++)
        {
                cout << ingredients[i] << endl;
                string ingredLower = ingredients[i];

                for (int j = 0; j < ingredients[i].length(); j++)
                {
                        // cout << ingredients[i].length() << endl;
                        ingredLower[j] = tolower(ingredients[i][j]);
                        cout << ingredLower[j] << endl;
                }
                cout << ingredLower << endl;

                if (ingredLower == query)
                {
                        return true;
                }
        }


        // for (int i = 0; i < containsSize; i++)
        // {
        //         string containsLower;
        //         for (int j = 0; j < contains[i].length(); i++)
        //         {
        //                 containsLower[j] = tolower(contains[i][j]);
        //         }
        //
        //         if (containsLower == query)
        //         {
        //                 return true;
        //         }
        // }
        return false;
}

int main()
{
        // time_t now = time(0);
        //
        // tm *ltm = localtime(&now);
        // string expirationDate = " 12/12/2021";
        // int n = expirationDate.length();
        // char char_array[n+1];
        // strcpy(char_array, expirationDate.c_str());
        // string finDate = to_string(ltm->tm_mon + 1) + "/" + to_string(ltm->tm_mday) + "/" + to_string(ltm->tm_year + 1900);
        // int x = finDate.length();
        // char char_array2[x+1];
        // strcpy(char_array2, finDate.c_str());
        // if (strcmp(char_array, char_array2) < 0)
        // {
        //         cout << "expired" << endl;
        // }
        // else
        //         cout << "not expired" << endl;

        //cout << ltm->tm_mon + 1 << "/" << ltm->tm_mday << "/" << ltm->tm_year << endl;
        string query = "miLk";
        cout << doesContain(query) << endl;
        return 0;

}
