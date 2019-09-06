// File: Feline.h
// Created by: Michael Napoli
// Created on: 8/27/2019
// Last modified on:

/* Class type variable that holds the informations regarding a simulated cat. */

#include <iostream>
#include <string>
#include <fstream>
#include "Feed.h"
#include "Cimage.h"
using namespace std;

class Feline
{
private:
	string name;
	string hunger_level;
	int hunger_count;
	string comfort_level;
	int comfort_count;
	Cimage cat_image;
		
	void feedCat() {
		if (((hunger_count - 3) >= 0)) { 
			hunger_count -= 3;
			this->iterateHunger(false);
		}
		else { 
			hunger_count = 0; 
			this->iterateHunger(false);
		}
		cout << "The cat accepts this meal." << endl;
	}
	void comfortCat() {
		if (((comfort_count - 2) >= 0)) { 
			comfort_count -= 3; 
			this->iterateComfort(false);
		}
		else { 
			comfort_count = 0;
			this->iterateComfort(false);
		}
		cout << "The cat enjoys your affection." << endl;
	}
	
	bool comfortCommands(string& input1, string& input2) {
		if (input1 == "pet" && input2 == name) { return true; }
		else if (input1 == "cuddle" && input2 == name) { return true; }			
		else if (input1 == "hug" && input2 == name) { return true; }
		else if (input1 == "snuggle" && input2 == name) { return true; }
		else { return false; }
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
	
	// 'get' CLASS TYPE FUNCTIONS
	string getName() { return name; }
	string getHungerStatus() {
		this->iterateHunger(false);
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
		if (hunger_count >= 0 && hunger_count <= 3) { hunger_level = "Full"; }
		else if (hunger_count > 3 && hunger_count <= 6) { hunger_level = "A little hungry"; }
		else if (hunger_count > 6 && hunger_count <= 10) { hunger_level = "Hungry"; }
		else if (hunger_count > 10) { hunger_level = "Starving"; }
		else {
			cout << "hunger_count = " << hunger_count << endl;
			cout << "ERROR: There is something wrong with the simulation's hunger features." << endl; 
		}
		
		if (hunger_count > 16) { this->killcat(); }
		
		if (iterate_TF) { ++hunger_count; }
	}
	void iterateComfort(bool iterate_TF) {		
		if (comfort_count >= 0 && comfort_count <= 3) { comfort_level = "Happy"; }
		else if (comfort_count > 3 && comfort_count <= 6) { comfort_level = "Satisfied"; }
		else if (comfort_count > 6 && comfort_count <= 9) { comfort_level = "Bored"; }
		else if (comfort_count > 9 && comfort_count <= 12) { comfort_level = "Bored and Tired"; }
		else if (comfort_count > 12 && comfort_count <= 15) { comfort_level = "Sad"; }
		else if (comfort_count > 15) { comfort_level = "Depressed"; }
		else { 
			cout << "comfort_count = " << comfort_count << endl;
			cout << "ERROR: There is something wrong with the simulation's hunger features." << endl; 
		}
		
		if (comfort_count > 20) { this->killcat(); }
		
		if (iterate_TF) { ++comfort_count; }
	}
	
	void display_feline() {
		cat_image.setImageNum(1);
		cat_image.display_image();
	}
	
	// KILL CAT FUNCTION	
	// erases load function for teh named cat
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

	bool run_command(string& input1, string& input2) {
		if (input1 == "feed" || input1 == "Feed") {
			Feed temp_food;
			if (temp_food.setFoodType(input2)) { this->feedCat(); }
		}
		else if (input1 == "buy" && input2 == "cat") { this->nameYourCat(); }
		else if (input1 == "kill" && input2 == name) { this->killcat(); }
		else if (this->comfortCommands(input1, input2)) { this->comfortCat(); }		
		else if (input1 == "stop" && input2 == "game") { return false; }
		
		return true;
	}
	
	// CAT SAVE/LOAD FUNCTIONS
	bool save() {
		ofstream fout;
		
		fout.open((name + ".txt"), ios::ate);
		
		if (!fout.is_open()) {
			cout << endl << "ERROR: Something is wrong with the save file." << endl;
			return false;
		}
		
		fout << name << " ";
		fout << hunger_count << " ";
		fout << comfort_count << " ";
		
		fout.close();
		
		return true;
	}

	bool load() {
		ifstream fin;
		
		fin.open((name + ".txt"));
		
		// if there is no file for the named cat, one is made
		if (!fin.is_open()) {
			cout << "There is no load file on record for that cat name." << endl;
			cout << "Your cat is being born now..." << endl;
			return false;
		}
		
		fin >> name >> hunger_count >> comfort_count;
		fin.close();
		
		return true;
	}
};



























