// Program Name: TestScores.cpp
// Author: Nathan Caron
// Assignment #3
// Date: 10/20/06
// Purpose: To take three test scores, average them
//          And convert them to a letter grade.

#include <iostream>
using namespace std;


int main()
{
	int score1, score2, score3;
	double average;

	cout << "\nEnter three test scores separated by spaces"
		 << "\nand I will average them for you : ";
	cin >> score1 >> score2 >> score3;

	average = (score1 + score2 + score3) / 3;

	cout << "\nYour average for the three tests is : ";

	average = average * 100;
	average = average + 0.5;
	average = int(average);
	average = average / 100;

	cout << average;
	cout << "\nYour letter grade is ";

	switch (int (average) / 10)
	{
		case 11: cout << "an A";
			break;
		case 10: cout << "an A";
			break;
		case 9:  cout << "an A";
			break;
		case 8:  cout << "a B";
			break;
		case 7:  cout << "a C";
			break;
		case 6:  cout << "a D";
			break;
		default: cout << "a F";
	}
	

	cout << endl << endl;



	return 0;
}