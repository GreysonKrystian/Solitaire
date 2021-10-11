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
	std::vector<Tile*> getTiles();
	void dealTheCards(sf::RenderWindow& window);
	std::vector<Card*> getRevealedCards();
	bool checkWinConditions();
	void changeTileOfCard(Tile* old_tile, Tile* new_tile, Card* chosen_card);
	bool checkIfChangeLegal(Tile* old_tile, Tile* new_tile, Card* chosen_card);
};