// File: cat_sim.cpp
// Created on: 8/27/2019
// Last modified on:

// Created by: Michael Napoli
// Created for: Christie Bradley

/* 
	Program that simulates a pet cat which you must "keep alive" by means
	of feeding, petting and nurturing.
*/

#include "Feline.h"
using namespace std;

// 'display_cat()' FUNCTION INITIALIZATION
void display_cat(Feline& disp_cat);

int main()
{
	Feline cat;
	string temp_name;
	string userInput1, userInput2;
	
	cout << "What is your cat's name? ";  // ask user for the name of their cat
	cin >> temp_name;
	cat.setName(temp_name);
	
	// if cat of the same name has been made before, the load file for that cat is opened
	if (cat.load()) {
		display_cat(cat);
		cout << endl;
	}
	
	do {		
		userInput1.clear();
		userInput2.clear();
		
		cout << "What would you like to do? ";
		cin >> userInput1 >> userInput2;
		
		if (!cat.run_command(userInput1, userInput2)) { break; }
		display_cat(cat);
		cout << endl;
		
		cat.iterateHunger(true);
		cat.iterateComfort(true);
	} while (userInput1 != "stop" && userInput2 != "game");
		
	// once the user decides to stop playing, the cat is saved to their specific file 
	// this overwrites any previous information about the cat of the same name
	if (cat.getName().length() != 0) { 
		if (cat.save()) { cout << cat.getName() << " was saved successfully." << endl; }
		else { cout << "Your cat was not saved." << endl; }
	}

	return 0;
}

// 'display_cat()' FUNCTION INITIALIZATION
void display_cat(Feline& disp_cat) {
	cout << "Your cat's name is " << disp_cat.getName() << endl;
	cout << "Hunger: " << disp_cat.getHungerStatus() << endl;
	cout << "Comfort: " << disp_cat.getComfortStatus() << endl << endl;
	disp_cat.display_feline();
	cout << endl;
}