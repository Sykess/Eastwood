

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstring>
using namespace std;


struct Card
{
	string person;
	string action;
	string object;
	string suit;
	int cardNum;
};

void loadDeck();

Card deck[52];

//  0 - 12: Spades
// 13 - 25: Clubs
// 26 - 38: Hearts
// 39 - 51: Diamonds

int main()
{
	loadDeck();
	
	cout << deck[39].cardNum << " " << deck[49].person << " " << deck[0].object;
	
	
	
	return 0;
}

void loadDeck()
{
	ifstream file;
	file.open("PAO.txt", ios::in);
	string token;
	int x, y, z = 0;
	char temp[35];
	
	while(getline(file, token))
	{
		x = y = 0;
		for(int i = 0; i < 5; i++)
		{
		
			while(token[x] != ';' && token[x] != '\0')
			{
				temp[y] = token[x];
				x++;
				y++;
			}
			temp[y] = '\0';
			if(i == 0)
				deck[z].cardNum = atoi(temp);
			if(i == 1)
				deck[z].suit = temp;
			if(i == 2)
				deck[z].person = temp;
			if(i == 3)
				deck[z].action = temp;
			if(i == 4)
				deck[z].object = temp;
			y = 0;
			x++;
		}
		z++;
	}
	file.close();
}



