
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

//jan 7 1900 sunday

int main()
{
	int sundays = 0;
 
for (int year = 1901; year <= 2000; year++) {
    for (int month = 1; month <= 12; month++) {
        if ((new DateTime(year, month, 1)).DayOfWeek == DayOfWeek.Sunday) {
            sundays++;
        }
    }
}
	
}


