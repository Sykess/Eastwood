

#include <iostream>
using namespace std;


int main()
{
    int result = 0;
    int maxLength = 0;
    for (int i = 1; i < 1000 ; ++i) {
        int rest = 1;
        for (int j = 0; j < i; j++)
            rest = (rest * 10) % i;
        int firstRemainder = rest;
        int recurringCycleLength = 0;
        do {
            rest = (rest * 10) % i;
            ++recurringCycleLength;
        } while (rest != firstRemainder);
        if (recurringCycleLength > maxLength) {
            result = i;
            maxLength = recurringCycleLength;
        }
    }
    cout << result << endl << maxLength;
    return 0;
}
