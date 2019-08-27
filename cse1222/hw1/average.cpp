// File: average.cpp
// Created by: Naeem Shareef
// Modified by: Michael Napoli
// Modified on: 5/14/19

/* A program to compute the averages of 3,5,8 and 
   of 4,6,13 and of 7,9,13,14 and output the 
   three averages on separate lines.
*/

#include <iostream>
using namespace std;

int main()
{
	/* Averages were given decimals so as to accurately 
	display their value instead of a truncated integer. */

	cout << "The average of 3, 5 and 8 is: " 
		<< (3.0+5.0+8.0)/3.0 << endl;
	cout << "The average of 4, 6 and 13 is: " 
		<< (4.0+6.0+13.0)/3.0 << endl;
	cout << "The average of 7,9,13 and 14 is: " 
		<< (7.0+9.0+13.0+14.0)/4.0 << endl;

return 0;
}
