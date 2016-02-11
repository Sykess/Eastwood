
#include <iostream>
using namespace std;


bool isPalindrome(int num, int base);


int main()
{
	int limit = 1000000;
	int result = 0;
	
	for(int x = 1; x < limit; x += 2)
	{
		if(isPalindrome(x, 10) && isPalindrome(x, 2))
			result += x;
	}
	cout << result;

}


bool isPalindrome(int num, int base)
{
	int reversed = 0;
	int n = num;
	
	while(n > 0)
	{
		reversed = reversed * base + n % base;
		n /= base;
	}
	return num == reversed;
}
