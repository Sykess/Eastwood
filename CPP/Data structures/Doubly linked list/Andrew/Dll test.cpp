
#include <fstream>
#include <iostream>


using namespace std;
#include "Dll.h"

int main()
{
	data d;
	d.quantity = 15;
	d.cost = 1.99;
	string str = "Hello";
	for(int x = 0; x < str.size(); x++)
	{
		d.toolname[x] = str[x];
		if(x+1 == str.size())
			d.toolname[x+1] = '\0';
	}
	Dll list;
	list.makeEmpty();

	list.add(23, d);
	list.add(29, d);
	list.add(-25, d);
	list.add(22, d);
	
	//cout << "Emptying: " << list.makeEmpty();
	
	
	//list.display(cout);
	list.remove(23, d);
	list.remove(-25, d);
	
	cout << "Hi" << endl;
	list.display(cout);
	
	
	
	return 0;
}
