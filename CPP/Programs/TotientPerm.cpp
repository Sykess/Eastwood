#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int n);
bool isPerm(long a, long b);

int main()
{
	vector<int> vec;
	long best(1), phiBest(1);
	double bestRat = 1000;
	
	for(int i = 2000; i < 5000; i++)
		if(isPrime(i))
			vec.push_back(i);
	cout << isPerm(871029,792801);
	
	for(int i = 0; i < vec.size(); i++)
	{
		for(int j = i+1; j < vec.size(); j++)
		{
			long n = vec[i] * vec[j];
			if(n > 10000000)
				break;
			long phi = (vec[i] - 1) * (vec[j] - 1);
			double ratio = (double) n / phi;
			
			if(isPerm(n, phi) && bestRat > ratio)
			{
				best = n;
				phiBest = phi;
				bestRat = ratio;
			}
		}
	}
	cout << "Best: " << best << "\nPhi Best: " << phiBest << "\nBest Ratio: " << bestRat;
	
}

bool isPerm(long a, long b)
{
	int array[10] = {0};
	
	while(a > 0)
	{
		array[a % 10]++;
		a /= 10;
	}
	while(b > 0)
	{
		array[b % 10]--;
		b /= 10;
	}
	
	for(int i = 0; i < 10; i++)
	{
		if(array[i] != 0)
			return false;
	}
	return true;
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
