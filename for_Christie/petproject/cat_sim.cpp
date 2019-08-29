// File: cat_sim.cpp
// Created on: 8/27/2019
// Last modified on:

// Created by: Michael Napoli
// Created for: Christie Bradley

/* 
	Program that simulates a pet cat which you must "keep alive" by means
	of feeding, petting and nurturing.
*/

#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include "Feline.h"
#include "Feed.h"
using namespace std;

// FUNCTION INITIALIZATIONS INITIALIZATION
// 'save()' FUNCTION
bool save(Feline& save_cat);

// 'load()' FUNCTION INITIALIZATION
bool load(Feline& load_cat);

// 'display_cat()' FUNCTION INITIALIZATION
void display_cat();

// 'run_command()' FUNCTION INITIALIZATION
void run_command(string input1, string input2);

int main()
{
	Feline cat;
	string userInput1, userInput2;
	string ignoreinput;
	
	if (load(cat)) {
		cout << "Your cat's name is " << cat.getName() << endl;
		cout << "Hunger: " << cat.getHungerStatus() << endl;
		cout << "Comfort: " << cat.getComfortStatus() << endl;
	}
	
	else { cat.nameYourCat(); }
	
	do {
		cout << "What would you like to do? ";
		cin >> userInput1 >> userInput2;
		
		run_command(userInput1, userInput2);
		
		if (userInput1 == "kill" && userInput2 == cat.getName()) {
			cat.killcat();
		}
		
	} while (userInput1 != "stop");
		
	if (!save(cat)) 
	{ cout << endl << "ERROR: Something is wrong with the save file." << endl; }

	return 0;
}

bool save(Feline& save_cat) {
	ofstream fout;
	
	fout.open("cat.txt", ios::ate);
	
	if (!fout.is_open()) {
		cout << endl << "ERROR: There is something wrong with the save file." << endl;
		return false;
	}
	
	fout << save_cat.getName() << " ";
	fout << save_cat.getHungerStatus() << " ";
	fout << save_cat.getComfortStatus() << " ";
	
	fout.close();
	
	return true;
}

bool load(Feline& load_cat) {
	ifstream fin;
	string temp_name, temp_hunger, temp_comfort;
	
	fin.open("cat.txt");
	if (!fin.is_open()) {
		cout << endl << "ERROR: The load file did not open correctly." << endl;
		return false;
	}
	
	fin >> temp_name >> temp_hunger >> temp_comfort;
	fin.close();
	
	load_cat.setName(temp_name);
	load_cat.setHunger(temp_hunger);
	load_cat.setComfort(temp_comfort);
	
	return true;
}

void run_command(string input1, string input2) {
	
}