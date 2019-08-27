// File: nestedWhileLoop.cpp
// Created by: Michael Napoli
// Created on: 5/26/2019

/* Program that outputs different possible domain
	names given the character length. Up to 3. */

#include <iostream>
#include <string>
using namespace std;

int main()
{
	char letter1 = 'a';
	char letter2;
	char letter3;
	int amount;
	int count = 0;

	cout << "How many characters would you like to use (1-3): ";
	cin >> amount;
	
	if (amount < 4 && amount > 0)
	{
		while (letter1 <= 'z')
		{
			if (amount == 2)
			{
				letter2 = 'a';
				while (letter2 <= 'z')
				{
					++count;
					cout << count << "). " << letter1 << letter2 << endl;
					letter2 = letter2 + 1;
				}
			}
			else if (amount == 3)
			{
				letter2 = 'a';
				while (letter2 <= 'z')
				{
					letter3 = 'a';
					while (letter3 <= 'z')
					{
						++count;
						cout << count << "). " << letter1 << letter2 << letter3 << endl;
						letter3 = letter3 + 1;						
					}
					letter2 = letter2 + 1;
				}
			}
			else
			{
				++count;
				cout << count << "). " << letter1 << endl;
			}
			letter1 = letter1 + 1;
		}


		if (amount == 1)
		{
			cout << "There are " << count << " different combinations." << endl;
		}
		else if (amount == 2)
		{
			cout << "There are " << count << " different combinations." << endl;
		}
		else
		{
			cout << "There are " << count << " different combinations." << endl;
		}
	}
	else
	{
		cout << "ERROR: Please enter a number from 1 to 3." << endl;
	}

	return 0;
}