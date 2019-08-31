// File: Feline.h
// Created by: Michael Napoli
// Created on: 8/27/2019
// Last modified on:

/* Class type variable that holds the informations regarding a simulated cat. */

#include <iostream>
#include <string>
#include "Feed.h"
using namespace std;

class Feline
{
private:
	string name;
	string hunger_level;
	int hunger_count;
	string comfort_level;
	int comfort_count;
		
	void feedCat() {
		if ((hunger_count - 3) >= 0) { hunger_count =- 3; }
		else { hunger_count = 0; }
	}
	void comfortCat() {
		if ((comfort_count - 4) >= 0) { comfort_count =- 4; }
		else { comfort_count = 0; }
	}
	
public:
	Feline() : hunger_count(0), comfort_count(0) 
	{ }

	// FUNCTION THAT BEGINS SIM
	void nameYourCat() { 		
		cout << "Enter the name of your cat: ";
		cin >> name;
	}
	
	// 'set' CLASS TYPE FUNCTIONS
	void setName(string temp_name) { 
		name = temp_name;
	}
	void setHunger(string temp_hunger) { hunger_level = temp_hunger; }
	void setComfort(string temp_comfort) { comfort_level = temp_comfort; }
	
	// 'get' CLASS TYPE FUNCTIONS
	string getName() { return name; }
	string getHungerStatus() { return hunger_level; }
	string getComfortStatus() { return comfort_level; }
	
	// ITERATE CAT STATS FUNCTIONS
	void iterateHunger() {
		if (hunger_count <= 3) { hunger_level = "Full"; }
		else if (hunger_count > 3 && hunger_count <= 6) { hunger_level = "A little hungry"; }
		else if (hunger_count > 6 && hunger_count <=10) { hunger_level = "Hungry"; }
		else if (hunger_count > 10) { hunger_level = "Starving"; }
		else { cout << endl << "ERROR: There is something wrong with the simulation's hunger features." << endl; }
		
		if (hunger_count > 16) { this->killcat(); }
		
		++hunger_count;
	}
	void iterateComfort() {		
		if (comfort_count <= 3) { comfort_level = "Happy"; }
		else if (comfort_count > 3 && comfort_count <= 6) { comfort_level = "Satisfied"; }
		else if (comfort_count > 6 && comfort_count <=10) { comfort_level = "Bored"; }
		else if (comfort_count > 10 && comfort_count <= 14) { comfort_level = "Bored and Tired"; }
		else if (comfort_count > 14 && comfort_count <= 18) { comfort_level = "Sad"; }
		else if (comfort_count > 18) { comfort_level = "Depressed"; }
		else { cout << endl << "ERROR: There is something wrong with the simulation's hunger features." << endl; }
		
		if (comfort_count > 24) { this->killcat(); }
		
		++comfort_count;
	}
	
	bool killcat() {
		string filename(name + ".txt");
		remove(filename.c_str());
		
		name = "";
		hunger_level = "";
		comfort_level = "";
		hunger_count = 0;
		comfort_count = 0;
		cout << endl << "Your cat has died, probably due to neglect." << endl;
		cout << "Maybe by choice." << endl << endl;
		
		return false;
	}

	void run_command(const string input1, const string input2) {
		if (input1 == "feed" || input1 == "Feed") {
			Feed temp_food;
			if (temp_food.setFoodType(input2)) {
				this->feedCat();
			}
		}
		else if (input1 == "buy" && input2 == "cat") {
			this->nameYourCat();
		}
	}
};



























