/*
  File: freq.cpp
  Created by: Michael Napoli
  Creation Date: 7/19/19
  Synopsis: Program that takes an input statement from the user and calculates:
  -how many of each specific vowel are inside
  -how many consonants are inside
  and then outputs these items back tothe user
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

// FUNCTION PROTOTYPES GO HERE:

// FUNCTION PROTOTYPE: init_vectors()
void init_vectors(vector<char> & vowels, vector<int> & frequencies);

// FUNCTION PROTOTYPE: read_text()
string read_text(const string & prompt);

// FUNCTION PROTOTYPE: is_alphabetic()
bool is_alphabetic(const char character);

// FUNCTION PROTOTYPE: create_list()
void create_list(const string & str_text, vector<char> & vec_text);

// FUNCTION PROTOTYPE: is_member()
bool is_member(const vector<char> & list, char character);

// FUNCTION PROTOTYPE: find_index()
int find_index(const vector<char> & list, char character);

// FUNCTION PROTOTYPE: compute_vowel_freqs()
int compute_vowel_freqs(const vector<char> & text, const vector<char> & vowels, vector<int> & freqs);

// FUNCTION PROTOTYPE: display_characters()
void display_characters(const vector<char> & characters, const int colwidth);

// FUNCTION PROTOTYPE: display_freqs()
void display_freqs(const vector<int> & freqs, const int colwidth);

int main()
{
	// Define local variables and constants
	vector<char> vowels;
	vector<int> freqs;
	string input;
	vector<char> text;
	int consonants(0);
	
	const int COLUMNWIDTH = 2;

	// Initialize the list of vowels and vowel frequencies.
	// Call function init_vectors with variables vowels and freqs
	init_vectors(vowels, freqs);
	
	// Prompt the user for the input text by calling function read_text	
	input = read_text("Enter your text: ");
	
	// Copy the characters (ignoring non-alphabetic characters) in the input string to the vector of characters in variable text
	// Call function create_list to do this
	create_list(input, text);
	
	// Compute the frequencies of vowels and consonants from the input text containing only alphabetic letters
	// Call function compute_vowel_freqs to do this
	consonants = compute_vowel_freqs(text, vowels, freqs);
	
	// Display the vowels and their frequencies
	// Call functions display_characters and display_freqs
	display_characters(vowels, COLUMNWIDTH);
	display_freqs(freqs, COLUMNWIDTH);

	// Display the number of consonants. No function calls here.
	cout << "There are " << consonants << " consonants." << endl;
  
  return 0;
}
		 
// FUNCTION DEFINITIONS GO HERE:

// FUNCTION DEFINITION: init_vectors()
// function that intializes two vectors:
// vector 'vowels' with the six phonetic vowels in alphabtical order
// and vector 'frequencies' with six 0's that are subject to change
void init_vectors(vector<char>& vowels, vector<int>& frequencies)
{
	const int vowel_num = 6;  // constant variable for number of vowels

	// loop that iterates for each vowel and places the number '0' into the frequency vector
	for (int i(0); i < vowel_num; ++i) {
		frequencies.push_back(0);
	}

	// push back vector limits to make room for each vowel
	vowels.push_back('a');
	vowels.push_back('e');
	vowels.push_back('i');
	vowels.push_back('o');
	vowels.push_back('u');
	vowels.push_back('y');

	return;  // return nothing
}

// FUNCTION DEFINITION: read_text()
// function that takes user input and ouputs it back to the main code
// 'prompt' - allows the main program to input the necessary prompt for the user
string read_text(const string& prompt)
{
	string userInput;  // variable that temporarily holds the user input sentence

	cout << prompt;  // output main program prompt
	getline(cin, userInput);  // assign user input to necessary variable

	return userInput;  // return the user's sentence
}

// FUNCTION DEFINITION: is_alphabetic()
// helper function that tells the function 'create_list()' whether or not an inputted character is a letter
// 'character' - character from program that is to be evaluated
bool is_alphabetic(const char character)
{
	// if input is lower or upper character
	if (isupper(character) || islower(character)) { return true; }  // return true
	else { return false; }  // otherwise, return false
}

// FUNCTION DEFINITION: create_list()
// function that utilizes helper function 'is_alphabetic()' to create a list of lower case letters from the main program
// 'str_text' - text inputted by the user in its original form
// 'vec_text' - empty vector that will contain the lower case letters from teh original vector
void create_list(const string& str_text, vector<char>& vec_text)
{
	// for all elements of the original sentence vector
	for (int i(0); i < str_text.length(); ++i) {
		if (is_alphabetic(str_text[i])) {  // if element is alphabetical
		  vec_text.push_back(tolower(str_text[i]));  // assign it to the vector in its lower case form
		}
	}

	return;  // return nothing
}

// FUNCTION DEFINITION: is_member()
// helper function to 'compute_vowel_freqs()'
// tells the program whether or not a character is within a list or not
// 'list' - the list that will be searched through
// 'character' - the character that will be evaluated
bool is_member(const vector<char>& list, char character)
{
	// for all elements in the 'list; vector
	for (int i(0); i < list.size(); ++i) {
		if (list[i] == character) {  // if the character being evaluated is found
			return true;  // return true
		}
	}

	return false;  // if loop finds no character that is the same, return false
}

// FUNCTION DEFINITION: find_index()
// helper function to 'compute_vowel_freqs()'
// searches through a given loop for a single character
// returns the index of said character once it is found
// 'list' - the list that will be searched through
// 'character' - the character that will be evaluated
int find_index(const vector<char>& list, char character)
{
	// for all elements within a loop
	for (int i(0); i < list.size(); ++i) {
		if (list[i] == character) {  // if the current index 'i' contains the character
			return i;  // return the index
		}
	}

	return -1;  // if character is not found, return -1 (this would result in an error)
}

// FUNCTION DEFINITION: compute_vowel_freqs()
// function that utilizes two helper functions to find the number of vowels and consonants in a given vector
// 'text' - original text given by main program
// 'vowels' - vector containing vowels
// 'freqs' - vector containing vowel frequencies
int compute_vowel_freqs(const vector<char>& text, const vector<char>& vowels, vector<int>& freqs)
{
	int cons(0);  // counter for consonants
	int vow_index(-1);  // vowel index (initialized at -1 to evluate for error in loop)

	// for all elements in the given 'text' vector
	for (int i(0); i < text.size(); ++i) {
		if (is_member(vowels, text[i])) {  // if charcater is a vowel 
			vow_index = find_index(vowels, text[i]);  // find vowel index
			++freqs[vow_index];  // increment index by one
		}
		else { ++cons; }  // otherwise, increment consonants by one
	}

	return cons;  // return consonant count
}

// FUNCTION DEFINITION: display_characters()
// function that displays the characters in a given vector
// 'characters' - vector to be displayed
// 'colwidth' - width of the collumn given
void display_characters(const vector<char>& characters, const int colwidth)
{
	// for all elements in the given vector
	for (int i(0); i < characters.size(); ++i) {
		cout << setw(colwidth + 2) << characters[i];  // output in the proper format
		if (i < characters.size() - 1) { cout << ","; }
	}
	cout << endl;  // end with a new line

	return;  // return nothing
}

// FUNCTION DEFINITION: display_freqs()
// function that displays the integers in a given vector
// 'characters' - vector to be displayed
// 'colwidth' - width of the collumn given
void display_freqs(const vector<int>& freqs, const int colwidth)
{
	// for all elements in the given vector
	for (int i(0); i < freqs.size(); ++i) {
		cout << setw(colwidth + 2) << freqs[i];  // output in the proper format
		if (i < freqs.size() - 1) { cout << ","; }
	}
	cout << endl;  // end with a new line

	return;  // return nothing
}
