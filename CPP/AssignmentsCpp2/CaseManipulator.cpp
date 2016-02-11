/*
 Program Name: CaseManipulator.cpp
 Author: Nathan Caron
 Assignment #3
 Date: 2/26/14
 Purpose: Take a string and switch the uppercase with the lowercase, then
 convert them all to lowercase, then convert them all to uppercase.
*/

#include <iostream>
#include <iomanip>
using namespace std;

const int SIZE = 100;

char upper(char *Ptr);
char lower(char *Ptr);
char reverse(char *Ptr);

int main()
{
    char *Ptr;
    Ptr = new char[SIZE];
    
    cout << "Enter a string: ";
    cin.getline(Ptr, SIZE);
    
    reverse(Ptr);
    cout << "Your string with cases reversed is: ";
    cout << Ptr << endl;
    
    lower(Ptr);
    cout << "Your string in all lowercase letters is: ";
    cout << Ptr << endl;
    
    upper(Ptr);
    cout << "Your string in all uppercase letters is: ";
    cout << Ptr << endl;
    
    
    delete[] Ptr;
    return 0;   
}


char lower(char *Ptr)
{
    for(int x=0; *(Ptr + x) != '\0'; x++)
    Ptr[x]=tolower(Ptr[x]);
    
    return *Ptr;
}


char upper(char *Ptr)
{
    for(int x=0; *(Ptr + x) != '\0'; x++)
    Ptr[x]=toupper(Ptr[x]);
    
    return *Ptr;
}


char reverse(char *Ptr)
{
    for(int x=0; *(Ptr + x) != '\0'; x++)
    {
        if(isupper(Ptr[x]))
        Ptr[x] = tolower(Ptr[x]);
        else
        if(islower(Ptr[x]))
        Ptr[x] = toupper(Ptr[x]);
    }
    return *Ptr;
}
