/*
 Program Name: Dll.h
 Author: Nathan Caron
 Assignment # 5
 Date: 4/9/2015
 Purpose: Doubly linked list class that we made in class with added 
 		  functions: getKeys(int*) and displayFormatted().
*/


#ifndef NODE_H
#define NODE_H

typedef struct data
{
	char toolName[35];
	int quantity;
	double cost;
}data;

struct node
{
	node * prev;
	node * next;
	int key;
	data d;
};

#endif



class Dll
{
	private:
		int qty;
		int max;
		node * curr;
	public:
		Dll();
		Dll(int);
		bool add(int, data);
		bool find(int, data&);
		bool deleteItem(int, data&);
		bool isEmpty();
		bool isFull();
		bool makeEmpty();
		void display();
		void displayFormatted();
		void getKeys(int*);
		int quantity();
		~Dll();
};
/////////////////////////////////////////////////////////////////////////////
Dll::Dll()
{
	qty = 0;
	max = INT_MAX;
	curr = NULL;
}
/////////////////////////////////////////////////////////////////////////////
Dll::Dll(int m)
{
	if(m > 0)
		max = m;
	else
		max = INT_MAX;
	qty = 0;
	curr = NULL;
}
/////////////////////////////////////////////////////////////////////////////
int Dll::quantity()
{
	return qty;
}
/////////////////////////////////////////////////////////////////////////////
void Dll::getKeys(int * array)
{
	int x = 0;
	for(;curr -> prev != NULL; curr = curr -> prev); // move to begin
	
	for(node * temp = curr;temp != NULL; temp = temp -> next)
		array[x++] = temp -> key;
		
}
/////////////////////////////////////////////////////////////////////////////
bool Dll::find(int k, data &d)
{
	if(isEmpty())
		return false;
	for(; curr -> key <= k; curr = curr -> next)
	{
		if(curr -> key == k)
		{
			d = curr -> d;
			return true;
		}
		if(curr -> next == NULL)
			break;
	}
	for(; k <= curr -> key; curr = curr -> prev)
	{
		if(curr -> key == k)
		{
			d = curr -> d;
			return true;
		}
		if(curr -> prev == NULL)
			break;
	}
	return false;
}
/////////////////////////////////////////////////////////////////////////////
bool Dll::add(int k, data d)
{
	node * temp;
	
	if(find(k, d) || isFull())
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
	
	if(curr -> key > k) //left add
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
/////////////////////////////////////////////////////////////////////////////
bool Dll::deleteItem(int k, data &d)
{
	node * temp;
	if(!find(k, d))
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
/////////////////////////////////////////////////////////////////////////////
void Dll::display()
{
	if(isEmpty())
		return;
	for(;curr -> prev != NULL; curr = curr -> prev); // move to begin
	
	for(node * temp = curr;temp != NULL; temp = temp -> next)
	{
		cout << setw(10) << temp -> key << setw(35) << temp -> d.toolName << setw(10)
			 << temp -> d.quantity << setw(10) << setprecision(2)
			 << fixed << temp -> d.cost << endl;
	}
}
/////////////////////////////////////////////////////////////////////////////
void Dll::displayFormatted()
{
	if(isEmpty())
		return;
	for(;curr -> prev != NULL; curr = curr -> prev); // move to begin
	
	for(node * temp = curr;temp != NULL; temp = temp -> next)
	{
		cout << temp -> key << ";" << temp -> d.toolName << ";"
			 << temp -> d.quantity << ";" << temp -> d.cost << endl;
	}
}
/////////////////////////////////////////////////////////////////////////////
bool Dll::makeEmpty()
{
	node * temp;
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
		delete  temp;
	}
	qty = 0;
	return true;
}
/////////////////////////////////////////////////////////////////////////////
bool Dll::isEmpty()
{
	if(qty == 0)
		return true;
	return false;
}
/////////////////////////////////////////////////////////////////////////////
bool Dll::isFull()
{
	if(qty >= max)
		return true;
	return false;
}
/////////////////////////////////////////////////////////////////////////////
Dll::~Dll()
{
	makeEmpty();
}
