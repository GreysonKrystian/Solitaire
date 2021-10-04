#pragma once
#include "GameBoard.h"
#include <iostream>
class Game
{
private:
	float window_width;
	float window_height;
	std::string name;
	std::vector<Card*> cards;
	Board board;
public:
	Game(float window_width, float window_height, std::string name, Board board);
	bool createPlayTiles(sf::RenderWindow &window);
	void placeCards(sf::RenderWindow &window);
	void moveCardWithMouse();
	void placeCardOnPile();
	void createCards();
};

