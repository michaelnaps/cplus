// Lecture 10
// topics inlcude: functions
/*
notes:
	-functions have three parts
		-name
		-input parameters
		-evaluates to an output
	-Examples: sqrt(a), exp(a), cos(a), pow(a, b)
	-format: y = f(x);
	variableType functionName(inputVariables)	**
	-meant to compute a task given arguments and may return an answer
		(but not always necessary)
	-after writing a function, it is never necessary to rethink the 
		computation
	-used when computing over different variables
	-begin program with function prototype		**
	-end program with the funtion definition	**
	-we can also build functions for output statements
		varaibleType = void
	-functions also may not need input arguments but only return an integer
		int functionName();
	-this is a valid function prototype
*/

#include <iostream>
#include <iomanip>
using namespace std;

// function prototypes
double dist(double x1, double y1, double x2, double y2);
void output_distance(double d);

// main body program
int main()
{
	int x1(0), y1(0), x2(0), y2(0);		// two points on x-y plane
	double distance;	// outputted distance between points

	// user inputted values
	cout << "Enter the values of x1 and y1: ";
	cin >> x1 >> y1;

	cout << "Enter the values of x2 and y2: ";
	cin >> x2 >> y2;

	// function call using user inputs
	distance = dist(x1, y1, x2, y2);

	// print
	output_distance(distance);

	// exit program
	return 0;
}

// function definition
double dist(double x1, double y1, double x2, double y2)		// 'dist' is the name of the func	
															// 'double' is return type
{
	double dx, dy, d;

	dx = x1 - x2;
	dy = y1 - y2;
	d = sqrt(dx * dx + dy * dy);

	return d;
}

void output_distance(double d)
{
	cout << endl << "The distance between the points is " << d << "." << endl;
}