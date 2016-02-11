#include "employee_class.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    employee *company; 
    string str;
    int qty, num;
    
    do{
        cout << "\nHow many employees do you have: ";
        cin >> qty; 
        if((qty < 1) || (qty > 30))
            cout << "\nMust be 1-30.";
    }while((qty < 1) || (qty > 30));
    
    company = new employee [qty];
    
    for(int x=0; x < qty; x++)
    {
        cout << "\nWhat is your name: ";
        cin >> str;
        company[x].setName(str);
        
        cout << "\nWhat is your id number: ";
        cin >> num;
        company[x].setIdNum(num);
        
        cout << "\nWhat department do you work for: ";
        cin >> str;
        company[x].setDept(str);
        
        cout << "\nWhat is your current possition: ";
        cin >> str;
        company[x].setPos(str);
    }
    
    cout << endl << left << setw(25) << "Name" << setw(15) << "ID Number" 
         << setw(25) << "Department" << setw(15) << "Position" 
         << "\n==============================================================="
         << "================="; 
 
    for(int x=0; x < qty; x++)
    {
        cout << left << setw(25) << company[x].getName() << setw(15) 
             << company[x].getIdNum() << setw(25) << company[x].getDept()   
             << setw(15) << company[x].getPos(); 
    }
    
    delete [] company;
 
    system("pause");
    return 0;
}
   
    
    
    
    
