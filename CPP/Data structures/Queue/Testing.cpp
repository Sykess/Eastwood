

#include<iostream>
#include "Queue.h"
using namespace std;



int main()
{
	Queue test;
	data d;
	
	d.id = 15;
	test.enQueue(d);
	d.id = 18;
	test.enQueue(d);
	d.id = 12;
	test.enQueue(d);
	
	test.deQueue(d);
	cout << "\nFirst out: " << d.id;
	test.deQueue(d);
	cout << "\nSecond out: " << d.id;
	test.deQueue(d);
	cout << "\nThird out: " << d.id;
	test.deQueue(d);
	cout << "\nNonexistant fourth out: " << d.id;
	
	return 0;
}
