
#include <iostream>
#include <string>
#include <set>
using namespace std;
using ULL = unsigned long long;

bool isPal(string str, int start, int end);


int main()
{
	set<ULL> myList;
	
	ULL runningTotal(0);
	ULL j(0);
	ULL totalSum(0);
	string str = "";
	
	for(ULL i = 1; i < 10000; ++i)
	{
		j = i + 1;
		runningTotal = (i * i) + (j * j);
		
		while(runningTotal < 100000000)
		{
			str = to_string(runningTotal);
			if(isPal(str, 0, str.length()-1 ))
			{
				myList.insert(runningTotal);
			}
			++j;
			runningTotal += (j * j);
		}
	}
	//can just use auto for set<ULL>::iterator
	for (set<ULL>::iterator i = myList.begin(); i != myList.end(); i++)
	{
		totalSum += *i;
	}
	cout << totalSum;
	
}

bool isPal(string str, int start, int end)
{
	if(start >= end)
		return true;
	if(str[start] != str[end])
		return false;
	if(str[start] == str[end])
		return isPal(str, start + 1, end - 1);
	return false;
}

/*
I don't think anyone else said this before, so here goes.

There's no need to precalculate squares. There's a closed form expression for 
sum of consecutive squares:

(1/6)[ m(m+1)(2m+1) - (n-1)(n)(2n-1) ]

where m is the last number in the series, and n the first. This comes from the closed 
form expression for the sum of the squares of the first n natural numbers:

n(n+1)(2n+1)/6

So each time through the outer loop, calculate the second term, and in the inner loop,
calculate first term and subtract. Blazing fast.
*/

