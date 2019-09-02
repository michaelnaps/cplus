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
		cout << "The cat accepts this meal." << endl;
	}
	void comfortCat() {
		if ((comfort_count - 4) >= 0) { comfort_count =- 4; }
		else { comfort_count = 0; }
		cout << "The cat enjoys your affection." << endl;
	}
	
	void comfortCommands(string& input1, string& input2) {
		if (input1 == "pet" && input2 == name) { this->comfortCat(); }
		else if (input1 == "cuddle" && input2 == name) { this->comfortCat(); }			
		else if (input1 == "hug" && input2 == name) { this->comfortCat(); }
		else if (input1 == "kiss" && input2 == name) { this->comfortCat(); }
		else { cout << "The cat does not accept your attempt to comfort." << endl; }
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
	void setName(string temp_name) { name = temp_name; }
	void setHungerCount(int temp_hcount) { hunger_count = temp_hcount; }
	void setComfortCount(int temp_ccount) { comfort_count = temp_ccount; }
	
	// 'get' CLASS TYPE FUNCTIONS
	string getName() { return name; }
	string getHungerStatus() {
		this->iterateComfort(false);
		return hunger_level; 
	}
	string getComfortStatus() {
		this->iterateComfort(false);
		return comfort_level; 
	}
	int getHungerCount() { return hunger_count; }
	int getComfortCount() { return comfort_count; }
	
	// ITERATE CAT STATS FUNCTIONS
	void iterateHunger(bool iterate_TF) {
		if (hunger_count <= 3) { hunger_level = "Full"; }
		else if (hunger_count > 3 && hunger_count <= 6) { hunger_level = "A little hungry"; }
		else if (hunger_count > 6 && hunger_count <=10) { hunger_level = "Hungry"; }
		else if (hunger_count > 10) { hunger_level = "Starving"; }
		else { cout << endl << "ERROR: There is something wrong with the simulation's hunger features." << endl; }
		
		if (hunger_count > 16) { this->killcat(); }
		
		if (iterate_TF) { ++hunger_count; }
	}
	void iterateComfort(bool iterate_TF) {		
		if (comfort_count <= 3) { comfort_level = "Happy"; }
		else if (comfort_count > 3 && comfort_count <= 6) { comfort_level = "Satisfied"; }
		else if (comfort_count > 6 && comfort_count <=10) { comfort_level = "Bored"; }
		else if (comfort_count > 10 && comfort_count <= 14) { comfort_level = "Bored and Tired"; }
		else if (comfort_count > 14 && comfort_count <= 18) { comfort_level = "Sad"; }
		else if (comfort_count > 18) { comfort_level = "Depressed"; }
		else { cout << endl << "ERROR: There is something wrong with the simulation's hunger features." << endl; }
		
		if (comfort_count > 24) { this->killcat(); }
		
		if (iterate_TF) { ++comfort_count; }
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

	void run_command(string& input1, string& input2) {
		if (input1 == "feed" || input1 == "Feed") {
			Feed temp_food;
			if (temp_food.setFoodType(input2)) { this->feedCat(); }
		}
		else if (input1 == "buy" && input2 == "cat") { this->nameYourCat(); }		
		else if (input1 == "kill" && input2 == name) { this->killcat(); }
		else if (input1 == "stop" && input2 == "game") { };
		else { this->comfortCommands(input1, input2); }
	}
};



























