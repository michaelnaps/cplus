/*
  File: replace.cpp
  Created by: Michael Napoli
  Creation Date: 7/19/19
  Synopsis: Program that asks the user for:
    -an intial string statement
    -a letter they want to replace
    -what character they would like to replace it with
  and utilizes user-made functions to:
    -replace the appropriate letter within a string
    -copy the string to a vector
    -output the vector
*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function prototypes
void replace(string & phrase, const string & letter, const string & replacement, vector<char> & text);
void display_phrase(const vector<char> & text);
 
int main()
{
  string phrase, letter, replacement;
  vector<char> text_vec;

  cout << "Enter phrase: ";
  getline(cin, phrase);

  if (phrase.length() > 0)
  {
	cout << "Enter letter to replace: ";
	getline(cin, letter);

	if (letter.length() == 1)
	{
		cout << "Enter replacement letter: ";
		getline(cin, replacement);
  
		if (replacement.length() == 1)
		{
			replace(phrase, letter, replacement, text_vec);
			cout << "String phrase: " << phrase << endl;
			cout << "Vector phrase: ";
			display_phrase(text_vec);
			cout << endl;
		}
		else
		{
			cout << "Replacement letter must be a single letter" << endl;
		}
	}
	else
	{
		cout << "Letter to replace must be a single letter" << endl;
	}
  }
  
  return 0;
}

// FUNCTION 
void replace(string & phrase, const string & letter, const string & replacement, vector<char> & text)
{
	// Insert your code here
  for (int i(0); i < phrase.length(); ++i) {  // for all elements of a given string
    if (phrase[i] == letter[0]) {  // if string elements is equal to the letter wanting to be replaced
      phrase.replace(i, 1, replacement);  // replace the element with the replacement character
    }
  }

  // for all elements of a given string
  for (int i(0); i < phrase.length(); ++i) {
    text.push_back(phrase[i]);  // copy string to the vector (making new memory for each element
  }
  cout << endl;  // end line (to format with solution given for quiz)

  return;  // return nothing
}

void display_phrase(const vector<char> & text)
{
	// Insert your code here
  // for vector given from main program
  for (int i(0); i < text.size(); ++i) {
    cout << text[i];  // output all elements
  }

  return;  // return nothing

}
