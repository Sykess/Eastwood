


#include <iostream>
#include <fstream>
#include "Sll.h"
#include "Usll.h"
using namespace std;


int main()
{
	fstream file;
	int numbers;
	Sll sorted;
	Usll unsorted;
	//node * search = NULL;
	
	
	file.open("Numberss.dat");
	
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
