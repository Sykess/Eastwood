


#include <iostream>
#include <fstream>
#include "SllFunc.h"
#include "UsllFunc.h"
using namespace std;


int main()
{
	fstream file;
	int numbers;
	Sll sorted;
	Usll unsorted;
	//node * search = NULL;
	
	
	file.open("Numbers.dat");
	
	if(!file)
	{
		cout << "Failed";
		return -1;
	}
	
	while(!file.eof())
	{
		file >> numbers;
		sorted.addItem(numbers);
		unsorted.addItem(numbers);
	}
	
	cout << "sorted list: \n";
	sorted.display();
	cout << "\nunsorted list: \n";
	unsorted.display();
	
	
	return 0;	
}
