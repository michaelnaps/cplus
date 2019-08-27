// File: circles.cpp
// Created by: Michael Napoli
// Created on: 5/29/2019
// Last modified on: 

/* Program that reads in the center coordinate and radii
	of three circles, A, B, and C, and a query point. It
	then uses these values to calculate the circles 
	which the point lies within. */

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double xA, yA, radA;		// coordinates and radius of circle A.
	double xB, yB, radB;		// coordinates and radius of circle B.
	double xC, yC, radC;		// coordinates and radius of circle C.
	double xPoint, yPoint;		// coordinates of query point.
	double distance;			// distance of circles center point from query point.
	char circle1;				// character variable for A, B, and C values.
	char circle2 = 'D';			// character variable for A, B, and C values. Starts as 'D' so it can be evaluated.
	int count = 0;				// count of how many circles contain the query point.

	// Read in values for the three circle's midpoint, radius, and a single query point
	cout << "Enter x and y coordinate of circle A (2 values): ";
	cin >> xA;
	cin >> yA;

	cout << "Enter radius of circle A: ";
	cin >> radA;

	cout << "Enter x and y coordinate of circle B (2 values): ";
	cin >> xB;
	cin >> yB;

	cout << "Enter radius of circle B: ";
	cin >> radB;

	cout << "Enter x and y coordinate of circle C (2 values): ";
	cin >> xC;
	cin >> yC;

	cout << "Enter radius of circle C: ";
	cin >> radC;

	cout << "Enter x and y coordinate of query point (2 values): ";
	cin >> xPoint;
	cin >> yPoint;

	// Calculate query points distance from circle C
	distance = sqrt(pow((xPoint - xC), 2.) + pow((yPoint - yC), 2.0));
	
	if (distance <= radC)
	{
		circle1 = 'C';
		circle2 = 'C';
		++count;				// count keeps track of how many circles contain query point
	}
	
	// Calculate distance from circle B
	distance = sqrt(pow((xPoint - xB), 2.) + pow((yPoint - yB), 2.0));

	if (distance <= radB)
	{
		circle1 = 'B';
		if (circle2 != 'C')		// if statement that stops the program from overwriting all
		{						//	potential variables that contain 'C'
			circle2 = 'B';
		}
		++count;
	}

	// Calculate distance from circle A
	distance = sqrt(pow((xPoint - xA), 2.) + pow((yPoint - yA), 2.0));

	if (distance <= radA)
	{
		circle1 = 'A';
		++count;
	}

	/* Output the circles that contain the query point using if statements that evaluate
		the count variable. */
	if (count == 1)			// when one circle contains the point
	{
		cout << "Circle " << circle1 << " contains point (" << xPoint
			<< "," << yPoint << ")." << endl;
	}
	else if (count == 2)	// when two circles contain the point
	{
		cout << "Circles " << circle1 << " and " << circle2 << " contain point ("
			<< xPoint << "," << yPoint << ")." << endl;
	}
	else if (count == 3)	// when all circles contain the point
	{
		cout << "Circles A, B, and C contain point (" << xPoint << "," << yPoint
			<< ")." << endl;
	}
	else					// when no circle contains the point
	{
		cout << "No circle contains point (" << xPoint << ","
			<< yPoint << ")." << endl;
	}

	return 0;
}