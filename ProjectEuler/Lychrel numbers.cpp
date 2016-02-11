
#include <iostream>

using namespace std;

bool isPal(string num, int start, int end);


int main()
{
	for(int 
	
}


bool isPal(string num, int start, int end)
{
	if(start >= end)
		return true;
	
	if(num[start] == num[end])
		return isPal(num, ++start, --end);
		
	return false;
}
