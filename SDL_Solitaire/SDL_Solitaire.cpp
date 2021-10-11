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

	while (window.isOpen())
	{


		while (window.pollEvent(event))
		{
			for (auto itr = board.getTiles().begin(); itr < board.getTiles().end(); itr++)
			{
				for (auto iter = (*itr)->getCardsOnTile().begin(); iter < (*itr)->getCardsOnTile().end(); iter++)
				{
					if (event.type == sf::Event::MouseLeft && float(sf::Mouse::getPosition(window).x >= (*iter)->getReveledPart()[0] &&
						float(sf::Mouse::getPosition(window).x) <= ((*iter)->getReveledPart()[0] + 125.0f) && float(sf::Mouse::getPosition(window).y) >= (*iter)->getReveledPart()[1] &&
						sf::Mouse::getPosition(window).y <= float((*iter)->getReveledPart()[1] + 181.5f)))
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
		game.getBoard().dealTheCards(window);
		window.display();
	}

	return 0;
}