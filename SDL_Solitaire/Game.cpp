#include "Game.h"





Game::Game(float window_width, float window_height, std::string name, Board& board)
{

	this->name = name;
	this->window_width = window_width;
	this->window_height = window_height;
	this->cards_size = { 125.0f, 181.5f };
	board = board;

	background.loadFromFile("images/background.png");
	background_sprite.setTexture(background);

	frame.loadFromFile("images/frame.png");
	frame_sprite.setTexture(frame);
	frame_sprite.setScale(0.25, 0.25);

	card_back.loadFromFile("card_back/basic.jpg");
	card_back_sprite.setTexture(card_back);
	card_back_sprite.setScale(0.25, 0.25);

}

Board& Game::getBoard()
{
	return board;
}

bool Game::checkWinConditions()
{
	unsigned int number_of_filled_piles = 0;
	for(auto itr = getBoard().getPiles().begin(); getBoard().getPiles().end() != itr; itr++)
	{
		if((*itr)->getLastCard() != nullptr && (*itr)->getLastCard()->getValue() == "king")
		{
			number_of_filled_piles++;
		}
	}
	if (number_of_filled_piles == 4)
		return true;
	return false;
}

sf::Vector2f Game::getCardsSize()
{
	return cards_size;
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


void Game::update(sf::RenderWindow& window)
{
	window.draw(background_sprite);


	frame_sprite.setPosition(100, 20);
	window.draw(frame_sprite);
	for (float x = 600; x <= 1350; x += 250)
	{
		frame_sprite.setPosition(x, 20);
		window.draw(frame_sprite);
		if(getBoard().getPileOnPosition(x) != nullptr && getBoard().getPileOnPosition(x)->getLastCard()!= nullptr)
			window.draw(getBoard().getPileOnPosition(x)->getLastCard()->getCardSprite());
	}
	for (float x = 100; x <= 1500; x += 220)
	{
		frame_sprite.setPosition(x, 250);
		window.draw(frame_sprite);
	}
	for(unsigned int i=0; i< board.getDeck().getCardsList().size();i++)
	{
		card_back_sprite.setPosition(100 + i*0.15, 20);
		window.draw(card_back_sprite);
		//board.getDeck().getCardSprite().setPosition(100 + i, 20);
		//window.draw(board.getDeck().getCardSprite());
	}
	if(board.getDeck().getCurrentlyDisplayedCard() != nullptr)
	{
		window.draw(board.getDeck().getCurrentlyDisplayedCard()->getCardSprite());
	}
	for(auto itr = board.getPiles().begin(); itr != board.getPiles().end(); itr++)
	{
		if((*itr)->getLastCard() != nullptr)
		{
			window.draw((*itr)->getLastCard()->getCardSprite());
		}
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
	for(unsigned int i=0;i<top_cards.size(); i++)
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

void Game::moveCardsOnScreen(sf::RenderWindow &window, std::vector<Card*> cards_to_move)
{
	window.clear();
	//std::cout << (*iter)->getValue() << " of " << (*iter)->getColor() << std::endl;
	//(*iter)->getCardSprite().setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
	//(*iter)->getCardSprite().setOrigin(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);

	//(*iter)->getCardSprite().setPosition(500, 500); 
	update(window);
	updateCards(window, cards_to_move);
	int relocation = 0;
	for (auto iter = cards_to_move.begin(); iter != cards_to_move.end(); iter++)
	{
		(*iter)->drawCard(window, true, relocation*20);
		relocation++;
	}
	window.display();
}

bool Game::isCardInPilesArea(sf::RenderWindow& window)
{
	for (auto itr = board.getPiles().begin(); itr != board.getPiles().end(); itr++)
	{
		if (sf::Mouse::getPosition(window).x > (*itr)->getPosition().x && sf::Mouse::getPosition(window).x < (*itr)->getPosition().x + getCardsSize().x &&
			sf::Mouse::getPosition(window).y >(*itr)->getPosition().y && sf::Mouse::getPosition(window).y < (*itr)->getPosition().y + getCardsSize().y)
			return true;
	}
	return false;
} 


void Game::showCardFromDeck(sf::RenderWindow& window)
{
	board.getDeck().putTopCardOnBack();
	board.getDeck().setCurrentlyDisplayedCard(nullptr);
	std::vector<Card*> card_to_move = { board.getDeck().getCardsList().back() };
	constexpr std::chrono::microseconds duration(1);
	card_to_move[0]->getCardSprite().setTexture(card_to_move[0]->getFrontTexture());
	for (float position_x = 100; position_x < 250; position_x++)
	{
		window.clear();
		update(window);
		updateCards(window, card_to_move);
		card_to_move[0]->getCardSprite().setPosition(position_x, 20);
		
		window.draw(card_to_move[0]->getCardSprite());
		window.display();
		std::this_thread::sleep_for(duration);
	}
	board.getDeck().setCurrentlyDisplayedCard(card_to_move[0]);
}