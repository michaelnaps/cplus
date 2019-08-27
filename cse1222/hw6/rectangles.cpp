/*
	File: rectangles.cpp
	Created by: Michael Napoli
	Creation Date: 7/22/19
	Synopsis: Program that takes a potentially infinite number of user-entered rectangles
	with given names. Once the program is stopped, the program outputs the dimensions and
	information describing all inputted rectangles along with each rectangle's dimensions
	scaled by 3.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Point
{
private:
	double px;
	double py;

public:
	void setX(const double x);
	void setY(const double y);
	double getX() const;
	double getY() const;
};

class Rectangle
{
private:
	string name;
	Point blPoint;
	double length, height;

public:
	// member functions
	void setName(const string & inName);
	void setBottomLeft(const double x, const double y);
	void setDimensions(const double inLength, const double inHeight);

	string getName() const;
	Point getBottomLeft() const;
	double getLength() const;
	double getHeight() const;
	
	double area() const;
	double perimeter() const;
	Point midPoint() const;
	void scaleBy3();
	void display() const;
};

// FUNCTION PROTOTYPE: display_banner()
void display_banner();

// FUNCTION PROTOTYPE: define_rectangle()
bool define_rectangle(const string prompt, const string error_input, const string error_inUse,
	string& userInput, vector<Rectangle>& rect_list);

// FUNCTION PROTOTYPE: rect_BLpoints()
void rect_BLpoints(const string rect_name, double& x, double& y);

// FUNCTION PROTOTYPE: rect_dim()
void rect_dim(const string rect_name, double& length, double& height);

// FUNCTION PROTOTYPE: add_rect_2_vect()
void add_rect_2_vect(const string name, const double x, const double y, 
	const double L, const double H, vector<Rectangle>& rect_list);

int main()
{
	// Define your local variables, e.g. a vector of class Rectangle
	bool allowedName(true);  // varaible that controls initial while loop iteration
	vector<Rectangle> rect_v;  // vector that holds values of class type 'Rectangle'
	string temp_name;  // temperary name for each rectangle
	
	// Display welcome banner
	display_banner();
	cout << endl;  // end with new line

	// while loop that iterates at least once and continues until the the correct naming parameters are met
	do {
		// 'allowedName is incorrect on first try, output "Try again."
		if (allowedName == false) { cout << endl << "Try again! "; }

		// 'allowedName' tells the while loop whether or not it needs to continue
		// 'define_rectangle()' - takes inputs described in the function defintion in order to create portions of a Rectangle vector
		allowedName = define_rectangle("Enter the name of the first Rectangle: ",
			"Invalid Input. Type 'rec' followed by the name or 'stop' if done.", "This name is already being used!",
			temp_name, rect_v);
	} while (allowedName == false);  // continue until 'allowedName' is true

	// while loop that iterates until the user enters 'stop'
	while (temp_name != "stop") {
		// if the user enters the name correctly, output "Thank you"
		if (allowedName == true) 
		{ cout << endl << "Thank you! "; }

		// otherwise, output "Try again"
		else 
		{ cout << endl << "Try again! "; }

		// create vector variables of class type 'Rectangle' until loop is exited
		allowedName = define_rectangle("Enter the name of the next Rectangle: ",
			"Invalid Input. Type 'rec' followed by the name or 'stop' if done.", "This name is already being used!",
			temp_name, rect_v);
	}

	// if 'rect_v' is not empty, print the vector components
	if (rect_v.size() != 0) {
		cout << endl;  // endline
		
		// print out how many rectangles are in the final vector
		cout << "You have " << rect_v.size() << " rectangle(s) in you list." << endl << endl;

		// for all elements of the vector
		for (int i(0); i < rect_v.size(); ++i) {
			//print the name of the vector
			cout << "Rectangle '" << rect_v[i].getName() << "': ";
			// print the vector components
			rect_v[i].display();
			// scale the vector by three around the midpoint, repeat
			cout << "     After scale by 3: ";
			rect_v[i].scaleBy3();
			rect_v[i].display();
			cout << endl;  // end with new line
		}
	}
	else {  // otherwise, tell the user there are no rectangles in their list
		cout << endl;
		cout << "You have no rectangles in your list." << endl;
	}

	return 0;  // end program
}
		 
// FUNCTION DEFINITION: display_banner()
// function that diplays banner with given instructions on how to enter rectangles
// no input parameters
void display_banner()
{
	cout << "Welcome! Create your own list of rectangles." << endl;
	cout << "You will be asked to provide information about each rectangle in your list by name." << endl;
	cout << "Type the word 'stop' for the rectangle name when you are done." << endl;

	return;  // return nothing
}

// FUNCTION DEFINITION: define_rectangle()
// function that defines the given vector element of class type 'Rectangle' by
// asking the user a series of questions pertaining to its dimensions
// 'prompt' - intial output that asks user for the rectangle name
// 'error_intput' - ERROR: outputted if user enters an incorrect name
// 'error_inUse' - ERROR: outputted if user enters a name that is already in use
// 'userInput' - temporary given name of the rectangle, later inputted into vector
// 'rect_list' - vector of class type 'Rectangle' that will be modified by end of function
bool define_rectangle(const string prompt, const string error_input, const string error_inUse,
	string& userInput, vector<Rectangle>& rect_list)
{
	double x, y;  // temporary variables for x and y coordinates of rectangle
	double L, H;  // temporary variables for length and height of rectangle

	// output the prompt that asks for user input
	cout << prompt;
	getline(cin, userInput);
	
	// if user enters "stop" the function is exited with return value 'true'
	if (userInput == "stop") { return true; }

	// if the user does not enter 'rec' before their rectangle's name
	if (userInput.find("rec ") == string::npos) { 
		cout << error_input << endl;  // output the appropraite error message
		return false;  // return flase to the main program
	}
	else { userInput.erase(userInput.find("rec "), 4); }  // otherwise, erase the 'rec ' identifier from the 'userInput' value

	// for all elements in the initial rectangle vector
	for (int i(0); i < rect_list.size(); ++i) {
	  if (userInput == rect_list[i].getName()) {  // check names so that none are repeated
			cout << error_inUse << endl;  // if one is repeated, output necessary error message
			return false;  // return to main program with value false
		}
	}

	// use helper function 'rect_BLpoints()' to enter the bottom left corner coordinates for the rectangle
	rect_BLpoints(userInput, x, y);

	// use helper function 'rec_dim()' to enter the length and height of the rectangle
	rect_dim(userInput, L, H);

	// use helper function 'add_rect_2_vect()' to add single rectangle to the end of a vector of rectangles
	add_rect_2_vect(userInput, x, y, L, H, rect_list);

	// command that ignores the cin new line character so that the next 'getline()' command executes correctly
	cin.ignore();

	// return true to the main program
	return true;
}

// FUNCTION PROTOTYPE: rect_BLpoints()
// helper function that takes user-inputted coordinates and returns them in a class type 'Point' variable
// 'rect_name' - the name of the current rectangle
// 'x' and 'y' - points to be modified and returned
void rect_BLpoints(const string rect_name, double& x, double& y)
{
	// output statement for user
	cout << "Enter " << rect_name << "'s bottom left x and y coordinate: ";
	cin >> x >> y;  // place input into variables

	return;  // return nothing
}

// FUNCTION DEFINITION: rect_dim()
// helper function that returns the length and height dimensions of the given rectangle
// 'rect_name' - given rectangle name
// 'length' and 'height' - variables for rectangle dimensions that will be modified and returned
void rect_dim(const string rect_name, double& length, double& height)
{
	// output statement for current rectangle's dimensions
	cout << "Enter " << rect_name << "'s length and height: ";
	cin >> length >> height;  // place input into the appropriate variables

	return;  // return nothing
}

// FUNCTION DEFINITION: add_rect_2_vect()
// helper function that takes the dimensions and name for a single rectangle and adds it to the end of the given vector
// 'name' - given rectangle name
// 'x' and 'y' - rectangle bottom left coordinates
// 'L' and 'H' - rectangle length and height
// 'rect_list' - vector list for rectangles that will be modified
void add_rect_2_vect(const string name, const double x, const double y, 
	const double L, const double H, vector<Rectangle>& rect_list)
{
	Rectangle temp;  // create temporary single rectangle

	// apply name and dimensions to single rectangle
	temp.setName(name);
	temp.setBottomLeft(x, y);
	temp.setDimensions(L, H);

	// add the single rectangle to the end of the rectangle vector
	rect_list.push_back(temp);

	// once the function returns to the position it was called from, the temporary rectangle is deleted from memory
	return;  // return nothing
}
			 
// CLASS MEMBER FUNCTION DEFINITINOS GO HERE:

void Point::setX(const double x) 
{ 
	px = x;
	return;  // return nothing
}

void Point::setY(const double y) 
{ 
	py = y; 
	return;  // return nothing
}

double Point::getX() const 
{ return (px); }

double Point::getY() const 
{ return (py); }

void Rectangle::setName(const string & inName) 
{
	name = inName;
	return;  // return nothing
}

void Rectangle::setBottomLeft(const double x, const double y) 
{
	blPoint.setX(x);
	blPoint.setY(y);

	return;  // return nothing
}

void Rectangle::setDimensions(const double inLength, const double inHeight) 
{
	length = inLength;
	height = inHeight;

	return;  // return nothing
}

string Rectangle::getName() const
{ return (name); }

Point Rectangle::getBottomLeft() const
{ return (blPoint); }

double Rectangle::getLength() const
{ return (length); }

double Rectangle::getHeight() const
{ return (height); }

double Rectangle::area() const
{ return (length * height); }
	
double Rectangle::perimeter() const
{ return ((length * 2) + (height * 2)); }

// MEMBER FUNCTION DEFINITION: midPoint()
// member function to rectangle class type that calculates the midpoint of a given rectangle
Point Rectangle::midPoint() const
{
	Point temp;  // temporary point variable

	// calculate the midpoint
	temp.setX(blPoint.getX() + (length / 2.0));
	temp.setY(blPoint.getY() + (height / 2.0));

	return temp;  // return the calcualted point to the position it was called from
}

// MEMBER FUNCTION DEFINITION: scaleBy3()
// member function that calcualates the given rectangles dimensions after it is scaled by a factor of three
void Rectangle::scaleBy3() 
{
	// calculate new coordinates for bottom left corner point
	blPoint.setX(blPoint.getX() - length);
	blPoint.setY(blPoint.getY() - height);

	// calculate the new length and height dimensions
	length *= 3;
	height *= 3;

	return;  // return nothing
}

// MEMBER FUNCTION DEFINITION: display()
// function that outpoints the dimensions of a given rectangle
void Rectangle::display() const
{
	// calculate midpoint
	Point midpoint = midPoint();

	// output the dimensions in a linear fasion
	cout << "Location is (" << blPoint.getX() << ", " << blPoint.getY() << "), ";
	cout << "Length is " << length << ", ";
	cout << "Height is " << height << ", ";
	cout << "Area is " << area() << ", ";
	cout << "Perimeter is " << perimeter() << ", ";
	cout << "Midpoint is located at (" << midpoint.getX() << ", " << midpoint.getY() << ")" << endl;  // end with a newline

	return;  // return nothing
}