#include <iostream>


int main()
{
    int x(7);
    int a(x);

    a = a / x * (x - 1);
    std::cout << a;


    return 0;
}
