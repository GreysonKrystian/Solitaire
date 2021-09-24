#include "card.h"


std::string Card::getColor()
{
	return Card::color;
};

std::string Card::getValue()
{
	return Card::value;
};

Card::Card(std::string color, std::string value)
{
	color = color;
	value = value;
};

Deck::Deck(int cards_in_deck = 0)
{
	cards_in_deck = cards_in_deck;
};

int Deck::getCardsLeft()
{
	return Deck::cards_in_deck;
}

void Deck::addCard()
{
	this->cards_in_deck += 1;
}

void Deck::shuffleDeck()
{
	std::random_shuffle(this->cardsList.begin(), this->cardsList.end(), [](int n) { return rand() % n; });
}

int Deck::removeCard()
{
	return Deck::getCardsLeft() - 1;
}

int Deck::fillDeck()
{
	std::vector<std::string> possible_colors = { "Spades", "Clubs", "Diamonds", "Hearts" };
	std::vector<std::string> possible_values = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };
	for (std::vector<std::string>::iterator ptr = possible_colors.begin(); ptr < possible_colors.end(); ptr++)
	{
		for (std::vector<std::string>::iterator itr = possible_values.begin(); itr < possible_values.end(); itr++)
		{
			Card* card = new Card(*(ptr), *(itr));
			this->cardsList.push_back(card);
			addCard();
		}
	}
}

Card* Deck::drawRandomCard()
{	
	int random_value = 0;
	Card* card = cardsList[random_value];
	cardsList.erase(cardsList.begin() + random_value);
	removeCard();
	return card;
}