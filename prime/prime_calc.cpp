// File: prime_calc.cpp
// Created by: Michael Napoli
// Created on: 2/8/2021
// Last modified on: 2/8/2021

/*
   Purpose: Continue calculating prime numbers until program is exited.
   Output prime numbers to '.txt' file and resume from the last number on
   next start up.
*/

#include <iostream>
#include <fstream>
using namespace std;

bool check_prime(const int& n) {
   for (int i(1); i < (n / 2); ++i) {
      if (n % i == 0) { return false; }
      else { return true; }
   }
}

int main()
{
   uint64_t n(1);  // iteration variable for number count

   fstream fout;  // output file id
   string filename = "save.txt";  // for external prime number file

   fout.open(filename.c_str(), fstream::in | fstream::out | fstream::app);

   if (fout.is_open()) { cout << "Save file opened successfully." << endl; }
   else { cout << "ERROR: Save file did not open correctly." << endl; }

   while(fout.is_open())
   {
      if (check_prime(n)) {
         cout << n << endl;
         fout << n << endl;
      }

      n += 2;
   }

   fout.close();

   return 0;
}
