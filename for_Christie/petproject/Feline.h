// File: Feline.h
// Created by: Michael Napoli
// Created on: 8/27/2019
// Last modified on: 9/11/2019

/* Class type variable that holds the informations regarding a simulated cat. */

#include <windows.h>

#include <iostream>
#include <string>
#include <ctime>
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
	
	// image class variables
	Cimage cat_image;  // image variable for ASCII cat
	int image_num;  // integer used to select which cat image to display
	int color_num;  // integer representation of the color of the cat (automatically set to the basic concole text color)
	
	// class function for feeding simulated cat (private)
	void feedCat() {
		if (((hunger_count - 3) >= 0)) {  // if the hunger tracking intger is above 3
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
		if (input2 == name) {
			if (input1 == "pet" && input2 == name) { return true; }
			else if (input1 == "cuddle" && input2 == name) { return true; }			
			else if (input1 == "hug" && input2 == name) { return true; }
			else if (input1 == "snuggle" && input2 == name) { return true; }
			else if (input1 == "play-with" && input2 == name) { return true; }
			else if (input1 == "walk") { return true; }
		}
		else { return false; }
	}
	
	// KILL CAT FUNCTION	(private)
	// erases load file for the named cat
	void killcat() {
		string filename(name + ".txt");  // creates string variable for the filename of the cat's save data
		remove(filename.c_str());  // deletes the cat save data is applicable
		
		name.clear();  // clears name variable
		hunger_level.clear();  // clears hunger title variable
		comfort_level.clear();  // clears comfort title variable
		hunger_count = 0;  // resets 'hunger_count'
		comfort_count = 0;  // resets 'comfort_count'
		image_num = 3;  // sets cat image to the designated dead cat image
		color_num = 7;  // set cat image color back to basic
		
		// show deceased cat
		cout << endl;
		this->display_feline();
		cout << endl;
		
		// tell user what happened if they don't already know
		cout << "Your cat has died, probably due to neglect." << endl;
		cout << "Maybe by choice." << endl << endl;
	}
	
	// function that uses time to iterate the stats of the given cat save data to "punish" long absence
	// compares a saved time and the current time to calculate the cat's hunger and comfort values
	void time_huncomf(const time_t& past_time) {
		int iteration;  // used to iterate the hunger/comfort variables
		time_t current(time(0));  // current time
		int elapsed(difftime(current, past_time));  // elapsed time from this session and last session
		
		iteration = (elapsed / 25200);  // cat loses one iteration in stats every SIX HOURS
		
		// the cat cannot die due to absence form the game
		// if statements moderate the maximum integer the hunger and comfort variables can reach
		if ((hunger_count + iteration) < 14) { hunger_count += iteration; }
		else { hunger_count = 12; }
		
		if ((comfort_count + iteration) < 18) { comfort_count += iteration; }
		else { comfort_count = 16; }
	}
	
	// ITERATE CAT STATS FUNCTIONS (private)
	
	// class function that iterates the hunger status of the simulated cat
	// if 'true' is entered into the function call, the 'hunger_count' variable will be updated
	// otherwise the function will evaluate the 'hunger_count' variable in order to update the hunger status title
	// also updates the image of the cat depending on the hunger level
	void iterateHunger(bool iterate_h) {
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
		
		// if the cat's 'hunger_count' variable is above 16 it dies of hunger
		if (hunger_count > 16) { 
			this->killcat();
			iterate_h = false;			
		}
		
		if (iterate_h) { ++hunger_count; }  // iterate 'hunger_count' command
	}
	
	// class function that iterates the comfort status of the simulated cat
	// if 'true' is entered into the function call, the 'comfort_count' variable will be updated
	// otherwise the function will evaluate the 'comfort_count' variable in order to update the comfort status title
	void iterateComfort(bool iterate_c) {		
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
			iterate_c = false;
		}
		
		if (iterate_c) { ++comfort_count; }  // iterate 'comfort_count' command
	}
	
	// class type function that changes the color of the outputted cat image
	void colorCat() {
		string temp_color;  // temporary value for cat color name
		
		// ask user what color they would like
		cout << endl << "What color would you like " << name << " to be?" << endl;
		
		// do-while loop that iterates until the user enters an acceptable color
		do {
			// shows user their options
			cout << "Your options include: " << endl;
			cout << "  -basic    -green" << endl;
			cout << "  -blue     -red" << endl;
			cout << "  -orange   -grey" << endl;
			cout << "  -purple   -yellow" << endl;
			
			// user input color choice
			cout << "Your choice: ";
			cin >> temp_color;
			
			// convert their string color choice into the proper integer value of 'color_num'
			if (temp_color == "green") { color_num = 2; }
			else if (temp_color == "blue") { color_num = 3; }
			else if (temp_color == "red") { color_num = 4; }
			else if (temp_color == "orange") { color_num = 6; }
			else if (temp_color == "basic") { color_num = 7; }
			else if (temp_color == "grey") { color_num = 8; }
			else if (temp_color == "purple") { color_num = 13; }
			else if (temp_color == "yellow") { color_num = 14; }
			else { 
				cout << "ERROR: color option not available." << endl << "Try again!" << endl << endl;
				color_num = 0;  // set 'color_num' to zero to iterate while loop again
			}
		} while (color_num == 0);
	}
	
public:
	Feline() : hunger_count(0), comfort_count(0),  // 'hunger_count' and 'comfort_count' are intialized at 0
	color_num(7)  // color of cat is initialized at the base window console text color
	{ }
	
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
	
	// class function that displays the designated image of the simulated cat
	void display_feline() {
		cat_image.setImage(image_num, color_num);
		cat_image.display_image();
	}

	// class function that runs user-inputted commands
	// input1 - string variable containg first half of command
	// input2 - string variable containing second half of command
	// ALL COMMANDS COME IN TWO WORD PHRASES
	bool run_command(string& input1, string& input2) {

		if (input1 == "stop" && input2 == "game") { return false; }
		
		// if the user's first input is "feed"
		else if (input1 == "feed") {
			Feed temp_food;  // a variable is made for the string 'input2'
			if (temp_food.setFoodType(input2)) {  // it is checked via the 'Feed' class and if true 
				this->feedCat();  // feeds the cat
				return true;  // return true
			}
		}
		
		// the 'comfortCommands' function checks the user's input for possible matches
		else if (this->comfortCommands(input1, input2)) { 
			this->comfortCat();  // if their command works, comfort the cat
			return true;  // returns true
		}		
		
		else if (input1 == "color" && input2 == name) {
			this->colorCat();
		}
		
		// if the user would like to kill their cat: they enter "kill catName"
		else if (input1 == "kill" && input2 == name) { 
			this->killcat();
			return false;  // return false
		}
		
		this->iterateHunger(true);  // iterate the cat's hunger variables on every loop (iterate = true)
		this->iterateComfort(true);  // iterate cat's comfort variables (iterate = true)
		
		return true;
	}
	
	// CAT SAVE/LOAD FUNCTIONS
	
	// 'save' function writes the appropriate data to a save file under the cat's name for later use
	bool save() {
		ofstream fout;  // stream variable used to open the correct file
		time_t current_time(time(0));  // used to save the time the game was ended
		
		fout.open((name + ".txt"), ios::ate);  // '.txt' is added to the end of the file name to place it in the correct format
		
		if (!fout.is_open()) {  // if the file does not open, returns ERROR statement
			cout << endl << "ERROR: Something is wrong with the save file." << endl;
			return false;  // return false
		}
		
		// if file does open:
		fout << name << " ";  // ouput the 'name' of the cat to the file
		fout << hunger_count << " ";  // ouput the hunger integer value of the cat
		fout << comfort_count << " ";  // output the comfort integer value of the cat
		fout << current_time << " ";  // output to the file the time the game period was ended
		fout << color_num << " ";
		
		fout.close();  // close the cat text file
		
		return true;  // return true
	}

	// 'load' function reads cat variable data into the appropriate places for use by the code
	bool load() {
		ifstream fin;  // stream variable used to open and read file
		time_t last_play_time;
		
		fin.open((name + ".txt"));  // opens the file of the given cat name with ".txt" placed on the end
		
		// if there is no file for the named cat, one is made
		if (!fin.is_open()) {
			cout << "There is no load file on record for that cat name." << endl;
			cout << "Your cat is being born now..." << endl;
			
			image_num = 4;  // cat image set to the new cat
			
			cout << endl;
			this->display_feline();  // displays the new cat
			cout << endl;
			
			// sets hunger and comfort variables
			hunger_count = 0; 
			this->iterateHunger(false);
			comfort_count = 0;
			this->iterateComfort(false);
			
			return false;  // return false
		}
		// otherwise the variable data for the cat is read in and applied appropriately
		else { 
			fin >> name >> hunger_count >> comfort_count >> last_play_time >> color_num;
			this->time_huncomf(last_play_time);  // iterate based on time gone from simulation
		}
		
		fin.close();  // the file is closed
		
		// updates the hunger and comfort functions
		this->iterateHunger(false);
		this->iterateComfort(false);
		
		return true;  // return true
	}
};



























