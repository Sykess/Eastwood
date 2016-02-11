
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

#define ONETHROUGHNINE 36
#define TENTONINETEEN 70
#define HUNDRED 7
#define HUNDREDAND 10
#define THOUSAND 11

int main()
{
	int total;
	
	total+= ONETHROUGHNINE;
	total+= TENTONINETEEN;
	// 20-99
	total+= 10 * (6 + 6 + 5 + 5 + 5 + 7 + 6 + 6) + (8 * ONETHROUGHNINE);
	//1-99 occurs 10 times
	total*= 10;
	// 1 through 9 said for hundreds ie ONE hundred and..., TWO hundred and...
	total += ONETHROUGHNINE * 100;
	total += HUNDRED * 9;
	//hundredand said 99 times per hundred with 9 hundreds
	total += HUNDREDAND * 9 * 99;
	//and lastly 1000
	total+= THOUSAND;
	
	cout << total;
	
}


