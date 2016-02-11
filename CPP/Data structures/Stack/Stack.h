
#include "StackDef.h"
#include <iostream>


Stack::Stack()
{
	qty = 0;
	top = NULL;
	max = INT_MAX;
}

Stack::Stack(int m)
{
	if(m > 0)
		max = m;
	else
		max = INT_MAX;
	qty = 0;
	top = NULL;
}

bool Stack::push(int k, data _d)
{
	node * temp;
	if(isFull())
		return false;
	temp = new node;
	temp -> key = k;
	temp -> d = _d;
	temp -> next = top;
	top = temp;
	qty++;
	return true;
}

bool Stack::pop(int &k, data &_d)
{
	node * temp;
	if(isEmpty())
		return false;
	k = top -> key;
	_d = top -> d;
	temp = top;
	top = top -> next;
	delete temp;
	qty--;
	return true;
}

bool Stack::peek(int &k, data &_d)
{
	if(isEmpty())
		return false;
	k = top -> key;
	_d = top -> d;
	return true;
}

bool Stack::makeEmpty()
{
	node * temp;
	while(top != NULL)
	{
		temp = top;
		top = top -> next;
		delete temp;
	}
	qty = 0;
	return true;
}

bool Stack::isFull()
{
	if(qty >= max)
		return true;
	return false;
}

bool Stack::isEmpty(){ return qty == 0; }

Stack::~Stack(){ makeEmpty(); }
