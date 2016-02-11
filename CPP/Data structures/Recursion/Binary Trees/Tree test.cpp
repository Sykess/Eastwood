
#include <iostream>
#include <fstream>
#include <math.h>
#include <sstream>

using namespace std;

#include "BT.h"




int main()
{
	BT tree;
	data d;

	
	/*
	tree.putItem(15, d);
	tree.putItem(16, d);
	tree.putItem(13, d);
	tree.putItem(100, d);
	tree.putItem(200, d);
	tree.putItem(5, d);
	tree.putItem(6, d);
	//cout << tree.deleteItem(100, d);
	//cout << tree.deleteItem(15, d);
	//cout << tree.deleteItem(16, d);
	//cout << tree.deleteItem(13, d);
	//cout << tree.deleteItem(6, d);
	//cout << tree.deleteItem(5, d);
	//cout << tree.deleteItem(200, d);
	//cout << endl << tree.getLength();
	//cout << endl << endl << endl;
	tree.display(4);
	
	tree.putItem(25, d);
	tree.putItem(18, d);
	tree.putItem(26, d);
	tree.putItem(13, d);
	tree.putItem(19, d);
	tree.putItem(21, d);
	tree.putItem(56, d);
	tree.putItem(43, d);
	tree.putItem(11, d);
	tree.putItem(6, d);
	tree.putItem(42, d);
	tree.putItem(15, d);
	tree.putItem(26, d);
	tree.putItem(85, d);
	tree.putItem(68, d);
	tree.putItem(12, d);
	tree.putItem(11, d);
	tree.putItem(50, d);
	tree.putItem(67, d);
	tree.putItem(69, d);
	tree.putItem(22, d);
	tree.putItem(23, d);
	tree.putItem(24, d);
	tree.putItem(25, d);
	//tree.deleteItem(50, d);
	tree.deleteItem(43, d);
	*/
	
	tree.putItem(1, d);
	tree.putItem(2, d);
	
	tree.putItem(50, d);
	tree.putItem(75, d);
	tree.putItem(100, d);
	tree.putItem(99, d);
	tree.putItem(98, d);
	//tree.putItem(97, d);
	tree.putItem(49, d);
	tree.putItem(48, d);
	tree.putItem(47, d);
	tree.putItem(46, d);
	//tree.putItem(45, d);
	//tree.putItem(94, d);
	//tree.putItem(96, d);
	//tree.putItem(95, d);
	tree.displayTree();
	cout << endl;
	cout << "Sort: " << endl;
	tree.sortTree();
	cout << endl << "done\n";
	tree.deleteItem(49, d);
	tree.sortTree();
	tree.deleteItem(48, d);
	tree.displayTree();
	cout << endl << tree.getDepth();
	cout << endl << tree.depthLeft();
	cout << endl << tree.depthRight();
	cout << endl;
	cout << tree.find(2, d);
	//tree.print(cout);
}
