// File: Feed.h
// Created by: Michael Napoli
// Created on: 8/29/2019
// Last modified on: 9/6/2019

/*
	Class type that evaluates the food being given to a simulated cat.
*/

#include <iostream>
#include <string>
using namespace std;

class Feed
{
private:
	string food_type;  // string for the food entered by the function call

	// depending on inputted food, return true if acceptable, otherwise false
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
	// function that can be called using class type
	bool setFoodType(string temp_food) {
		food_type = temp_food;  // class type string that holds the food variable

		// use inputted food, return true of the food checks to be acceptable
		if (this->check_food()) { return true; }
		else { return false; }
	}
};
