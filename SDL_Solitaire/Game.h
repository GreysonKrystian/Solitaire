#pragma once
#include "GameBoard.h"
#include <chrono>
#include <thread>
#include <iostream>
class Game
{
private:
	sf::Vector2f cards_size;
	float window_width;
	float window_height;
	std::string name;
	Board board;
	sf::Texture background;
	sf::Texture frame;
	sf::Texture card_back;
public:
	bool checkWinConditions();
	sf::Sprite background_sprite;
	sf::Sprite frame_sprite;
	sf::Sprite card_back_sprite;
	sf::Vector2f getCardsSize();
	Game(float window_width, float window_height, std::string name, Board& board);
	//bool createPlayTiles(sf::RenderWindow &window);
	void placeCards(sf::RenderWindow &window);
	//void moveCardWithMouse();
	//void placeCardOnPile();
	//bool createBackground(sf::RenderWindow& window);
	void update(sf::RenderWindow& window);
	void updateCards(sf::RenderWindow& window, std::vector<Card*> currently_moved_cards);
	bool checkIfReleasedCardsInArea(float mouse_pos_x, float mouse_pos_y);
	void moveCardsOnScreen(sf::RenderWindow& window, std::vector<Card*> cards_to_move);
	void showCardFromDeck(sf::RenderWindow& window);
	bool isCardFromTilesClicked();
	Board& getBoard();
};

