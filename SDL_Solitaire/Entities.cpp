#include "Entities.h"

Card::Card(std::string color, std::string value)
{
	this->color = color;
	this->value = value;
	this->size = {125.0f, 181.5f};
	sprite_of_card.setScale(0.25, 0.25);
	this->is_revealed = false;
	back_texture.loadFromFile("card_back/basic.jpg");
	front_texture.loadFromFile("images/" + value + "_of_" + color + ".png");
}

void Card::changeIsOnTopState()
{
	if (is_on_top == true)
		is_on_top = false;
	else if (is_on_top == false)
		is_on_top = true;
}

bool Card::isOnTop()
{
	return is_on_top;
}

bool Card::isRevealed()
{
	return is_revealed;
}

std::vector<sf::Vector2f> Card::getRevealedPartPosition()
{
	std::vector<sf::Vector2f> revealed;
	if (!is_on_top)
	{
		revealed = {position[0], {position[1].x, position[0].y + 20}}; //TODO
	}
	else
	{
		revealed = {position[0], position[1]};
	}
	return revealed;
}

void Card::setPosition(sf::Vector2f left_upper_corner, sf::Vector2f right_lower_corner)
{
	position = {left_upper_corner, right_lower_corner};
}


void Card::drawCard(sf::RenderWindow& window, bool move_mouse, int y_axis_relocation)
{
	if (is_revealed)
		sprite_of_card.setTexture(front_texture);
	else
		sprite_of_card.setTexture(back_texture);
	if (!move_mouse)
		sprite_of_card.setPosition(position[0]);
	else
		sprite_of_card.setPosition(sf::Mouse::getPosition(window).x,
		                           sf::Mouse::getPosition(window).y + y_axis_relocation);
	window.draw(sprite_of_card);
}

std::string Card::getColor()
{
	return color;
};

std::string Card::getValue()
{
	return value;
};


sf::Texture& Card::getBackTexture()
{
	return back_texture;
}

sf::Texture& Card::getFrontTexture()
{
	return front_texture;
}

sf::Sprite& Card::getCardSprite()
{
	return sprite_of_card;
}

sf::Vector2f& Card::getSize()
{
	return size;
}

void Card::changeIsRevealedState()
{
	if (is_revealed == true)
		is_revealed = false;
	else if (is_revealed == false)
		is_revealed = true;
}


std::deque<Card*>& Deck::getCardsList()
{
	return cards_list;
}

Deck::Deck()
{
	fillDeck();
	shuffleDeck();
}


void Deck::shuffleDeck()
{
	srand(time(nullptr));
	std::random_shuffle(this->cards_list.begin(), this->cards_list.end(), [](int n) { return rand() % n; });
}

void Deck::putTopCardOnBack()
{
	if (currently_displayed_card != nullptr)
	{
		Card* front_card = cards_list.front();
		cards_list.pop_front();
		cards_list.push_back(front_card);
	}
}

void Deck::fillDeck()
{
	auto two_s = new Card("spades", "2");
	auto two_c = new Card("clubs", "2");
	auto two_d = new Card("diamonds", "2");
	auto two_h = new Card("hearts", "2");

	auto three_s = new Card("spades", "3");
	auto three_c = new Card("clubs", "3");
	auto three_d = new Card("diamonds", "3");
	auto three_h = new Card("hearts", "3");

	auto four_s = new Card("spades", "4");
	auto four_c = new Card("clubs", "4");
	auto four_d = new Card("diamonds", "4");
	auto four_h = new Card("hearts", "4");

	auto five_s = new Card("spades", "5");
	auto five_c = new Card("clubs", "5");
	auto five_d = new Card("diamonds", "5");
	auto five_h = new Card("hearts", "5");

	auto six_s = new Card("spades", "6");
	auto six_c = new Card("clubs", "6");
	auto six_d = new Card("diamonds", "6");
	auto six_h = new Card("hearts", "6");

	auto seven_s = new Card("spades", "7");
	auto seven_c = new Card("clubs", "7");
	auto seven_d = new Card("diamonds", "7");
	auto seven_h = new Card("hearts", "7");

	auto eight_s = new Card("spades", "8");
	auto eight_c = new Card("clubs", "8");
	auto eight_d = new Card("diamonds", "8");
	auto eight_h = new Card("hearts", "8");

	auto nine_s = new Card("spades", "9");
	auto nine_c = new Card("clubs", "9");
	auto nine_d = new Card("diamonds", "9");
	auto nine_h = new Card("hearts", "9");

	auto ten_s = new Card("spades", "10");
	auto ten_c = new Card("clubs", "10");
	auto ten_d = new Card("diamonds", "10");
	auto ten_h = new Card("hearts", "10");

	auto jack_s = new Card("spades", "jack");
	auto jack_c = new Card("clubs", "jack");
	auto jack_d = new Card("diamonds", "jack");
	auto jack_h = new Card("hearts", "jack");

	auto queen_s = new Card("spades", "queen");
	auto queen_c = new Card("clubs", "queen");
	auto queen_d = new Card("diamonds", "queen");
	auto queen_h = new Card("hearts", "queen");

	auto king_s = new Card("spades", "king");
	auto king_c = new Card("clubs", "king");
	auto king_d = new Card("diamonds", "king");
	auto king_h = new Card("hearts", "king");

	auto ace_s = new Card("spades", "ace");
	auto ace_c = new Card("clubs", "ace");
	auto ace_d = new Card("diamonds", "ace");
	auto ace_h = new Card("hearts", "ace");

	cards_list = {

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

Card* Deck::drawRandomCard()
{
	srand(time(nullptr));
	int random_value = rand() % cards_list.size();
	Card* card = cards_list[random_value];
	cards_list.erase(cards_list.begin() + random_value);
	return card;
}

void Deck::clearCurrentlyDisplayedCard()
{
	currently_displayed_card = nullptr;
}


Tile::Tile(sf::Vector2f position_on_board)
{
	this->position_on_board = position_on_board;
}

Card*& Deck::getCurrentlyDisplayedCard()
{
	return currently_displayed_card;
}

void Deck::setCurrentlyDisplayedCard(Card* card)
{
	currently_displayed_card = card;
}

std::deque<Card*>& Tile::getCardsOnTile()
{
	return cards_on_tile;
}

void Tile::addCardToTile(Card* card)
{
	cards_on_tile.push_back(card);
}

sf::Vector2f& Tile::getPositionOnBoard()
{
	return position_on_board;
}


Card* Pile::getLastCard()
{
	return last_card;
}

sf::Vector2f Pile::getPosition()
{
	return position;
}

Pile::Pile(sf::Vector2f position)
{
	this->position = position;
	this->number_of_cards_on_pile = 0;
	this->last_card = nullptr;
}

void Pile::putCardOnPile(Card* card)
{
	last_card = card;
	number_of_cards_on_pile += 1;
}

bool Pile::isPuttingCardOnLegal(Card* card)
{
	const std::vector<std::string> value_order = {
		"ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "jack", "queen", "king"
	};
	if (last_card == nullptr)
	{
		if (card->getValue() == "ace")
			return true;
		return false;
	}
	if (last_card->getColor() != card->getColor())
		return false;
	if (last_card->getValue() == "ace" && card->getValue() != "2")
	{
		return false;
	}
	if (std::find(value_order.begin(), value_order.end(), last_card->getValue()) !=
		std::find(value_order.begin(), value_order.end(), card->getValue()) - 1)
		return false;

	return true;
}
