

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

#include "cards.h"


int main()
{
	deckOfCards deck;
	string blah;

	blah = deck.takeCard();
	cout << blah << "+";
	blah = deck.takeCard();
	cout << blah.append("h");
	
	deck.displayDeck();
}
