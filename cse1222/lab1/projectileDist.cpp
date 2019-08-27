// File: projectileDist.cpp
// Created by: Michael Napoli
// Created on: 5/14/19

/* Program that computes the total horizontal distance
	travelled by an object shot at a 45 degree angle on 
	Earth. */

#include <iostream>
using namespace std;

int main()
{
	double vel;
	double distance;

	// User input of initial velocity.
	cout << "Enter the initial velocity (meter/second): ";
	cin >> vel;

	// Calculation of horizontal distance travelled.
	distance = (vel * vel) / 9.81;

	cout << "Horizontal distance travelled is "
		<< distance << " meters." << endl;
	
	return 0;
}
