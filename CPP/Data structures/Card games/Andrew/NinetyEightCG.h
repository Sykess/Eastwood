/******************************************************************************
program: 	NinetyEightCG.h
author:		A.Hayden
date:		5/4/15
assignment:	...
purpose:	
******************************************************************************/

#include <time.h>
#include <cstdlib>
#include <conio.h>
#include "cards.h"

class NinetyEight
{
    private:
        string ** player;    //row column  
        deckOfCards deck;
        char choice;
        int pickCard;
        int pileVal;
        int playerNum;
    public:
        NinetyEight();
        string hand();
        int cardVal(string cardV); //send in card of choice returns value of card picked -> int(cardV) - 48
        void displayRules();
        void playNinetyEight(); // equivalent to main
        int pileValue(int);    //returns value of the pile;
        bool closeGame();
        ~NinetyEight();
};
///////////////////////////////////////////////////////////////////////////////
NinetyEight::NinetyEight()
{
	pileVal = 0;
	player = new string*[2];
	for(int i = 0; i < 2; i++)
		player[i] = new string[4];
	
	for(int i = 0; i < 2; i++)
		for(int j = 0; j < 4; j++)
			player[i][j] = "";
			
	deck.shuffleDeck();
	choice = 'a';
	pickCard = 0;
	playerNum = 0;
}
///////////////////////////////////////////////////////////////////////////////
string NinetyEight::hand()
{
        deck.shuffleDeck();
        for(int x = 0; x < 2; x++)
            for(int y = 0; y < 4; y++)
                player[x][y] = deck.takeCard();
}
///////////////////////////////////////////////////////////////////////////////
void NinetyEight::playNinetyEight() //equivalent to int main()
{
    displayRules();
    //pileVal = 0;
    playerNum = 1;
    do{
    	pileVal = 0;
        hand();
        while(pileVal <= 98)		//game continues until the pile is greater
        {							//than 98
        	cout << endl << endl;
        	cout << "\n\tPLAYER 1" << "\t\tPLAYER 2" << endl;
        	cout << "\n\t";
			for(int y = 0; y < 4; y++)
            	cout << player[0][y] << " ";
            
			cout << "\t" << pileVal << "\t";
			
            for(int y = 0; y < 4; y++)
            	cout << player[1][y] << " ";
            cout << endl;
            if(playerNum == 1)		//player 1
            {
            	cout << "\nPlayer " << playerNum << ": What card would you like"
            		 << " to play? (1-4): ";
            	do{
            		cin >> pickCard;
            		if((pickCard < 1) || (pickCard > 4))
            			cout << "\nInvalid card. Try again."<< endl;
				}while((pickCard < 1) || (pickCard > 4));
            	pileValue(cardVal(player[0][pickCard - 1]));
            	player[0][pickCard - 1] = deck.takeCard();
            	playerNum += 1;
			}
			
			if(pileVal > 98)
			{
				cout << "Player 1 loses, DRINK!\n";
				continue;
			}
			
			cout << "\nPile now has a value of " << pileVal << endl;
			
			if(playerNum == 2)		//player 2
            {
            	cout << "\nPlayer " << playerNum << ": What card would you like"
            		 << " to play? (1-4): ";
            	do{
            		cin >> pickCard;
            		if((pickCard < 1) || (pickCard > 4))
            			cout << "\nInvalid card. Try again."<< endl;
				}while((pickCard < 1) || (pickCard > 4));
            	pileValue(cardVal(player[1][pickCard - 1]));
            	player[1][pickCard - 1] = deck.takeCard();
            	playerNum -= 1;
			}
			
			if(pileVal > 98)
			{
				cout << "Player 2 loses, DRINK!\n";
				continue;
			}
		}
        
        do{
        	cout << "\nWould you like to play again Y/N: ";
        	cin >> choice;
		}while((choice != 'n') && (choice != 'N') && (choice != 'y') 
			  && (choice != 'Y'));
        
    }while((choice != 'n') && (choice != 'N'));
}
///////////////////////////////////////////////////////////////////////////////
void NinetyEight::displayRules()
{
    cout << "\nHELLO! Welcome to the game of 98!"
         << "\n The rules of this game are simple:"
         << "\n\t1) Each player gets 4 cards."
         << "\n\t2) Players take turns playing 1 card from their hand"
         << "\n\t3) The value of the pile is determined by the card played"
         << "\n\t4) First person to make the value of the pile MORE THAN 98"
         << "\n\t   loses the game AND MUST take a drink"
         << endl << endl;

    cout << "\n\t\tCARD VALUES"
         << "\n\t\t-----------"
         << "\n\tA to 9:\t\tIncreases value by face value"
         << "\n\t10:\t\treduce value by ten"
         << "\n\tJ,Q:\t\tvalue stays the same"
         << "\n\tK:\t\tvalue of the pile set to 98"
         << endl << endl;
    system("pause");
    system("CLS");
}
///////////////////////////////////////////////////////////////////////////////
int NinetyEight::cardVal(string cardV)
{
	switch(cardV[0])
	{
		case 'A':
			return 1;
		case '2':
			return 2;
		case '3':
			return 3;
		case '4':
			return 4;
		case '5':
			return 5;
		case '6':
			return 6;
		case '7':
			return 7;
		case '8':
			return 8;
		case '9':
			return 9;
		case 'T':
			return -10;
		case 'J':
			return 0;
		case 'Q':
			return 0;
		case 'K':
			return 98 - pileVal;
				
	}
}
///////////////////////////////////////////////////////////////////////////////
int NinetyEight::pileValue(int pile)
{
    return pileVal += pile;
}
///////////////////////////////////////////////////////////////////////////////
NinetyEight::~NinetyEight()
{
	for(int i = 0; i < 2; i++)
		delete[] player[i];
	delete[] player;
}
