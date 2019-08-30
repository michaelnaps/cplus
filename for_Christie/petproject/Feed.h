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
		if (food_type == "sushi" || food_type == "Sushi") {
			cout << "The cat accepts this meal." << endl;
			return true;
		}
		else {
			cout << endl << "The cat does not accepts and is now mad at you. Try again!" << endl;
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