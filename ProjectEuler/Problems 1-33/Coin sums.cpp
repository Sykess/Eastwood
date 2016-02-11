

// problem 31
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;


int main()
{
	/*
	int max = 200;
	int sizes[] = {1, 2, 5, 10, 20, 50, 100, 200};
	int combos[max + 1];
	//combos[0] = 1;
	
	
	for(int x = 0; x < 8; x++)
	{
		for(int y = sizes[x]; y <= max; y++)
		{
			combos[y] += combos[y - sizes[x]];
		}
	}
	cout << combos[200]; */
	
            int target  = 200;
            int ways = 0;

            for (int a = target; a >= 0; a -= 200) {
                for (int b = a; b >= 0; b -= 100) {
                    for (int c = b; c >= 0; c -= 50) {
                        for (int d = c; d >= 0; d -= 20) {
                            for (int e = d; e >= 0; e -= 10) {
                                for (int f = e; f >= 0; f -= 5) {
                                    for (int g = f; g >= 0; g -= 2) {                                                                                    
                                                ways++;                                            
                                    }
                                }
                            }
                        }
                    }
                }
            }
            cout << ways;
}
