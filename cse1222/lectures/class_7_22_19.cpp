// Lecture 19
// topics include: class type cont., classes and member functions, Object Oriented Programming (OOP)
/*
notes:
	-class types and functions
		-functions can return a class type
	-prototypes must come before the compiler, but AFTER the class type
	-class types can also include another class type
	-"composition" - combining class types to create and simplify variables
	-'public:' - tells compiler that anyone can change these members
	-'private' - tells compiler that NOT anyone can change these members
		-key word "limit"
		-member functions of the class type can access these variables

	Member Functions:
		-format
		returnType className::functionName()
		-"Mutator" member functions - change values within a class type
		-"Accessor" member functions - returns the necessary value safely

	Object Oriented Programming (OOP):
		-a program that defines and manipulates objects to solve problems
		-each object is independent of ALL other objects
		-this makes the creation of large projects much easier so that multiple people
			can be writing whole programs that interact with one another simultaneously
		-

*/

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

// this class 'Pointer' can be used in other class types, AND can be utilized in the main program
class Pointer {  // this is now a variable type
public:
	double x;  // x-coordinate
	double y;  // y-coordinate
	double x2, y2;
};

class Circle {
public:
	Pointer center;  // center point x, y coordinates
	double radius;  // radius of circle
};  // NOTE: semicolon

// FUNCTION PROTOTYPE: intersects()
bool intersects(const Circle& c1, const Circle& c2);

// FUNCTION PROTOTYPE: dist()
double dist(const Pointer& p1, const Pointer& p2);

int main()
{
	Circle c1;  // circle 1
	Circle c2;  // circle 2
	vector<Circle> c_list(2);

	c1.center.x = 3.0;  // x - midpoint for circle
	c1.center.y = 2.5;  // y - midpoint for circle
	c1.radius = 1.0;  // gives a value to circle 'radius' variable

	c2 = c1;  // copies the values of 'c1' to 'c2'

	// place both circles in a vector
	c_list[0] = c1;
	c_list[1] = c2;

	return 0;
}

double dist(const Pointer& p1, const Pointer& p2)
{ return sqrt(pow(p1.x - p2.x, 2.0) + pow(p1.y - p2.y, 2.0)); }

bool intersects(const Circle& c1, const Circle& c2)
{
	double distance = dist(c1.center, c2.center);

	if (distance <= c1.radius) {
		return true;
	}
	else if (distance <= c2.radius) {
		return true;
	}
	else { return false; }
}