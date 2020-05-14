#pragma once
using namespace std;
#include <iostream>
#include <vector>
#include "Card.hpp"


class Player {

	private:
		
		int score;
		string name;
		

	public:
		Player(vector<Card> myHand, int score, string name);
		vector<Card> myHand;

		vector<Card> Hit(vector<Card> deck);
		void DisplayCard();
		bool PromptTurn(vector<Card> deck);
		bool DealerTurn(vector<Card> deck);
		int ComputeScore();
};