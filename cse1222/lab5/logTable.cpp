// File: logTable.cpp
// Created by: Michael Napoli
// Created on: 6/13/2019
// Last modified on:

/* Program that reads in a starting base value a, a starting 
	value b, a row and column number. Then computes the log of
	combinations and places the values in a neatly spaced
	table. */

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	int a(0), b(0);		// user inputted starting values for base and integer
	int rowNum(0);	// user inputted number of rows
	int collumnNum(0);	// user inputted number of collumns
	int sigFig(0);		// user inputted amound of significant decimals shown
	int space1(6);	// amount of space used for table
	int space2(2);	// amount of space used for table
	int space3(2);	// amount of space used for table


	// Recieve input from users for appropraite variables
	cout << "Enter start value for base a: ";
	cin >> a;

	cout << "Enter how many base values: ";
	cin >> rowNum;

	cout << "Enter start value b: ";
	cin >> b;

	cout << "Enter how many b values: ";
	cin >> collumnNum;

	cout << "Enter precision: ";
	cin >> sigFig;

	cout.precision(sigFig);		// change fixed precision of all table values to user input variable 'sigFig'
	space1 = space1 + sigFig;	// give variable 'space1' (used to space calculation entries) 7 + user inputted 'sigFig' value

	cout << endl;

	cout << "Table starts at logarithm of b = " << b << " with base a = " << a << endl;

	cout << setw(10) << "Log Values";	// "Log Value" has width of 10, sets width for whole collumn

	for (int i(0); i < collumnNum; ++i)	// Prints table first row (heading)
	{
		if (i > 9)		// if increment integer is about 10, changes 'space2' (used to space the header) the value of 3
		{ space2 = 3; }

		cout << setw(space1 - space2) << "b +" << setw(space2) << i;
	}
	cout << endl;

	for (double i(0); i < rowNum; ++i)		// constructs the individual table rows
	{
		if (i > 9)		// if increment integer is about 9, changes 'space3' (used to space the collumn titles) the value of 3
		{ space3 = 3; }

		cout << setw(10 - space3) << "a +" << setw(space3) << i;

		cout.setf(ios::fixed);		// changes displayed decimal digits to user inputted amount
		for (double n(0); n < collumnNum; n++)		// constructs the row's calculated values, spaced correctly
		{
			cout << setw(space1) << (log10(b + n) / log10(a + i));
		}
		cout.unsetf(ios::fixed);	// unsets the user inputted digit amount

		cout << endl;
	}

	// exit program
	return 0;
}