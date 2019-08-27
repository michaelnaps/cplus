/*
  File: degrees2radians.cpp
  Created by: Michael Napoli
  Creation Date: 6/21/2019
  Synopsis: Program that uses two user inputs of radius length and the
  angle in degrees to output the arc length.
*/

#include <iostream>
#include <cmath>

using namespace std;

// FUNCTION PROTOTYPE FOR degrees2radians
double degrees2radians(double angle_deg);

// FUNCTION PROTOTYPE FOR compute_arc_length
double compute_arc_length(double radius, double angle_rad);


int main()
{
  // Declare and initialize your variables
  double radius, angle_degrees(0.0), angle_radians(0.0), arc_length;

  // Read in polar coordinates
  cout << "Enter radius: ";
  cin >> radius;

  cout << "Enter polar angle (degrees): ";
  cin >> angle_degrees;

  // Convert degrees to radians
  angle_radians = degrees2radians(angle_degrees);

  // Compute arc length
  arc_length = compute_arc_length(radius, angle_radians);

  // Output arc length
  cout << "The arc length is " << arc_length << endl;

  return 0;
}

// DEFINE FUNCTION degrees2radians here:
// function that converts an angle given in degrees to radians
// 'angle_deg' variable is the inputted angle in degrees
double degrees2radians(double angle_deg)
{
  return angle_deg * (M_PI / 180.0);   // return the angle converted from degrees to radians
}

// DEFINE FUNCTION compute_arc_length here:
// function that computes the arc length of the portion of a circle given:
// 'radius' which is the radius of the circle
//  'angle_rad' which is the angle in radians
double compute_arc_length(double radius, double angle_rad)
{
  return radius * angle_rad;   // return to the main program window the arc length
}

