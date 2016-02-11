/******************************************************************************
program: 	NinetyEightCG.cpp
author:		A.Hayden
date:		5/4/15
assignment:	...
purpose:	to use given cards.h header file and create a two-player game
			of ninety eight. First to 98 by adding point value of cards loses
			and must take a drink
******************************************************************************/

#include <iostream>
using namespace std;
#include "NinetyEightCG.h"

int main()
{
	NinetyEight playMe;
	deckOfCards mine;
    mine.displayDeck();
    //cout << "Hi";
    playMe.playNinetyEight();
    cout << "\nSo far so good." << endl << endl;
    return 0;
}
