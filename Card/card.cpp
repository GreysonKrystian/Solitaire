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
	auto rng = std::default_random_engine{};
	std::random_shuffle(this->cardsList.begin(), this->cardsList.end(), rng);
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
