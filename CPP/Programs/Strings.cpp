
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isPrime(int n);
int findPairs(vector<int> vec);
void createVec(vector<int> & vec);
bool pairs(int a, int b);

int main()
{
	vector<int> vec;
	createVec(vec);
	cout << findPairs(vec);
	
	
}

bool isPrime(int n)
{
	if(n <= 1)
		return false;
	if(n == 2 || n == 3)
		return true;
	for(int i = 2; i <= n/2; i++)
	{
		if(n % i == 0)
			return false;
	}
	return true;
}

void createVec(vector<int> & vec)
{
	for(int i = 2; i < 1000; i++)
	{
		if(isPrime(i))
			vec.push_back(i);
	}
	
}


int findPairs(vector<int> vec)
{
	int a(0), b(1), c(2), d(3), e(4);
	
	while(true)
	{
		if(!pairs(vec[a],vec[e])){
			e++;continue;
		}
		if(!pairs(vec[a],vec[d])){
			d++;continue;
		}
		if(!pairs(vec[a],vec[c])){
			c++;continue;
		}
		if(!pairs(vec[a],vec[b])){
			b++;continue;
		}
		if(!pairs(vec[b],vec[e])){
			e++;continue;
		}
		if(!pairs(vec[b],vec[d])){
			d++;continue;
		}
		if(!pairs(vec[b],vec[c])){
			c++;continue;
		}
	}
}

int findPairs(vector<int> vec)
{
	for(int a = 0; a < vec.size()-5; a++){
	for(int b = a+1; b < vec.size()-4; b++){
	for(int c = b+1; c < vec.size()-4; c++){
	for(int d = c+1; d < vec.size()-3; d++){
	for(int e = d+1; e < vec.size()-2; e++)
	{
		if(!pairs(vec[a],vec[b]))
			continue;
		if(!pairs(vec[a],vec[c]))
			continue;
		if(!pairs(vec[a],vec[d]))
			continue;
		if(!pairs(vec[a],vec[e]))
			continue;
		if(!pairs(vec[b],vec[c]))
			continue;
		if(!pairs(vec[b],vec[d]))
			continue;
		if(!pairs(vec[b],vec[e]))
			continue;
		cout << vec[a] << " "<< vec[b] << " " << vec[c] << " " << vec[d] << " " << vec[e];
		return vec[a] + vec[b] + vec[c] + vec[d] + vec[e];
		
						
	}//end e
	}//end d
	}//end c
	}//end b
	}//end a
	return 0;
}


bool pairs(int a, int b)
{
	string c, d, e;
	c = to_string(a);
	d = to_string(b);
	e = c + d;
	d += c;
	if(isPrime(stoi(e)) && isPrime(stoi(d)))
		return true;
	return false;
}




