// File: investments.cpp
// Created by: Michael Napoli
// Created on: 5/24/2019
// Last modified on: 5/25/2019

/* Program that calculates two differing investment totals
	based on user input of an initial investment, the interest rate,
	and the time frame of the investment. The two types are then 
	compared. */

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int investment;				// initial investment given
	int interestRate;			// percent interest rate of the investment
	int months;					// time frame in unit months
	double years;				// user's entered months converted into years
	double finalInvestment;		// final investment total of the first investment type
	double profit1;				// profit gained from first investment type	
	double compInvestment;		// final investment total of the second investment type
	double profit2;				// profit gained from second investment type

	// user inputs
	cout << "Enter the initial investment (dollars): ";
	cin >> investment;

	cout << "Enter interest rate per year (percentage): ";
	cin >> interestRate;

	cout << "Enter number of months: ";
	cin >> months;
	cout << endl;

	// Convert months to years
	years = months / 12.0;

	// Calculate the final investment value, type one
	finalInvestment = investment * pow((1.0 + (interestRate / 100.0)), years);
	
	// Calculate profit from investment type one
	profit1 = finalInvestment - investment;

	cout << "Value of you investment compounded annually after " << years
		<< " year(s) is " << finalInvestment << " dollars." << endl;
	cout << "Profit from your investment after " << years << " year(s) is "
		<< profit1 << " dollars." << endl << endl;

	// Calculate value of investment continuously compounded during time frame, type two
	compInvestment = investment * exp((interestRate / 100.0) * (months / 12.0));

	// Calculate profit using the compounded total, investment type two
	profit2 = compInvestment - investment;

	cout << "Value of your investment continuously compounded after " << months / 12
		<< " year(s) is " << compInvestment << " dollars." << endl;	
	cout << "Profit from this investment is " << profit2 << " dollars." << endl << endl;

	cout << "The difference between both investment types is "
		<< fabs(compInvestment - finalInvestment) << " dollars." << endl;

	return 0;
}