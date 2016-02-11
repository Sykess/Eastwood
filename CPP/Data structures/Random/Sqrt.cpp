


#include <iostream>
#include <iomanip>
using namespace std;


float sqrt(float f);

int main()
{
	float f;
	cout << "Enter number to be square rooted: ";
	cin >> f;
	
	cout << "\nAnswer is: ";
	cout << setprecision(10) << sqrt(f);
	
	
}


float sqrt(float f)
{
	float answer = 0.2549729994354
	 + (1.172251620351 * f)
	 - (0.6720680317089 * (f * f))
	 + (0.3075057498669 * (f * f * f))
	 - (0.0626624251406 * (f * f * f * f));
	return answer;
}
