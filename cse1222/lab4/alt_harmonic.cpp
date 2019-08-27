// File: alt_harmonic.cpp
// Created by: Michael Napoli
// Created on: 6/5/2019
// Last modifed on: 

/* Program that uses the sum of an alternating harmonic series
	(Taylor Series) to calculate the value of ln(2) to a close
	approximation. */

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int userInput;	// number of times the program goes through the equation
	int k;			// loop integer used to calculate sum
	double sum(0);	// sum of all values of k that go through equation

	cout << "Enter n: ";
	cin >> userInput;

	for (k = 1; k <= userInput; ++k)	// add values of k to sum until integer n is reached
	{
		sum += pow(-1.0, k + 1.0) / k;
	}

	cout << "The alternating series converges to " << sum << endl;

	return 0;
}