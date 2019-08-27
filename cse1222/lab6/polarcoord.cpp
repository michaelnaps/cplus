/*
  File: polarcoord.cpp
  Created by: Michael Napoli
  Creation Date: 6/20/2019
  Last modified on: 6/22/2019
*/

/* Program that converts polar coordinates and a polar
	angle to cartesian coordinates. */

#include <iostream>
#include <cmath>

using namespace std;

// FUNCTION PROTOTYPE FOR degrees2radians
double degrees2radians(double deg_angle);	

// FUNCTION PROTOTYPE FOR compute_coord
void compute_coord(double radius, double rad_angle, double& x, double& y);	

// DO NOT MODIFY THE MAIN ROUTINE IN ANY WAY
int main()
{
	double angle_degrees(0.0), angle_radians(0.0), radius(0.0);
	double coord_x(0.0), coord_y(0.0);

	// Read in polar coordinates
	cout << "Enter radius: ";
	cin >> radius;

	cout << "Enter polar angle (degrees): ";
	cin >> angle_degrees;

	// Convert degrees to radians
	angle_radians = degrees2radians(angle_degrees);

	// Compute Cartesian (x,y) coordinates
	compute_coord(radius, angle_radians, coord_x, coord_y);

	// Output Cartesian coordinates
	cout << "Cartesian coordinates: ";
	cout << "(" << coord_x << "," << coord_y << ")" << endl;

	return 0;
}

// DEFINE FUNCTION degrees2radians here:
// function that takes the variable angle in degrees and converts it into radians
double degrees2radians(double deg_angle)
{
	return deg_angle * (M_PI / 180.0);	// output to main program the input degrees converted to radians
}

// DEFINE FUNCTION compute_coord here:
// function that inputs two variables:
// 'radius' - radius of the circle's arc
// 'rad_angle' - angle of arc in radians
// and outputs the following two variables:
// 'x' and 'y' - coordinates for calculated end of the arc
void compute_coord(double radius, double rad_angle, double& x, double& y)
{
	x = radius * cos(rad_angle);	// change the 'coord_x' input value to its respective cartesian coordinate
	y = radius * sin(rad_angle);	// change the 'coord_y' input value to its respective cartesian coordinate

	return;
}
