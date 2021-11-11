#pragma once
#include "Entities.h"



class Board
{
	std::vector<Tile*> tiles;
	Deck deck;
	std::vector<Card*> revealed_cards;
	std::vector<Pile*> piles;
public:

	Board();
	std::vector<Pile*>& getPiles();
	std::vector<Card*>& getRevealedCards();
	std::vector<Tile*> &getTiles();
	std::vector<Card*>& getCardsOnBoard();
	Deck& getDeck();
	void dealTheCards();
	std::vector<Card*> getCardsOnTopOfTiles();
	void setRevealedCards();
	void putCardFromDeckOnTile(Tile* tile, Card* chosen_card);
	void changeTileOfCards(Tile* old_tile, Tile* new_tile, Card* chosen_card);
	bool isPlacingCardHereLegal(Tile* new_tile, Card* clicked_card);
	Tile* getTileOnPosition(int mouse_position_x);
	Pile* getPileOnPosition(int mouse_position_x);
};