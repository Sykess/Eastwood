

#include <iostream>
#include <conio.h>
using namespace std;
#include "cards.h"

int main()
{
	deckOfCards myDeck;
	cout << "Press any key";
	getch();
	myDeck.shuffleDeck();
	myDeck.displayDeck();
	cout << endl << endl <<  clock();
	
}
