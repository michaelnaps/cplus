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
	string comfort_level;
	int hunger_count, comfort_count;
	
	void create_cat() {
		hunger_level = "Full";
		comfort_level = "Happy";
		comfort_count = 0;
		hunger_count = 0;
	}
	
public:
	// FUNCTION THAT BEGINS SIM
	void nameYourCat() { 		
		cout << "Enter the name of your cat: ";
		cin >> name;		
		this->create_cat();
	}
	
	// 'set' CLASS TYPE FUNCTIONS
	void setName(string temp_name) { 
		name = temp_name;
		this->create_cat();
	}
	void setHunger(string temp_hunger) { hunger_level = temp_hunger; }
	void setComfort(string temp_comfort) { comfort_level = temp_comfort; }
	
	// 'get' CLASS TYPE FUNCTIONS
	string getName() { return name; }
	string getHungerStatus() { return hunger_level; }
	string getComfortStatus() { return comfort_level; }
	
	// ITERATE CAT STATS FUNCTIONS
	void iterateHunger() {
		if (hunger_level == "Full") { hunger_level = "A little hungry"; }
		else if (hunger_level == "A little hungry") { hunger_level = "Hungry"; }
		else if (hunger_level == "Hungry") { hunger_level = "Starving"; }
		else if (hunger_level == "Starving") { ++hunger_count; }
		else { cout << endl << "ERROR: There is something wrong with the simulations hunger features." << endl; }
		
		if (hunger_count == 5) { this->killcat(); }
	}
	void iterateComfort() {
		if (comfort_level == "Happy") { comfort_level = "Satisfied"; }
		else if (comfort_level == "Satisfied") { comfort_level = "Bored"; }
		else if (comfort_level == "Bored") { comfort_level = "Tired and bored"; }
		else if (comfort_level == "Super Bored") { comfort_level = "Sad"; }
		else if (comfort_level == "Sad") { comfort_level = "Depressed"; }
		else if (comfort_level == "Depressed") { ++comfort_count; }
		else { 
			cout << endl << "ERROR: There is something wrong with the simulation's comfort functionality." << endl;
			cout << "Resetting cat's comfort." << endl;
			comfort_level = "Happy";
			comfort_count = 0;
		}
		
		if (comfort_count == 5) { this->killcat(); }
	}
	
	bool killcat() {
		string filename(name + ".txt");
		remove(filename.c_str());
		
		name = "";
		hunger_level = "";
		comfort_level = "";
		cout << endl << "Your cat has died, probably due to neglect." << endl;
		cout << "Maybe by choice." << endl << endl;
		
		return false;
	}

	void run_command(const string input1, const string input2) {
		if (input1 == "feed" || input1 == "Feed") {
			Feed temp_food;
			temp_food.setFoodType(input2);
		}
		else if (input1 == "buy" && input2 == "cat") {
			this->nameYourCat();
		}
	}
};



























