/*
 Program Name: StackDef.h
 Author: Nathan Caron
 Assignment #3
 Date: 2/25/2015
 Purpose: Define class Stack.
*/

#include "Node.h"


class Stack
{
	private:
		node * top;
		int qty;
		int max;
	public:
		Stack();
		Stack(int);
		bool push(int, data);
		bool pop(int &, data &);
		bool isFull();
		bool peek(int &, data &);
		bool isEmpty();
		bool makeEmpty();
		~Stack();
};
