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
	//window.setFramerateLimit(60);
	//window.setVerticalSyncEnabled(true);
	sf::Event event;
	game.getBoard().dealTheCards();


	game.getBoard().setRevealedCards();
	for (auto itr = game.getBoard().getRevealedCards().begin(); itr != game.getBoard().getRevealedCards().end(); itr++)
	{
		(*itr)->texture.loadFromFile("images/" + (*itr)->getValue() + "_of_" + (*itr)->getColor() + ".png");
	}
	Card* clicked_card = nullptr;
	Tile* tile_of_origin = nullptr;
	while (window.isOpen())
	{
		game.update(window, game.background_sprite, game.frame_sprite);
		game.updateCards(window, {});
		window.display();
		while (window.pollEvent(event))
		{
			for (auto itr = game.getBoard().getTiles().begin(); itr != game.getBoard().getTiles().end(); itr++)
			{
				for (auto iter = (*itr)->getCardsOnTile().begin(); iter != (*itr)->getCardsOnTile().end(); iter++)
				{
					//auto a = float(sf::Mouse::getPosition(window).x);
					//auto b = (*iter)->getReveledPart()[0].x;
					//auto c = float(sf::Mouse::getPosition(window).x);
					//auto d = (*iter)->getReveledPart()[1].x;
					//auto e = float(sf::Mouse::getPosition(window).y);
					//auto f = (*iter)->getReveledPart()[0].y;
					//auto g = sf::Mouse::getPosition(window).y;
					//auto h = float((*iter)->getReveledPart()[1].y);

					if ((event.mouseButton.button == sf::Mouse::Left) && (float(sf::Mouse::getPosition(window).x) >= (*iter)->getRevealedPartPosition()[0].x) &&
						(float(sf::Mouse::getPosition(window).x) <= (*iter)->getRevealedPartPosition()[1].x) && (float(sf::Mouse::getPosition(window).y) >= (*iter)->getRevealedPartPosition()[0].y)
						&&(sf::Mouse::getPosition(window).y <= float((*iter)->getRevealedPartPosition()[1].y)) && (*iter)->checkIfIsRevealed())
					{
						while (sf::Mouse::isButtonPressed(sf::Mouse::Left))
						{
							window.clear();
							//std::cout << (*iter)->getValue() << " of " << (*iter)->getColor() << std::endl;
							//(*iter)->getCardSprite().setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
							//(*iter)->getCardSprite().setOrigin(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);

							//(*iter)->getCardSprite().setPosition(500, 500); 
							game.update(window, game.background_sprite, game.frame_sprite);
							game.updateCards(window, { (*iter) });
							(*iter)->drawCard(window, true);
							window.display();
							clicked_card = (*iter);
							tile_of_origin = (*itr);
							std::cout << clicked_card << std::endl;
							std::cout << tile_of_origin << std::endl;
						}
						if (event.type == sf::Event::MouseButtonReleased && game.checkIfReleasedCardsInArea(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)
							&& game.getBoard().isTileChangeLegal(tile_of_origin, (game.getBoard().getTileOnPosition(sf::Mouse::getPosition(window).x)), clicked_card))
						{
							game.getBoard().changeTileOfCards(tile_of_origin, (game.getBoard().getTileOnPosition(sf::Mouse::getPosition(window).x)), clicked_card);
						}
					}
				}
			}
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		//std::cout << sf::Mouse::getPosition(window).x << ", " << sf::Mouse::getPosition(window).y << std::endl;
		//game.createBackground(window);
		//if (game.createPlayTiles(window))
		//{
		//	return 0;
		//}
		//game.placeCards(window);
	}

	return 0;
}