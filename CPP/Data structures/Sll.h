
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
		~Sll();
};
/////////////////////////////////////////////////////////////








