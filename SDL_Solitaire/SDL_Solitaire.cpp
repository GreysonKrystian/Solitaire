#pragma once
#include "Game.h"
#include <iostream>

float window_width = 1600;
float window_height = 800;
int main()
{
	Board board;
	Game game(window_width, window_height, "solitaire", board);
	sf::RenderWindow window(sf::VideoMode(window_width, window_height), "solitaire");
	sf::Event event;
	game.getBoard().dealTheCards(window);
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			for (auto itr = game.getBoard().getTiles().begin(); itr != game.getBoard().getTiles().end(); itr++)
			{
				for (auto iter = (*itr)->getCardsOnTile().begin(); iter != (*itr)->getCardsOnTile().end(); iter++)
				{
					if (event.type == sf::Event::MouseLeft && float(sf::Mouse::getPosition(window).x >= (*iter)->getReveledPart()[0].x &&
						float(sf::Mouse::getPosition(window).x) <= ((*iter)->getReveledPart()[1].x) && float(sf::Mouse::getPosition(window).y) >= (*iter)->getReveledPart()[0].y &&
						sf::Mouse::getPosition(window).y <= float((*iter)->getReveledPart()[1].y)))
					{
						std::cout << (*iter)->getValue() << ", " << (*iter)->getColor();
					};
				}
			}
			

			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		game.createBackground(window);
		if (game.createPlayTiles(window))
		{
			return 0;
		}
		window.display();
	}

	return 0;
}