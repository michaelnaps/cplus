// Lecture 6
// topics include: for loops, scope, do-while loops, loop practice, algorithms
/*
notes:
	-for loops must be updated within so that the conditional statement
		will eventually become false
	-use for loops when the interation being used is specific
	-use for loops when list of things being looped over is known
	-use while loops when iteration number is unknown
	-use while loop when general ending needs to be reached
	-use do while loop when the exitting of the loop is user controlled
	-Scope: the lifespan of a variable
		-if a variable is declared inside a for statement, the variable is
			deleted once the loop ends
		-to avoid this, declare the variable before the loop
		-scope is defined by {}
	-Algorithms:
		-determines when a process is successful
		-step-by-step procedure for solving a problem
*/

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main()
{
	int m, n(0);

	for (m = 1; m <= 10; ++m)
	{
		n = (n + m) * 2;
	}
	cout << "n = " << n << endl;

	for (int k(0); k < 12; ++k)
	{
		n = (k + n) * 2;
		cout << n << " ";
	}
	cout << endl;
	// cout << k << endl;
	// ^ would cause an error (outside of loop)
	
	cout << "m = " << m << endl;
	cout << endl;

	// nested for loop practice
	int L;

	cout << "Enter the length: ";
	cin >> L;

	for (int i(0); i < L; ++i)
	{
		for (int k(0); k < i; ++k)
		{
			cout << " ";
		}
		cout << "x" << endl;
	}

	// do-while loop
	int a(0);
	int count;

	cout << endl;
	cout << "Enter the count: ";
	cin >> count;

	do 
	{
		a = a + 1;
		cout << a << " ";
	} 
	while (count > a);

	cout << endl;

	return 0;
}