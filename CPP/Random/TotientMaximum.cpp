
#include <iostream>

int relativelyPrime(int num);

int main()
{
    int number(0), total(1);
    double temp(0), max(0);

    // Easy way:
    int primes[] = {2,3,5,7,11,13,17,19,23,29};
    for(int i = 0; i < 10; ++i)
        if(total * primes[i] < 1000000)
            total *= primes[i];
    std::cout << total;

    // Hard way:
    /* 
    for(int i = 500000; i < 520000; i+= 2)
    {
        temp = (double) i / (double) relativelyPrime(i);
        if(temp > max)
        {
            max = temp;
            number = i;
        }
    }
    std::cout << number; */



    return 0;
}
    
int relativelyPrime(int num)
{
    int amount(1);
    if(num % 2 == 0)
    {
        for(int i = 3; i < num; i+= 2)
            if(num % i != 0)
                amount++;
        return amount;
    }

    for(int i = 2; i < num; ++i)
    {
        if(i % 3 == 0)
            continue;
        if(num % i != 0)
            amount++;
    }
    return amount;
}




