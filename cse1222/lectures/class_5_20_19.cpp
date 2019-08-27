// Lab: 1
// topics include: incrementing values, coercion, selection structures
/*
notes:
	-assigning an integer to a floating point variable converts the
		integer to a floating point number
	-the compiler will only convert an integer variable into a double if
		it is being mathematically affected by a floating point value
	-mathematical functions:
		- #include <cmath>
		-functions have highest precedents - evaluated first within a 
			function
		-all mathematical functions should be entered as floating points
		-square root - sqrt
			-input: a single decimal number or variable (a double)
			-output: the square root of the inputted value
			-Example: y = sqrt(9.0) = 3.0
		-power - pow(var,n)
			-input: variable = number that will be raised to power
					n = power that it is being raised to
			-output: the variable raised to the inputted power
			-tip: when squaring values - use (var * var) format
				-more accurate and faster
		-sine, cosine, and tangent - sin, cos, tan
			-all functions are specified in radians, not degrees
			-conversion: 1 degree = (pi / 180)
			-M_PI = the value of pi
	-when mathematically combining different types of variables, the compiler 
		will automatically convert to the largest variable type present
		-when an integer is needed to be a double, a simple way to solve this
			is to multiply by 1.0 which will turn it into a double

	-Selection Structures: decisions - flow of control
		-sequaences execute in sequential (linear) order - top-to-bottom
		-if and else statements
		- < - less than
		- > - greater than
		- <= - less than or equal to
		- >= - greater than or equal to
		- == - equal to
		- != - not equal to
*/

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main()
{
	int i = 0;
	int n = 3;
	double y = 3; // no problem
	// error: int y = 3.6;
	char c = 5; // c now equals X, see ascii table

	double a = 81.0;
	double b = sqrt(a);
	double d = pow(sqrt(a), sqrt(b)) * b;
	
	cout << "i = " << i << endl;
	// increment variable i by one unit
	i = ++i;
	cout << "i = " << i << endl;
	// increment variable by "n" units
	i = i + n;
	cout << "n = " << n << " and i = " << i << endl;

	// does not output the number 88
	cout << "c = " << c << endl;

	cout << "a = " << a << " b = " << b << endl;
	cout << "d = pow(sqrt(a), sqrt(b)) * b = " << d << endl;

	// Flow of Control
	double numerator, denominator;

	cout << "Enter the numerator: ";
	cin >> numerator;

	cout << "Enter the denominator: ";
	cin >> denominator;

	// if and else statements that safely calculate a given quotient
	if (denominator != 0)
	{
		cout << numerator << " / " << denominator << " = "
			<< numerator / denominator << endl;
	}
	else
	{
		cout << "ERROR: The denominator is 0. The quotient is undefined." << endl;
	}

	// is the value in variable q even?
	int q;
	
	cout << "Enter the value of q: ";
	cin >> q;

	if (q % 2 == 0)
	{
		cout << "It is even." << endl;
	}
	else
	{
		cout << "It is odd." << endl;
	}

	return 0;
}