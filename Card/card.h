#include <stdio.h>
#include <string>
#include <vector>
#include<iterator>
#include <algorithm>
#include <random>
#pragma once

class Card
{
	std::string color;
	std::string value;
public:
	std::string getColor();
	std::string getValue();
	Card(std::string color, std::string value);
};

class Deck
{
	int cards_in_deck;
	void shuffleDeck();
	int removeCard();
	int fillDeck();
	std::vector<Card*> cardsList;
public:
	Deck(int cards_in_deck);
	int getCardsLeft();
	void addCard();
};