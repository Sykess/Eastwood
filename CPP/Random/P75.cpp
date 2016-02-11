#include <iostream>

int gcd(int a, int b);

int main()
{
    const int limit = 1500000;
    // a = m^2 - n^2;  b = 2mn;  c = m^2 + n^2
    int triangles[limit+1];
    for(int i = 0; i < limit+1; ++i)
        triangles[i] = 0;

    int result(0), mLimit(1225); // mlimit found by sqrt(limit)

    for(long m = 2; m < mLimit; ++m){
        for(long n = 1; n < m; ++n){
            if(((n + m) % 2) == 1 && gcd(n, m) == 1){
                long a = m * m + n * n;
                long b = 2 * m * n;
                long c = m * m - n * n;
                long p = a + b + c;
                while(p <= limit){
                    triangles[p]++;
                    if(triangles[p] == 1) result++;
                    if(triangles[p] == 2) result--;
                    p += a+b+c;
                }
            }
        }
    }
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



