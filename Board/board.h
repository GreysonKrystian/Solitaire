#pragma once
#include "../Card/card.h"

class Tile
{
	int cards_left;
	std::vector<Card*> cards_on_tile;
public:
	std::vector<Card*> getCardsOnTile();
};

class Board
{
	std::vector<Tile*> tiles;
	Deck deck;
	std::vector<Card*> revealed_cards;
public:
	void dealTheCards();
	void getRevealedCards();
	bool checkWinConditions();
	void changeTileOfCard(Tile* previous_tile, Tile* new_tile);
	void changeTileOfMultipleCards(Tile* previous_tile, Tile* new_tile);
	bool checkIfChangeLegal();
};

class Pile
{
	int number_of_cards_on_pile;
	Card* last_card;
};