// Lecture 13
// topics include: floating point numbers, type casting, arrays
/*
notes:
	-when using floating point values, never use simple equality '=='
	-instead use approximations:
	-Example
		if (abs(num1 - num2) > EPSILON) {}
		'EPSILON' is variable with a number similar to 0.0000012
	-this if statement tells whether or not num1 and num2 are almost equal
	-think of this like an error approximation
	-some floating point values even have to be summed in a specific order
	-key point:
		-be alert as to what variable type to use for differing programs
	-also, default use should be double variable type
	-idea: convert lower presicisions to higher only when necessary so as 
		to conserve precision and accuracy by forcing the change
	-Example
		int x = 5;
		double y = log(double(x));		// forces x to act as a double
	-overloaded functions:
		-functions with the same name choose the correct function based
			on the type of variable inputted
		-an ambiguous error is caused by the program being able to use
			multiple different function and it doesn't know which one to
			choose
	
	-Arrays: WARNING: C++ is not a safe language... You HAVE to know how to use it completely.
		-programs often need to repeat code in order to utilize lists, etc.
		-arrays allow you to put a single value into one variable
		-one-dimensional array lists are linear and are ordered **
		-all array values are the same variable type
		-index refers to the numbers position
		-format
			varaibleType name[size] = {values};		// value initialization is optional
		-if you initialize an array with values you can:
			int array[] = {1, 2, 3};
		-the empty brackets forces the program to decide how big the array must be itself
			-cannot be done if not intialized at compile time
			-program must know how large an array is at compile time
		-index that calls a variable can be any integer, variables included

*/

#include <iostream>
using namespace std;

int main()
{
	float i = 0.8;
	int arr1[3];

	cout.setf(ios::fixed);
	cout.precision(30);

	cout << i << endl;

	cout.unsetf(ios::fixed);

	cout << i << "\n\n";

	// Output array input backwards
	for (int k(0); k < 3; ++k)
	{
		cout << "Enter 3 numbers: ";
		cin >> arr1[k];
	}
	cout << endl;

	for (int k(2); k >= 0; --k)
	{
		cout << arr1[k] << endl;
	}
	
	return 0;
}