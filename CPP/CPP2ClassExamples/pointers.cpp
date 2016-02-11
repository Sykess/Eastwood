#include <iostream>
#include <conio.h> //needed for getch()
using namespace std;

int main()
{
    int x = 45; 
    int *xPtr = &x;
    
    cout << "The value of x is " << x << endl;
    
    cout << "The address of x is " << &x << endl;
    
  
    cout << "The memorey address of xPtr is " << &xPtr << endl;
    cout << "The value xPtr points to " << *xPtr << endl;
    
    cout << "The memorey address xPtr points to " <<xPtr << endl;
    
    *xPtr *= 5;
    cout << "The value of x after math on xPtr " << x << endl;
    
    
    
    getch();
    return 0;
}
    
    
