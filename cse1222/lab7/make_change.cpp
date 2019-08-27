/*
  File: make_change.cpp
  Created by: Michael Napoli
  Creation Date: 6/29/2019
  Synopsis: Program that uses functions outside 'main' to
	convert a user-given dollar amount into the necessary 
	change in coins.
*/

#include <cstdlib>
#include <iostream>

using namespace std;

// FUNCTION PROTOTYPE FOR read_change
double read_change();

// FUNCTION PROTOTYPE FOR convert2cents
int convert2cents(double dollars);

// FUNCTION PROTOTYPE FOR change_quarters
int change_quarters(int& cents);

// FUNCTION PROTOTYPE FOR change_dimes
int change_dimes(int& cents);

// FUNCTION PROTOTYPE FOR change_nickels
int change_nickels(int& cents);

// FUNCTION PROTOTYPE FOR write_change
void write_change(int Q, int D, int N, int P);

int main()
{
  double dollars(0.0);
  int cents(0), quarters(0), dimes(0), nickels(0), pennies(0);

  dollars = read_change();
  cents = convert2cents(dollars);

  cout << endl << "Making change for " << cents << " cents" << endl;

  quarters = change_quarters(cents);
  dimes = change_dimes(cents);
  nickels = change_nickels(cents);
  pennies = cents;
 
  write_change(quarters, dimes, nickels, pennies);

  return 0;
}

// DEFINE FUNCTION read_change HERE:
// function takes in no values and returns a dollar amount
// 'dollars' = user-inputted amount of money
double read_change()
{
  double dollars;

    cout << "Enter change in dollars ($): ";
    cin >> dollars;
    if (dollars < 0)	// output error to user if dollar amount is negative
      {
	cout << "Illegal negative value " << dollars << " for dollars." << endl;
	
	exit(0);  // exit program if user-input is negative
      }

  return dollars; // return positive dollar amount
}

// DEFINE FUNCTION convert2cents HERE:
// input is the double for dollar amount 
// output is the total dollar amount converted to cents
int convert2cents(double dollars)
{
  return dollars * 100;
}

// DEFINE FUNCTION change_quarters HERE:
// input is passed by reference for cent amount
// output is amount of whole quaters that can be used
int change_quarters(int& cents)
{
  int quarters = cents / 25;	// integer will divide cents by 25 and cut off the remainder without changing the integer out front
  cents -= (quarters * 25);		// cents will be decreased by the amount of quarters now being used

  return quarters;
}

// DEFINE FUNCTION change_dimes HERE:
// input is passed by reference for cent amount
// output is amount of whole dimes that can be used
int change_dimes(int& cents)
{
	int dimes = cents / 10;		// follows same process as in function 'change_quaters' but adjusting for dimes
	cents -= (dimes * 10);

	return dimes;
}  

// DEFINE FUNCTION change_nickels HERE:
// input is passed by reference for cent amount
// output is amount of whole nickels that can be used
int change_nickels(int& cents)
{
	int nickels = cents / 5;	// follows same process as in function 'change_quaters' but adjusting for nickels
	cents -= (nickels * 5);

	return nickels;
}

// DEFINE FUNCTION write_change HERE:
// output statement for number of quarters, dimes, nickels and pennies
// 'Q' = quarters
// 'D' = dimes
// 'N' = nickels
// 'P' = pennies
// only ouputs if the value is greater then 0
void write_change(int Q, int D, int N, int P)
{
  if (Q > 0)
    {
	cout << "Quaters: " << Q << endl;
    }
  if (D > 0)
    {
	cout << "Dimes: " << D << endl;
    }
  if (N > 0)
    {
	cout << "Nickels: " << N << endl;
    }
  if (P > 0)
    {
	cout << "Pennies: " << P << endl;
    }

  return;
}
