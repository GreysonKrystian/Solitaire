#include "Entities.h"


Card::Card(unsigned int image_indicator)
{
	std::vector<std::string> values = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "jack", "queen", "king", "ace"};
	std::vector<std::string> colors = {"spades", "clubs", "diamonds", "hearts"};
	for (auto values_itr = values.begin(); values_itr < values.end(); values_itr++)
	{
		for (auto colors_itr = colors.begin(); colors_itr < colors.end(); colors_itr++)
		{
			card_sprites.push_back("images/" + (*values_itr) + "_of_" + (*colors_itr) + ".png");
		}
	}
	sf::Texture texture;
	texture.loadFromFile(card_sprites[image_indicator]);
	type_of_card.setTexture(texture);
}

void Card::moveCard()
{
}

void Card::drawCard(sf::RenderWindow& window)
{

}

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
}
void Card::setPosition(sf::Vector2f given_position)
{
	position = given_position;
}

Deck::Deck()
{
}

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

void Deck::fillDeck()
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


Tile::Tile()
{
}

std::vector<Card*> Tile::getCardsOnTile()
{
	return cards_on_tile;
}

void Tile::addCardToTile(Card* card)
{
	cards_on_tile.push_back(card);
}

