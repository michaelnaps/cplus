// Lecture 17
// topics include: vector class, adding/removing elements
/*
notes:
	#include <string>
	-this include line brings to the compiler the "string" class
	#include <vectors>
	-this "vector" class is intended to make array calculations easier
		-much like "string" did for character arrays
	-functions include:
		size()
		push_back()
		pop_back()
		clear()
	-a C++ vector does not neccesarily have the qualties of the actual defintion
		for the word vector in mathematics
	-array limitations:
		-array has a fixed size
			-known at compile time
			-this could have been fixed with dynamic memory but this was dangerous
			-the vector class also fixes this problem
	
	-variable initialization:
		vector<dataType> varaibleName(elementSize, elementNums);
	
	-vector declarations do NOT need a size to compile **
	-when a vector is declared with a size, the vector is guranteed to give 
		the value of zero for all spaces if they are not intitialized **
	-'elementNums' - values that all array elements will be intitialized at
	-when using vectors, can still overshoot the end of the array
	
	varaibleName.size() **
		-gives the size of the array, aka how many elements are in the vector
		-meant to replace the SIZE variable used for arrays
		-it is a "dot command" with no parameters
	-the vector class can also utilize string arrays
	-loops are still needed to operate through arrays
	
	varaibleName.push_back(integerAddition)
		-this dot command adds the 'addition' to the end of the array
		-it increases the size of the vector by one
	
	variableName.pop_back()
		-removes the last element in the array

	variableName.back()
		-returns the last element of the array, usually used in connecting with the
			'push_back' dot command

	variableName.clear()
		-clears all elements within the vector
	
	-when passing vectors to a function, do not include a size variable
	-Example:
		void print_vector(vector<int> list);
	-To pass by reference:
		void print_vector(vector<int> & list);
	-to make the vector constant:
		void print_vector(const vector<int> & list); **

*/

#include <iostream>
#include <string>
#include <vector>  // new include line **
using namespace std;

int main()
{
	string lastName;  // last name string
	int SIZE(0);  // size for fute vectors

	cout << "Enter last name: ";
	cin >> lastName;

	cout << "Your last name is " << lastName << "." << endl;
	cout << "It has " << lastName.length() << " characters." << "\n\n";  // output string length

	cout << "Enter the vector size: ";
	cin >> SIZE;

	vector<int> list(SIZE);  // vector type intitialization examaple (array size = 'SIZE')

	// outputs the length of the vector 'list'
	cout << "The power of two for all numbers between 1 and " << list.size() << " are:" << endl;

	for (int i(0); i < list.size(); ++i) {
		list[i] = (i + 1) * (i + 1);
		cout << list[i] << " ";  // prints the power of two for 1 through 'SIZE'
	}
	cout << endl;

	cout << endl << "How many words do you need? ";
	cin >> SIZE;  // changing SIZE variable

	vector<string> sent(SIZE);  // new vector made of strings with size = 'SIZE'

	for (int i(0); i < sent.size(); ++i) {
		cout << "Enter word #" << i + 1 << ": ";  // allow user to enter words for each space
		cin >> sent[i];
	}

	// for loop that prints the vector sentence
	cout << endl << "This is a copy: " << endl;
	for (int i(0); i < sent.size(); ++i) {
		cout << sent[i] << " ";
	}
	cout << "\n\n";

	// or
	vector<string> sent2;  // intitialize at "x" so while loop is started
	int i(0);
	string userInput("x");

	cout << "Enter sentence (end with seperate '.'): ";

	while (userInput != ".") {
		cin >> userInput;
		sent2.push_back(userInput);
		++i;
	}

	cout << "This is a copy: ";
	for (int i(0); i < sent2.size(); ++i) {
		cout << sent2[i] << " ";
	}
	cout << endl;

	return 0;
}