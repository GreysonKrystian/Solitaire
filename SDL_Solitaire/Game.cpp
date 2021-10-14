#include "Game.h"

Game::Game(float window_width, float window_height, std::string name, Board& board)
{
	this->name = name;
	this->window_width = window_width;
	this->window_height = window_height;
	board = board;
}

bool Game::createPlayTiles(sf::RenderWindow &window)
{
	sf::Texture frame;
	if (!frame.loadFromFile("images/frame.png"))
	{
		return 1;
	}
	sf::Sprite frame_sprite;
	frame_sprite.setTexture(frame);
	frame_sprite.setScale(0.25, 0.25);
	frame_sprite.setPosition(100, 20);
	window.draw(frame_sprite);
	for (float x = 600; x <= 1350; x += 250)
	{
		frame_sprite.setPosition(x, 20);
		window.draw(frame_sprite);
	}
	for (float x = 100; x <= 1500; x += 220)
	{
		frame_sprite.setPosition(x, 250);
		window.draw(frame_sprite);
	}
	return 0;
}


void Game::update(sf::RenderWindow& window)
{
	createBackground(window);
	createPlayTiles(window);
	placeCards(window);
}

void Game::placeCards(sf::RenderWindow &window)
{
	for (auto itr = board.getTiles().begin(); itr != board.getTiles().end(); itr++)
	{
		for (auto iter = (*itr)->getCardsOnTile().begin(); iter != (*itr)->getCardsOnTile().end(); iter++)
		{
			(*iter)->drawCard(window, false);
		}
	}
	
}

//void Game::moveCardWithMouse(Card* card) TODO
//{
//	int* result = std::find(board.getRevealedCards(), end, 0);
//	if (card in )
//}

bool Game::createBackground(sf::RenderWindow& window)
{
	sf::Texture background;
	if (!background.loadFromFile("images/background.png"))
	{
		return 0;
	}
	sf::Sprite background_sprite;
	background_sprite.setTexture(background);
	window.draw(background_sprite);
}

void Game::testUpdate(sf::RenderWindow& window,sf::Sprite& background_sprite, sf::Sprite& frame_sprite, )
{
	window.draw(background_sprite);

	for (float x = 600; x <= 1350; x += 250)
	{
		frame_sprite.setPosition(x, 20);
		window.draw(frame_sprite);
	}
	for (float x = 100; x <= 1500; x += 220)
	{
		frame_sprite.setPosition(x, 250);
		window.draw(frame_sprite);
	}

	for (auto itr = board.getTiles().begin(); itr != board.getTiles().end(); itr++)
	{
		for (auto iter = (*itr)->getCardsOnTile().begin(); iter != (*itr)->getCardsOnTile().end(); iter++)
		{
			(*iter)->drawCard(window, false);
		}
	}
}


Board& Game::getBoard()
{
	return board;
}

//void Game::update(sf::Time dt)
//{

//}