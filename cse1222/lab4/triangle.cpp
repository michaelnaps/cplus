// File: triangle.cpp
// Created by: Michael Napoli
// Created on: 6/5/2019
// Last modifed on: 

/* Program that takes a user input and creates a right triangle
	using digits between 1 and 9. Once the collumn number reaches
	10, the program sets the collumn number value to zero so
	that each collumn is only one digit. */

#include <iostream>
using namespace std;

int main()
{
	int userInput;		// user inputted 
	int i(1);			// while loop integer. Used only for loop maintaining
	int collumn(1);		// number of digits in a collumn (maximum equal to user Input)
	int row(1);			// number of rows (equal to userInput)

	cout << "Enter number of rows: ";
	cin >> userInput;

	while (row <= userInput)	// execute while the row value is less then the userInput
	{
		while (i <= row)		// execute while the loop counter is less then the current row number
		{
			if (collumn == 10)	// collumn is set to 0 when it is ten and starts counting up from there
			{
				collumn = 0;
			}
			cout << collumn;
			++collumn;
			++i;
		}
		cout << endl;
		collumn = 1;			// reset collumn number back to 1
		i = 1;					// reset while loop counter back to 1
		++row;
	}

	return 0;
}