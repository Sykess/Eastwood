

#include<iostream>
#include "Node.h"
using namespace std;


class Sll
{
	private:
		int max;
		int qty;
		node * list;
	public:
		Sll();
		Sll(int);
		bool addItem(int);
		bool deleteItem(int);
		bool findItem(int);
		bool isFull();
		bool isEmpty();
		bool makeEmpty();
		void display();
		~Sll();
};
/////////////////////////////////////////////////////////////
Sll::Sll()
{
	qty = 0;
	list = NULL;
	max = INT_MAX;
}
/////////////////////////////////////////////////////////////
Sll::Sll(int m)
{
	if(m > 0)
		max = m;
	else
		max = INT_MAX;
	qty = 0;
	list = NULL;
}
/////////////////////////////////////////////////////////////
bool Sll::isFull()
{
	if(qty >= max)
		return true;
	return false;
}
/////////////////////////////////////////////////////////////
bool Sll::isEmpty()
{
	return qty == 0;
}
/////////////////////////////////////////////////////////////
bool Sll::makeEmpty()
{
	for(node * scan = list; list != NULL; scan = list)
	{
		list = list -> next;
		delete scan;
	}
	qty = 0;
}
/////////////////////////////////////////////////////////////
void Sll::display()
{
	for(node * curr = list; curr != NULL; curr = curr -> next)
		cout << curr -> val << " ";
	//cout << "list is at: " << list -> val;
}
/////////////////////////////////////////////////////////////
bool Sll::addItem(int num)
{
	node * temp, * scan;
	if(isFull())
		return false;
	if((list == NULL)||(list -> val > num))
	{
		//cout << "entering here";
		temp = new node;
		temp -> val = num;
		if(list == NULL)
			temp -> next = NULL;
		else
			temp -> next = list;
		list = temp;
		qty++;
		return true;
	}
	for(scan = list; scan != NULL;scan = scan -> next)
	{
		if(scan -> val == num)//duplicate
			return false;
		if((scan -> next == NULL) || (scan -> next -> val > num))
			break;
	}
	temp = new node;
	temp -> val = num;
	temp -> next = scan -> next;
	scan -> next = temp;
	qty++;
	return true;
}
/////////////////////////////////////////////////////////////
bool Sll::deleteItem(int num)
{
	node * temp;
	if(isEmpty())
		return false;
	if(list -> val == num)
	{
		temp = list;
		list = list -> next;
		delete temp;
		qty--;
		return true;
	}
	for(node * scan = list; scan -> next != NULL; scan = scan -> next)
	{
		if(scan -> next -> val == num)
		{
			temp = scan -> next;
			scan -> next = temp -> next;
			delete temp;
			qty--;
			return true;
		}
	}
	return false;
}
/////////////////////////////////////////////////////////////
bool Sll::findItem(int value)
{
	for(node * scan = list; scan != NULL; scan = scan -> next)
	{
		if(scan -> val == value)
			return true;
	}
	return false;
}
//////////////////////////////////////////////////////////////
Sll::~Sll()
{
	makeEmpty();
}








