
#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;



int main()
{
	fstream file;
	int counter = 0;
	string num;
	
	file.open("cipher.txt", ios::in);
	getline(file, num, ',');
	int blah = atoi(num.c_str());
	cout << blah;
	getline(file, num, ',');
	blah = atoi(num.c_str());
	cout << blah;
	file.close();
	
	
}
