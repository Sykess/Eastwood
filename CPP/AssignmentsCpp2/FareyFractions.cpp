/*
 Program Name: FareyFractions.cpp
 Author: Nathan Caron
 Assignment #1
 Date: 1/28/14
 Purpose: Creates the Farey fraction sequence 
*/



/// There's nothing really to grade here, it's an F. I waited too late
/// to start and now I'm pretty lost and out of time.  Haven't done c++ in 
/// 7 years now so I had to spend almost 8 hours catching back up.  I will do
/// better next assignment, and learned my lesson about waiting until 
/// last minute.

#include <iostream>
using namespace std;

const int SIZE = 23;

void display_farey();
void build_farey(const int [][SIZE]);
void order_farey();
void write_farey(const int [][SIZE], int);





int main()
{
    int ff[2][SIZE]= {0,1};  
      

    int order = 1;


    build_farey(ff);
    
    return 0;
}



void build_farey(const int ff[][SIZE])
{
     int order = 2;
     
     int c=0;
     
     
     if (ff[1][c] + ff[1][c+1]==order)
     {
              write_farey(ff, c);
     }
     
     
     
     
     
     
     
     
}




void order_farey()
{
     
     
     }
     
     
     
     
void write_farey(const int ff[][SIZE], int placeToOpen)
{
     int top = placeToOpen + 1;
 
     
     }
