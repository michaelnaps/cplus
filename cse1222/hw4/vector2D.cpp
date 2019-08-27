/*
  File: vector2D.cpp
  Created by: Michael Napoli
  Creation Date: 7/2/2019
  Synopsis: Program that utilizes functions outside the main program to:
		-read user inputs for two vectors and a scalar
		-write to the command window
		-calculate vector length
		-add and subtract vectors
		-multiply vectors by a scalar
		-create unit vectors
		-evaluate whether or not vectors are perpendicular
*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const double EPSILON(1e-12);

// function prototypes

// ENTER FUNCTION PROTOTYPE FOR read_vector HERE.
void read_vector(const string& prompt, double& x, double& y);

// ENTER FUNCTION PROTOTYPE FOR vector_length HERE.
double vector_length(double x, double y);

// ENTER FUNCTION PROTOTYPE FOR write_vector HERE.
void write_vector(const string prompt, double x, double y);

// ENTER FUNCTION PROTOTYPE FOR vector_add HERE.
void vector_add(double x1, double y1, double x2, double y2, double& x3, double& y3);

// ENTER FUNCTION PROTOTYPE FOR vector_subtract HERE.
void vector_subtract(double x1, double y1, double x2, double y2, double& x3, double& y3);

// ENTER FUNCTION PROTOTYPE FOR scalar_mult HERE.
void scalar_mult(double x1, double y1, double mult, double& x2, double& y2);

// ENTER FUNCTION PROTOTYPE FOR normalize HERE.
void normalize(double& x, double& y);

// ENTER FUNCTION PROTOTYPE FOR perpendicular HERE.
void perpendicular(double x1, double y1, double x2, double y2);

// *** DO NOT CHANGE ANY CODE IN THE MAIN FUNCTION.
int main()
{
  double u1, v1;	// coordinates of first vector
  double u2, v2;	// coordinates of second vector
  double u3, v3;
  double scalar;

  read_vector("Enter first vector (2 floats): ", u1, v1);
  read_vector("Enter second vector (2 floats): ", u2, v2);
  
  cout << "Enter scalar multiplier: ";
  cin >> scalar;
  cout << endl;

  write_vector("First vector: ", u1, v1);
  write_vector("Second vector: ", u2, v2);

  cout << endl;
  
  vector_add(u1, v1, u2, v2, u3, v3);
  write_vector("Vector add: ", u3, v3);

  vector_subtract(u1, v1, u2, v2, u3, v3);
  write_vector("Vector subtract: ", u3, v3);

  scalar_mult(u1, v1, scalar, u3, v3);
  write_vector("Scalar multiplier: ", u3, v3);

  cout << endl;
  
  write_vector("First vector: ", u1, v1);
  write_vector("Second vector: ", u2, v2);
  perpendicular(u1, v1, u2, v2);
  
  return(0);
}

// DEFINE FUNCTION read_vector HERE.
// outputs a main program imputted prompt to the screen which takes
// the input of two variables 'x' and 'y'
// 'x' is a pass by reference variable
// 'y' is a pass by reference variable
// 'prompt' is pass by reference but made constant so it cannot be changed
void read_vector(const string& prompt, double& x, double& y)
{
	cout << prompt;  // output the prompt entered in the main program
	cin >> x >> y;  // take two inputs from the user and output them both to the main

	return;  // return nothing, output to screen, changes made via pass by reference
}

// DEFINE FUNCTION vector_length HERE.
// uses pythagorean theorem to calculate the distance between the
// start and endpoints of a given vector
// 'x' is a pass by value variable
// 'y' is a pass by value variable
double vector_length(double x, double y)
{
	return sqrt(pow(x, 2) + pow(y, 2));  // return the length of the given vector
}

// DEFINE FUNCTION write_vector HERE.
// writes the given prompt by the main program along with the
// dimentions of the vector and the length, or magnitude
// 'prompt' is a string given by program and is passed by value
// 'x' is the x coordinate of the endpoint of the vector
// 'y' is the y coordinate of the endpoint of the vector
void write_vector(const string prompt, double x, double y)
{
	cout << prompt << "(" << x << "," << y << ")"
		<< " has length ";
	cout << vector_length(x, y) << endl;  // use function 'vector_length' to output the length of the displayed vector

	return;  // return nothing, only output to screen
}

// DEFINE FUNCTION vector_add HERE.
// function that adds the x and y componenents of a vector and outputs them
// to two variables that are pass by reference
// 'x1' and 'y1' are x-y coordinates for first vector
// 'x2' and 'y2' are x-y coordinates for second vector
// 'x3' and 'y3' are the resulting coordinates for the addition of the vectors
void vector_add(double x1, double y1, double x2, double y2, double& x3, double& y3)
{
	// add vectors x and y values together
	x3 = x1 + x2;
	y3 = y1 + y2;

	return;  // return nothing, changes made via pass by reference
}

// DEFINE FUNCTION vector_subtract HERE.
// similar to the 'vector_add' function but instead substracts
// 'x1' and 'y1' are x-y coordinates for first vector
// 'x2' and 'y2' are x-y coordinates for second vector
// 'x3' and 'y3' are the resulting coordinates for the subtraction of the vectors
void vector_subtract(double x1, double y1, double x2, double y2, double& x3, double& y3)
{
	// subtract respective x-y coordinates
	x3 = x1 - x2;
	y3 = y1 - y2;

	return;  // return nothing, changes made via pass by reference
}

// DEFINE FUNCTION scalar_mult HERE.
// function that inputs a single vector, a scalar, and two 'empty'
// x-y coordinates to be passed by reference
// 'x1' and 'y1' are the initial input x-y coordinates
// 'mult' is the scalar given by the main program
// 'x2' and 'y2' are passed by reference and are the components of the multiplied initial vector
void scalar_mult(double x1, double y1, double mult, double& x2, double& y2)
{
	// multiply the vector components by the scalar respectively
	x2 = mult * x1;
	y2 = mult * y1;

	return;  // return nothing, changes made via pass by reference
}

// DEFINE FUNCTION normalize HERE.
// function that takes two inputs from program for vector x-y coordinates
// and converts them to their respective unit vector of length 1
// 'x' is pass by reference and is the x component of the vector
// 'y' is pass by reference and is the y component of the vector
void normalize(double& x, double& y)
{
	// create variable for length of vector with given coordinates
	double length = vector_length(x, y);
	
	// if length = 0 make unit vector values 0
	// this is to avoid dividing by 0
	if (abs(length) < EPSILON)
	{
		x = 0;
		y = 0;
	}
	else  // else divide both components by the length of teh initial vector
	{
		x /= length;
		y /= length;
	}

	return;  // return nothing, changes made via pass by reference
}

// DEFINE FUNCTION perpendicular HERE.
// function that takes inputs of two x-y unit vectors and
// computes whether or not they are perpendicular
// 'x1' and 'y1' x-y components of first unit vector
// 'x2' and 'y2' x-y components of second unit vector
void perpendicular(double x1, double y1, double x2, double y2)
{
	// necessary variable initializations
	double unit_vector1_x(x1), unit_vector1_y(y1);  // x-y variables for the unit vector of vector 1
	double unit_vector2_x(x2), unit_vector2_y(y2);  // x-y variables for the unit vector of vector 2
	double neg_unit_x1(0), neg_unit_y1(0);  // negative values for vector 1 x-y components

	// calculate unit vectors using 'normalize' command
	normalize(unit_vector1_x, unit_vector1_y);
	normalize(unit_vector2_x, unit_vector2_y);

	// create negative values for vector 1 components
	neg_unit_x1 = unit_vector1_y * -1;
	neg_unit_y1 = unit_vector1_x * -1;

	// if statement that evaluates whether or not vectors are perpendicular
	// if -x1 = y2 AND y1 = x2 then the vectors are perpendicular
	if (abs(neg_unit_x1 - unit_vector2_x) < EPSILON && abs(unit_vector1_x - unit_vector2_y) < EPSILON)
	{
		cout << "Vectors are PERPENDICULAR" << endl;
	}
	// if x1 = y2 AND -y1 = x2 then the vectors are perpendicular
	else if (abs(neg_unit_y1 - unit_vector2_y) < EPSILON && abs(unit_vector1_y - unit_vector2_x) < EPSILON)
	{
		cout << "Vectors are PERPENDICULAR" << endl;
	}
	// otherwise the vectors are NOT perpendicular
	else
	{
		cout << "Vectors are NOT PERPENDICULAR" << endl;
	}

	return; // return nothing, only output to screen
}