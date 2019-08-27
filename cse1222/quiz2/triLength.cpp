// File: triLength.cpp
// Created by: Michael Napoli
// Created on: 5/24/2019
/* Synopsis: The following program reads in two side lengths from the user
   along with an angle value to comput the side length of the last remaining
   side length. */

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  double sideA;       // value of side A
  double sideAsqr;    // value of side A sqaured
  double sideB;       // value of side B
  double sideBsqr;    // value of side B squared
  double sideC;       // value of side C
  double userDegrees; // degrees of angle between sides A and B
  double userRad;     // angle between sides A and B in radians

  cout << "Enter length of side A: ";
  cin >> sideA;

  cout << "Enter length of side B: ";
  cin >> sideB;

  cout << "Enter angle between sides A and B (degrees): ";
  cin >> userDegrees;

  // Calculate the degrees in radians
  userRad = userDegrees * (M_PI / 180.0);

  // Convert sides into themselves raised to the power of two.
  sideAsqr = sideA * sideA;
  sideBsqr = sideB * sideB;

  // Calculate the length of sideC
  sideC = sqrt(sideAsqr + sideBsqr - (2 * sideA * sideB * cos(userRad)));

  cout << "Length of side C is " << sideC << "." << endl;

  return 0;
}
