
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;


int main()
{
	int num[6];
	// needed otherwise same random numbers always generated
	srand(time(0));
	num[0] = rand() % 35 + 1;
	cout << num[0] << endl;
	num[0] = rand() % 35 + 1;
	cout << num[0] << endl;
	num[0] = rand() % 35 + 1;
	cout << num[0] << endl;
	num[0] = rand() % 35 + 1;
	cout << num[0] << endl;
	num[0] = rand() % 35 + 1;
	cout << num[0] << endl;
	num[0] = rand() % 35 + 1;
	cout << num[0] << endl;
}
