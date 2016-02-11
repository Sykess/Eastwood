// Program Name: Sorting.cpp
// Author: Nathan Caron
// Assignment #7
// Date: 12/13/06
// Purpose: Sort numbers with bubble sort and selection sort

#include <iostream>
using namespace std;

//Global constants
const int SIZE = 8;

//function prototypes
void bubbleSort(int num[SIZE]);
void selectionSort(int num[SIZE]);
void display(const int num[SIZE]);

int main()
{

	int array1[SIZE] = {12, 9, 43, 96, 2, 31, 77, 0};
	int array2[SIZE] = {12, 9, 43, 96, 2, 31, 77, 0};


	cout << endl << "Array 1";
	display(array1);
	cout << endl;
	bubbleSort(array1);

	cout << endl << "Array 2";
	display(array2);
	cout << endl;
	selectionSort(array2);

	cout << endl << endl;


	return 0;
}

/////////////////////////////////////////////

void bubbleSort(int num[SIZE])
{
	cout << endl << "Bubble Sort: " << endl;
	double temp;
	int pass = 0, swap;
	int x = 0, stop = SIZE - 1;
	
	while(pass++ < (SIZE - 1))
	{
		swap = 0;
		for(x=0; x < SIZE - 1; x++)
		{
			if(num[x] > num[x + 1])
			{
				swap++;
				temp = num[x];
				num[x] = num[x+1];
				num[x+1] = temp;
				stop--;
			}
		}
		display(num);
		cout << endl << "The number of swaps was : " << swap << endl;
	}
	cout << endl;
}

/////////////////////////////////////////////

void selectionSort(int num[SIZE])
{
	cout << endl << "Selection Sort:" << endl;
	int small = 0, swap = 0;
	int x, temp, pass = 0;
	while(pass < (SIZE-1))
	{
		small = pass;

		display(num);
		cout << endl << "The number of swaps was : " << swap << endl;

		swap = 0;
	
		for(x = pass; x < SIZE; x++)
			if(num[x] < num[small])
				small = x;

			if(small != pass)
			{
				temp = num[small];
				num[small] = num[pass];
				num[pass] = temp;
				swap++;
			}
			pass++;
	}
	cout << endl;
}

/////////////////////////////////////////////

void display(const int num[SIZE])
{
	cout << endl;
	for(int x = 0; x < SIZE; x++)
	cout << num[x] << " ";
}