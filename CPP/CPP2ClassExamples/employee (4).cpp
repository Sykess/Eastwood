#include "employee_class.h"

int main()
{
    employee you("Bob",123,"Engineering","Flunky");  
    
    cout << "\nYou are: " << you.getName()
         << "\nYour ID number is: " << you.getIdNum()
         << "\nYour depatrtment is: " << you.getDept()
         << "\nYour possition is: " << you.getPos() << endl << endl;
    
    you.setName("Steve");
    you.setIdNum(999);
    you.setDept("Janatorial");
    you.setPos("Toilet Cleaner");     
         
    cout << "\nYou now are: " << you.getName()
         << "\nYour ID number is: " << you.getIdNum()
         << "\nYour depatrtment is: " << you.getDept()
         << "\nYour possition is: " << you.getPos() << endl << endl;
    
    return 0;
}
   
    
    
    
    
