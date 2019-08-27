// File: trapezoid.cpp
// Created by: Michael Napoli
// Created on: 6/16/2019
// Last modified on: 6/17/2019

/* Program that takes a user input for starting row count and 
	the number of rows and prints an inverted trapezoid. */

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	// Declare and initialize variables
	int ntop(0), nbottom(0);	// Top row size and bottom row size
	int nrows(0);	// Total number of rows
	

	// Repeatedly prompt for top row size until valid value is entered
	while (ntop < 2)	// loop does not exit until 'ntop' is larger then 2
	{
		cout << "Enter size of top: ";
		cin >> ntop;

		if (ntop < 2)
		{
			cout << "Size of top row must be at least 2." << endl;
		}
	}

	// Prompt for total number of rows
	// Repeatedly prompt for total number of rows until valid value is entered
	while (nbottom <= 1)
	{
		cout << "Enter number of rows: ";
		cin >> nrows;

		// Compute bottom row size
		nbottom = ntop - ((nrows - 1) * 2);

		if (nbottom <= 1)
		{
			cout << "Invalid number of rows." << endl;
		}
	}

	// Print the inverted trapezoid
	for (int i(0); i < nrows; ++i)	// for loop repeats all the way up to, but not including, 'nrows'
	{
		for (int k(1); k <= i; ++k)		// for loop repeats up to but not including current row number 'i'
		{
			cout << " ";	// prints necessary spaces
		}
		for (int k(1); k <= (ntop - (2 * i)); ++k)	// loop iterates until k is equal to the 'ntop' value minus 2 times the row number 'i'
		{
			cout << "@";	// prints necessary "@" symbols
		}

		// no spaces after final "@" needed for any row

		cout << endl;
	}
	cout << endl;

	// end program
	return 0;
}