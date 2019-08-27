// Lecture 9
// topics inlcude: formatting ouput, constant values
/*
notes:
	- default
	-will only display as many sig figs as needed, up to six decimal digits
	- cout.setf(ios::fixed);	->		cout.unsetf(ios::fixed);
		-would not display scientific notation
		-would display as many integers as the limit, always
	- cout.setf(ios::scientific);	->		cout.unsetf(ios::scientific);
		-forces program to always display scientific notation
	- cout.precision(x)
		-sets value to cout using cout.setf(ios::fixed);
		-x is the number of decimal places printed
	-iomanip library - contains many other formatters then listed here
		- setw(x)
			-tells the program how many characters to use for the output
			-if they are not available, blank characters will be used
			-can go above the width number set if necessary
			-only applies to very next ouput
		- setprecision(x)
			-controls the amount of decimals outputted
		- showpos
			-shows '+' in front of positive numbers
	-constant values
		-used to give specific numbers meaning so that later evaluation is
			easily readable
		- const double GALLON_TO_LITER(3.785411784);
			-creates a variable 'GALLON_TO_LITER' and permanently gives the
				conversion factor to it
		-it is convention to use all capital letters
*/

#include <iostream>
#include <ios>			// new library
#include <iomanip>		// new library
using namespace std;

int main()
{
	double x = 1234.56789012;
	int userInput, count;

	cout << x << endl;  // default notation

	cout.setf(ios::fixed);  // automatically displays 6 decimal digits
	cout << x << endl;
	cout.unsetf(ios::fixed);

	cout.setf(ios::scientific);  // scientific notation
	cout << x << endl;
	cout.unsetf(ios::scientific);

	cout.precision(3);  // sets decimal digits to 3
	cout.setf(ios::fixed);
	cout << x << endl;
	cout.unsetf(ios::fixed);

	x = 12;

	cout << setw(8) << x << endl;	// output 10 total digit and space width

	cout << "Enter a number and count: ";
	cin >> userInput >> count;

	for (int i(1); i <= userInput; ++i)
	{
		cout << setw(4) << i << " ";		// use setw(x) to print a well formatted table
		if (i % count == 0)
		{ cout << endl; }
	}

	return 0;
}