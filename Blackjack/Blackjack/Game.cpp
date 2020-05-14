using namespace std;
#include <iostream>
#include "Game.hpp"

Game::Game() {
	this->deck = deck;
}

vector <Card> Game::InitDeck() {

	vector<Card> deck;
	//hearts
	deck.push_back( Card("Hearts", "Ace", 0));
	deck.push_back( Card("Hearts", "Two", 2));
	deck.push_back( Card("Hearts", "Three", 3));
	deck.push_back( Card("Hearts", "Four", 4));
	deck.push_back( Card("Hearts", "Five", 5));
	deck.push_back( Card("Hearts", "Six", 6));
	deck.push_back( Card("Hearts", "Seven", 7));
	deck.push_back( Card("Hearts", "Eight", 8));
	deck.push_back( Card("Hearts", "Nine", 9));
	deck.push_back( Card("Hearts", "Ten", 10));
	deck.push_back( Card("Hearts", "Jack", 10));
	deck.push_back( Card("Hearts", "Queen", 10));
	deck.push_back( Card("Hearts", "King", 10));

	//spades
	deck.push_back( Card("Spades", "Ace", 0));
	deck.push_back( Card("Spades", "Two", 2));
	deck.push_back( Card("Spades", "Three", 3));
	deck.push_back( Card("Spades", "Four", 4));
	deck.push_back( Card("Spades", "Five", 5));
	deck.push_back( Card("Spades", "Six", 6));
	deck.push_back( Card("Spades", "Seven", 7));
	deck.push_back( Card("Spades", "Eight", 8));
	deck.push_back( Card("Spades", "Nine", 9));
	deck.push_back( Card("Spades", "Ten", 10));
	deck.push_back( Card("Spades", "Jack", 10));
	deck.push_back( Card("Spades", "Queen", 10));
	deck.push_back( Card("Spades", "King", 10));

	//diamonds
	deck.push_back( Card("Diamonds", "Ace", 0));
	deck.push_back( Card("Diamonds", "Two", 2));
	deck.push_back( Card("Diamonds", "Three", 3));
	deck.push_back( Card("Diamonds", "Four", 4));
	deck.push_back( Card("Diamonds", "Five", 5));
	deck.push_back( Card("Diamonds", "Six", 6));
	deck.push_back( Card("Diamonds", "Seven", 7));
	deck.push_back( Card("Diamonds", "Eight", 8));
	deck.push_back( Card("Diamonds", "Nine", 9));
	deck.push_back( Card("Diamonds", "Ten", 10));
	deck.push_back( Card("Diamonds", "Jack", 10));
	deck.push_back( Card("Diamonds", "Queen", 10));
	deck.push_back( Card("Diamonds", "King", 10));

	//clubs
	deck.push_back( Card("Clubs", "Ace", 0));
	deck.push_back( Card("Clubs", "Two", 2));
	deck.push_back( Card("Clubs", "Three", 3));
	deck.push_back( Card("Clubs", "Four", 4));
	deck.push_back( Card("Clubs", "Five", 5));
	deck.push_back( Card("Clubs", "Six", 6));
	deck.push_back( Card("Clubs", "Seven", 7));
	deck.push_back( Card("Clubs", "Eight", 8));
	deck.push_back( Card("Clubs", "Nine", 9));
	deck.push_back( Card("Clubs", "Ten", 10));
	deck.push_back( Card("Clubs", "Jack", 10));
	deck.push_back( Card("Clubs", "Queen", 10));
	deck.push_back( Card("Clubs", "King", 10));

	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	shuffle(begin(deck), end(deck), default_random_engine(seed));
	
	return deck;
}

void Game::Start(){
	
	deck = this->InitDeck();

	vector<Card> myHand;
	int score = 0;
	Player dealer = Player(myHand, score, "dealer");
	Player user = Player(myHand, score, "you");
	myHand.clear();

	for (int i = 0; i < 2; i++) {
		deck = user.Hit(deck);
		deck = dealer.Hit(deck);
	}



	int dealerScoretest;
	int userScoretest;
	dealer.DisplayCard();
	user.DisplayCard();


	bool userStay = false;
	bool dealerStay = false;
	while (dealerStay == false || userStay == false) {

		if (userStay == false) {
			userStay = user.PromptTurn(deck);
			if (userStay == false) {
				deck.erase(deck.begin());
				int userScore = user.ComputeScore();
				if (userScore > 21) {
					userStay = true;
					cout << "Bust! you will be forced to stay for the rest of the game." << endl;
				}
			}
		}
		user.DisplayCard();


		//make the dealer AI
		if (dealerStay == false) {
			dealerStay = dealer.DealerTurn(deck);
			if (dealerStay == false) {
				deck.erase(deck.begin());
			}

		}
		dealer.DisplayCard();
	}
	int userFinalScore = user.ComputeScore();
	int dealerFinalScore = dealer.ComputeScore();
	cout << "Your score is " + userFinalScore << endl;
	cout << "The dealer's score is " + dealerFinalScore << endl;

	bool dealerBust;
	bool userBust;
	if (userFinalScore > 21) {
		userBust = true;
	}
	else {
		userBust = false;
	}

	if (dealerFinalScore > 21) {
		dealerBust = true;
	}
	else {
		dealerBust = false;
	}

	if (dealerBust == true && userBust == true) {
		cout << "you both bust, tie";
	}
	if (dealerBust == true && userBust == false) {
		cout << "dealer busts, you win";
	}
	if (dealerBust == false && userBust == true) {
		cout << "you bust, dealer wins";
	}
	if (dealerBust == false && userBust == false) {
		if (userFinalScore == dealerFinalScore) {
			cout << "tie!";
		}
		else if (userFinalScore > dealerFinalScore) {
			cout << "you win!";
		}
		else if (userFinalScore < dealerFinalScore) {
			cout << "dealer wins!";
		}
	}
	std::cin.ignore();



}

