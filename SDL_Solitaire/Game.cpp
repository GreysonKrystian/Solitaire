#include "Game.h"

Game::Game(float window_width, float window_height, std::string name)
{
	this->name = name;
	this->window_width = window_width;
	this->window_height = window_height;
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
	for (int x = 600; x <= 1350; x += 250)
	{
		frame_sprite.setPosition(x, 20);
		window.draw(frame_sprite);
	}
	for (int x = 100; x <= 1500; x += 250)
	{
		frame_sprite.setPosition(x, 250);
		window.draw(frame_sprite);
	}
	return 0;
}

void Game::placeCards(sf::RenderWindow &window)
{
}

