#include<iterator>
#include <algorithm>
#include <random>
#include <SFML/Graphics.hpp>
#pragma once

class Card
{
	std::string color;
	std::string value;
	std::vector<sf::Vector2f> position; // left upper, left lower, right upper, right lower
	sf::Sprite type_of_card;
	bool is_on_top;
public:
	sf::Sprite &getCardSprite();
	void changeIsOnTopState();
	bool is_revealed;
	std::vector<sf::Vector2f> getReveledPart();
	Card(std::string color, std::string value);
	void moveCard();
	void drawCard(sf::RenderWindow& window);
	std::string getColor();
	std::string getValue();
	void setPosition(sf::Vector2f left_upper_corner, sf::Vector2f right_lower_corner);
};

class Deck
{
	int cards_in_deck;
	void shuffleDeck();
	void removeCard();
	void fillDeck();
	std::vector<Card*> cards_list;
	sf::Sprite card_back;
public:
	sf::Sprite getCardBack();
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
	std::vector<Card*> &getCardsOnTile();
	void addCardToTile(Card*);

};

class Pile
{
	int number_of_cards_on_pile;
	Card* last_card;
};