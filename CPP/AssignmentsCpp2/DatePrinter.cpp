/*
 Program Name: DatePrinter.cpp
 Author: Nathan Caron
 Assignment #3
 Date: 2/26/14
 Purpose: Allows user to input date in format mm/dd/yyyy and sends back
 that same date in the format February 26, 2014.
*/

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

const int SIZE = 100;


int main()
{
    
    char string[SIZE];
    char month[3];
    int choice;
    
    
    cout << "Enter a date in the format mm/dd/yyyy: ";
    cin.getline(string, SIZE);
    

    
    
    while((string[0] < 48 || string[0] > 49) || 
         (string[1] < 48 || string[1] > 57) || 
         (string[3] < 48 || string[3] > 51) || 
         (string[4] < 48 || string[4] > 57) || 
         (string[6] < 48 || string[6] > 50) ||
         (string[7] < 48 || string[7] > 57) ||
         (string[8] < 48 || string[8] > 57) ||
         (string[9] < 48 || string[9] > 57))
    {
        cout << "Incorrect entry, try again in the "
             << "format mm/dd/yyyy: ";
    cin.getline(string, SIZE);
}

    strncpy(month, string, 2);
    choice = atoi(month);

    switch(choice)
    {
    case 1: cout << "\nJanuary ";
    break;
    case 2: cout << "\nFebruary ";
    break;
    case 3: cout << "\nMarch ";
    break;
    case 4: cout << "\nApril ";
    break;
    case 5: cout << "\nMay ";
    break;
    case 6: cout << "\nJune ";
    break;
    case 7: cout << "\nJuly ";
    break;
    case 8: cout << "\nAugust ";
    break;
    case 9: cout << "\nSeptember ";
    break;
    case 10: cout << "\nOctober ";
    break;
    case 11: cout << "\nNovember ";
    break;
    case 12: cout << "\nDecember ";
    break;
    }
    
    cout << string[3] << string[4] << ", ";
    cout << string[6] << string[7] << string[8] << string[9] << endl;
    
    
    
    system ("pause");
    return 0;
}

