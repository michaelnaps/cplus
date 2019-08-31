// File: Feed.h
// Created by: Michael Napoli
// Created on: 8/29/2019
// Last modified on: 

/*
	Class type that evaluates the food being given to a simulated cat.
*/

#include <iostream>
#include <string>
using namespace std;

class Feed
{
private:
	string food_type;
	
	bool check_food() {
		if (food_type == "sushi") { return true; }
		else if (food_type == "fish") { return true; }
		else if (food_type == "milk") { return true; }
		else if (food_type == "catfood") { return true; }
		else if (food_type == "pizza") { return true; }
		else if (food_type == "tuna") { return true; }
		else {
			cout << "The cat does not accept and is considering clawing you. Try again!" << endl;
			return false;
		}
	}

public:
	bool setFoodType(string temp) {
		food_type = temp;
		
		if (this->check_food()) { return true; }		
		else { return false; }
	}
};