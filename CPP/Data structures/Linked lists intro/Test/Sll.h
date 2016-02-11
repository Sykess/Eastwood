/*
 Program Name: Sll.h
 Author: Nathan Caron
 Assignment #2
 Date: 2/13/2015
 Purpose: Declare sorted linked list class.
*/

#include "Node.h"

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
		int getLength();
		~Sll();
};








