#include <iostream>
#include <vector>
using namespace std;

bool proper(int n, int d);

int main()
{
    int max = 1000000;
    unsigned long long total = 0;
    int phi[max+1];
    for(int i = 0; i <= max; ++i)
        phi[i] = i;

    for(int i = 2; i <= max; ++i){
        if(phi[i] == i){
            for(int j = i; j <= max; j+= i)
                phi[j] = phi[j] / i * (i - 1);
        }
        total += phi[i];
    }
    std::cout << total;

    /*
    for(int n = 1; n <= max; ++n)
    {
        for(int d = 1; d < n; ++d)
        {
            if(n%2 == 0 && d%2 == 0)
                continue;

            if(proper(n, d))
                total++;
        }
    }*/
    //std::cout << total;
    //std::cout << std::endl;

    return 0;
}

bool proper(int n, int d)
{
    for(int i = 2; i < n; ++i)
    {
        if(n % i == 0 && d % i == 0)
            return false;
    }
    return true;

}







