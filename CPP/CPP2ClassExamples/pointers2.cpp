#include <iostream>
#include <conio.h> //needed for getch()
using namespace std;

int main()
{
    int *Ptr = NULL;
    
    cout << "\nPtr points to address " << Ptr;
    
    Ptr = new int; //dynamicly creates space for an int
    
    cout << "\nPtr points to address " << Ptr << " after dynamic allocation";
    
    cout << "\nPtr points to the value " << *Ptr;
    
    *Ptr = 421;
    
    cout << "\nPtr points to the value " << *Ptr << " after assignment";
    
    delete Ptr; //deallocates th memorey ie gives it back
    
    getch();
    return 0;
}
    
    
