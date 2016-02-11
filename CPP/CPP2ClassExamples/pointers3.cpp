#include <iostream>
#include <conio.h> //needed for getch()
using namespace std;

int main()
{
    int size;
    int *aPtr, *bPtr;
    
    
    cout << "\nHow big do you want the array? ";
    cin >> size;
    
    bPtr = aPtr = new int [size];
    
    for(int x=0; x < size; x++)
        cin >> *bPtr++;
        
    cout << endl;
        
    for(int x=0; x < size; x++)
        cout << aPtr[x] << " ";
    
    delete [] aPtr;
    
    getch();
    return 0;
}
    
    
