// File: sin.cpp
// Created by: Naeem Shareef
// Modified by: Michael Napoli
// Modified on: 5/14/19

/* A program to read in an angle x in radians and
   compute sin(x) and sin(x) + sin(x)*sin(x) 
   and the square root of (1+sin(x))
   and output the solutions on separate lines.
*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double x;
	double y;
	const long double pi = 3.1415926535897932384626433832795; // added for accurate usage of the constant pi
	
	/* Read in angle in radians */
	cout << "Enter angle (radians): ";
	cin >> x;
	
	/* Compute sin(x) */
	y = sin(x);

	cout << "sin(x) = " << y << endl;
	cout << "sin(x) + sin(x)*sin(x) = " 
		<< y + y*y << endl;
	cout << "The square root of (1+sin(x)) = " << sqrt(1+y) 
		<< endl;
	
	return 0;
}
