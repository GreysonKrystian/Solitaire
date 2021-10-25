#include <deque>
#include <SFML/Graphics.hpp>
#include <list>
#pragma once

class Card
{
	sf::Vector2f size;
	std::string color;
	std::string value;
	std::vector<sf::Vector2f> position; // left upper,  right lower
	sf::Sprite sprite_of_card;
	bool is_on_top;
	bool is_revealed;
	sf::Texture back_texture;
	sf::Texture front_texture;
public:
	sf::Texture& getBackTexture();
	sf::Texture& getFrontTexture();
	sf::Sprite &getCardSprite();
	sf::Vector2f& getSize();
	void changeIsRevealedState();
	void changeIsOnTopState();
	bool isOnTop();
	bool isRevealed();
	std::vector<sf::Vector2f> getRevealedPartPosition();
	Card(std::string color, std::string value);
	void drawCard(sf::RenderWindow& window, bool move_mouse, int y_axis_relocation=0);
	std::string getColor();
	std::string getValue();
	void setPosition(sf::Vector2f left_upper_corner, sf::Vector2f right_lower_corner);
};

class Deck
{
	void shuffleDeck();
	void fillDeck();
	std::vector<Card*> cards_list;
public:
	std::vector<Card*>& getCardsList();
	Deck();
	Card* drawRandomCard();
};

class Tile
{
	int cards_left;
	std::vector<Card*> cards_on_tile;
	sf::Vector2f position_on_board;
public:
	Tile(sf::Vector2f position_on_board);
	std::vector<Card*> &getCardsOnTile();
	void addCardToTile(Card*);
	sf::Vector2f& getPositionOnBoard();
};

class Pile
{
	int number_of_cards_on_pile;
	Card* last_card;
};