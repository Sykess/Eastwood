#include <iostream>


int Farey(int n);

int main()
{
    std::cout << Farey(12000) << std::endl;

    return 0;
}


int Farey(int n)
{
    int a(0), b(1), c(1), d(n), result(0);
    bool add = false;

    while(c <= n)
    {
        int k = (n + b) / d;
        int e = k * c - a;
        int f = k * d - b;
        a = c; b = d; c = e; d = f;
        if(a == 1 && b == 2) break;
        if(add) result++;
        if(a == 1 && b == 3) add = true;
    }
    return result;
}


