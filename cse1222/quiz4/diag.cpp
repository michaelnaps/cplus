// File: diag.cpp
// Created by: Michael Napoli
// Created on: 6/7/2019

/* Program that takes a user inputted number of lines and prints
   that many lines of the character '+', ending each line with an
   'x'. */

#include <iostream>
using namespace std;

int main()
{
  int n;             // number of rows
  int i;  // loop variable
  int k;  // loop variable
  char plus = '+';   // holds plus symbol so that it is later easily changed if necessary
  char x = 'x';      // holds x value so that it is later easily changed if necessary

  cout << "Enter number of table rows: ";
  cin >> n;

  i = n;

  while (i > 0)  // loop that evaluates on numbers row > 0
    {
      k = i - 2;
      while (k >= 0)  // prints 1 less than the row number
	{
	  cout << plus;
	  --k;
	}
      cout << x << endl;
      --i;
    }

  return 0;
}
