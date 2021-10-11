#include "Entities.h"


std::vector<sf::Vector2f> Card::getReveledPart()
{
	std::vector<sf::Vector2f> revealed;
	if (is_on_top)
	{
		revealed = { position[0], {position[0].x + 0, position[1].y + 0} }; //TODO
	}
	else
	{
		revealed = { position[0], position[3] };
	}
	return revealed;
}

Card::Card(std::string color, std::string value)
{
	this->color = color;
	this->value = value;
	type_of_card.setScale(0.25, 0.25);
	this->is_revealed = false;
}

void Card::moveCard()
{
}


void Card::drawCard(sf::RenderWindow& window)
{
	sf::Texture texture;
	if (is_revealed)
		texture.loadFromFile("images/" + value + "_of_" + color + ".png");
	else
		texture.loadFromFile("card_back/basic.jpg");
	type_of_card.setTexture(texture);
	type_of_card.setPosition(position[0]);
	window.draw(type_of_card);
}

std::string Card::getColor()
{
	return Card::color;
};

std::string Card::getValue()
{
	return Card::value;
};


void Card::setPosition(sf::Vector2f left_upper_corner, sf::Vector2f left_lower_corner, sf::Vector2f right_upper_corner, sf::Vector2f right_lower_corner)
{
	position = {left_upper_corner, left_lower_corner, right_upper_corner, right_lower_corner};
}

sf::Sprite Deck::getCardBack()
{
	return card_back;
}

Deck::Deck()
{
	fillDeck();
	shuffleDeck();
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
	std::random_shuffle(this->cards_list.begin(), this->cards_list.end(), [](int n) { return rand() % n; });
}

void Deck::removeCard()
{
	cards_in_deck -= 1;
}

void Deck::fillDeck()
{

	Card* two_s = new Card("spades", "2");
	Card* two_c = new Card("clubs", "2");
	Card* two_d = new Card("diamonds", "2");
	Card* two_h = new Card("hearts", "2");

	Card* three_s = new Card("spades", "3");
	Card* three_c = new Card("clubs", "3");
	Card* three_d = new Card("diamonds", "3");
	Card* three_h = new Card("hearts", "3");

	Card* four_s = new Card("spades", "4");
	Card* four_c = new Card("clubs", "4");
	Card* four_d = new Card("diamonds", "4");
	Card* four_h = new Card("hearts", "4");

	Card* five_s = new Card("spades", "5");
	Card* five_c = new Card("clubs", "5");
	Card* five_d = new Card("diamonds", "5");
	Card* five_h = new Card("hearts", "5");

	Card* six_s = new Card("spades", "6");
	Card* six_c = new Card("clubs", "6");
	Card* six_d = new Card("diamonds", "6");
	Card* six_h = new Card("hearts", "6");

	Card* seven_s = new Card("spades", "7");
	Card* seven_c = new Card("clubs", "7");
	Card* seven_d = new Card("diamonds", "7");
	Card* seven_h = new Card("hearts", "7");

	Card* eight_s = new Card("spades", "8");
	Card* eight_c = new Card("clubs", "8");
	Card* eight_d = new Card("diamonds", "8");
	Card* eight_h = new Card("hearts", "8");

	Card* nine_s = new Card("spades", "9");
	Card* nine_c = new Card("clubs", "9");
	Card* nine_d = new Card("diamonds", "9");
	Card* nine_h = new Card("hearts", "9");

	Card* ten_s = new Card("spades", "10");
	Card* ten_c = new Card("clubs", "10");
	Card* ten_d = new Card("diamonds", "10");
	Card* ten_h = new Card("hearts", "10");

	Card* jack_s = new Card("spades", "jack");
	Card* jack_c = new Card("clubs", "jack");
	Card* jack_d = new Card("diamonds", "jack");
	Card* jack_h = new Card("hearts", "jack");

	Card* queen_s = new Card("spades", "queen");
	Card* queen_c = new Card("clubs", "queen");
	Card* queen_d = new Card("diamonds", "queen");
	Card* queen_h = new Card("hearts", "queen");

	Card* king_s = new Card("spades", "king");
	Card* king_c = new Card("clubs", "king");
	Card* king_d = new Card("diamonds", "king");
	Card* king_h = new Card("hearts", "king");

	Card* ace_s = new Card("spades", "ace");
	Card* ace_c = new Card("clubs", "ace");
	Card* ace_d = new Card("diamonds", "ace");
	Card* ace_h = new Card("hearts", "ace");

	cards_list = {

	two_s,
	two_c,
	two_d,
	two_h,
	three_s,
	three_c,
	three_d,
	three_h,
	four_s,
	four_c,
	four_d,
	four_h,
	five_s,
	five_c,
	five_d,
	five_h,
	six_s,
	six_c,
	six_d,
	six_h,
	seven_s,
	seven_c,
	seven_d,
	seven_h,
	eight_s,
	eight_c,
	eight_d,
	eight_h,
	nine_s,
	nine_c,
	nine_d,
	nine_h,
	ten_s,
	ten_c,
	ten_d,
	ten_h,
	jack_s,
	jack_c,
	jack_d,
	jack_h,
	queen_s,
	queen_c,
	queen_d,
	queen_h,
	king_s,
	king_c,
	king_d,
	king_h,
	ace_s,
	ace_c,
	ace_d,
	ace_h
	};
	cards_in_deck = 52;
}

Card* Deck::drawRandomCard()
{
	int random_value = 0;
	Card* card = cards_list[random_value];
	cards_list.erase(cards_list.begin() + random_value);
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

