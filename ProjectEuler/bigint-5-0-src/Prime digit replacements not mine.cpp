


#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <iomanip>
#include <sstream>
#include "bigInt.h"

using namespace std;



int main()
{
	unsigned long long num = pow(10, 15);
	//cout << num;
	BigInt x = "2034082";
	
	//stringstream s;
	//s << num;
	cout << setprecision(2030) << num;
}
