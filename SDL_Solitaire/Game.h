#pragma once
#include <../Board/board.h>
#include <SFML/Graphics.hpp>
#include <iostream>
class Game
{
private:
	float window_width;
	float window_height;
	std::string name;
public:
	Game(float window_width, float window_height, std::string name);
	bool createPlayTiles(sf::RenderWindow &window);
	void placeCards(sf::RenderWindow &window);
	void moveCardWithMouse();
	void placeCardOnPile();
	void takeCard();
};

