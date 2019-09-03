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
#include <fstream>
using namespace std;

// FUNCTION INITIALIZATIONS INITIALIZATION
// 'save()' FUNCTION
bool save(Feline& save_cat);

// 'load()' FUNCTION INITIALIZATION
bool load(Feline& load_cat);

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
	if (load(cat)) {
		display_cat(cat);
		cout << endl;
	}
	
	do {		
		userInput1.clear();
		userInput2.clear();
		
		cout << "What would you like to do? ";
		cin >> userInput1 >> userInput2;
		
		cat.run_command(userInput1, userInput2);
		display_cat(cat);
		cout << endl;
		
		cat.iterateHunger(true);
		cat.iterateComfort(true);
	} while (userInput1 != "stop");
		
	// once the user decides to stop playing, the cat is saved to their specific file 
	// this overwrites any previous information about the cat of the same name
	if (cat.getName().length() != 0) { 
		if (save(cat)) { cout << "Your cat was saved successfully." << endl; }
	}

	return 0;
}

bool save(Feline& save_cat) {
	ofstream fout;
	
	fout.open((save_cat.getName() + ".txt"), ios::ate);
	
	if (!fout.is_open()) {
		cout << endl << "ERROR: Something is wrong with the save file." << endl;
		return false;
	}
	
	fout << save_cat.getName() << " ";
	fout << save_cat.getHungerCount() << " ";
	fout << save_cat.getComfortCount() << " ";
	
	fout.close();
	
	return true;
}

bool load(Feline& load_cat) {
	ifstream fin;
	string temp_name;
	int temp_hungerCount, temp_comfortCount;
	
	fin.open((load_cat.getName() + ".txt"));
	
	if (!fin.is_open()) {  // if there is no file for the named cat, one is made
		cout << "There is no load file on record for that cat name." << endl;
		cout << "Your cat is being born now..." << endl;
		return false;
	}
	
	fin >> temp_name >> temp_hungerCount >> temp_comfortCount;
	fin.close();
	
	load_cat.setName(temp_name);
	load_cat.setHungerCount(temp_hungerCount);
	load_cat.setComfortCount(temp_comfortCount);
	
	return true;
}

// 'display_cat()' FUNCTION INITIALIZATION
void display_cat(Feline& disp_cat) {
	cout << "Your cat's name is " << disp_cat.getName() << endl;
	cout << "Hunger: " << disp_cat.getHungerStatus() << endl;
	cout << "Comfort: " << disp_cat.getComfortStatus() << endl;
}