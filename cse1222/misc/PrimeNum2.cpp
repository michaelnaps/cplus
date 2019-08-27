// File: PrimeNum.cpp
// Created by: Michael Napoli
// Created on: 6/5/2019
// Last modified on: 

/* Program that calculates whether or not a number is
	prime by looking for remainder values. Up to a given
	limit.*/

#include <iostream>
using namespace std;

int main()
{
	int num;
	int limit;
	int i;
	int count(0);

	cout << "Enter the limit: ";
	cin >> limit;

	// for loop that runs every number up to the limit through the prime checker
	for (num = 1; num <= limit; ++num)
	{
		count = 0;

		for (i = 1; i < num; ++i)		// for loop that divides num by every number leading up to it
		{
			if (num % i == 0)
			{
				++count;				// if the number is divisible, count is > 1
			}
			if (count > 1)
			{
				break;
			}
		}
		if (count == 1)		// if count = 1, the number was not divisible by any other number
		{
			cout << "The number " << num << " is prime." << endl;
		}
	}

	return 0;
}