// File: molarMass.cpp
// Created by: Michael Napoli
// Created on: 8/15/2019
// Last modified on: 8/15/2019

/* 
   Program that calculates the molar mass of compounds until
   the user enters "stop".
*/

#include <iostream>
#include "Chemistry.h"  // include file made by Michael Napoli
using namespace std;

int main()
{
   string temp_comp;  // string variable for the temporary compound name
   Chemistry user_comp;  // class type 'Chemistry' variable for the calculation of the molar mass

   // output statement telling user how to end the program
   cout << "Enter 'stop' when done with the program." << endl;

   // do-while loop that iterates until the user enters "stop"
   do {
      cout << "Enter compound: ";  // ask user for compound name
      cin >> temp_comp;  // input compound name into temporary variable

      user_comp.setCompound(temp_comp);  // place compound into 'Chemistry' variable

      // if user did not enter "stop"
      if (temp_comp != "stop") {
         // output to the user the molar mass of their compound
         cout << "Molar Mass of " << user_comp.getCompound();
         cout << " = " << user_comp.getMolarMass() << endl << endl;
      }
   } while (temp_comp != "stop");

   return 0;  // end program
}