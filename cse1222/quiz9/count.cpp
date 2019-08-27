/*
  File: count.cpp
  Created by: Michael Napoli
  Creation Date: 7/12/19
  Synopsis: Program that takes user-inputted array of integers and counts how many positive
  and zero value numbers there are using defined functions.
*/

#include <cstdlib>
#include <iostream>

using namespace std;

// FUNCTION PROTOTYPES
void get_list(int list[], int size);
int count_pos(const int list[], int size);
int count_zeros(const int list[], int size);

int main()
{
  int length;
  int num_pos, num_zeros;
  int * list;

  // Prompt and read number of elements from the user into the variable length
  cout << "Enter number of elements: ";
  cin >> length;
  
  // Create a new array (dynamically allocate) of size length and assign it to variable list
  list = new int[length];

  // Prompt and read the elements from the user. Call the function get_list
  get_list(list, length);
  
  // Count the number of positive numbers in the list. Call the function count_pos. Use variable num_pos
  num_pos = count_pos(list, length);
  
  // Count the number of zeros in the list. Call the function count_zeros. Use variable num_zeros
  num_zeros = count_zeros(list, length);
  
  // Display number of positive elements
  cout << "Number of positive elements: " << num_pos << endl;
  
  // Display number of zeros
  cout << "Number of zero elements: " << num_zeros << endl;
  
  // De-allocate the list
  delete[] list;
  
  return 0;
}

// FUNCTION DEFINTIONS GO HERE

// FUNCTION DEFINITION: get_list()
// function that builds array with number of elements 'size'
// 'list' - pointer variable that points to the beginning of the memory that was allocated for the array
// 'size' - given length of the array
void get_list(int list[], int size)
{
  cout << "Enter list:" << endl;  // output to user to enter values for the array

  for (int i(0); i < size; ++i) {  // loop variable 'i' increments until the array is full
    cin >> list[i];  // all values are placed into the array
  }

  return;
}

// FUNCTION DEFINITION: count_pos()
// function that counts the positive integers within an array
// 'list' - given pointer for the beginning of the array
// 'size' - length of given array
int count_pos(const int list[], int size)
{
  int pos_num(0);  // counter for positive values

  for (int i(0); i < size; ++i) {  // loop evaluates all elements of the array
    if (list[i] > 0) {  // if array element is greater then 0
      ++pos_num;  // increment postive integer counter
    }
  }

  return pos_num;  // return the number of positive elements found in the array
}

// FUNCTION DEFINITION: count_zeros()
// function that counts all zero values within a given array
// 'list' - array pointer
// 'size' - length of given array
int count_zeros(const int list[], int size)
{
  int zeros_num(0);  // variable that tracks the number of 0's found in the array

  for (int i(0); i < size; ++i) {  // for loop that iterates over all array elements
    if (list[i] == 0) {  // if array element is equal to 0
      ++zeros_num;  // increment counter by one
    }
  }

  return zeros_num;  // return the number of 0's found in the array
}
