﻿#pragma once
#include "Game.h"
#include <iostream>

float window_width = 1600;
float window_height = 800;
int main()
{
	Game game(window_width, window_height, "solitaire");
	sf::RenderWindow window(sf::VideoMode(window_width, window_height), "solitaire");
	sf::Event event;
	sf::Texture background;
	if (!background.loadFromFile("images/bacground.png"))
	{
		return 0;
	}
	sf::Sprite background_sprite;
	background_sprite.setTexture(background);
	while (window.isOpen())
	{


		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		window.draw(background_sprite);
		if (game.createPlayTiles(window))
		{
			return 0;
		}
		window.display();
	}

	return 0;
}