// Lecture 2
// topics include: error analysis, cout and cin, variables usage and data types
/*
notes:
	-when debugging, fix one error at a time, always starting with the first
	-some errors will compile but they will output a warning that tells you something
		is "ugly" or just incorrect in its writing
	-syntax errors
		-mispelled something
		-forgot symbol, etc.
		-NOT a syntax error if the code compiles
	-runtime error
		-when the compiler has no answer for a mathematic equation, etc. so it cannot
			continue running the code and it stops running
		-NOT a runtime error if the code finishes running
	-logic error
		-operator error - the compiler reasoning behind the code written yields 
			unexpected results
		-Example: cout << "Hello World!" << "Goodbye World!" << endl;
			-copy and paste
	
	-C++ variable declarations are of the form: dataType variableName
	-dataType: int, float, char, double, unsigned int,...
		-double - number whose value includes decimals
		-int - integer
		-char - characters, i.e. strings
		-float - 
	-variableName: composed of alphanumaerical characters or underscores '_'

	-C++ does know PEMDAS
*/

#include <iostream>
#include <cmath> //adds certain mathematical functions
using namespace std;

int main()
{
	cout << "cout can output strings like this sentence and..." << endl;
	cout << "1 + 2 + 3 + 4 = " << 1 + 2 + 3 + 4 << " ... equations.";
	cout << endl << endl;

	cout << "The sqare root of 15 is " << sqrt(15.0) << endl;
	cout << "and e^15 = " << exp(15.0) << endl << endl;

	double x = 15;
	cout << "The sqare root of " << x << " is " << sqrt(x) << endl;
	cout << "and e^" << x << " = " << exp(x) << endl << endl;

	double y;
	cout << "What value are you using to calculate? ";
	cin >> y;
	cout << "The sqare root of " << y << " is " << sqrt(y) << endl;
	cout << "and e^" << y << " = " << exp(y) << endl << endl;

	return 0;
}