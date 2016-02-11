


#include <iostream>
#include <limits>
using namespace std;


int main()
{
	int x;
	cout << "Enter a number: ";
	cin >> x;
	while(cin.fail() || x < 0 || x > 1) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout << "Bad entry.  Enter a NUMBER: ";
    cin >> x;
	}
	cout << "x = " << x << endl;
	
	
}

                                                       
