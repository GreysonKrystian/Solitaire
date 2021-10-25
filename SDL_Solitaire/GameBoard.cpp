#include "GameBoard.h"


Deck &Board::getDeck()
{
	return deck;
}

Board::Board()
{
	Tile* tile_one = new Tile({ 100, 250 });
	Tile* tile_two = new Tile({ 100 + 220, 250 });
	Tile* tile_three = new Tile({ 100 + 220*2, 250 });
	Tile* tile_four = new Tile({ 100 + 220*3, 250 });
	Tile* tile_five = new Tile({ 100 + 220*4, 250 });
	Tile* tile_six = new Tile({ 100 + 220*5, 250 });
	Tile* tile_seven = new Tile({ 100 + 220*6, 250 });

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
			cards.push_back(*iter);
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
			float y = 250 + k * 20;
			card->setPosition({ x, y }, {x + card->getSize().x, y + card->getSize().y });
			if (k == i)
			{
				card->changeIsRevealedState();
				card->changeIsOnTopState();
			}
		}
	}
}

std::vector<Card*> Board::getCardsOnTopOfTiles()
{
	std::vector<Card*> cards_on_top;
	for (auto itr = tiles.begin(); itr != tiles.end(); itr++)
	{
		if (!(*itr)->getCardsOnTile().empty())
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
			if ((*iter)->isOnTop())
			{
				revealed_cards.push_back(*iter);
			}
		}
	}
}


void Board::changeTileOfCards(Tile* old_tile, Tile* new_tile, Card* chosen_card)
{
	std::list<Card*> cards_to_transfer;
	for (auto itr = old_tile->getCardsOnTile().rbegin(); itr != old_tile->getCardsOnTile().rend(); itr++)
	{
		cards_to_transfer.push_front(*itr);
		if ((*itr) == chosen_card)
			break;
	}
	for (unsigned int i = 0 ; i < cards_to_transfer.size(); i++)
	{
		old_tile->getCardsOnTile().pop_back();
	}
	new_tile->getCardsOnTile().back()->changeIsOnTopState();
	for (auto itr = cards_to_transfer.begin(); itr!= cards_to_transfer.end(); itr++)
	{
		(*itr)->setPosition({ new_tile->getPositionOnBoard().x, new_tile->getCardsOnTile().back()->getRevealedPartPosition()[0].y+20 },
			{ new_tile->getPositionOnBoard().x + chosen_card->getSize().x, new_tile->getCardsOnTile().back()->getRevealedPartPosition()[0].y + chosen_card->getSize().y+20 });
		new_tile->addCardToTile((*itr));
	}
	old_tile->getCardsOnTile().back()->changeIsOnTopState();
}

bool Board::isTileChangeLegal(Tile* old_tile, Tile* new_tile, Card* clicked_card)
{
	// add to empty tile  TODO
	// deal with king clicked
	std::vector<std::string> value_order = { "ace","2","3","4","5","6","7","8","9","10","jack","queen","king" };
	if (std::find(value_order.begin(), value_order.end(), new_tile->getCardsOnTile().back()->getValue()) !=
		std::find(value_order.begin(), value_order.end(), clicked_card->getValue())+1)
	{
		return false;
	}
	if (clicked_card->getColor() == "spades" || clicked_card->getColor() == "clubs")
	{
		if (new_tile->getCardsOnTile().back()->getColor() == "spades" || new_tile->getCardsOnTile().back()->getColor() == "clubs")
		{
			return false;
		}
	}
	else
	{
		if (new_tile->getCardsOnTile().back()->getColor() == "diamonds" || new_tile->getCardsOnTile().back()->getColor() == "hearts")
		{
			return false;
		}
	}
	return true;
}

Tile* Board::getTileOnPosition(int mouse_position_x)
{
	const int tile_index = (mouse_position_x - 100) / 220;
	return getTiles()[tile_index];
}

std::vector<Card*>& Board::getRevealedCards()
{
	return revealed_cards;
}