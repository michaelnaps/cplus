// Lecture 18
// topics include: vectors cont., class functions
/*
notes:
	-most data types are "basic" data types
		-they are primitive and built in
		-"pre-defined"
	-'arrays', 'strings' and 'vectors' are non-primitive data types
		-these represent lists of items
	-User-Defined data types:
		-'Class' is a user-defined data type that encapsulates info in one place
		-a 'class' stitches groups of variables together so that they are
				seen as one piece of information
		-the variables within a class are called 'class members' or 'attributes'
		-they can contain multiple 'variables' that all pertain to one value in the
			main program
		-also, an infinte amount of variables pertaining to the class type can be
			created
		-general convention that first letter of class name is to be capital  **
		-passing to functions:
			-still have option to pass by reference or value
			-default to pass by const reference
			-order for functions, classes and int main()
				1). header file includes
				2). class declarations
				3). function prototypes
				4). int main()
				5). function defintions
		-Circle Class:
			-a circle is made up of:
				-radius
				-center (x, y) coordinates
*/

#include <iostream>
#include <vector>
using namespace std;

class Circle  // this is now a variable type
{
public:
	double x;  // x-coordinate of midpoint
	double y;  // y-coordinate of midpoint
	double radius;  // radius of circle
};  // NOTE: semicolon

// bool intersects(const Circle& c1, const Circle& c2);

void create_arr(vector<int>& v);

void write_arr(vector<int>& v);

void moveVectorMax(vector<int>& v);

int main()
{
	Circle c1;  // circle 1
	Circle c2;  // circle 2
	vector<Circle> c_list(2);

	c1.x = 2.5;  // gives a value to circle 'x' variable
	c1.y = 3.0;  // gives a value to circle 'y' variable
	c1.radius = 1.0;  // gives a value to circle 'radius' variable

	c2 = c1;  // copies the values of 'c1' to 'c2'
	
	// place both circles in a vector
	c_list[0] = c1;
	c_list[1] = c2;

	// Vector Math and functions:
	vector<int> userVect(3);

	create_arr(userVect);

	cout << "The original vector:" << endl;
	write_arr(userVect);
	cout << endl;

	moveVectorMax(userVect);

	cout << "Vector with maximum up front:" << endl;
	write_arr(userVect);
	cout << endl;

	return 0;
}

/* bool intersects(const Circle& c1, const Circle& c2)
{

} */

// function that creates a vector
void create_arr(vector<int>& v)
{
	cout << "Enter vector elements (" << v.size() << " int): " << endl;

	for (int i(0); i < v.size(); ++i) {
		cin >> v[i];
	}
	cout << endl;

	return;  // return nothing
}

// function that writes a vector
void write_arr(vector<int>& v)
{
	for (int i(0); i < v.size(); ++i) {
		cout << v[i] << " ";
	}
	cout << endl;

	return;  // return nothing
}

// function that moves maximum vect value to the front of the vector
void moveVectorMax(vector<int>& v)
{
	int temp(0);

	for (int i(0); i < v.size(); ++i) {
		if (v[0] < v[i]) {
			temp = v[0];
			v[0] = v[i];
			v[i] = temp;
		}
	}

	return;  // return nothing
}