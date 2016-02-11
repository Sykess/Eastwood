
#include <iostream>
#include "UsllFunc.h"
using namespace std;


int main()
{
	Usll test;
	
	test.addItem(15);
	cout << test.isFull();
	cout << test.addItem(16);
	cout << "length = " << test.getLength();
	cout << test.deleteItem(16);
	//cout << test.isFull();
	test.addItem(17);
	test.addItem(16); 
	
	cout << test.findItem(17);
	test.display();
	


	cout << "hi";
	
	return 0;
}
