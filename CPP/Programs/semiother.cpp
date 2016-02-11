#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include "bitfield.h"

unsigned long * prime_sieve(const unsigned long bound)
{
	bitfield sieve(bound);
	unsigned long counter = 3; //2 is special now
	unsigned long tmp2;
	unsigned long amount = bound/2 + bound%2; //We remove 1 and even numbers altogether
	sieve.set(1);
	tmp2 = 4;
	while(tmp2 <= bound) {
		sieve.set(tmp2);
		tmp2 += 2;
	}
	while(counter <= bound) {
		if(!(sieve.get(counter))) {
			tmp2 = counter * 3;
			while(tmp2 <= bound) {
				if(!(sieve.get(tmp2))) {
					--amount;
					sieve.set(tmp2);
				}
				tmp2 += 2 * counter;
			}
		}
		counter+=2;
	}
	unsigned long * result = (unsigned long*)malloc((amount+1)*sizeof(unsigned long));
	if(result == NULL) {
		printf("Could not allocate memory!\n");
		exit(2);
	}
	counter = 1;
	tmp2 = 1;
	while(counter <= bound) {
		if(!(sieve.get(counter))) {
			result[tmp2] = counter;
			++tmp2;
		}
		counter+=2;
	}
	if(bound >= 2) {
		result[0] = 2;
		result[tmp2] = 0;
	} else
		result[0] = 0;
	return &result[0];
}

int main(int argc, char** argv)
{
	argc = 2;
	char * word = (char*)"100000000";
	argv[1] = word;
	if(argc != 2) {
		printf("Incorrect amount of arguments\n");
		exit(0);
	}
	unsigned long bound = strtoul(argv[1], NULL, 10);
	printf("Testing for primes...\n");
	unsigned long* primes = prime_sieve((bound)/2);
	std::cout << primes[0] << " " << primes[1] << std::endl;
	unsigned long counter1 = 0;
	unsigned long counter2 = 0;
	unsigned long amount = 0;
	printf("Checking composites...\n");
	while(primes[counter1] != 0) {
		counter2 = counter1;
		while(primes[counter2] != 0) {
			if((unsigned long long)primes[counter1]*primes[counter2] < bound) {
				++amount;
				++counter2;
			} else break;
		}
		++counter1;
	}
	printf("Result: %lu\n", amount);
	return 0;
}
