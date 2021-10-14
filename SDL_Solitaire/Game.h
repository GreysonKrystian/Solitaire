#pragma once
#include "GameBoard.h"
#include <iostream>
class Game
{
private:
	float window_width;
	float window_height;
	std::string name;
	Board board;
	sf::Texture background;
	sf::Texture frame;
public:
	sf::Sprite background_sprite;
	sf::Sprite frame_sprite;
	Game(float window_width, float window_height, std::string name, Board& board);
	//bool createPlayTiles(sf::RenderWindow &window);
	void placeCards(sf::RenderWindow &window);
	//void moveCardWithMouse();
	//void placeCardOnPile();
	//bool createBackground(sf::RenderWindow& window);
	void update(sf::RenderWindow& window, sf::Sprite& background_sprite, sf::Sprite& frame_sprite);
	void updateCards(sf::RenderWindow& window, std::vector<Card*> currently_moved_cards);
	Board& getBoard();
};

