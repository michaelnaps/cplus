#include <iostream>
#include <string>
#include <vector>
using namespace std;

void create_el_vect() {
      ifstream fin_element;
      string temp_el;

      fin_element.open("element_list.txt");

      if (!fin_element.is_open()) { 
         cout << "ERROR: The element file did NOT open." << endl;
      }

      while (!fin_element.eof()) {
         fin_element >> temp_el;
         elements.push_back(temp_el);
      }
        
      fin_element.close();

      return;  // return nothing
   }
   void create_AMU_vect() {
      ifstream fin_MM;
      double temp_MM;
        
      fin_MM.open("MM_list.txt");

      if (!fin_MM.is_open()) { 
         cout << "ERROR: The molar mass file did NOT open." << endl;
         cout << "Check to see if the file is located in the appropriate folder." << endl;
      }

      while (!fin_MM.eof()) {
         fin_MM >> temp_MM;
         atomic_mass_units.push_back(temp_MM);
      }
        
      fin_MM.close();

      return;  // return nothing
   }
   string getEl(int n) { return elements[n]; }
   double getAMU(int n) { return atomic_mass_units[n]; }
   int getSize() {
      if (elements.size() == atomic_mass_units.size()) { return elements.size(); }
      else {
         cout << "Periodic table files do not match correctly." << endl; 
         return 1; 
      }
   }