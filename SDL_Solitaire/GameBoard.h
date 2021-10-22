#pragma once
#pragma once
#include "Entities.h"



class Board
{
	std::vector<Tile*> tiles;
	Deck deck;
	std::vector<Card*> revealed_cards;
public:
	Board();
	std::vector<Card*>& getRevealedCards();
	std::vector<Tile*> &getTiles();
	std::vector<Card*>& getCardsOnBoard();
	void dealTheCards();
	std::vector<Card*> getCardsOnTopOfTiles();
	void setRevealedCards();
	void changeTileOfCards(Tile* old_tile, Tile* new_tile, Card* chosen_card);
	bool isTileChangeLegal(Tile* old_tile, Tile* new_tile, Card* clicked_card);
	Tile* getTileOnPosition(int mouse_position_x);
};