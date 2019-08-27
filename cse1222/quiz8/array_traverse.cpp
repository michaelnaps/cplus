/*
  File: array_traverse.cpp
  Created by: Michael Napoli
  Creation Date: 7/8/2019
  Synopsis: Program that reads in user-inputted positive integers and
  computes their average. It then outputs all odd integers that are greater
  then or equal to the average.
*/

/* test numbers: 1345 234 5234 5625 625 624 56345 6235 65 634 56 0 */

#include <iostream>
#include <iomanip>

using namespace std;

const int SIZE(10);
  
// Function prototypes
void read_list(int a[], int & num_elements);
void print_array(const int a[], const int num_elements);
double compute_average(const int a[], const int num_elements);
void print_odds_above(const int a[], const int num_elements, const double val);

int main()
{
  int num_elements(0);
  double avg(0.0);
  int array[SIZE];

  read_list(array, num_elements);
	
  if (num_elements > 0)
  {
	// Display original list
	cout << endl << "You entered the list:" << endl;
	print_array(array, num_elements);
	
	// Compute average
	avg = compute_average(array, num_elements);
	cout << "Average = " << avg << endl;
	
	// Display list values less than the average
	cout << endl << "Odd values at or above the average:" << endl; 
	print_odds_above(array, num_elements, avg);
  }
  else {
	cout << "The list is empty." << endl;
  }
  
  return 0;
}

// INSERT FUNCTIONS HERE

// FUNCTION DEFINITION: read_list()
// function that reads user inputs and assigns them to an array
// of known size
// 'a' is the array taken from the main program
// 'num_elements' is the number of values in the array after the function is called
// 'num_elements' is passed by reference so that it can be modified
void read_list(int a[], int & num_elements)
{
  int i(0);  // loop iteration variable
  int userInput;  // variable to hold user input
  num_elements = 0;  // num_elements is initialized at 0 in case it wasn't already in the main program

  // output statement asking for variables
  cout << "Enter up to 10 positive numbers (ints) terminated by 0" << endl;

  // while loop that iterates until the value '0' is inputted or until the limit 'SIZE' is reached
  while (i < SIZE && userInput != 0) {
    cin >> userInput;

    if (userInput > 0) {  // if 'userInput' is greater then 0
      a[i] = userInput;  // add the input to a new element in the array
      ++num_elements; ++i;  // iterate 'num_elements' and 'i' by 1
    }
  }

  return;  // return nothing
}

// FUNCTION DEFINITION: print_array()
// function that prints out a given array
// 'a' is the constant array given from the main program
// 'num_elements' is the number of elements in the given array (constant)
void print_array(const int a[], const int num_elements)
{
  // output all values within the array, seperated by a space
  for (int i(0); i < num_elements; ++i) {
      cout << a[i] << " ";
    }

  cout << endl;  // end with a new line
	 
  return;  // return nothing
}

// FUNCTION DEFINITION: compute_average()
// function that computes the average of a given array
// 'a' is the array given from the main program
// 'num_elements' is the number of array elements
double compute_average(const int a[], const int num_elements)
{
  double arraySum(0);  // sum of all the array values, initialized at 0

  // for all values within the array
  for (int i(0); i < num_elements; ++i) {
    arraySum += a[i];  // add to the variable 'arraySum'
  }

  return arraySum / num_elements;  // return the sum of the array elements divided by the length of the array for the average
}

// FUNCTION DEFINITION: print_odds_above()
// function that prints the od numbers above a given value
// 'a' is the given array
// 'num_elements' is the number of array elements
// 'val' is the value that is to be evaluated against all array elements
void print_odds_above(const int a[], const int num_elements, const double val)
{
  // for all array elements
  for (int i(0); i < num_elements; ++i) {
    if (a[i] > val) {  // if the element is larger then the variable 'val'
      if (a[i] % 2 != 0) {  // and is not divisible by 2
	cout << a[i] << " ";  // print the element, seperate elements by a space
      }
    }
  }
  cout << endl; // end with a new line

  return;  // return nothing
}
