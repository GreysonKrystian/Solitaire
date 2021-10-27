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
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left && float(sf::Mouse::getPosition(window).x) >= 100.0f &&
					float(sf::Mouse::getPosition(window).x) <= 100.f + game.getCardsSize().x && float(sf::Mouse::getPosition(window).y) >= 20.0f
					&& sf::Mouse::getPosition(window).y <= 20.0f + game.getCardsSize().y)
				{
					game.showCardFromDeck(window);
					constexpr std::chrono::microseconds duration(1);
					std::this_thread::sleep_for(duration);
				}

				if (event.mouseButton.button == sf::Mouse::Left && (static_cast<float>(sf::Mouse::getPosition(window).x) >= 250.0f &&
					(static_cast<float>(sf::Mouse::getPosition(window).x) <= 250.0f + game.getCardsSize().x && static_cast<float>(sf::Mouse::getPosition(window).y) >= 20.0f
						&& sf::Mouse::getPosition(window).y <= 20.0f + game.getCardsSize().y)))
				{
					auto clicked_card_from_deck = game.getBoard().getDeck().getCardsList().back();
					clicked_card_from_deck->changeIsRevealedState();
					while (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{
						game.moveCardsOnScreen(window, { game.getBoard().getDeck().getCardsList().back() });
					}
					if (game.checkIfReleasedCardsInArea(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)
						&& game.getBoard().isPlacingCardHereLegal(game.getBoard().getTileOnPosition(sf::Mouse::getPosition(window).x), clicked_card_from_deck))
					{
						game.getBoard().putCardFromDeckOnTile(game.getBoard().getTileOnPosition(sf::Mouse::getPosition(window).x), clicked_card_from_deck);
					}
					else
					{
						clicked_card_from_deck->changeIsRevealedState();
						clicked_card_from_deck->getCardSprite().setPosition(250.0f, 20.0f);
						window.clear();
						game.update(window);
						game.updateCards(window, {});
						window.draw(clicked_card_from_deck->getCardSprite());
						window.display();
					}
				}			
				for (auto itr = game.getBoard().getTiles().begin(); itr != game.getBoard().getTiles().end(); itr++)
				{
					for (auto iter = (*itr)->getCardsOnTile().begin(); iter != (*itr)->getCardsOnTile().end(); iter++)
					{
						if (event.mouseButton.button == sf::Mouse::Left && float(sf::Mouse::getPosition(window).x) >= (*iter)->getRevealedPartPosition()[0].x &&
							float(sf::Mouse::getPosition(window).x) <= (*iter)->getRevealedPartPosition()[1].x && float(sf::Mouse::getPosition(window).y) >= (*iter)->getRevealedPartPosition()[0].y
							&& sf::Mouse::getPosition(window).y <= float((*iter)->getRevealedPartPosition()[1].y) && (*iter)->isRevealed())
						{
							while (sf::Mouse::isButtonPressed(sf::Mouse::Left))
							{
								std::vector<Card*> cards_to_move;
								for (auto cards_iterator = iter; cards_iterator != (*itr)->getCardsOnTile().end(); cards_iterator++)
								{
									cards_to_move.push_back(*cards_iterator);
								}
								game.moveCardsOnScreen(window, cards_to_move);
								clicked_card = *iter;
								tile_of_origin = *itr;
							}
						}
					}
				}
			}

			if (event.type == sf::Event::MouseButtonReleased && game.checkIfReleasedCardsInArea(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)
				&& game.getBoard().isPlacingCardHereLegal(game.getBoard().getTileOnPosition(sf::Mouse::getPosition(window).x), clicked_card))
			{
				game.getBoard().changeTileOfCards(tile_of_origin, game.getBoard().getTileOnPosition(sf::Mouse::getPosition(window).x), clicked_card);
				if (!tile_of_origin->getCardsOnTile().back()->isRevealed())
					tile_of_origin->getCardsOnTile().back()->changeIsRevealedState();
				break;
			}
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
	}
	return 0;
}