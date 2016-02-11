#include <iostream>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <algorithm>
using namespace std;



int main()
{
	string name = "";
	string s = "";
	
	
	int x = 5;
	int * ptr;
	int array[10] = {5};
	ptr = array;
	
	cout << &ptr << endl << ptr << endl << &array;
	
	cout << "Enter name: ";
	cin >> name;
	//s = name;
	//std::transform(name.begin(), name.end(), s.begin(), ::toupper);
	for(auto & c : name)
		c = toupper(c);
	cout << name;
	cout << endl << s << endl;
	cout << "Enter age: ";
	cin >> name;
	cout << name;
	return 0;
	
	
}
