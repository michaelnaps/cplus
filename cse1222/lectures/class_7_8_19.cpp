// Lecture 16
// topics include: c-style strings, c++ strings, string processing
/*
notes:
	-cannot add length to char strings
	-deleting a variable from the string does not always shift variables to the left
	-concatenating two char strings could run out of memory

	#include <strings>
	-Example declaration:
		string variableName;
	-strings can be copied using '='
	-strings can be combined via addition
	-Example:
		string3 = string1 + string2
		string3 = "string1string2"
	-c++ strings stop taking in values during cin use at the first white space
	-use 'getline'
		getline(source, destination);  **
	types of strings:
		string literals - "Hello World"
		c-style strings - char s[20];
		c++ style strings - string s;
	-strings can be operted like arrays using [] and element indexies
	-it can editted and changed in the same way

	-string length can be found via the length function:  **
		variableName.length();  // returns the length of the string (array)

	-this is called a member function, or dot notation  **
		variableName.functionCall()

	-portions of the string can be taken out via the function  **
		variableName.substr(x, y);
		'x' is the start of the index
		'y' is the maximum length of the new string

	-portionsof the string can be replaced via the function  **
		varaibleName.replace(x, y, newString);
		-this function changes THE STRING ITSELF

	-add something to any part of the string using the following function **
		variableName.insert(x, newString)
		'x' is the intial index point
	-using relational operators
	
	-strings can be inputted into functions like any integer or double variable like
		the one seen below

*/

#include <iostream>
#include <string>  // new library
using namespace std;

string outputFile(string inputFile);

int main()
{
	string lastName, firstName;
	string fullName;
	string input_fileName, output_fileName;

	cout << "Enter last name: ";
	cin >> lastName;

	cout << "Enter first name: ";
	cin >> firstName;

	/* cout << "Enter full name: "
	getline(cin, fullName); */

	cout << firstName + " " + lastName << endl;
	// or
	// cout << fullName << endl;

	cout << "Enter file name: ";
	cin >> input_fileName;

	cout << "Intial file name is " << input_fileName << endl;

	output_fileName = outputFile(input_fileName);

	cout << "Final file name is: " << output_fileName << endl;

	return 0;
}

string outputFile(string inputFile)
{
	if (inputFile.substr(0, 2) == "in") {
		inputFile.replace(0, 2, "out");
	}
	else {
		inputFile.insert(0, "out.");
	}

	return inputFile;
}