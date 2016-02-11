

#include <iostream>
using namespace  std;

#include "Poker.h"
#include "cards.h"


int main()
{
	//while(1)
	//	cout << time(0) << endl << endl;
	Poker mygame(3);
	//deckOfCards deck;
	//deck.shuffleDeck();
	//deck.displayDeck();
	//string test2 = "Ts8s9s2s4s";
	//test2.append(deck.takeCard());
	/*test2 = "";
	
	test2.append(deck.takeCard());
	test2.append(deck.takeCard());
	test2.append(deck.takeCard());
	test2.append(deck.takeCard());
	test2.append(deck.takeCard());
	cout << test2 << endl;*/
	
	//string test = "2s3k4k6kAk";
	
	//cout << mygame.scoreHand(test2);
	//cout << endl << endl;
	//mygame.displayHand();
	//cout << endl;
	
	mygame.playGame();
	
	return 0;
	
}
