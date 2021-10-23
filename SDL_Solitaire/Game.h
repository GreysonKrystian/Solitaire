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
	bool checkWinConditions();
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
	bool checkIfReleasedCardsInArea(float mouse_pos_x, float mouse_pos_y);
	void moveCardsOnScreen(sf::RenderWindow& window, std::vector<Card*> cards_to_move);
	Board& getBoard();
};

