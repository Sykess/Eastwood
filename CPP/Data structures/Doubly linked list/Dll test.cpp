

#include "Dll.h"
#include <iostream>
using namespace std;


int main()
{
	data d;
	d.num = 15;
	Dll list;
	list.makeEmpty();

	list.add(23, d);
	list.add(29, d);
	list.add(-25, d);
	list.add(22, d);
	
	//cout << "Emptying: " << list.makeEmpty();
	
	
	list.display();
	
	
	
	
	return 0;
}
