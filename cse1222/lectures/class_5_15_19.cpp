// Lecture 3
// topics include: multiple variable declaration, different data types
/*
notes:
	-multiple variable declaration can be used to describe a common
		theme found among them
	-can also you combine multiple variables into a single cin command
	-Data Types:
		-commas are never allowed within a single variable value
		-integer type - int
			-any number with no decimal point attached
			-its potential value is determined by the capacity of the 
				computer being used
			-needs to be atleast 16 bits
			-most computers can handle up to 32 bits (4.3 billion values)
			-one bit is necessary to refer to the sign of the object - 31 bits
		-floating point - float, double, long double
			-can have a decimal point
			-can be signed or unsigned
			-differences between the three types listed are the precision 
				and range
			-float - 32 bits - can only approximate fractional values
			-double - 64 bits - most often used (best precision)
			-long double - minimum of 64 bits
			-float might be used to increase speed and memory usage
				-still not preferred - low precision
			-floating point numbers can be written in scientific notation
				-134.56 = 1.3456e2
			-decimals in equations tell the compiler that the value is a
				floating point
		-characters - char
			-All leters of the alphabet, digits 0-9 (representative), various
				symbols (+, *, -, &, ^, %, etc.)
			-ASCII - numeric values for letters and symbols
			-write a character in single quotes 'like this'
			-8, '8', and "8" are all different
		-boolean - true or false - bool
			-only utilize 1 byte of storage
			-can be created, but most often used unintentionally
	-Arithmetic Operations:
		-Binary operators include: +, -, /, *, %
		-operand - operator - operand
		-Symbol Precedence:
			1 - (), Unary -
			2 - *, /, %
			3 - +, -
*/

#include <iostream>
#include <string> // now capable of applying strings to variables
using namespace std;

int main()
{
	double x; // could also be "double x, y, z;"
	double y;
	double z;
	float a, b;

	char c; // one letter or symbol
	string d; // all strings up to first white space

	cout << "Enter values for x, y, and z: ";
	cin >> x >> y >> z; // could also split into multiple lines
	cout << "x = " << x << ", y = " << y << ", z = " << z << endl;
	cout << endl;

	// cout << pow(2, 1000) << endl << endl;

	cout << "Enter large floating point value: ";
	cin >> a;
	cout << a << endl << endl;

	cout << "Enter one string value: ";
	cin >> c;
	cout << c << endl << endl;

	cout << "Enter string: ";
	cin >> d;
	cout << d << endl;

	return 0;
}