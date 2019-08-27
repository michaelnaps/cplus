/*
  File: isprime.cpp
  Created by: Michael Napoli
  Creation Date: 6/20/2019
*/

#include <iostream>
#include <cmath>

using namespace std;

// FUNCTION PROTOTYPE FOR read_range
void read_range(int& min, int& max);

// FUNCTION PROTOTYPE FOR is_prime
bool is_prime(int i);

// DO NOT MODIFY THE MAIN ROUTINE IN ANY WAY
int main()
{
	int imin(0), imax(0);

	// Read in range
	read_range(imin, imax);

	// Print prime numbers
	cout << "Primes:";
	for (int j = imin; j <= imax; j++) {
		if (is_prime(j))
		{
			cout << "  " << j;
		}
	}
	cout << endl;

	return 0;
}

// DEFINE FUNCTION read_range() HERE:
// read read in two variables 'min' and 'max' that will be changed in function
// repeatedly runs the user through the while loop until an acceptable 'min' and 'max' value is entered
// function is type 'void' so nothing is returned, variables are just modified
void read_range(int& min, int& max)
{
	bool eval_min_max(true);	// bool variable that moderates do-while loop

	do {
		// user input statements
	        cout << "Enter minimum and maximum: ";
	        cin >> min >> max;

		// if statements that checks that checks the given parameters
		if (min < 2 || max < 2)		// if either 'min' or 'max' are less then 2 then repeats loop
		{
			cout << "Error. Minimum and maximum must be at least 2." << endl;
		}
		else if (min > max)		// if 'min' is greater then 'max' then repeats loop
		{
			cout << "Error. Minimum must be less than maximum." << endl;
		}
		else	// if 'min' and 'max' pass parameters 'eval_min_max' is made false and the loop is exited
		{
			eval_min_max = false;
		}
	} while (eval_min_max);

	return;
}

// DEFINE FUNCTION is_prime() HERE:
// take integer input from main program and place in variable 'num'
// calculate whether or not it is prime by dividing by all number less then 'num'
bool is_prime(int num)
{
	for (int i(2); i < num; ++i)	// for loop that loops integers 2 through, but not including, 'num'
	{
		if (num % i == 0)
		{
			return false;	// if 'num' value is divisible by any number, the function immediately ouputs false
		}
	}
	return true;	// if 'num' passes through the for loop without being divisible by any number, function returns true
}