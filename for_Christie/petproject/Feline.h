// File: Feline.h
// Created by: Michael Napoli
// Created on: 8/27/2019
// Last modified on:

/* Class type variable that holds the informations regarding a simulated cat. */

#include <iostream>
#include <ctime>
#include <string>
#include <fstream>
#include "Feed.h"  // class type made specifically to check feed commands
#include "Cimage.h"  // class type made specifically to output ASCII cat images
using namespace std;

class Feline
{
private:
	string name;  // name of cat
	string hunger_level;  // hunger level title for cat
	int hunger_count;  // hunger level tracking integer
	string comfort_level;  // comfort level title for cat
	int comfort_count;  // comfort level tracking integer
	Cimage cat_image;  // image variable for ASCII cat
	int image_num;  // integer used to select which cat image to display
	
	// class function for feeding simulated cat (private)
	void feedCat() {
		if (((hunger_count - 3) >= 0)) { // if the hunger tracking intger is above 3
			hunger_count -= 3;  // the 'hunger_count' is updated to reflect the cat being fed
			this->iterateHunger(false);  // updates the 'hunger_level' variable
		}
		else {  // otherwise make 'hunger_count' equal to 0, this way the variable can never be negative
			hunger_count = 0; 
			this->iterateHunger(false);
		}
		cout << "The cat accepts this meal." << endl;  // output that the cat accepts
	}
	// class function for comforting simulated cat (private)
	void comfortCat() {
		if (((comfort_count - 3) >= 0)) {  // if the comfort tracking integer is above 3
			comfort_count -= 3;  // the 'comfort_count' is updated to reflect being comforted
			this->iterateComfort(false);  // update the 'comfort_level' variable
		}
		else {  // otherwise make 'comfort_count' equal to 0, this way the variable can never be negative
			comfort_count = 0;
			this->iterateComfort(false);
		}
		cout << "The cat enjoys your affection." << endl;  // output that the cat accepts
	}
	
	// class type helper function that evaluates comfort commands given by the user (private)
	// if any condition is true based on the user inputted commands, the function returns true, otherwise returns false
	bool comfortCommands(string& input1, string& input2) {
		if (input1 == "pet" && input2 == name) { return true; }
		else if (input1 == "cuddle" && input2 == name) { return true; }			
		else if (input1 == "hug" && input2 == name) { return true; }
		else if (input1 == "snuggle" && input2 == name) { return true; }
		else { return false; }
	}
	
public:
	Feline() : hunger_count(0), comfort_count(0)  // 'hunger_count' and 'comfort_count' are intialized at 0
	{ }

	// FUNCTION THAT BEGINS SIM
	void nameYourCat() {  // class type function that names the cat		
		cout << "Enter the name of your cat: ";
		cin >> name;
	}
	
	// 'set' CLASS TYPE FUNCTIONS
	void setName(string temp_name) { name = temp_name; }  // class type functions that names the cat
	
	// 'get' CLASS TYPE FUNCTIONS
	string getName() { return name; }  // returns the current cat's name
	string getHungerStatus() {  // returns the hunger status title of the cat
		return hunger_level;
	}
	string getComfortStatus() {  // returns the comfort status title of the cat
		return comfort_level;
	}
	
	// ITERATE CAT STATS FUNCTIONS
	// class function that iterates the hunger status of the simulated cat
	// if 'true' is entered into the function call, the 'hunger_count' variable will be updated
	// otherwise the function will evaluate the 'hunger_count' variable in order to update the hunger status title
	// also updates the image of the cat depending on the hunger level
	void iterateHunger(bool iterate_TF) {
		if (hunger_count >= 0 && hunger_count <= 3) {  // if 'hunger_count' is between 0 and 3 the cat is "Full"
			hunger_level = "Full"; 
			image_num = 6;
		}
		else if (hunger_count > 3 && hunger_count <= 6) {  // 4-6 the cat is "A little hungry"
			hunger_level = "A little hungry";
			image_num = 5;
		}
		else if (hunger_count > 6 && hunger_count <= 10) {  // 7-10 the cat is "Hungry"
			hunger_level = "Hungry"; 
			image_num = 2;
		}
		else if (hunger_count > 10) {  // 10 and above the cat is "Starving"
			hunger_level = "Starving"; 
			image_num = 1;
		}
		else {  // if these parameters are not met there is something wrong with the 'hunger_count' variable
			cout << "hunger_count = " << hunger_count << endl;
			cout << "ERROR: There is something wrong with the simulation's hunger features." << endl; 
		}
		
		// if the cat's hunger level is above 16 it dies of hunger
		if (hunger_count > 16) { 
			this->killcat();
			iterate_TF = false;			
		}
		
		if (iterate_TF) { ++hunger_count; }  // iterate 'hunger_count' command
	}
	
	// class function that iterates the comfort status of the simulated cat
	// if 'true' is entered into the function call, the 'comfort_count' variable will be updated
	// otherwise the function will evaluate the 'comfort_count' variable in order to update the comfort status title
	void iterateComfort(bool iterate_TF) {		
		if (comfort_count >= 0 && comfort_count <= 3) { comfort_level = "Happy"; }  // 0-3 the cat is "Happy"
		else if (comfort_count > 3 && comfort_count <= 6) { comfort_level = "Satisfied"; }  // 4-6 the cat is "Satisfied"
		else if (comfort_count > 6 && comfort_count <= 9) { comfort_level = "Bored"; }  // 7-9 the cat is "Bored"
		else if (comfort_count > 9 && comfort_count <= 12) { comfort_level = "Bored and Tired"; }  // 10-12 the cat is "Bored and Tired"
		else if (comfort_count > 12 && comfort_count <= 15) { comfort_level = "Sad"; }  // 13-15 the cat is "Sad"
		else if (comfort_count > 15) { comfort_level = "Depressed"; }  // 15 and above the cat is "Depressed"
		else {  // if these parameters are not met the function outputs an error
			cout << "comfort_count = " << comfort_count << endl;
			cout << "ERROR: There is something wrong with the simulation's hunger features." << endl; 
		}
		
		// if the comfort integer get to 20 the cat dies of depression
		if (comfort_count > 20) { 
			this->killcat();
			iterate_TF = false;
		}
		
		if (iterate_TF) { ++comfort_count; }  // iterate 'comfort_count' command
	}
	
	// class function that displays the designated image of the simulated cat
	void display_feline() {
		cat_image.setImageNum(image_num);
		cat_image.display_image();
	}
	
	// KILL CAT FUNCTION	
	// erases load file for the named cat
	bool killcat() {
		string filename(name + ".txt");
		remove(filename.c_str());  // deletes the cat load data is applicable
		
		name.clear();
		hunger_level.clear();
		comfort_level.clear();
		hunger_count = 0;
		comfort_count = 0;
		image_num = 3;
		
		// show deceased cat
		this->display_feline();
		cout << "Your cat has died, probably due to neglect." << endl;
		cout << "Maybe by choice." << endl << endl;
		
		return false;
	}

	bool run_command(string& input1, string& input2) {
		if (input1 == "feed") {
			Feed temp_food;
			if (temp_food.setFoodType(input2)) { 
				this->feedCat();
				return true;
			}
		}
		else if (input1 == "buy" && input2 == "cat") { this->nameYourCat(); }
		else if (input1 == "kill" && input2 == name) { 
			this->killcat(); 
			return false;
		}
		else if (this->comfortCommands(input1, input2)) { 
			this->comfortCat(); 
			return true;
		}		
		else if (input1 == "stop" && input2 == "game") { return false; }
		
		this->iterateHunger(true);  // iterate the cat's hunger variables on every loop (iterate = true)
		this->iterateComfort(true);  // iterate cat's comfort variables (iterate = true)
		
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
		
		this->iterateHunger(false);
		this->iterateComfort(false);
		
		return true;
	}
};



























