// File: split.cpp
// Created by: Michael Napoli
// Created on: 7/13/19
// Last modified on: 7/14/19

/* 
	Program that reads in a user-intputted array and 
	seperates the positive and negative numbers into
	two new arrays. 
*/

#include <iostream>
using namespace std;

// FUNTION PROTOTYPE: read_list()
void read_list(int* arr, const int size);

// FUNCTION PROTOTYPE: write_arr()
void write_arr(const int* arr, const int size);

// FUNCTION PROTOTYPE: count_neg()
void count(int* arr, const int total_size, int& neg_size, int& pos_size);

// FUNCTION PROTOTYPE: seperate__pos_neg()
void split(const int* arr1, int* arr2, int* arr3, const int size1);

int main()
{
	int* total_arr(0);  // initial user-inputted array
	int* pos_arr(0);  // pointer for array of positive values
	int* neg_arr(0);  // pointer for array of negative values
	int total_length(0), pos_length(0), neg_length(0);  // number of elements in each array

	// ask user how many elements are in initial array
	cout << "Enter number of elements: ";
	cin >> total_length;

	// adjust size of 'total_arr' pointer for appropriate number of elements
	total_arr = new int[total_length];

	// write to array pointer using outside function
	read_list(total_arr, total_length);

	// count how many positive and negative values were entered into the initial array
	count(total_arr, total_length, neg_length, pos_length);
	
	// adjust size of 'pos_arr' and 'neg_arr' pointers appropriately
	pos_arr = new int[pos_length];
	neg_arr = new int[neg_length];

	// seperate initial array into its postive and negative array variables using outside function
	split(total_arr, neg_arr, pos_arr, total_length);

	// print negative elements using outside function
	cout << "Negative elements:" << endl;
	write_arr(neg_arr, neg_length);

	// print positive elements using outside function
	cout << "Positive elements:" << endl;
	write_arr(pos_arr, pos_length);

	// deallocate array pointer memory
	delete[] total_arr;
	delete[] pos_arr;
	delete[] neg_arr;

	return 0;  // end program
}

// FUNCTION DEFINITION: read_list()
// function that asks the user to enter integers and places them into an array
// 'arr' - program given array pointer
// 'size' - program given length of array
void read_list(int* arr, const int size)
{
	// output statement asking for values
	cout << "Enter list:" << endl;

	// for all elements of 'arr'
	for (int i(0); i < size; ++i) {
		cin >> arr[i];  // each user input is placed in the array
	}

	return;  // return nothing
}

// FUNCTION DEFITNION: write_arr()
// function that writes array values to the screen
// 'arr' - program given array pointer
// 'size' - length of the given array
void write_arr(const int* arr, const int size)
{
	// for all elements in the given array
	for (int i(0); i < size; ++i) {
		cout << " " << arr[i];  // ouput the element seperated by a space
	}
	cout << endl;  // end with a new line

	return;  // return nothing
}

// FUNCTION DEFINTION: count()
// function that counts the negative and positive values of an array
// 'arr' - given array to be evaluated
// 'total_size' - length of the array
// 'neg_size' - number of negative elements in array
// 'pos_num' - number of positive elements in array
void count(int* arr, const int total_size, int& neg_num, int& pos_num)
{
	// for all elemets in given array
	for (int i(0); i < total_size; ++i) {
		if (arr[i] < 0) {
			++neg_num;  // if array value negative, increment negative size by one
		}
		else {
			++pos_num;  // otherwise increment size by one
		}
	}

	return;  // return nothing
}

// FUNCTION DEFINTION: split()
// function that extracts negative and positive array values and inputs them into new arrays
// 'arr1' - beginning array with all elements
// 'arr2', 'arr3' - new arrays for negative and postive values respectively
// 'size' - length of total array
void split(const int* arr, int* neg_arr, int* pos_arr, const int size)
{
	int neg_arr_i(0);  // element number for negative array
	int pos_arr_i(0);  // element number for positive array

	// for all elements of the intial array
	for (int i(0); i < size; ++i) {
		if (arr[i] < 0) {  // if it is negative
			neg_arr[neg_arr_i] = arr[i];  // implement into negative array
			++neg_arr_i;  // increment element counter variable for negative array
		}
		else {  // otherwise
			pos_arr[pos_arr_i] = arr[i];  // implement into postive array
			++pos_arr_i;  // increment element counter variable for positive array
		}
	}

	return;  // return nothing
}
