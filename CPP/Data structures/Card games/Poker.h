/*
 Program Name: Poker.h
 Author: Nathan Caron
 Assignment #8
 Date: 5/4/14
 Purpose: Class to play a game of 5 card stud.  The betting is working, however
 		  I spent so much time on that I didn't get around to making a working
 		  computer.  Since betting was optional, this doesn't change the
 		  basic game since without betting a computer player doesn't do anything.
*/


#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#include "cards.h"


#ifndef POKER_H
#define POKER_H
class Poker
{
	private:
		deckOfCards myDeck;
		string * hands;
		int pot;
		int * money;
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
		int scoreHand(string);
		void deal(int, bool[]);
		void displayHand(bool []);
		void getAnte(bool stillIn[]);
		void sortHand(string&);
		void welcome();
		void resetHands();
		void getBets(bool stillIn[], int dealer, int round);
	public:
		Poker();
		Poker(int);	
		void playGame();
		~Poker();
};

Poker::Poker()
{
	players = 2;
	pot = 0;
	myDeck.shuffleDeck();
	hands = new string[players];
	money = new int[players];
	for(int i = 0; i < players; i++)
	{
		hands[i] = "";
		money[i] = 200;
	}
	
}

Poker::Poker(int n)
{
	players = n;
	pot = 0;
	myDeck.shuffleDeck();
	hands = new string[players];
	money = new int[players];
	for(int i = 0; i < players; i++)
	{
		hands[i] = "";
		money[i] = 200;
	}
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
	//cout << "Hand is: " << hand << endl;
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

void Poker::displayHand(bool stillIn[])
{
	int counter = 0;
		
	for(int i = 0; i < players; i++)
	{
		if(!stillIn[i])
			continue;
		cout << "Player " << i+1 << ":\n";
		cout << "XX";
		for(int j = 2; j < hands[i].length(); j++)
		{
			if(counter % 2 == 0)
				cout << " ";
			cout << hands[i][j];
			counter++;
		}
		cout << "\n\n";
	}
	
}

void Poker::getBets(bool stillIn[], int dealer, int round)
{
	cout << "Betting round!\n";
	int choice;
	int currentBet = 0, tempBet = 0, minBet;
	int cont = 0;
	int max = 0;
	int loop = 0;
	
	if(round <= 2)
		minBet = 2;
	else
		minBet = 4;
	
	for(int i = 0; i < players; i++)
		if(stillIn[i])
			max++;
	
	//used cont and max so if a bet is made everyone has to react
	while(cont < max)
	{
		for(int i = 0; i < players; i++)
		{
			system("CLS");
			displayHand(stillIn);
			dealer++;

			if(dealer >= players)
				dealer = 0;
			if(!stillIn[dealer])
				continue;
			cout << "Player " << dealer+1 << "it's your turn to act\n"
				 << "Would you like to view your full hand? 1 for yes, 2 for no: ";
			cin >> choice;
		
			while(choice < 1 || choice > 2)
			{
				cout << "Invalid choice, 1 for yes or 2 for no: ";
				cin >>  choice;
			}
		
			if(choice == 1)
				cout << "\n" << hands[dealer];
			
			cout << "\nThe current bet is $" << currentBet
				 << "\nThe pot is $" << pot
				 << "\nYou have " << money[dealer] << " available.\n"
				 << "What do you want to do?\n1 to check/call\n"
				 << "2 to bet/raise\n3 to fold: ";
			 
				
			if(money[dealer] <= 0)
			{
				choice = 1;
				cout << "Auto check since out of money! Press any key\n";
				getch();
			}
			else
			{
				cin >> choice;
		
				while(choice < 1 || choice > 3)
				{
					cout << "Incorrect choice, choose 1-3: ";
					cin >> choice;
				}
			}	
	
			switch(choice)
			{
				case 1: cout << "Check/Call\n";
					//case of reraise, only works properly with 2
					if(tempBet > 0)
					{
						if(money[dealer] - currentBet < 0)
						{
							pot += money[dealer];
							money[dealer] = 0;
						}
						else
						{
							pot += currentBet;
							money[dealer]-= currentBet;
						}
						cont++;
						break;
					}
					
					if(money[dealer] - currentBet < 0)
					{
						pot += money[dealer];
						money[dealer] = 0;
					}
					else
					{
						pot += currentBet;
						money[dealer]-= currentBet;
					}
					cont++;
					break;
				case 2: cout << "Raise amount: ";
						cin >> tempBet;
						while(tempBet < 0 || tempBet > money[dealer]
							  || tempBet < minBet)
						{
							cout << "Invalid amount, minimum is "
								 << minBet << " Enter amount: ";
							cin >> tempBet;
						}
						cont = 1;
						currentBet += tempBet;
						money[dealer] -= currentBet;
						pot += currentBet;
						break;
				case 3: cout << "Folded!\n";
						stillIn[dealer] = false;
						max--;
						break;	
			};
			
			//keep counter of acts
			if(loop < 3)
			{
				loop++;
			}
			else
			{
				loop = 0;
				break;
			}
			
			//if everyone has acted since bet, break out of for loop
			if(cont >= max - 1)
				break;
		}
	
	}//end while
}

void Poker::getAnte(bool stillIn[])
{
	for(int i = 0; i < players; i++)
	{
		if(stillIn[i])
		{
			//$2 for ante
			money[i] -= 2;
			if(money[i] < 0)
			{
				pot += money[i] + 2;
				money[i] = 0;
			}
			else
				pot += 2;
		}
	}
}

void Poker::playGame()
{
	welcome();
	//dealer determines betting order and order in which cards
	//are dealt out
	int dealer = 0;
	int winner, winScore, choice;
	bool stillIn[players];
	
	do
	{
		system("CLS");
		resetHands();
		pot = 0;
		winner = 0;
		winScore = 0;
		myDeck.shuffleDeck();
		
		for(int i = 0; i < players; i++)
		{
			if(money[i] > 0)
				stillIn[i] = true;
			else
				stillIn[i] = false;
		}
		
		getAnte(stillIn);
		
		for(int i = 0; i < 5; i++)
		{
			deal(dealer, stillIn);
			if(i == 0)
				continue;
			displayHand(stillIn);
			getBets(stillIn, dealer, i);
			
		}
		
		for(int i = 0; i < players; i++)
		{
			if(!stillIn[i])
				continue;
			if(scoreHand(hands[i]) > winScore)
			{
				winner = i;
				winScore = scoreHand(hands[i]);
			}
			
			cout << "Player " << i+1 << "'s hand: "
			     << hands[i] << " which scores "
				 << scoreHand(hands[i]) << " points!\n\n";
		}
		cout << "\n\nThe winner is player " << winner + 1;
		money[winner]+= pot;
		
		//rotate dealer
		dealer >= players - 1 ? dealer = 0: dealer++;
		
		//cout << endl << "\nDealer  is: " << dealer+1;
		cout << "\n\nContinue playing? (1-yes, 2-no): ";
		cin >> choice;
		while(choice < 1 || choice > 2)
		{
			cout << "Incorrect entry, 1 for yes, 2 for no: ";
			cin >> choice;
		}
	}while(choice == 1);
	
}

void Poker::resetHands()
{
	for(int i = 0; i < players; i++)
		hands[i] = "";
}


void Poker::deal(int dealer, bool stillIn[])
{
	for(int i = 0; i < players; i++)
	{
		dealer++;
		if(dealer >= players)
			dealer = 0;
		if(!stillIn[dealer])
			continue;
		hands[dealer].append(myDeck.takeCard());
	}
}

Poker::~Poker()
{
	delete[] hands;
	delete[] money;
}

#endif

int main()
{
	Poker game;
	game.playGame();
}
