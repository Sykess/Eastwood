#include <iostream>
using namespace std;


int main()
{
	unsigned long long t(3), a(0), b(2), c(1), d(0), e(0), f(1);
	unsigned long long tt(0), aa(0), bb(0), cc(0);
	
	for(int i = 0; i < 30; i++)
	{
		aa = a;bb=b;cc=c;tt=t;
		
		t = 2 * tt + bb - aa;
		a = cc;
		b = 2 * bb - aa + d;
		c = tt - (aa + cc);
		d = e;
		e = f;
		f = tt;
		
	}
	cout << f;
}
