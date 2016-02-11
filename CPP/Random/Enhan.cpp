#include <iostream>
using namespace std;


int main()
{
    int array[] = {0,1,2,3,4,5};
    for(int i : array )
    {
        //cout << i;
        array[i] += 1;
    }
    for(int i : array )
        cout << i;
    return 0;
}

