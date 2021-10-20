#include "GameBoard.h"


Board::Board()
{
	Tile* tile_one = new Tile();
	Tile* tile_two = new Tile();
	Tile* tile_three = new Tile();
	Tile* tile_four = new Tile();
	Tile* tile_five = new Tile();
	Tile* tile_six = new Tile();
	Tile* tile_seven = new Tile();

	tiles = {
		tile_one, tile_two, tile_three, tile_four, tile_five, tile_six, tile_seven
	};
}

std::vector<Tile*> &Board::getTiles()
{
	return tiles;
}



std::vector<Card*>& Board::getCardsOnBoard()
{
	std::vector<Card*> cards;
	for (auto itr = tiles.begin(); itr != tiles.end(); itr++)
	{
		for (auto iter = (*itr)->getCardsOnTile().begin(); iter != (*itr)->getCardsOnTile().end(); iter++)
		{
			cards.push_back((*iter));
		}
	}
	return cards;
}

void Board::dealTheCards()
{
	for (int i = 0; i < 7; i++)
	{
		for (int k = 0; k <= i; k++)
		{
			Card* card = deck.drawRandomCard();
			tiles[i]->addCardToTile(card);
			float x = 100 + i * 220;
			float y = 250 + k * 30;
			card->setPosition({ x, y }, {x+125.0f, y + 181.5f });
			if (k == i)
			{
				card->changeIsRevealedState();
				card->changeIsOnTopState();
			}
		}
	}
}

std::vector<Card*>& Board::getCardsOnTopOfTiles()
{
	std::vector<Card*> cards_on_top;
	for (auto itr = tiles.begin(); itr != tiles.end(); itr++)
	{
		if ((*itr)->getCardsOnTile().size() != 0)
			cards_on_top.push_back((*itr)->getCardsOnTile().back());
		else
			cards_on_top.push_back(nullptr);
	}
	return cards_on_top;
}

void Board::setRevealedCards() // syf
{

	for (auto itr = tiles.begin(); itr != tiles.end(); itr++)
	{
		for (auto iter = (*itr)->getCardsOnTile().begin(); iter != (*itr)->getCardsOnTile().end(); iter++)
		{
			if ((*iter)->checkIfIsOnTop())
			{
				revealed_cards.push_back((*iter));
			}
		}
	}
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

bool Board::isTileChangeLegal(Tile* old_tile, Tile* new_tile, Card* clicked_card)
{
	// add to empty tile  TODO
	// deal with king clicked
	std::vector<std::string> value_order = { "ace","2","3","4","5","6","7","8","9","10","jack","queen","king" };
	if (std::find(value_order.begin(), value_order.end(), clicked_card->getValue()) != (std::find(value_order.begin(), value_order.end(), new_tile->getCardsOnTile().back()->getValue())))
	{
		return false;
	}
	if (clicked_card->getColor() == "Spades" || clicked_card->getColor() == "Clubs")
	{
		if (new_tile->getCardsOnTile().back()->getColor() == "Spades" || new_tile->getCardsOnTile().back()->getColor() == "Clubs")
		{
			return false;
		}
	}
	else
	{
		if (new_tile->getCardsOnTile().back()->getColor() == "Diamonds" || new_tile->getCardsOnTile().back()->getColor() == "Hearts")
		{
			return false;
		}
	}
	return true;
}

