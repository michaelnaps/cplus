// File: heart.cpp
// Created on: 7/11/19
// Last modified on: 7/12/19

// Created by: Michael Napoli
// Created for: Christie Bradley

/* Program that prints a heart with user-inputted maximum radius. */

#include <iostream>
using namespace std;

// FUNCTION PROTOTYPE: print_line()
void print_line(const int begin, const int middle, const int end);

int main()
{
	int heart_radius(0);  // maximum radius of the heart
	int heart_height(0);  // height of the top half of the heart
	
   // while loop that iterates until user enters 0 for 'heart_radius'
   do {
      // output and input statements
      cout << "Enter the maximum radius (>= 5): ";
      cin >> heart_radius; 
      cout << endl;

      // 'heart_height' is one-fifth the radius of the height
      heart_height = heart_radius / 5;

      // for all lines above the first solid line
      for (int i(heart_height); i > 0; --i) {
         print_line(i, heart_radius - i * 2, i);  // first half of line
         print_line(i, heart_radius - i * 2, i);  // second half of line
         cout << endl;
      }

      // for all lines after and including the first solid line
      for (int i(0); i < heart_radius; ++i) {
         // print line with width that is appropriate for that portion of heart
         print_line(i, (2 * heart_radius - 2 * i), 0);
         cout << endl;
      }
      cout << endl;
   } while (heart_radius != 0);

	return 0;
}

// FUNCTION PROTOTYPE: 
// function takes three inputs to build a single line
// 'begin' - beginning of the line, is made up of spaces
// 'middle' - middle of the line, is made up of astrisks
// 'end' - end of the line, is made up of spaces
void print_line(const int begin, const int middle, const int end)
{
	// all for loops print the number of astrisks/spaces inputted by the program
	for (int i(0); i < begin; ++i) {
		cout << " ";
	}

	for (int i(0); i < middle; ++i) {
		cout << "*";
	}

	for (int i(0); i < end; ++i) {
		cout << " ";
	}

	return;  // return nothing
}