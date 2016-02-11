/*
 Program Name: Usll.h
 Author: Nathan Caron
 Assignment #2
 Date: 2/13/2015
 Purpose: Declare unsorted linked list class.
*/

#include "Node.h"

class Usll
{
	private:
		int max;
		int qty;
		node * first;
	public:
		Usll();
		Usll(int);
		bool addItem(int);
		bool deleteItem(int);
		bool isFull();
		bool isEmpty();
		bool findItem(int);
		int getLength();
		bool makeEmpty();
		void display();
		~Usll();
};

