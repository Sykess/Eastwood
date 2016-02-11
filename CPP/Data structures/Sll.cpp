
#include <iostream>
#include "Sll.h"
using namespace std;


int main()
{
	Sll test;
	
	test.addItem(25);
	test.addItem(15);
	test.addItem(33);
	test.addItem(-27);
	cout << test.deleteItem(25);
	//test.makeEmpty();
	test.display();
	cout << "find 33" << test.findItem(-27);
}
