#include <iostream>
#include <vector>
using namespace std;

void create(vector<int> &tri, vector<int> &sqr, vector<int> &pent, vector<int> &hex,
		   vector<int> &hept, vector<int> &oct);


int main()
{
	vector<int> tri, sqr, pent, hex, hept, oct;
	create(tri, sqr, pent, hex, hept, oct);
	bool finished = false;
	
	while(!finished)
	{
		break;
	}
	
}

void create(vector<int> &tri, vector<int> &sqr, vector<int> &pent, vector<int> &hex,
		   vector<int> &hept, vector<int> &oct)
{
	int t, s, p, hx, hp, o, temp;
	
	for(int i = 1; i <= 140; i++)
	{
		t = i * (i + 1) / 2;
		s = i * i;
		p = i * (3 * i - 1) / 2;
		hx = i * (2 * i - 1);
		hp = i * (5 * i - 3) / 2;
		o = i * (3 * i - 2);
		
		if(t >= 1000 && t < 10000)
			tri.push_back(t);
		if(s >= 1000 && s < 10000)
			sqr.push_back(s);
		if(p >= 1000 && p < 10000)
			pent.push_back(p);
		if(hx >= 1000 && hx < 10000)
			hex.push_back(hx);
		if(hp >= 1000 && hp < 10000)
			hept.push_back(hp);
		if(o >= 1000 && o < 10000)
			oct.push_back(o);
	}
}
