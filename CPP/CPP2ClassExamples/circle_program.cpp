#include "circle.h"
#include <iostream>
using namespace std;

int main()
{
    double rad;
    circle c;
    
    do{
        cout << "\nEnter a radius ";
        cin >> rad;
        
        if(!c.setRadius(rad))
            cout << "\nThat is an invalid entry.";
        else
            break;
    }while(true);
   
    cout << "\nA circle with a radius of " << c.getRadius()
         << " has a diameter of " << c.getDiameter()
         << " and a circumfrence of " << c.getCircumfrence()
         << " and it\'s area is " << c.getArea() << endl << endl; 
    
    system("pause");
    return 0;
}
    
    
    
    
