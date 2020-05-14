#include <string>
#include <iostream>
#include <vector>
#include "Player.hpp"

Player::Player(vector<Card> myHand, int score, string name)
{
	this->myHand = myHand;
	this->score = score;
	this->name = name;
}



vector<Card> Player::Hit(vector<Card> deck)
{
	this->myHand.push_back(deck[0]);
	deck.erase(deck.begin());
	return deck;
}

void Player::DisplayCard() {
	cout << "Hand of " + this->name + ":" << endl;

	for (int i = 0; i < this->myHand.size(); i++) {
		cout << this->myHand[i].name + ", ";
	}
	cout << endl;
	cout << endl;
}
bool Player::PromptTurn(vector<Card> deck) {
	cout << "Type either HIT to hit or STAY to stay" << endl;
	string input;
	cin >> input;
	while (true) {
		if (input == "HIT") {
			deck = this->Hit(deck);
			return false;
			break;
		}
		if (input == "STAY") {
			return true;
			break;
		}
		else {
			
		}
	}

}

bool Player::DealerTurn(vector<Card> deck)
{
	int dealerScore = this->ComputeScore();

	if (dealerScore < 17) {
		this->Hit(deck);
		return false;
	}
	else {
		return true;
	}

	return true;
}

int Player::ComputeScore()
{
	int score = 0;
	int aceCounter = 0;
	for (int i = 0; i < size(this->myHand); i++) {
		if (this->myHand[i].name == "Ace") {
			aceCounter++;
		}
		else {
			score += this->myHand[i].value;
		}
	}
	int testScore;
	int aceOne = 0;
	int aceEleven = aceCounter;

	if (score + aceCounter > 21) {
		score += aceCounter;
	}
	else {

		while (true) {
			if (score + aceOne + (11 * aceEleven) > 21) {
				aceOne += 1;
				aceEleven -= 1;

			}
			else {
				score += aceOne + (11 * aceEleven);

				break;
			}
		}

	}

	return score;

}

