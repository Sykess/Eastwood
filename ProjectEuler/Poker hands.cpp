

#include <iostream>
#include <fstream>
using namespace std;

#include "Poker.h"



int main()
{
	fstream file;
	string temp;
	string str1 = "";
	string str2 = "";
	int player = 0;
	int count = 1;
	Poker poke(2);
	int wins = 0;
	cout << "blah";
	file.open("poker.txt", ios::in);
	cout << "blah";
	
	while(!file.eof())
	{
		file >> temp;
		if(player < 5)
		{
			str1.append(temp);
			player++;
		}
		else
		{
			str2.append(temp);
			player++;
		}
		if(player == 10)
			player = 0;
		if(count == 10)
		{
			if(poke.scoreHand(str1) > poke.scoreHand(str2))
			{
				wins++;
				cout << "Player 1 wins!" << endl;
			}
			str1 = "";
			str2 = "";
			count = 0;
		}
		count++;
		//cout << "Hi" << endl;
		//cout << temp << endl;
	}
	cout << "Wins: " << wins;
	file.close();
}
