
#include <iostream>
#include <fstream>
using namespace std;


int main()
{
	char c;
	fstream file("sudoku.txt", ios::in);
	//file.getline(c.cStr(), 256, ",");
	c = file.get();
	
	cout << c;
	file.close();
}
