#include "Game.h"


Game::Game(float window_width, float window_height, std::string name, Board& board)
{
	this->name = name;
	this->window_width = window_width;
	this->window_height = window_height;
	board = board;


	background.loadFromFile("images/background.png");
	background_sprite.setTexture(background);

	frame.loadFromFile("images/frame.png");
	frame_sprite.setTexture(frame);
	frame_sprite.setScale(0.25, 0.25);
}

Board& Game::getBoard()
{
	return board;
}
//bool Game::createPlayTiles(sf::RenderWindow &window)
//{
//	sf::Texture frame;
//	if (!frame.loadFromFile("images/frame.png"))
//	{
//		return 1;
//	}
//	frame_sprite.setTexture(frame);
//	frame_sprite.setScale(0.25, 0.25);
//	frame_sprite.setPosition(100, 20);
//	//window.draw(frame_sprite);
//	for (float x = 600; x <= 1350; x += 250)
//	{
//		frame_sprite.setPosition(x, 20);
//		//window.draw(frame_sprite);
//	}
//	for (float x = 100; x <= 1500; x += 220)
//	{
//		frame_sprite.setPosition(x, 250);
//		//window.draw(frame_sprite);
//	}
//	return 0;
//}
//
//
//void Game::update(sf::RenderWindow& window)
//{
//	createBackground(window);
//	createPlayTiles(window);
//	placeCards(window);
//}

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

//bool Game::createBackground(sf::RenderWindow& window)
//{
//	sf::Texture background;
//	if (!background.loadFromFile("images/background.png"))
//	{
//		return 0;
//	}
//	background_sprite.setTexture(background);
//	//window.draw(background_sprite);
//}


void Game::update(sf::RenderWindow& window,sf::Sprite& background_sprite, sf::Sprite& frame_sprite)
{
	window.draw(background_sprite);


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
}


void Game::updateCards(sf::RenderWindow& window, std::vector<Card*> currently_moved_cards)
{
	for (auto itr = board.getTiles().begin(); itr != board.getTiles().end(); itr++)
	{
		for (auto iter = (*itr)->getCardsOnTile().begin(); iter != (*itr)->getCardsOnTile().end(); iter++)
		{
			if (!(std::find(currently_moved_cards.begin(), currently_moved_cards.end(), (*iter)) != currently_moved_cards.end()))
			{
				(*iter)->drawCard(window, false);
			}		
		}
	}
}


bool Game::checkIfReleasedCardsInArea(float mouse_pos_x, float  mouse_pos_y)
{
	auto top_cards = board.getCardsOnTopOfTiles();
	auto itr = top_cards.begin();
	for(unsigned int i=1;i<=top_cards.size(); i++)
	{
		if ((*itr) != nullptr)
		{
			if (mouse_pos_x >= (*itr)->getRevealedPartPosition()[0].x && mouse_pos_x <= (*itr)->getRevealedPartPosition()[1].x &&
				mouse_pos_y >= (*itr)->getRevealedPartPosition()[0].y && mouse_pos_y <= (*itr)->getRevealedPartPosition()[1].y)
			{
				return true;
			}
		}
		else
		{
			if (mouse_pos_x >= (100.0f + i * 220.0f) && mouse_pos_x < (225.0f + i * 220.0f) &&
				mouse_pos_y >= 250.0f && mouse_pos_y <= 431.5f)
			{
				return true;
			}
		}
		++itr;
	}
	return false;
}