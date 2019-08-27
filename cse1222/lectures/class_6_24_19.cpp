// Lecture 12
// topics include: functions (pass by reference), numerical error
/*
notes:
	-pass by reference has the ability to modify the variables used in the
		main program and passed through the function
	-when using a pass by reference, the types being exchanged must be the same
	-this ability is risky and will sometimes be forgotten by programmers
		-the character '&' that makes it a reference is unseen by anywhere but
			the function defition and prototype
	"Principle of Least Surprise"
		-if there are multiple ways to do something, always choose the most
			obvious approach so that other programmers are not surprised by the
			outcome of your code
	-the pass by reference type can be used to return multiple variables to the
		program window
		-that being said, if one return value is via pass by reference then all
			return values should be and the function should not 'return' anything
			back
	-can be used to swap values **
	-'algorithm' includes swap function **
	-if calling a function that calls for variables that are not intended to change,
		it may make sense to make them constant in the prototype/definition line

	-numeric error: floating point values are always an approximation
*/

#include <iostream>
#include <algorithm>  // has 'swap' among other common necessary functions
using namespace std;

void mult2(double& x);	// 'void' type used if function only uses pass by reference

int main()
{
	double userInput;
	double x, y;

	cout << "Enter number: ";
	cin >> userInput;

	mult2(userInput);

	cout << "That number multiplied by 2 = " << userInput << endl;

	return 0;
}

void mult2(double& x)
{
	x = x * 2;

	return;
}