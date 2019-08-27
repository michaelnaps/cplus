// File: areaCalculator.cpp
// Created by: Michael Napoli
// Created on: 6/1/2019

/* Program that evaluates the shape of an object and
	calculates the area. */

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main()
{
	string shape;
	double side1, side2;
	double area = 0;
	const long double pi = 3.1415926535897932384626433832795;
	
		cout << "What shape are you evaluating? The options include: " << endl;
		cout << " Circle\n Rectangle\n Square\n Right Triangle\n Cylinder" << endl;
	while (area == 0)
	{
		cout << "Enter the shape: ";
		getline(cin, shape);

		if (shape == "circle" || shape == "Circle")
		{
			cout << "Enter the radius: ";
			cin >> side1;

			area = pi * pow(side1, 2.0);
		}
		else if (shape == "rectangle" || shape == "Rectangle")
		{
			cout << "Enter the length and width (two values): ";
			cin >> side1;
			cin >> side2;

			if (side1 == side2)
			{
				cout << "This is a square." << endl;
			}

			area = side1 * side2;
		}
		else if (shape == "square" || shape == "Square")
		{
			cout << "Enter the length of a side: ";
			cin >> side1;

			area = pow(side1, 2.0);
		}
		else if (shape == "right triangle" || shape == "Right Triangle")
		{
			cout << "Enter the base length and height: ";
			cin >> side1;
			cin >> side2;

			area = (1.0 / 2.0) * side1 * side2;
		}
		else if (shape == "cylinder" || shape == "Cylinder")
		{
			cout << "Enter the radius of the base and the height: ";
			cin >> side1;
			cin >> side2;

			area = pi * pow(side1, 2.0) * side2;
		}
		else
		{
			cout << endl << shape << " is not recognized." << endl;
			cout << "Please enter an acceptable shape." << endl;
		}

		if (area != 0)
		{
			cout << "The area is " << area << " units." << endl;
		}
	}

	return 0;
}