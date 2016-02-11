
#include "Stack.h"
#include<iostream>
using namespace std;

int main()
{
	Stack testing;
	int key1, key2;
	data d1, d2;
	
	key1 = 15;
	d1.name = 'k';
	
	testing.push(key1, d1);
	testing.pop(key2, d2); // since it passes by reference it actually modifies key2 and d2
	
	cout << "Key: " << key2 << "\nName data: " << d2.name << endl; // then display to show they're both modified
	
	cout << "Pop(0 = false, 1 = true): " << testing.pop(key2, d2) << endl;  // to show list is now empty again
																			// note since pop returns a bool, if you cout it like I did
																			// here it will display either a 0 or a 1, and it still
																			// performs its functions, so If I removed the first call
																			// to pop, this one would display a 1 and key2 and d2 would
																			// be assigned the values
	
	return 0;
}
