#include "board.h"


std::vector<Card*> Tile::getCardsOnTile()
	{
		return cards_on_tile;
	}

void Board::dealTheCards()
{
	for (int i = 0; i < 7; i++)
	{
		for (int k = 0; k < i; k++)
		{
			tiles[i]->getCardsOnTile()[k] = deck.drawRandomCard();
		}
			
	}
}

void Board::getRevealedCards()
{
	std::vector<Card*> cards;
	for (auto itr = tiles.begin(); itr < tiles.end(); itr++)
	{
		if ((*itr)->getCardsOnTile().size() != 0)
		{
			cards.push_back((*itr)->getCardsOnTile().back());
		}
		else
			cards.push_back(nullptr);
	}
}

bool Board::checkWinConditions()
{
	return false;
}

void Board::changeTileOfCard(Tile* previous_tile, Tile* new_tile)
{
	for (auto itr = tiles.begin(); itr < tiles.end(); itr++)
	{

	}
}

bool Board::checkIfChangeLegal()
{
	return false;
}
