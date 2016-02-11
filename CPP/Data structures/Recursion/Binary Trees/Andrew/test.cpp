


#include <iostream>
#include <fstream>

using namespace std;

#include "BinaryTree.h"


int main()
{
	data d;
	BT tree;
	
	tree.putItem(25, d);
	tree.putItem(18, d);
	tree.putItem(26, d);
	tree.putItem(13, d);
	tree.putItem(19, d);
	tree.putItem(56, d);
	tree.putItem(42, d);
	tree.putItem(85, d);
	tree.putItem(50, d);
	tree.putItem(68, d);
	tree.putItem(86, d);
	tree.deleteItem(18, d);
	tree.deleteItem(42, d);
	tree.deleteItem(50, d);
	tree.print(cout);
	cout << tree.putItem(50, d);
	tree.print(cout);
}
