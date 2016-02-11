
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
using namespace std;

#include "cards.h"




class Poker
{
	private:
		deckOfCards myDeck;
		string * hands;
		int players;
		int royalFlush(string);
		int straightFlush(string);
		int fourOfAKind(string);
		int fullHouse(string);
		int flush(string);
		int straight(string);
		int threeOfAKind(string);
		int twoPair(string);
		int pair(string);
		int highCard(string);
		int intVal(char);
		void sortHand(string&);
		void welcome();
	public:
		Poker(int);
		int scoreHand(string);
		void firstDeal();
		void deal();
		void displayHand(int);
		string getCard();
		~Poker();
};

Poker::Poker(int n)
{
	players = n;
	myDeck.shuffleDeck();
	hands = new string[players];
	for(int i = 0; i < players; i++)
		hands[i] = "";
}

void Poker::welcome()
{
	cout << "******************************************\n"
	     << "******************************************\n"
		 << "******************************************\n"
		 << "******* W E L C O M E ******  T O ********\n"
		 << "******************************************\n"
		 << "************* N A T E ' S ****************\n"
		 << "******************************************\n"
		 << "********* P O K E R *** G A M E **********\n"
		 << "******************************************\n"
		 << "******************************************\n"
		 << "******************************************\n"
		 << "\nPress any key to continue...";
	getch();
	system("CLS");
}

string Poker::getCard()
{
	return myDeck.takeCard();
}

int Poker::intVal(char c)
{
	// if c is 2-9
	if(c >= 50 && c <= 57)
		return int(c) - 48;
	if(c == 'T')
		return 10;
	if(c == 'J')
		return 11;
	if(c == 'Q')
		return 12;
	if(c == 'K')
		return 13;
	if(c == 'A')
		return 14;
	cout << c << endl;
	cout << "Error!";
	return 0;
}

int Poker::scoreHand(string hand)
{
	sortHand(hand);
	cout << "Hand is: " << hand << endl;
	if(royalFlush(hand))
		return royalFlush(hand);
	if(straightFlush(hand))
		return straightFlush(hand);
	if(fourOfAKind(hand))
		return fourOfAKind(hand);
	if(fullHouse(hand))
		return fullHouse(hand);
	if(flush(hand))
		return flush(hand);
	if(straight(hand))
		return straight(hand);
	if(threeOfAKind(hand))
		return threeOfAKind(hand);
	if(twoPair(hand))
		return twoPair(hand);
	if(pair(hand))
		return pair(hand);
	//default if no others are true
	return highCard(hand);
}

int Poker::royalFlush(string hand)
{
	if(straightFlush(hand) == 134)
		return 135;
	return 0;
}

int Poker::straightFlush(string hand)
{
	if(hand.length() < 10)
		return 0;
	if(flush(hand) && straight(hand))
	{
		if(intVal(hand[0]) == 2 && intVal(hand[8]) == 14)
			return 120 + intVal(hand[6]);
		return 120 + intVal(hand[8]);
	}
	return 0;
}

int Poker::fourOfAKind(string hand)
{
	if(hand.length() < 8)
		return 0;
	if(hand[0] == hand[2] && hand[2] == hand[4] && hand[4] == hand[6])
	{
		if(hand[0] > 57)
			return 105 + intVal(hand[0]);
		else
			return 105 + ((int)hand[0] - 48);
	}
	if(hand.length() < 10)
		return 0;
	if(hand[2] == hand[4] && hand[4] == hand[6] && hand[6] == hand[8])
		return 105 + intVal(hand[2]);
	return 0;
}

int Poker::fullHouse(string hand)
{
	if(hand.length() < 10)
		return 0;
		
	if(hand[0] == hand[2] && hand[4] == hand[6] && hand[6] == hand[8])
		return 90 + intVal(hand[4]);

	if(hand[0] == hand[2] && hand[2] == hand[4] && hand[6] == hand[8])
		return 90 + intVal(hand[0]);

	return 0;
}

int Poker::flush(string hand)
{
	if(hand.length() < 10)
		return 0;
	for(int i = 1; i < 8; i+= 2)
	{
		if(hand[i] != hand[i + 2])
			return 0;
	}
	return 75 + intVal(hand[8]);
}

int Poker::straight(string hand)
{
	if(hand.length() < 10)
		return 0;
	if(intVal(hand[0]) + 1 != intVal(hand[2]))
		return 0;
	if(intVal(hand[2]) + 1 != intVal(hand[4]))
		return 0;
	if(intVal(hand[4]) + 1 != intVal(hand[6]))
		return 0;
	if(intVal(hand[8]) == 14)
	{
		if(intVal(hand[0]) == 2)
			return 60 + intVal(hand[6]);
		if(intVal(hand[6]) == 13)
			return 74;
	}
	if(intVal(hand[6]) + 1 != intVal(hand[8]))
		return 0;
	return 60 + intVal(hand[8]);
}

int Poker::threeOfAKind(string hand)
{
	for(int i = 0; i <= 4; i+=2)
	{
		if(hand[i] == hand[i + 2] && hand[i + 2] == hand[i + 4])
			return 45 + intVal(hand[i]);
	}
	return 0;
}

int Poker::twoPair(string hand)
{
	if(hand[0] == hand[2])
		if(hand[4] == hand[6])
			return 30 + intVal(hand[4]);
		else if(hand[6] == hand[8])
			return 30 + intVal(hand[6]);
	if(hand[2] == hand[4] && hand[6] == hand[8])
		return 30 + intVal(hand[6]);
	return 0;
}

int Poker::pair(string hand)
{
	
	for(int i = 0; i <= 6; i+=2)
	{
		if(hand[i] == hand[i + 2])
			return 15 + intVal(hand[i]);
	}
	return 0;
}

int Poker::highCard(string hand)
{
	int length = hand.length();
	if(length == 0)
		return 0;
	return intVal(hand[length - 2]);
}

void Poker::sortHand(string & hand)
{
	int cards = hand.length() / 2;
	string temp[cards];
	string tempCard;
	char suit;
	int index = 0;
	
	for(int i = 0; i < cards; i++)
	{
		temp[i] = hand[index++];
		tempCard = hand[index++];
		temp[i].append(tempCard);
	}
	
	for(int i = 0; i < cards - 1; i++)
	{
		if(intVal(temp[i][0]) > intVal(temp[i+1][0]))
		{
			tempCard = temp[i];
			temp[i] = temp[i+1];
			temp[i+1] = tempCard;
			if(i != 0)
				i-= 2;
		}
	}
	hand = "";
	for(int i = 0; i < cards; i++)
	{
		hand.append(temp[i]);
	}
}

void Poker::firstDeal()
{
	for(int i = 0; i < 5; i++)
		for(int p = 0; p < players; p++)
			hands[p].append(myDeck.takeCard());
	
			
	cout << hands[0] << " score: " << scoreHand(hands[0]) << endl;
	cout << hands[1] << " score: " << scoreHand(hands[1]) << endl;
}

void Poker::displayHand(int player)
{
	
	
}


void Poker::deal()
{
	
	
}

Poker::~Poker()
{
	delete[] hands;
}
