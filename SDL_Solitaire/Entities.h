#include<iterator>
#include <algorithm>
#include <random>
#include <SFML/Graphics.hpp>
#pragma once

class Card
{
	std::string color;
	std::string value;
	std::vector<sf::Vector2f> position; // left upper,  right lower
	sf::Sprite type_of_card;
	bool is_on_top;
	bool is_revealed;
public:
	sf::Texture texture;
	sf::Sprite &getCardSprite();
	void changeIsRevealedState();
	void changeIsOnTopState();
	bool checkIfIsOnTop();
	bool checkIfIsRevealed();
	std::vector<sf::Vector2f> getRevealedPartPosition();
	Card(std::string color, std::string value);
	void moveCard();
	void drawCard(sf::RenderWindow& window, bool move_mouse);
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