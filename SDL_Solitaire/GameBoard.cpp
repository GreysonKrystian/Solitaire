#include "GameBoard.h"


Board::Board()
{
}

void Board::dealTheCards(sf::RenderWindow& window)
{
	for (int i = 0; i < 7; i++)
	{
		for (int k = 0; k < i; k++)
		{
			tiles[i]->getCardsOnTile().push_back(deck.drawRandomCard());
		}
	}
}

std::vector<Card*> Board::getRevealedCards()
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
	return cards;
}

bool Board::checkWinConditions()
{
	return false; //TODO
}

void Board::changeTileOfCard(Tile* old_tile, Tile* new_tile, Card* chosen_card)
{
	std::vector<Card*> cards_to_transfer;
	for (auto itr = old_tile->getCardsOnTile().begin(); itr < old_tile->getCardsOnTile().end(); itr++)
	{
		cards_to_transfer.push_back((*itr));
		old_tile->getCardsOnTile().pop_back();
		if ((*itr) == chosen_card)
			break;
	}
}

bool Board::checkIfChangeLegal(Tile* old_tile, Tile* new_tile, Card* chosen_card)
{
	// TODO

}

