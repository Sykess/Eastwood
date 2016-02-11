/******************************************************************************
program:	DLL.h
author:		A.Hayden
date:		4/8/15
assignment:	#5
purpose:	double linked list header file
******************************************************************************/

#include "Node.h"



class Dll
{
	private:
		int qty;
		int max;
		node *curr;
	public:
		Dll();
		Dll(int);
		bool add(int, data);
		bool find(int, data&);
		bool remove(int, data&);
		bool isFull();
		bool isEmpty();
		bool makeEmpty();
		void display(ostream &);
		void displayCost();
		~Dll();
};

///////////////////////////////////////////////////////////////////////////////

Dll::Dll()
{
	qty = 0;
	max = INT_MAX;
	curr = NULL;
}

///////////////////////////////////////////////////////////////////////////////

Dll::Dll(int m)
{
	if(m > 0)
		max = m;
	else
		max = INT_MAX;

	curr = NULL;
	qty = 0;
}

///////////////////////////////////////////////////////////////////////////////

bool Dll::find(int k, data &d)
{
	if(isEmpty())
		return false;

	for( ; curr -> key <= k; curr = curr -> next)
	{
		if(curr -> key == k)
			return true;
		if(curr -> next == NULL)
			break;
	}
	for( ; k <= curr -> key; curr = curr -> prev)
	{
		if(curr -> key == k)
			return true;
		if(curr -> prev == NULL)
			break;
	}

	return false;
}

///////////////////////////////////////////////////////////////////////////////

bool Dll::add(int k, data d)
{
	node *temp;
	
	if((find(k,d)) || isFull())
		return false;

	temp = new node;
	temp -> key = k;
	temp -> d = d;
	
	if(isEmpty())
	{
		curr = temp;
		curr -> prev = NULL;
		curr -> next = NULL;
		qty++;
		return true;
	}
	
	if(curr -> key > k)
	{
		temp -> next = curr;
		temp -> prev = curr -> prev;
		curr -> prev = temp;
		if(temp -> prev != NULL)
			temp -> prev -> next = temp;
	}
	else
	{
		temp -> prev = curr;
		temp -> next = curr -> next;
		curr -> next = temp;
		if(temp -> next != NULL)
			temp -> next -> prev = temp;
	}
	qty++;
	return true;
}

///////////////////////////////////////////////////////////////////////////////

bool Dll::remove(int k, data &d)
{
	node *temp;
	if(!find(k,d))
		return false;
	temp = curr;
	d = temp -> d;

	if(curr -> prev == NULL)
	{
		curr = curr -> next;
		curr -> prev = NULL;
	}
	else
	{
		curr = curr -> prev;
		
		if(temp -> next == NULL)
			curr -> next = NULL;
		else
		{
			curr -> next = temp -> next;
			temp -> next -> prev = curr;
		}
	}
	
	delete temp;
	qty--;
	return true;
}

///////////////////////////////////////////////////////////////////////////////

bool Dll::makeEmpty()
{
	node *temp;
	
	if(isEmpty())
		return true;
		
	for(node * part = curr -> next; part != NULL; )
	{
		temp = part;
		part = part -> next;
		delete temp;
	}
	
	while(curr != NULL)
	{
		temp = curr;
		curr = curr -> prev;
		delete temp;
	}
	
	qty = 0;
	return true;
}

///////////////////////////////////////////////////////////////////////////////

bool Dll::isEmpty()
{
	if(qty == 0)
		return true;
	return false;
}

///////////////////////////////////////////////////////////////////////////////

bool Dll::isFull()
{
	if(qty >= max)
		return true;
	return false;
}

///////////////////////////////////////////////////////////////////////////////

void Dll::display(ostream &out)
{
	if(isEmpty())
		return;
	for(; curr -> prev != NULL; curr = curr -> prev); //move curr to 1st node
	//for(; curr -> next != NULL; curr = curr -> next)
	do
	{
		out << curr -> key << "; "
			<< curr -> d.toolname << "; "
			<< curr -> d.quantity << "; "
			<< curr -> d.cost << endl;
		if(curr -> next == NULL)
			return;
		curr = curr -> next;
	}while(true);
}

void Dll::displayCost()
{
	if(isEmpty())
		return;
	for(; curr -> prev != NULL; curr = curr -> prev); //move curr to 1st node
	
	for(node *temp, *temp2; curr -> next != NULL;)
	{
		temp = curr -> next;
		if(temp -> d.cost < curr -> d.cost)
		{
			temp2 = temp -> next;
			temp -> prev = curr -> prev;
			temp -> next = curr;
			if(curr -> prev != NULL)
				curr -> prev -> next = temp;
			curr -> prev = temp;
			curr -> next = temp2;
			temp2 -> prev = curr;
			if(curr -> prev -> prev != NULL)
				curr = curr -> prev -> prev;
			else if(curr -> prev != NULL)
				curr = curr -> prev;
		}
		else
			curr = curr -> next;
	}
	for(; curr -> prev != NULL; curr = curr -> prev);
	do
	{
   	     cout << curr -> key << ";"
   	   		 << curr -> d.toolname << ";"
   			 << curr -> d.quantity << ";"
    		 << curr -> d.cost << endl;
	 	if(curr -> next == NULL)
	           return;
	 	curr = curr -> next;
	}while(true);
}

///////////////////////////////////////////////////////////////////////////////

Dll::~Dll()
{
	makeEmpty();
}
