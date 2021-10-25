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
	Card* clicked_card = nullptr;
	Tile* tile_of_origin = nullptr;
	while (window.isOpen())
	{
		//std::cout << float(sf::Mouse::getPosition(window).x) << std::endl;
		game.update(window);
		game.updateCards(window, {});
		window.display();
		while (window.pollEvent(event))
		{
			for (auto itr = game.getBoard().getTiles().begin(); itr != game.getBoard().getTiles().end(); itr++)
			{
				for (auto iter = (*itr)->getCardsOnTile().begin(); iter != (*itr)->getCardsOnTile().end(); iter++)
				{
					if ((event.mouseButton.button == sf::Mouse::Left) && (float(sf::Mouse::getPosition(window).x) >= (*iter)->getRevealedPartPosition()[0].x) &&
						(float(sf::Mouse::getPosition(window).x) <= (*iter)->getRevealedPartPosition()[1].x) && (float(sf::Mouse::getPosition(window).y) >= (*iter)->getRevealedPartPosition()[0].y)
						&&(sf::Mouse::getPosition(window).y <= float((*iter)->getRevealedPartPosition()[1].y)) && (*iter)->isRevealed())
					{
						while (sf::Mouse::isButtonPressed(sf::Mouse::Left))
						{
							std::vector<Card*> cards_to_move;
							for(auto cards_iterator = iter; cards_iterator != (*itr)->getCardsOnTile().end(); cards_iterator++)
							{
								cards_to_move.push_back((*cards_iterator));
							}
							game.moveCardsOnScreen(window, cards_to_move);
							clicked_card = (*iter);
							tile_of_origin = (*itr);
						}
						if (event.type == sf::Event::MouseButtonReleased && game.checkIfReleasedCardsInArea(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)
							&& game.getBoard().isTileChangeLegal(tile_of_origin, (game.getBoard().getTileOnPosition(sf::Mouse::getPosition(window).x)), clicked_card))
						{
							game.getBoard().changeTileOfCards(tile_of_origin, (game.getBoard().getTileOnPosition(sf::Mouse::getPosition(window).x)), clicked_card);
							if (!tile_of_origin->getCardsOnTile().back()->isRevealed())
								tile_of_origin->getCardsOnTile().back()->changeIsRevealedState();
							break;
						}
					}
				}
			}
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
	}

	return 0;
}