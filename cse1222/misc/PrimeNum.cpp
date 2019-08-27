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

	cout << "Enter the limit: ";
	cin >> limit;

	for (num = 1; num <= limit; ++num)
	{
		if (num % 2 == 0)
		{
			if (num == 2)
			{
				cout << "The number " << num << " is prime." << endl;
			}
		}
		else if (num % 3 == 0)
		{
			if (num == 3)
			{
				cout << "The number " << num << " is prime." << endl;
			}
		}
		else if (num % 5 == 0)
		{
			if (num == 5)
			{
				cout << "The number " << num << " is prime." << endl;
			}
		}
		else if (num % 7 == 0)
		{
			if (num == 7)
			{
				cout << "The number " << num << " is prime." << endl;
			}
		}
		else if (num % 11 == 0)
		{
			if (num == 11)
			{
				cout << "The number " << num << " is prime." << endl;
			}
		}
		else if (num % 13 == 0)
		{
			if (num == 13)
			{
				cout << "The number " << num << " is prime." << endl;
			}
		}
		else if (num % 19 == 0)
		{	
			if (num == 19)
			{
				cout << "The number " << num << " is prime." << endl;
			}
		}
		else if (num % 29 == 0)
		{
			if (num == 29)
			{
				cout << "The number " << num << " is prime." << endl;
			}
		}
		else if (num % 91 == 0)
		{
			if (num == 91)
			{
				cout << "The number " << num << " is prime." << endl;
			}
		}
		else
		{
			cout << "The number " << num << " is prime." << endl; 
		}
	}

	return 0;
}