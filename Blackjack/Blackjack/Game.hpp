#pragma once
using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include "Player.hpp"
#include "Card.hpp"



class Game {
	private:
		vector<Card> deck;

	public:
		Game();
		vector<Card> InitDeck();
		void Start();
};