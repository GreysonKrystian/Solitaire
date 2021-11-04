#pragma once
#include "Game.h"
#include <iostream>

float window_width = 1600;
float window_height = 800;

int main()
{
	Board board;
	Game game(window_width, window_height, "solitaire", board);
	sf::RenderWindow window(sf::VideoMode(window_width, window_height), "solitaire", sf::Style::Close);
	sf::Event event;
	game.getBoard().dealTheCards();
	game.getBoard().setRevealedCards();
	while (window.isOpen())
	{
		Card* clicked_card = nullptr;
		Tile* tile_of_origin = nullptr;
		//std::cout << float(sf::Mouse::getPosition(window).x) << std::endl;
		game.update(window);
		game.updateCards(window, {});
		window.display();
		if (game.checkWinConditions())
		{
			std::cout << "WIN!" << std::endl;
		}
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (!game.getBoard().getDeck().getCardsList().empty())
				{
					// REVEALING CARD FROM DECK
					if (event.mouseButton.button == sf::Mouse::Left && static_cast<float>(sf::Mouse::getPosition(window)
							.x) >= 100.0f &&
						static_cast<float>(sf::Mouse::getPosition(window).x) <= 100.f + game.getCardsSize().x &&
						static_cast<float>(sf::Mouse::getPosition(window).y) >= 20.0f
						&& sf::Mouse::getPosition(window).y <= 20.0f + game.getCardsSize().y)
					{
						game.showCardFromDeck(window);
						constexpr std::chrono::microseconds duration(1);
						std::this_thread::sleep_for(duration);
					}

					// MOVING CARD FROM DECK
					if (event.mouseButton.button == sf::Mouse::Left && game.getBoard().getDeck().
					                                                        getCurrentlyDisplayedCard() != nullptr && (
						static_cast<float>(sf::Mouse::getPosition(window).x) >= 250.0f &&
						(static_cast<float>(sf::Mouse::getPosition(window).x) <= 250.0f + game.getCardsSize().x &&
							static_cast<float>(sf::Mouse::getPosition(window).y) >= 20.0f
							&& sf::Mouse::getPosition(window).y <= 20.0f + game.getCardsSize().y)))
					{
						auto clicked_card_from_deck = game.getBoard().getDeck().getCurrentlyDisplayedCard();
						clicked_card_from_deck->changeIsRevealedState();
						while (sf::Mouse::isButtonPressed(sf::Mouse::Left))
						{
							game.moveCardsOnScreen(window, {game.getBoard().getDeck().getCardsList().back()});
						}
						Pile* pile = game.getBoard().getPileOnPosition(sf::Mouse::getPosition(window).x);
						if (game.checkIfReleasedCardsInArea(sf::Mouse::getPosition(window).x,
						                                    sf::Mouse::getPosition(window).y) && game.getBoard().
							getTileOnPosition(sf::Mouse::getPosition(window).x) != nullptr
							&& game.getBoard().isPlacingCardHereLegal(game.getBoard().getTileOnPosition(sf::Mouse::getPosition(window).x),
								game.getBoard().getDeck().getCardsList().back()))
						{
							game.getBoard().putCardFromDeckOnTile(
								game.getBoard().getTileOnPosition(sf::Mouse::getPosition(window).x),
								game.getBoard().getDeck().getCardsList().back());
							game.getBoard().getDeck().clearCurrentlyDisplayedCard();
						}
						else if (pile != nullptr && game.isCardInPilesArea(window) && pile->isPuttingCardOnLegal(
							game.getBoard().getDeck().getCardsList().back()))
						{
							//pile->putCardOnPile(game.getBoard().getDeck().getCardsList().back());
							//game.getBoard().getDeck().getCardsList().pop_back();
							//game.getBoard().getDeck().clearCurrentlyDisplayedCard();
							//// zamienic w funkcje TODO
							//clicked_card_from_deck->getCardSprite().setPosition(pile->getPosition().x, pile->getPosition().y);
							//window.clear();
							//game.update(window);
							//game.updateCards(window, {});
							//window.draw(clicked_card_from_deck->getCardSprite());
							//window.display();
							game.placeCardOnTile(window, pile, clicked_card_from_deck);
						}
						else
						{
							// zamienic w funkcje TODO
							game.moveRevealedDeckCardToDefaultPosition(window, clicked_card_from_deck);
							//clicked_card_from_deck->changeIsRevealedState();
							//clicked_card_from_deck->getCardSprite().setPosition(250.0f, 20.0f);
							//window.clear();
							//game.update(window);
							//game.updateCards(window, {});
							//window.draw(clicked_card_from_deck->getCardSprite());
							//window.display();
						}
					}
				}

				// MOVING CARD FROM TILE
				for (auto itr = game.getBoard().getTiles().begin(); itr != game.getBoard().getTiles().end(); ++itr)
				{
					for (auto iter = (*itr)->getCardsOnTile().begin(); iter != (*itr)->getCardsOnTile().end(); ++iter)
					{
						if (event.mouseButton.button == sf::Mouse::Left && static_cast<float>(
								sf::Mouse::getPosition(window).x) >= (*iter)->getRevealedPartPosition()[0].x &&
							static_cast<float>(sf::Mouse::getPosition(window).x) <= (*iter)->getRevealedPartPosition()[
								1].x && static_cast<float>(sf::Mouse::getPosition(window).y) >= (*iter)->
							getRevealedPartPosition()[0].y
							&& sf::Mouse::getPosition(window).y <= static_cast<float>((*iter)->getRevealedPartPosition()
								[1].y) && (*iter)->isRevealed())
						{
							while (sf::Mouse::isButtonPressed(sf::Mouse::Left))
							{
								std::vector<Card*> cards_to_move;
								for (auto cards_iterator = iter; cards_iterator != (*itr)->getCardsOnTile().end(); ++
								     cards_iterator)
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
			if (clicked_card != nullptr && tile_of_origin != nullptr)
			{
				Pile* pile = game.getBoard().getPileOnPosition(sf::Mouse::getPosition(window).x);

				if (event.type == sf::Event::MouseButtonReleased && game.checkIfReleasedCardsInArea(
						sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)
					&& game.getBoard().getTileOnPosition(sf::Mouse::getPosition(window).x) != nullptr
					&& game.getBoard().isPlacingCardHereLegal(
						game.getBoard().getTileOnPosition(sf::Mouse::getPosition(window).x), clicked_card))
				{
					game.getBoard().changeTileOfCards(tile_of_origin,
					                                  game.getBoard().getTileOnPosition(
						                                  sf::Mouse::getPosition(window).x), clicked_card);
					if (!tile_of_origin->getCardsOnTile().empty() && !tile_of_origin->getCardsOnTile().back()->
						isRevealed())
						tile_of_origin->getCardsOnTile().back()->changeIsRevealedState();
					break;
				}

				if (event.type == sf::Event::MouseButtonReleased && pile != nullptr && game.isCardInPilesArea(window) &&
					pile->isPuttingCardOnLegal(clicked_card) && clicked_card->isOnTop())
				{
					pile->putCardOnPile(clicked_card);
					tile_of_origin->getCardsOnTile().pop_back();
					clicked_card->getCardSprite().setPosition(pile->getPosition().x, pile->getPosition().y);
					if (!tile_of_origin->getCardsOnTile().empty())
					{
						tile_of_origin->getCardsOnTile().back()->changeIsOnTopState();
						if (!tile_of_origin->getCardsOnTile().back()->isRevealed())
						{
							tile_of_origin->getCardsOnTile().back()->changeIsRevealedState();
						}
					}
					clicked_card->changeIsOnTopState();
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
