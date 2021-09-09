#include "board.h"
#include "../Card/card.h"

class Tile
{
	int cards_left;
	std::vector<Card*> cards_on_tile;
};

class Board
{
	std::vector<Tile*> tiles;
	Deck deck;
	Card revealed_card;

};

class Pile
{
	int number_of_cards_on_pile;
	Card last_card;
};