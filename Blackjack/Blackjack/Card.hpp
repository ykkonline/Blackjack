#pragma once
using namespace std;

#include <vector>
#include <iostream>


class Card {
	private:


	public:
		Card(string suit, string name, int value);
		
		string name;
		string suit;
		int value;
};