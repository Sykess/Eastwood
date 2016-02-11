

#include<iostream>
#include<string>
#include<cstring>
#include<sstream>
using namespace std;


int main()
{
	string test;
	double result;
	bool cont = true;
	
	do
	{
		cin >> test;
		stringstream convert(test);
		if(!(convert >> result))
			result = 0;
			
		cout << "double result " << result;
		
		cout << "size" << test.size();
		
		cout << "test at 0: " << test[0] << endl;
		
		
		cout << " " << test << "+";
	}while(cont);
	
	
	return 0;
}
