/*
 Program Name: CaronNateBT.cpp
 Author: Nathan Caron
 Assignment #7
 Date: 4/28/14
 Purpose: Load numbers from 2 files into a binary tree.  Delete duplicates, and
 		  output them to a file.  Then output the tree to a file.  I got a tree
 		  form display working, however it looks worse the bigger the tree gets.
*/


#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>

using namespace std;

#include "BT.h"

// function prototypes
void loadTree(string, BT&);
void saveMerged(BT&);

int main()
{
	BT tree;
	data d; // dummy data
	loadTree("data1.txt", tree);
	loadTree("data2.txt", tree);
	
	cout << "\nTree before balancing has a depth of " << tree.getDepth()
		 << " and a quantity of " << tree.getLength()
	     << "\nThe contents are:\n";
	tree.print(cout);
	
	tree.balance();
	cout << "\n\nTree after balancing has a depth of " << tree.getDepth()
		 << " and a quantity of " << tree.getLength()
		 << "\nThe contents in tree form are:\n";

	// if tree is > 127 the displayTree will not display nicely
	tree.displayTree();
	saveMerged(tree);
	
}

void loadTree(string opened, BT & tree)
{
	int num;
	data d;
	fstream file, err;
	file.open(opened.c_str(), ios::in);
	err.open("errors.txt", ios::out | ios::app);
	
	if(!file)
	{
		cout << opened << " could not be opened!\n";
		err.close();
		return;
	}
	if(!err)
	{
		cout << "errors.txt could not be opened!\n";
		file.close();
		return;
	}
	
	cout << "Loading from " << opened << "...\n";

	while(!file.eof())
	{
		file >> num;
		if(!tree.putItem(num, d))
		{
			tree.deleteItem(num, d);
			err << num << endl;
		}
	}
	file.close();
	err.close();
}

void saveMerged(BT & tree)
{
	fstream merge;
	merge.open("merged.txt", ios::out | ios::app);
	if(!merge.is_open())
	{
		cout << "Could not open merged.txt" << endl;
		return;
	}
	cout << "\nSaving tree data to merged.txt...\n";
	tree.print(merge);
	merge << endl;
	merge.close();
	cout << "Saving Complete.\n";
}
