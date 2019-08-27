// File: bodes_law.cpp
// Created by: Michael Napoli
// Created on: 6/14/2019

/* Program that creates a table of values for the distance of
   each planet from the Sun. */

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

#include <iostream>
#include <cmath>
using namespace std;
 
int main()
{
  const double au_to_miles(93000000);   // constant that converts astronomical units to miles
  const double miles_to_meters(1609.344);   // constant that converts miles to meters
	
  double dist_au_earth(0.0), dist_au_saturn(0.0), dist_au_neptune(0.0); // astronmical unit distances for earth, saturn, and neptune
	double dist_miles_earth(0.0), dist_miles_saturn(0.0), dist_miles_neptune(0.0);   // miles distances for earth, saturn, and neptun
	double dist_meters_earth(0.0), dist_meters_saturn(0.0), dist_meters_neptune(0.0);   // meter distances for earth, saturn, and neptun

	// calculate for distance from Sun in astronomical units
	dist_au_earth = (4.0 + 3.0 * pow(2.0, 3.0 - 2.0)) / 10.0;
	dist_au_saturn = (4.0 + 3.0 * pow(2.0, 6.0 - 2.0)) / 10.0;
	dist_au_neptune = (4.0 + 3.0 * pow(2.0, 8.0 - 2.0)) / 10.0;
	
	// calculate distance in miles
	dist_miles_earth = dist_au_earth * au_to_miles;
	dist_miles_saturn = dist_au_saturn * au_to_miles;
	dist_miles_neptune = dist_au_neptune * au_to_miles;

	// calculate distance in meters
	dist_meters_earth = dist_miles_earth * miles_to_meters;
	dist_meters_saturn = dist_miles_saturn * miles_to_meters;
	dist_meters_neptune = dist_miles_neptune * miles_to_meters;	
	
	cout.precision(3);   // set precision to 3 digits
	cout.setf(ios::scientific);   // make all numbers shown in scientific

	// output statements that show the necessary amount of significant figures with spaces so
	// that the table display orderly
	cout << endl << "Planet" << setw(20) << "Astro Units (est.)" 
	     << setw(14) << "Miles (est.)" << setw(15) << "Meters (est.)" << endl ;
	cout << "----------------------------------------" << endl;
	cout << "Earth" << setprecision(3) << setw(14) << dist_au_earth 
	     << setprecision(2) << setw(21) << dist_miles_earth 
	     << setprecision(3) << setw(15) << dist_meters_earth << endl ;
	cout << "Saturn"  << setprecision(3) << setw(13) << dist_au_saturn 
	     << setprecision(2) << setw(21) << dist_miles_saturn 
	     << setprecision(3) << setw(15) << dist_meters_saturn << endl;
	cout << "Neptune" << setprecision(3) << setw(12) << dist_au_neptune 
	     << setprecision(2) << setw(21) << dist_miles_neptune 
	     << setprecision(3) << setw(15) << dist_meters_neptune << endl ;
	
	cout.unsetf(ios::scientific);   // stop showing all numbers in scientific

	return 0;
}  
