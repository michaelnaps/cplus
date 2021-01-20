// File: cat_sim.cpp
// Created on: 8/27/2019
// Last modified on: 1/20/2021

// Created by: Michael Napoli

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
	Feline cat;  // cat variable for controlling the simulated cat
	string temp_name;  // temporary name used to initiate cat sim.
	string userInput1, userInput2;  // user inputted commands for the cat
	string close_input;

	cout << "What is your cat's name? ";  // ask user for the name of their cat
	cin >> temp_name;

	cat.setName(temp_name);  // apply temporary name to Feline class type variable

	// if cat of the same name has been made before, the load file for that cat is opened
	if (cat.load()) {
		display_cat(cat);  // the cat is displayed
	}

	do {
		userInput1.clear();  // user inputted commands are cleared on every iteration of the do-while loop
		userInput2.clear();

		cout << "What would you like to do? ";  // ask user for their commands
		cin >> userInput1 >> userInput2;

		// run commands, if the command returns false, loop is exited
		if (!cat.run_command(userInput1, userInput2)) { break; }

		if (cat.getName().length() != 0) {
			display_cat(cat);
		}
	} while (cat.getName().length() != 0);  // when user enters 'stop game' the loop is exited

	// once the user decides to stop playing, the cat is saved to their specific file
	// this overwrites any previous information about the cat of the same name
	if (cat.getName().length() != 0) {  // if cat name is longer than 0, the cat is saved
		if (cat.save()) { cout << endl << cat.getName() << " was saved successfully." << endl; }
		else { cout << "Your cat was not saved." << endl; }  // if the cat is not saved successfully, ouputs error code
	}

	// end program by hitting 'enter' on keyboard
	cout << endl;
	cout << "Enter a symbol and press Enter to continue... ";
	cin >> userInput1;

	return 0;
}

// FUNCTION DEFINITION: 'display_cat()'
void display_cat(Feline& disp_cat) {
	cout << "Your cat's name is " << disp_cat.getName() << endl;  // display cat name
	cout << "Hunger: " << disp_cat.getHungerStatus() << endl;  // display cat's hunger level
	cout << "Comfort: " << disp_cat.getComfortStatus() << endl << endl;  // display cat's comfort level
	disp_cat.display_feline();  // display command prompt capable image of cat
	cout << endl;
}
