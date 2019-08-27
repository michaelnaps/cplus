// Lecture 3
// topics include: logical operators, boolean variable type, nested if statements
//	switch statements, exit commands, loops
/*
notes:
	-to make an if statement that evaluates two differing components
		of a variable, logical opertors are needed
		- and - &&
		- or - ||
	-switch statements:
		-alternative to if-else statement chain
		-faster when items are fixed
		-Example:
			switch (expression)
			{
				case value1:
					...
				case value2:
					...
				...
			}
	-variable type: boolean - bool
		-true or false variable
		-Example: bool var(true);
	-exit command - exit(n); - differing values of n can mean differing error messages

*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int j;

	cout << "Enter value: ";
	cin >> j;

	if (j % 2 == 1)
	{
		cout << "The number is odd." << endl;
	}
	else
	{
		cout << "The number is even." << endl;
	}

	// using and/or statements
	if (j >= 0 && j <= 10)
	{
		cout << "The number is between 0 and 10." << endl;
	}
	else if (j >= 11 && j <= 20)
	{
		cout << "The number is between 10 and 20." << endl;

		if (j == 15)
		{
			cout << "The number is " << j << "." << endl;
		}
	}
	else if (j > 20)
	{
		cout << "The number is greater then 20." << endl;
	}
	else
	{
		cout << "The number is negative." << endl;
	}
	
	cout << endl;

	double i = 0;
	double n;
	double L;
	
	cout << "Enter the maximum number (must be divisible by 10): ";
	cin >> n;
	
	// while loop
	while (i < n)
	{
		i = i + 10;
		L = log10(i);
		cout << "log("<< i <<") = " << L << endl;

	}


	return 0;
}