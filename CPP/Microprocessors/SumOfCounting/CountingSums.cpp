

#include "CountingSums.h"
#include "Arduino.h"


//my initial function that took  12 seconds, so I found other
//ways to keep things interesting
int sumOfCounting(int num)
{
  int total = 0;
  for(int x = 1; x <= num; x++)
    total += x;
  return total;
}

int sumAnotherWay(int num)
{
  int index = 0, total = 0;
  //started index at 0 and incremented index before adding
  //to total so I could use < instead of <=
  while(index < num)
  {
    index++;
    total += index;
  }
  return total;
}

int sumWithRecursion(int num, int index, int total)
{
  // base case, once index goes above num, return total
  if(num < index)
    return total;
  return sumWithRecursion(num, index + 1, total += index);
}

//I got creative here
int sumOverlyComplicated(int num)
{
  if(num % 2 == 0)
    complicatedEven(num);
  else
    complicatedOdd(num);
}

int complicatedEven(int num)
{
  int total = 0;
  //start at 2, increment by 2, adding all even numbers to total
  for(int x = 2; x <= num; x+= 2)
    total += x;
  //if number was even to begin with, need to add odd numbers	
  if(num % 2 == 0)
    total += complicatedOdd(num);
		
  return total;
}

int complicatedOdd(int num)
{
  int total = 0;
  //start at 1, increment by 2, adding all odd numbers to total
  for(int x = 1; x <= num; x+= 2)
    total += x;
  //if number odd to begin with, need to add even numbers	
  if(num % 2 != 0)
    total += complicatedEven(num);
	
  return total;
}

//pair off the first and last numbers and work towards eachother
//such as 1 + 100, 2 + 99, 3 + 98.  Every pair is 101, and there
//are 50 pairs in the N=100 problem.  This helps lead to the
//formula, since N/2 pairs multiplied by N + 1 gives you the
//total.
int pairs(int num)
{
  int high = num;
  int total = 0;
	
  for(int low = 1; high > low; high--, low++)
    total += high + low;

  return total;
}

//and taking the pairs one step further...
int pairsFormula(int num)
{
  float pairs = (float)num / 2;
  return pairs * (num + 1);
}
