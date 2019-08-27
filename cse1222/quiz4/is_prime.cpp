// File: is_prime.cpp
// Created by: Michael Napoli
// Created on: 6/7/2019

/* Program that takes a suer inputted number and calculates
   whether or not it is prime. */

#include <iostream>
using namespace std;

int main()
{
  int userInput;  // user inputted value
  int i;  // used for for loop iteration and division
  int count(0); // counts the number of values 'userInput' is divisible by

  cout << "Enter an integer greater than 2: ";
  cin >> userInput;

  for (i = 1; i < userInput; ++i)  // for loop that uses integers up to userInput - 1
    {
      if (userInput % i == 0)
	{
	  ++count;
	}
      if (count > 1)
	{
	  break;
	}
    }
  
  if (count > 1)  // if statement that evaluates count value to find if a number was divisible by more numbers than just 1
    {
      cout << endl << "The value " << userInput << ": NOT PRIME." << endl;
    }
  else 
    {
      cout << endl << "The value " << userInput << ": PRIME." << endl;
    }

  return 0;
}
