// Lecture 4
// topics include: while loops, for loops
/*
notes:
	-while loops evaluate the same statement and repeats the inside
		of the loop until the statement is found to be false
	-Format:
		while (conditional statement)
		{
			statement1;
			statement2;
			...
		}
	-a variable controlled so that the loop can eventually be false and
		exit the loop is called the loop control variable
	-floating point values are never exact. They are the closest
		binary point the computer use
		.1 = .0999999897 in the computer's binary
	-for loops repeats itself until the maximum amount of reptitions is met
	-Format:
		for (initialization expression; conditional statement; increment)
		{
			statement1;
			...
		}

*/

#include <iostream>
using namespace std;

int main()
{
	int i;
	int n = 1;
	int m;

	cout << "What is your starting value? ";
	cin >> m;
	i = m;
	cout << endl;

	while (n <= i)
	{
		cout << n << endl;
		++n;
		if (i == n)
		{
			while (i > 0)
			{
				cout << i << endl;
				--i;
			}
		}
	}
	
	cout << endl;

	i = m;
	for (n = 1; n <= i; ++n)
	{
		cout << n << endl;
	}
	for (n = i - 1; n > 0; --n)
	{
		cout << n << endl;
	}

	cout << endl << "Goodbye." << endl;

	// make a rectangle
	int width;
	int length;

	cout << endl << "Enter length of rectangle: ";
	cin >> length;
	cout << "Enter width of rectangle: ";
	cin >> width;
	cout << endl;

	for (int i = 1; i <= length; ++i)
	{
		for (int n = 1; n <= width; ++n)
		{
			cout << "*";
		}
		cout << endl;
	}

	// to make square, change "width" in the nested for statement to "length"

	return 0;
}