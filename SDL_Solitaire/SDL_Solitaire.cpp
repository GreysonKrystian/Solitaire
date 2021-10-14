﻿#pragma once
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


	sf::Sprite test;
	sf::Texture texture2;
	texture2.loadFromFile("card_back/basic.jpg");
	test.setTexture(texture2);
	test.setScale(0.25, 0.25);
	test.setPosition(500,500);

	game.getBoard().setRevealedCards();
	for (auto itr = game.getBoard().getRevealedCards().begin(); itr != game.getBoard().getRevealedCards().end(); itr++)
	{
		(*itr)->texture.loadFromFile("images/" + (*itr)->getValue() + "_of_" + (*itr)->getColor() + ".png");
	}
	
	while (window.isOpen())
	{
		game.update(window);
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


					if ((event.mouseButton.button == sf::Mouse::Left) && (float(sf::Mouse::getPosition(window).x) >= (*iter)->getReveledPart()[0].x) &&
						(float(sf::Mouse::getPosition(window).x) <= (*iter)->getReveledPart()[1].x) && (float(sf::Mouse::getPosition(window).y) >= (*iter)->getReveledPart()[0].y) &&
						(sf::Mouse::getPosition(window).y <= float((*iter)->getReveledPart()[1].y)))
					{
						while (sf::Mouse::isButtonPressed(sf::Mouse::Left))
						{
							window.clear();
							//std::cout << (*iter)->getValue() << " of " << (*iter)->getColor() << std::endl;
							//(*iter)->getCardSprite().setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
							//(*iter)->getCardSprite().setOrigin(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);

							//(*iter)->getCardSprite().setPosition(500, 500);
							game.update(window);
							(*iter)->drawCard(window, true);
							window.display();
							
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