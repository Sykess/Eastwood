

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
