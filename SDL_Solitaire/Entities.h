#include<iterator>
#include <algorithm>
#include <random>
#include <SFML/Graphics.hpp>
#pragma once

class Card
{
	std::string color;
	std::string value;
	sf::Vector2f position;
	sf::Sprite type_of_card;
	std::vector<std::string> card_sprites{};
public:
	Card(std::string color, std::string value);
	void moveCard();
	void drawCard(sf::RenderWindow& window);
	std::string getColor();
	std::string getValue();
	void setPosition(sf::Vector2f given_position);
};

class Deck
{
	int cards_in_deck;
	void shuffleDeck();
	void removeCard();
	void fillDeck();
	std::vector<Card*> cards_list;
public:
	Deck();
	int getCardsLeft();
	void addCard();
	Card* drawRandomCard();
};

class Tile
{
	int cards_left;
	std::vector<Card*> cards_on_tile;
public:
	Tile();
	std::vector<Card*> getCardsOnTile();
	void addCardToTile(Card*);

};

class Pile
{
	int number_of_cards_on_pile;
	Card* last_card;
};