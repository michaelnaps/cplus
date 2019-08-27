// File: single_rep.cpp
// Created by: Michael Napoli
// Created on: 8/9/2019
// Last modified on: 

/* 
   Program that takes in two compounds and returns
   the resultant single replacement reaction. 
*/

#include <iostream>
#include <string>
#include "Chemistry.h"
using namespace std;

bool check_compound_or_element(string test_str);

int main()
{
   Chemistry reactant_1, reactant_2;
   Chemistry product_1, product_2;
   string temp_comp;
   bool TF_1, TF_2;

   do {
      cout << "Enter two reactants." << endl;
      cout << "A single element (first) and a compound (second): ";
      cin >> temp_comp; reactant_1.setCompound(temp_comp);
      cin >> temp_comp; reactant_2.setCompound(temp_comp);

      TF_1 = check_compound_or_element(reactant_1.getCompound());
      TF_2 = check_compound_or_element(reactant_2.getCompound());

      if (!TF_1 && !TF_2)
      { cout << "ERROR: Please enter a single element and a compound." << endl; }

   } while (!TF_1 && !TF_2);

   return 0;
}

bool check_compound_or_element(string test_str)
{
   int count(0);

   for (int i(0); i < test_str.length(); ++i) {
      if (isupper(test_str[i])) { ++count; }
      if (count > 1) { return false; }
   }

   return true;
}