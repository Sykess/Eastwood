#include <iostream>


int gcd(int a, int b);



int main()
{
    int a(3), b(2), lim(12000), result(0);

    for(int d = 5; d <= lim; ++d)
        for(int n = d / a + 1; n < (d - 1) / b + 1; ++n)
            if(gcd(n, d) == 1) result++;

    std::cout << result;


    return 0;
}

int gcd(int a, int b)
{
    int t(0);
    while(b != 0){
        t = b;
        b = a % b;
        a = t;
    }
    return a;
}
