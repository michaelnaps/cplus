// File: Feed.h
// Created by: Michael Napoli
// Created on: 8/29/2019
// Last modified on: 

/*
	Class type that evaluates the food being given to a simulated cat.
*/

class Feed
{
private:
	string food_type;
	
	bool check_food() {
		if (food_type == "sushi" || food_type == "Sushi") {
			cout << endl << "That food is acceptable." << endl;
			return true;
		}
		else {
			cout << endl << "That food is not acceptable" << endl;
			return false;
		}
	}

public:
	bool setFoodType(string temp) {
		food_type = temp;
		
		if (this->check_food()) { return true; }		
		else { return false; )
	}
};