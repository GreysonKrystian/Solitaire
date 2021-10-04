#include "Game.h"

Game::Game(float window_width, float window_height, std::string name, Board board)
{
	this->name = name;
	this->window_width = window_width;
	this->window_height = window_height;
	board = board;
	createCards();
}

bool Game::createPlayTiles(sf::RenderWindow &window)
{
	sf::Texture frame;
	if (!frame.loadFromFile("images/frame.png"))
	{
		return 1;
	}
	sf::Sprite frame_sprite;
	frame_sprite.setTexture(frame);
	frame_sprite.setScale(0.25, 0.25);
	frame_sprite.setPosition(100, 20);
	window.draw(frame_sprite);
	for (int x = 600; x <= 1350; x += 250)
	{
		frame_sprite.setPosition(x, 20);
		window.draw(frame_sprite);
	}
	for (int x = 100; x <= 1500; x += 250)
	{
		frame_sprite.setPosition(x, 250);
		window.draw(frame_sprite);
	}
	return 0;
}

void Game::placeCards(sf::RenderWindow &window)
{
}

//void Game::moveCardWithMouse(Card* card) TODO
//{
//	int* result = std::find(board.getRevealedCards(), end, 0);
//	if (card in )
//}

void Game::createCards()
{
	Card *two_s = new Card(0);
	Card* two_c = new Card(1);
	Card* two_d = new Card(2);
	Card* two_h = new Card(3);

	Card* three_s = new Card(4);
	Card* three_c = new Card(5);
	Card* three_d = new Card(6);
	Card* three_h = new Card(7);

	Card* four_s = new Card(8);
	Card* four_c = new Card(9);
	Card* four_d = new Card(10);
	Card* four_h = new Card(11);

	Card* five_s = new Card(12);
	Card* five_c = new Card(13);
	Card* five_d = new Card(14);
	Card* five_h = new Card(15);

	Card* six_s = new Card(16);
	Card* six_c = new Card(17);
	Card* six_d = new Card(18);
	Card* six_h = new Card(19);

	Card* seven_s = new Card(20);
	Card* seven_c = new Card(21);
	Card* seven_d = new Card(22);
	Card* seven_h = new Card(23);

	Card* eight_s = new Card(24);
	Card* eight_c = new Card(25);
	Card* eight_d = new Card(26);
	Card* eight_h = new Card(27);

	Card* nine_s = new Card(28);
	Card* nine_c = new Card(29);
	Card* nine_d = new Card(30);
	Card* nine_h = new Card(31);

	Card* ten_s = new Card(32);
	Card* ten_c = new Card(33);
	Card* ten_d = new Card(34);
	Card* ten_h = new Card(35);

	Card* jack_s = new Card(36);
	Card* jack_c = new Card(37);
	Card* jack_d = new Card(38);
	Card* jack_h = new Card(39);

	Card* queen_s = new Card(40);
	Card* queen_c = new Card(41);
	Card* queen_d = new Card(42);
	Card* queen_h = new Card(43);

	Card* king_s = new Card(44);
	Card* king_c = new Card(45);
	Card* king_d = new Card(46);
	Card* king_h = new Card(47);

	Card* ace_s = new Card(48);
	Card* ace_c = new Card(49);
	Card* ace_d = new Card(50);
	Card* ace_h = new Card(51);

	cards = {

	two_s,
	two_c,
	two_d,
	two_h,
	three_s,
	three_c,
	three_d,
	three_h,
	four_s,
	four_c,
	four_d,
	four_h,
	five_s,
	five_c,
	five_d,
	five_h,
	six_s,
	six_c,
	six_d,
	six_h,
	seven_s,
	seven_c,
	seven_d,
	seven_h,
	eight_s,
	eight_c,
	eight_d,
	eight_h,
	nine_s,
	nine_c,
	nine_d,
	nine_h,
	ten_s,
	ten_c,
	ten_d,
	ten_h,
	jack_s,
	jack_c,
	jack_d,
	jack_h,
	queen_s,
	queen_c,
	queen_d,
	queen_h,
	king_s,
	king_c,
	king_d,
	king_h,
	ace_s,
	ace_c,
	ace_d,
	ace_h
	};
}

