/*
 Program Name: UsllFunc.h
 Author: Nathan Caron
 Assignment #2
 Date: 2/13/2015
 Purpose: Declare functions for unsorted linked list.
*/

#include<iostream>
#include "Usll.h"
using namespace std;

Usll::Usll()
{
	qty = 0;
	first = NULL;
	max = INT_MAX;
}
/////////////////////////////////////////////////////////////
Usll::Usll(int m)
{
	if(m > 0)
		max = m;
	else
		max = INT_MAX;
	first = NULL;
	qty = 0;
}
/////////////////////////////////////////////////////////////
bool Usll::addItem(int num)
{
	node * scan = first;
	if(isFull())
		return false;
	if(isEmpty())
	{
		first = new node;
		first-> val = num;
		first-> next = NULL;
		qty++;
		return true;
	}
	do
	{
		if(scan-> val == num)
			return false;
		if(scan-> next != NULL) //if not last node
			scan = scan-> next;
		else
			break;
	}while(true);
	
	scan-> next = new node;
	scan-> next -> val = num; 
	scan-> next -> next = NULL;
	qty++;
	return true;
}
/////////////////////////////////////////////////////////////
bool Usll::deleteItem(int value)
{
	node *temp;
	if(isEmpty())
		return false;
	if(first-> val == value)
	{
		temp = first;
		first = first -> next;
		delete temp;
		qty--;
		return true;
	}
	for(node * prev = first; prev -> next != NULL; prev = prev -> next)
	{
		if(prev -> next -> val == value)
		{
			temp = prev -> next;
			prev -> next = temp -> next;
			delete temp;
			qty--;
			return true;
		}
	}
	return false;
}
/////////////////////////////////////////////////////////////
bool Usll::isFull(){ return qty == max; }
/////////////////////////////////////////////////////////////
bool Usll::isEmpty(){ return qty == 0; }
/////////////////////////////////////////////////////////////
int Usll::getLength(){ return qty; }
/////////////////////////////////////////////////////////////
bool Usll::findItem(int value)
{
	for(node * scan = first; scan != NULL; scan = scan -> next)
	{
		if(scan -> val == value)
			return true;
	}
	return false;
}
/////////////////////////////////////////////////////////////
void Usll::display()
{
	int count = 0;
	for(node * curr = first; curr != NULL; curr = curr -> next)
	{
		cout << curr-> val << " ";
		count++;
		if(count % 10 == 0)
			cout << endl;
	}
}
/////////////////////////////////////////////////////////////
bool Usll::makeEmpty()
{
	for(node * scan = first; first != NULL; scan = first)
	{
		first = first -> next;
		delete scan;
	}
	qty = 0;
}
/////////////////////////////////////////////////////////////
Usll::~Usll(){ makeEmpty(); }

