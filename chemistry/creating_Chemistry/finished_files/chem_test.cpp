// chem_test.cpp
// Created by: Michael Napoli

#include <iostream>
#include <iomanip>
#include "Chemistry.h"
using namespace std;

int main() 
{
   Chemistry comp;
   Periodic_table PT;

   PT.create_PT();

   comp.setCompound("C12H34Ca");
   comp.setMass(2.23);
   comp.setVolume(0.500);

   cout << comp.getMolarMass() << endl;
   cout << comp.getMass() << endl;
   cout << comp.getMoles() << endl;
   cout << comp.getMolarity() << endl;
   cout << comp.getCompound() << endl;
   cout << PT.getSize() << endl;

   return 0;
}