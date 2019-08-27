// File: position.cpp
// Created by: Michael Napoli
// Created on: 5/29/2019
// Last modified on: 6/3/2019

/* Program that evaluates two x and y coordiantes and tells
	the user the directional placement of those coordinates with 
	respect to one another. */

#include <iostream>
#include <string>
using namespace std;

int main()
{
	double x1, y1;
	double x2, y2;
	string leftRight;
	string aboveBelow;

	cout << "Enter coordinates of the first point (2 values): ";
	cin >> x1 >> y1;
	cout << "Enter coordinates of the second point (2 values): ";
	cin >> x2 >> y2;

	/* if else statement that tells whether the first point is to the right 
		or left of the second point. */
	if ((x1 - x2) > 0)
	{
		leftRight = "right";
	}
	else
	{
		leftRight = "left";
	}

	/* if else statement that tells whether the first point is above or below 
		the second point. */
	if ((y1 - y2) > 0)
	{
		aboveBelow = "above";
	}
	else
	{
		aboveBelow = "below";
	}

	// Final output statement.
	cout << "Point (" << x1 << "," << y1 << ") is " << leftRight << " and "
		<< aboveBelow << " point (" << x2 << "," << y2 << ")." << endl;

	return 0;
}