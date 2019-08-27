// File: fallMoon.cpp
// Created by: Michael Napoli
// Created on: 5/14/19

/* Program that computes the total travelled distance of an
	object dropped on the moon. As well as the final velocity
	of the object once it reaches the ground. */

#include <iostream>
using namespace std;

int main()
{
	double fallTime;
	double vel;
	double distance;

	// User input for time falling.
	cout << "Enter the time: ";
	cin >> fallTime;
	cout << endl;

	// Calculation of final velocity.
	vel = fallTime * 1.6;

	cout << "After " << fallTime << " seconds, the velocity on the moon is "
		<< vel << " meters per second." << endl;

	// Calculation of total distance.
	distance = (1.0 / 2.0) * vel * fallTime * fallTime;

	cout << "After " << fallTime << " seconds, the falling distance on the moon is "
	     << distance << " meters." << endl;

	return 0;
}
