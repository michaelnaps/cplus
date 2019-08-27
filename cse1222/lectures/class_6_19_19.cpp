// Lecture 11
// topics include: functions cont., return statement, variable scoping, global variables
/*
notes:
	-functions are primarily meant for code organization
	-helps avoid duplicating code
	-enables code reusability
	-splits complex programs into multiple simpler parts (easy to test)
	-helps hide parts that would otherwise make the code harder to
		write
		-Ex: pow(x,n); sqrt(x); etc.
	-function that outputs area of a circle (shown below)
	-prototypes describe the interface of the function
		-how other code will interact and make use of the code within
			the function definition
	-functions are able to have the same name as long as their input
		values differ in type
	-Example:
		double function_name(double i, double j);
		double funciton_name(char i, char j);
	-the program will evaluate the function that utilizes the same 
		variable type as the input
	-functions can initialize variables within the prototype
		-if this is done, the program will only use the initialized value
			if there is no value inputted at the function call within the
			main program code
	-void functions do not have return statements
	-any function that is not void, needs a return statement
		-signals the end of execution for a given function		**
	-it is possible to have more then one return statement
		-within if statements
	-good practice always has a return statement that touches the closing
		brace of any given function
	- specific variables initialized within a function can never leave the 
		function
	-can be useful to prevent functions from "communicating" with one another
		in a way that you be negative
	-this way, variable names can be the same in multiple functions but they
		never interfere with one another
	-global variables:
		-any variable declared outside of any function, as well as the program
			that is being run (refer to 'PI')
		-any variable written in another function will mask the global variable
			within its specific scope
	-functions must contain comments that describe the total action of the function
	-when taking a variable from the main program, it should be made constant so that
		it cannot be changed through the function unless that is what is intended

*/

#include <iostream>
using namespace std;

// global variable 'PI'
const double M_PI = 3.141592653589793238462643383279502884197;	// global variable

// function prototypes
double cir_Area(double r);
double cyl_Volume(double h, double r);


int main()
{
	double circleArea, circleRadius;
	double cylinderVolume, cylinderHeight;

	cout << "Enter the radius of the circle: ";
	cin >> circleRadius;

	circleArea = cir_Area(circleRadius);

	cout << "The area of the circle is " << circleArea << "." << endl;

	cout << "Enter the height of the cylinder: ";
	cin >> cylinderHeight;

	cylinderVolume = cyl_Volume(cylinderHeight, circleRadius);

	cout << "The volume of the cylinder is " << cylinderVolume << endl;

	return 0;
}

// function definitions
double cir_Area(double radius)
{
	// calculate and exit function
	return radius * radius * M_PI;
}

double cyl_Volume(double height, double radius)
{
	// calculate and exit function
	return cir_Area(radius)* height;
}