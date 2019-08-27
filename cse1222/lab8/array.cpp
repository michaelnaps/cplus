// File: array.cpp
// Created by: Michael Napoli
// Created on: 7/5/2019
// Last modified on: 

/* Program that takes inputs from the user and creates an array.
	The inputs are then evaluated to find which one is the largest
	and that value is added to the individual array elements. */

#include <iostream>
using namespace std;

// FUNCTION PROTOTYPE: read_list()
void read_list(int* newArrVal, int& count);

// FUNCTION PROTOTYPE: print_arry()
void print_array(const int* userArrVal, const int count);

// FUNCTION PROTOTYPE: find_max()
int find_max(const int* userArrVal, const int count);

// FUNCTION PROTOTYPE: array_add()
void array_add(int* newArrVal, const int count, const int max);

int main()
{
	int length(0);  // length of the array
	int userArr[20];  // array declaration with size = 20
	int maxArrVal;  // variable for the maximum value in the array

	// read in user entered values to the array
	read_list(userArr, length);

	// output intial array values before addition
	cout << "Original list (" << length << " values):";
	print_array(userArr, length);
	cout << endl;

	// find maximum array value and output to user
	maxArrVal = find_max(userArr, length);
	cout << "The maximum value is " << maxArrVal << endl;

	// add maximum value to all array values and output to the user
	array_add(userArr, length, maxArrVal);
	cout << endl << "Modified list (" << length << " values):";
	print_array(userArr, length);

	return 0;
}

// FUNCTION DEFINITION: read_list()
// function that takes input of array pointer pass by value and counter pass by reference
// 'count' - count of how many elements are in the array
// 'newArrVal' - pointer for initial array, used to change the array variables
void read_list(int* newArrVal, int& count)
{
	int userInput(0);  // variable that is used to build the array values

	cout << "Enter non-negative numbers (ints) terminated by -99" << endl;  // user input statement for array elements

	while (userInput != -99 && count < 20) {  // while loop that iterates while 'count' is less then 20 and 'userInput' does not equal -99
		cin >> userInput;

		if (userInput >= 0) {  // if 'userInput' is positive, add the value to the array
			newArrVal[count] = userInput;
			++count;  // increment counter variables
		}
	}
	cout << endl;

	return;  // return nothing
}

// FUNCTION DEFINITION: print_array()
// function that prints a given array
// 'arrayVal' - pointer for intial array value (constant)
// 'size' - length of given array (constant)
void print_array(const int* arrayVal, const int size)
{
	cout << endl;

	// increment for array values 0 to ('size' - 1)
	for (int i(0); i < size; ++i) {
		cout << arrayVal[i];  // output the array value at current location
		if (i < size - 1) {  // output comma and space for all but the last iteration
			cout << ", ";
		}
	}

	cout << "." << endl; // end with a period

	return;  // return nothing
}

// FUNCTION DEFINITION: find_max()
// function that finds the maximum number within an array
// 'arrayVal' - pointer to intial array memory loaction (constant)
// 'size' - array size (constant)
int find_max(const int* arrayVal, const int size) 
{
	int arrayMax(-1);  // intialized at -1 so that every value in array is larger (all are positive)

	// increment from intitial to final array value
	for (int i(0); i < size; ++i) {
		if (arrayVal[i] > arrayMax) {  // if current array value is greater then maximum, replace maximum
			arrayMax = arrayVal[i];
		}
	}

	return arrayMax; // return maximum array value
}

// FUNCTION DEFINITION: array_add()
// function that adds intputted number to all array values
// 'arrayVal' - pointer for initial array memory slot
// 'size' - size of array (constant)
// 'user_addition' - number to be added to array values (constant)
void array_add(int* arrayVal, const int size, const int user_addition)
{
	// for intial to final array value
	for (int i(0); i < size; ++i) {
		arrayVal[i] += user_addition;  // add inputted number to all array elements
	}

	return;  // return nothing
}