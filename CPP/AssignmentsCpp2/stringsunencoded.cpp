/*
 Program Name: Strings.cpp
 Author: Nathan Caron
 Assignment #2
 Date: 2/12/14
 Purpose: Find out how many vowels, constants, and total letters in a string.
*/


#include <iostream>
#include <iomanip>  

using namespace std;

const int SIZE = 1000;

int vowel(char *const sPtr);
int constant(char *const sPtr);
int countAll(char *const sPtr);
void displayMenu();

int main()
{
    char *sPtr;
    sPtr = new char[SIZE];
    
    cout << "Enter a string:";
    cin.getline(sPtr, SIZE);
    
    
    char choice;
    
    do
    {
        displayMenu();
        cin >> choice;
    while (toupper(choice) < 'A' || toupper(choice) > 'E') 
    {
        cout << "Incorrect entry, please make a choice "
             << "in the range of A through E:";
        cin >> choice;
    }

    
    switch(choice)
    {
    case 'a' :
    case 'A' : vowel(sPtr);
    break;
        
    case 'b' :
    case 'B' : constant(sPtr);
    break;
        
    case 'c' :
    case 'C' : countAll(sPtr);
    break;
        
    case 'd' :
    case 'D' : cout << "\nEnter a string:";
               cin.ignore();
               cin.getline(sPtr, SIZE);
    break;
        
    }
}while (toupper(choice) != 'E');
    
    
    
    delete[] sPtr;
    return 0;
}


void displayMenu()
{
    cout << "\nMenu" << "\n";
    cout << "=====================\n";
    cout << "\t a) Count Vowels\n";
    cout << "\t b) Count Constants\n";
    cout << "\t c) Count All\n";
    cout << "\t d) Enter a string\n";
    cout << "\t e) Exit the program\n";
    cout << "Enter your choice: ";
}


int vowel(char *const Ptr)
{

    int vowel = 0;

    
    
    for(int x=0; *(Ptr + x) != '\0'; x++)    // Gets total vowels

    if((*(Ptr + x) == 97 || *(Ptr + x) == 65 || *(Ptr + x) == 101
    || *(Ptr + x) == 69 || *(Ptr + x) == 105 || *(Ptr + x) == 73
    || *(Ptr + x) == 111 || *(Ptr + x) == 79 || *(Ptr + x) == 117
    || *(Ptr + x) == 85))
    vowel++;
    
    cout << "\nThere are " << vowel << " vowels in your string.\n";

    
}


int constant(char *const Ptr)
{
    int total = 0;
    int vowel = 0;
    int constant = 0;
    
    for(int x=0; *(Ptr + x) != '\0'; x++) //Gets total letters.
    if((*(Ptr + x) >= 65 && *(Ptr + x) <= 90) 
    ||(*(Ptr + x) >= 97 && *(Ptr + x) <= 122))
    total++;
    
    for(int x=0; *(Ptr + x) != '\0'; x++) //Gets total vowels.
    if((*(Ptr + x) == 97 || *(Ptr + x) == 65 || *(Ptr + x) == 101
    || *(Ptr + x) == 69 || *(Ptr + x) == 105 || *(Ptr + x) == 73
    || *(Ptr + x) == 111 || *(Ptr + x) == 79 || *(Ptr + x) == 117
    || *(Ptr + x) == 85))
    vowel++;
    
    constant = total - vowel;  //Subtract vowel from total to get constant.
    cout << "\nThere are " << constant << " constants in your string.\n";
    
    
}


int countAll(char *const Ptr)
{
    int total = 0;
    for(int x=0; *(Ptr + x) != '\0'; x++)
    if((*(Ptr + x) >= 65 && *(Ptr + x) <= 90) 
    ||(*(Ptr + x) >= 97 && *(Ptr + x) <= 122))
    total++;
    cout << "\nThere are " << total << " total letters in your string.\n";
    
}
