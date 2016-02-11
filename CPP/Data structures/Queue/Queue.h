/*
 Program Name: Queue.h
 Author: Nathan Caron
 Assignment #4
 Date: 3/6/15
 Purpose: Provide Queue class and implementation.
*/



#include <iostream>
using namespace std;

typedef struct data
{
	int custNum;
	int time;
}data;
////////////////////////////////////////////////////////////////
struct node
{
	int key;
	data d;
	node * next;
};
////////////////////////////////////////////////////////////////
class Queue
{
	private:
		int max;
		int qty;
		node * in, * out;
	public:
		Queue(int);
		Queue();
		bool enQueue(data);
		bool deQueue(data &);
		bool vwQueue(data &);
		bool changeTime(data &);
		bool makeEmpty();
		bool isEmpty();
		bool isFull();
		void display();
		~Queue(); 
};
////////////////////////////////////////////////////////////////
Queue::Queue(int m)
{
	if(m > 0)
		max = m;
	else
		max = INT_MAX;
	qty = 0;
	in = NULL;
	out = NULL;
}
////////////////////////////////////////////////////////////////
Queue::Queue()
{
	max = INT_MAX;
	qty = 0;
	in = NULL;
	out = NULL;
}
////////////////////////////////////////////////////////////////
bool Queue::vwQueue(data &_d)
{
	if(isEmpty())
		return false;
	_d = out -> d;
	return true;
}
////////////////////////////////////////////////////////////////
bool Queue::changeTime(data &_d)
{
	if(isEmpty())
		return false;
	out -> d = _d;
	return true;
}

////////////////////////////////////////////////////////////////
bool Queue::enQueue(data _d)
{
	if(isFull())
		return false;
	node * temp = new node;
	temp -> d = _d;
	temp -> next = NULL;
	if(isEmpty())
		in = out = temp;
	else
	{
		in -> next = temp;
		in = temp;
	}
	qty++;
	return true;
}
////////////////////////////////////////////////////////////////
bool Queue::deQueue(data& _d)
{
	if(isEmpty())
		return false;
	node * temp = out;
	_d = temp -> d;
	out = out -> next;
	if(out == NULL)
		in = out;
	delete temp;
	qty--;
	return true;
}
////////////////////////////////////////////////////////////////
bool Queue::makeEmpty()
{
	for(node * curr = out; curr != NULL; curr = out)
	{
		out = out -> next;
		delete curr;
	}
	qty = 0;
	in = NULL;
	return true;
}
////////////////////////////////////////////////////////////////
bool Queue::isFull()
{
	if(qty >= max)
		return true;
	return false;
}
////////////////////////////////////////////////////////////////
bool Queue::isEmpty(){ return qty == 0; }
////////////////////////////////////////////////////////////////
void Queue::display()
{
	for(node * curr = out; curr != NULL; curr = curr -> next)
		cout << curr -> d.custNum << " ";
}
////////////////////////////////////////////////////////////////
Queue::~Queue(){ makeEmpty(); }

