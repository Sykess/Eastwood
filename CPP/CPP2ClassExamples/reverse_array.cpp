/****************************************************************************
program:    reverse_array.cpp
author:     panczner
date:       2/3/14
assignment  n/a
purpose:    to demonstrait pointers
******************************************************************************/
#include <iostream>
#include <conio.h>
using namespace std;

//function prototypes
int * reverse_and_create(const int array[], int size);

int main()
{
    int s=5, array[]={1,2,3,4,5};
    int *reversePtr,* rPtr;
    
    reversePtr = reverse_and_create(array, s);
    
//    for(int x=0; x < s; x++)
//       cout << reversePtr[x] << " ";

    rPtr = reversePtr; //2 pointers to th ereversed list
    for(int x=0; x < s; x++)
        cout << *rPtr++ << " ";
    
    delete [] reversePtr;
    
    getch();
}
///////////////////////////////////////////////////////////////////////////////
int * reverse_and_create(const int array[], int size)
{
    //int * allows us to return an address of an int ie a pointer
    int * aPtr;
    int original=0, duplicate=size-1;
    
    aPtr = new int [size];   
    
    while(original < size)
    {
        aPtr[duplicate--] = array[original++];   
    }
    
    return aPtr; //returns the address of where the array starts
}
























