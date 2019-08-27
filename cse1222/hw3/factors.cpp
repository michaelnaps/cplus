// File: factors.cpp
// Created by: Michael Napoli
// Created on: 6/16/2019
// Last modified on: 6/17/2019

/* Program that takes a user inputted integer and finds all  
   factors of all numbers leading up to the user input. */

#include <iostream>
using namespace std;

int main()
{
	int finalNum(0);	// number inputted by user (counted to)
	int com(0);		// used to tell program to input comma if necessary

	while (finalNum <= 0)	// loop that asks user to enter number until their input is positive
	{
		cout << "Enter integer: ";
		cin >> finalNum;

		if (finalNum <= 0)
		{
			cout << "Enter a positive number." << endl;
		}
	}

	cout << endl <<  "Factors of all numbers up to " << finalNum << endl;

	// print all factors leading up to, and including, 'finalNum'
	for (int i(1); i <= finalNum; ++i)	// 'i' variable counts to, and includes, 'finalNum'
	{
		cout << i << ":";		// displays the value of the current number being evaluated
		for (int n(1); n <= i; ++n)		// for loop that finds all factors of the input 'i'
		{
			if (com == 1)	// if there is a number before the current number, it will seperate them by a comma
			{
				cout << ",";
			}

			com = 0;

			if (i % n == 0)		// if statement that tells whether or not 'n' is a factor of 'i'
			{
				cout << " " << n;
				com = 1;
			}
		}
		cout << endl;	// next line
		com = 0;
	}

	// exit program
	return 0;
}
