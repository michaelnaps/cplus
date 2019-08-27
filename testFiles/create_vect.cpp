// File: create_vects.cpp
// Created by: Michael Napoli
// Created on: 8/5/2019

/* Program that reads outisde files and creates appropriate vectors. */

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main()
{
   ifstream fin_elements;
   vector <string> elements;
   string temp_el;
   
   fin_elements.open("element_list.txt");
   
   if (!fin_elements.is_open()) {
      cout << "ERROR: File did not open." << endl;
      return 10;
   }

   while (!fin_elements.eof()) {
      fin_elements >> temp_el;
      elements.push_back(temp_el);
   }

   fin_elements.close();

   for (int i(0); i < elements.size(); ++i) {
      cout << elements[i] << " ";
   }
   cout << endl;

   return 0;
}