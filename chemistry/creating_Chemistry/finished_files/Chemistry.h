// File: Chemistry.h
/*
   Purpose: Include file that incorporates chemistry calculations
   into the basic C++ programming system.

   Capabilities:
      -calculate molar mass of given compound
      -calculate moles with given compound and mass of sample
      -calculate molarity using moles and entered volume
*/
// Created on: 8/6/2019
// Last modified on: 8/15/2019

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
using namespace std;

/* 
   Class type that creates a useable periodic table containing:
      -abreviated element name
      -amu of specified element
   This periodic table is contained in two vectors and is NON-modifiable
*/
class Periodic_table
{
private:
   vector<string> elements;  // vector for element name strings
   vector<double> atomic_mass_units;  // vector for amu values

   // helper member function that add components of the periodic table to the appropriate vectors (private)
   void create_PT_vects(string el, double amu) {
      elements.push_back(el);
      atomic_mass_units.push_back(amu);
   }

public:
   /* member function that creates both the 'elements' vector and the 'atomic_mass_units' vector
      in the correct order according to the periodic table */
   void create_PT()
   {
      if (elements.size() == 0) {  // if vectors have not been created yet, create
         create_PT_vects("H", 1.0079);
         create_PT_vects("He", 4.0026);
         create_PT_vects("Li", 6.941);
         create_PT_vects("Be", 9.0122);
         create_PT_vects("B", 10.811);
         create_PT_vects("C", 12.011);
         create_PT_vects("N", 14.007);
         create_PT_vects("O", 15.999);
         create_PT_vects("F", 18.998);
         create_PT_vects("Ne", 20.180);
         create_PT_vects("Na", 22.990);
         create_PT_vects("Mg", 24.305);
         create_PT_vects("Al", 26.982);
         create_PT_vects("Si", 28.086);
         create_PT_vects("P", 30.974);
         create_PT_vects("S", 32.065);
         create_PT_vects("Cl", 35.453);
         create_PT_vects("Ar", 39.948);
         create_PT_vects("K", 39.098);
         create_PT_vects("Ca", 40.078);
         create_PT_vects("Sc", 44.956);
         create_PT_vects("Ti", 47.886);
         create_PT_vects("V", 50.942);
         create_PT_vects("Cr", 51.996);
         create_PT_vects("Mn", 54.938);
         create_PT_vects("Fe", 55.845);
         create_PT_vects("Co", 58.933);
         create_PT_vects("Ni", 58.693);
         create_PT_vects("Cu", 63.546);
         create_PT_vects("Zn", 65.409);
         create_PT_vects("Ga", 69.723);
         create_PT_vects("Ge", 72.64);
         create_PT_vects("As", 74.922);
         create_PT_vects("Se", 78.96);
         create_PT_vects("Br", 79.904);
         create_PT_vects("Kr", 83.798);
         create_PT_vects("Rb", 85.468);
         create_PT_vects("Sr", 87.62);
         create_PT_vects("Y", 88.906);
         create_PT_vects("Zr", 91.224);
         create_PT_vects("Nb", 92.906);
         create_PT_vects("Mo", 95.94);
         create_PT_vects("Tc", 98);
         create_PT_vects("Ru", 101.07);
         create_PT_vects("Rh", 102.91);
         create_PT_vects("Pd", 106.42);
         create_PT_vects("Ag", 107.87);
         create_PT_vects("Cd", 112.41);
         create_PT_vects("In", 114.82);
         create_PT_vects("Sn", 118.71);
         create_PT_vects("Sb", 121.76);
         create_PT_vects("Te", 127.60);
         create_PT_vects("I", 126.904);
         create_PT_vects("Xe", 131.294);
         create_PT_vects("Cs", 132.91);
         create_PT_vects("Ba", 137.33);
         create_PT_vects("La", 138.91);
         create_PT_vects("Ce", 140.12);
         create_PT_vects("Pr", 140.91);
         create_PT_vects("Nd", 144.24);
         create_PT_vects("Pm", 145);
         create_PT_vects("Sm", 150.36);
         create_PT_vects("Eu", 151.96);
         create_PT_vects("Gd", 157.25);
         create_PT_vects("Tb", 158.93);
         create_PT_vects("Dy", 162.50);
         create_PT_vects("Ho", 164.93);
         create_PT_vects("Er", 167.26);
         create_PT_vects("Tm", 168.93);
         create_PT_vects("Yb", 173.04);
         create_PT_vects("Lu", 174.97);
         create_PT_vects("Hf", 178.49);
         create_PT_vects("Ta", 180.95);
         create_PT_vects("W", 183.84);
         create_PT_vects("Re", 186.21);
         create_PT_vects("Os", 190.23);
         create_PT_vects("Ir", 192.217);
         create_PT_vects("Pt", 195.085);
         create_PT_vects("Au", 196.967);
         create_PT_vects("Hg", 200.592);
         create_PT_vects("Tl", 204.383);
         create_PT_vects("Pb", 207.2);
         create_PT_vects("Bi", 208.980);
         create_PT_vects("Po", 208.982);
         create_PT_vects("At", 209.987);
         create_PT_vects("Rn", 222.018);
         create_PT_vects("Fr", 223.020);
         create_PT_vects("Ra", 226.025);
         create_PT_vects("Ac", 227.028);
         create_PT_vects("Th", 232.038);
         create_PT_vects("Pa", 231.036);
         create_PT_vects("U", 238.029);
         create_PT_vects("Np", 237.048);
         create_PT_vects("Pu", 244.064);
         create_PT_vects("Am", 243.061);
         create_PT_vects("Cm", 247.070);
         create_PT_vects("Bk", 247.070);
         create_PT_vects("Cf", 251.080);
         create_PT_vects("Es", 254);
         create_PT_vects("Fm", 257.095);
         create_PT_vects("Md", 258.1);
         create_PT_vects("No", 259.101);
         create_PT_vects("Lr", 262);
         create_PT_vects("Rf", 261);
         create_PT_vects("Db", 262);
         create_PT_vects("Sg", 266);
         create_PT_vects("Bh", 264);
         create_PT_vects("Hs", 269);
         create_PT_vects("Mt", 278);
         create_PT_vects("Ds", 281);
         create_PT_vects("Rg", 280);
         create_PT_vects("Cn", 285);
         create_PT_vects("Nh", 286);
         create_PT_vects("Fl", 289);
         create_PT_vects("Mc", 289);
         create_PT_vects("Lv", 293);
         create_PT_vects("Ts", 294);
         create_PT_vects("Og", 294);
      }
   }
   // return element based on number of protons
   string getEl(int n) const { return elements[n - 1]; }
   // return amu value based on number of protons
   double getAMU(int n) const { return atomic_mass_units[n - 1]; }
   // return size of periodic table (how many elements are present)
   int getSize() const {
      if (elements.size() == atomic_mass_units.size()) { return atomic_mass_units.size(); }
      else {
         cout << "ERROR: Periodic table values do not match correctly." << endl; 
         return 1; 
      }
   }
};

/*
   Class type that's member variables contain:
      -a compound name
      -the compound's molar mass
      -the mass of a given sample
      -the moles of a given sample
      -the volume of the solution the given sample is a part of
      -the molarity of the given solution
      -a variable made of the 'Periodic_table' class type
   This class type can be used for solving chemical equations and/or
   doing reaction stoichiometry
*/
class Chemistry
{
private:
   string compound;  // inputted compound
   double volume;  // volume of solution
   double mass;  // mass of sample size
   double molar_mass;  // molar mass of compound
   double moles;  // moles of sample size
   double molarity;  // molarity of sample solution
   Periodic_table PT;  // periodic table vectors (element names and respective AMU)
	const double EPSILON;
   
   // CALCULATION MEMBER FUNCTIONS (private)

   // calculates mass based on available values
   // if not possible, returns the appropriate error message
   void calc_mass() {
      if (fabs(moles) > EPSILON && fabs(molar_mass) > EPSILON) { mass = (moles * molar_mass); }
      else if (fabs(molarity) > EPSILON && fabs(molar_mass) > EPSILON && fabs(volume) > EPSILON) { mass = ((molarity * volume) * molar_mass); }
      else { 
         cout << "ERROR: There is not enough information to solve for mass." << endl;
         mass = 0;
      }
   }
   // calculates moles based on available values
   // if not possible, returns appropriate error message
   void calc_moles() {
      if (fabs(molarity) > EPSILON && fabs(volume) > EPSILON) { moles = (molarity * volume); }
      else if (fabs(molar_mass) > EPSILON && fabs(mass) > EPSILON) { moles = (mass / molar_mass); }
      else { 
         cout << "ERROR: There is not enough information to solve for moles." << endl;
         moles = 0;
      }
   }
   // calculates molarity based on available values
   // if not possible, returns appropriate error message
   void calc_molarity() {
      if (fabs(moles) > EPSILON && fabs(volume) > EPSILON) { molarity = (moles / volume); }
      else if (fabs(volume) > EPSILON && fabs(mass) > EPSILON && fabs(molar_mass) > EPSILON) { molarity = ((mass / molar_mass) / volume); }
      else { 
         cout << "ERROR: There is not enough information to solve for molarity." << endl;
         molarity = 0;
      }
   }
   // calculates molar mass based on the 'compound' string
   void calc_molarMass() {
      molar_mass = 0;
      PT.create_PT();

      for (int proton_num(1); proton_num <= PT.getSize(); ++proton_num) {
         check_el(PT.getEl(proton_num), PT.getAMU(proton_num));
      }
   }
   // runs check for all possible elements within the 'compound' string
   // utilizes 'multiple' variable in order to scale appropriate elements
   // utilizes if statements to evaluate mono and poly abreviated elements
   void check_el(string el, double el_mass) {
      int multiple(1);  // multiple (1 if not otherwise specified)
      int el_loc(-1);  // given elements location in the given compound

      if (el.length() == 1) {
         if (compound.find(el) != string::npos && 
         (isupper(compound[compound.find(el) + 1]) || isdigit(compound[compound.find(el) + 1]) ||
         (compound.find(el) == compound.length() - 1)))
         {
            el_loc = compound.find(el);
            multiple = multiple_for_el(el, el_loc);
            molar_mass += (multiple * el_mass);
         }
         else if (compound.find(el, 2) != string::npos &&
         (isupper(compound[compound.find(el, 2) + 1]) || isdigit(compound[compound.find(el, 2) + 1]) ||
         (compound.find(el) == compound.length() - 1)))
         {
            el_loc = compound.find(el, 2);
            multiple = multiple_for_el(el, el_loc);
            molar_mass += (multiple * el_mass);
         }
      }
      else if (el.length() == 2) {
         if (compound.find(el) != string::npos)
         {
            el_loc = compound.find(el);
            multiple = multiple_for_el(el, el_loc);
            molar_mass += (multiple * el_mass);
         }
      }

      multiple = 1;  // set multiple back to 1
   }
   // helper member function that checks for multiples within the 'compound' string
   int multiple_for_el(string el, int el_loc) {
      int multiple(1);
      stringstream num_out;  // stream variable for transferring between string and integer variable types

      num_out.str(std::string());  // clears string stream variable

      if (isdigit(compound[el_loc + el.length()])) { 
         if (isdigit(compound[el_loc + el.length() + 1])) { 
            num_out << compound[el_loc + el.length()];
            num_out << compound[el_loc + el.length() + 1];
         }
         else { num_out << compound[el_loc + el.length()]; }
         num_out >> multiple; 
      }

      return multiple;
   }

public:
   // Initialize member variables
   Chemistry() : compound("X"), volume(0), mass(0), molar_mass(0), moles(0), molarity(0),
	EPSILON(1.2E-8)
   { }

   // SET MEMBER FUNCTIONS
   // if the given value is 0 or 'X', the value of the function will be calculated using available data
   
   void setCompound(string temp_compound) { 
      string c(compound);  // to judge whether or not the initial compound is being changed from a previous version
      compound = temp_compound;
      if (c != compound) { this->calc_molarMass(); }  // if it is being changed, calculate new molar mass
   }
   void setVolume(double temp_volume) { 
      volume = temp_volume; 
   }
   void setMass(double temp_mass) { 
      if (fabs(temp_mass) > EPSILON) { mass = temp_mass; }
      else { this->calc_mass(); }
   }
   void setMolarMass(double temp_MM) {
      if (fabs(temp_MM) > EPSILON) { molar_mass = temp_MM; }
      else { this->calc_molarMass(); }
   }
   void setMoles(double temp_moles) { 
      if (fabs(temp_moles) > EPSILON) { moles = temp_moles; }
      else { this->calc_moles(); }
   }
   void setMolarity(double temp_molarity) {
      if (fabs(temp_molarity) > EPSILON) { molarity = temp_molarity; }
      else { this->calc_molarity(); }
   }

   // GET MEMBER FUNCTIONS
   // if the value being called is not present, it is calculated using the 'set' member function
   string getCompound() const {
      if (compound != "X") { return compound; }
      else { cout << "ERROR: No compound was entered. " << endl; }
   }
   double getMass() {
      if (fabs(mass) > EPSILON) { return mass; }
      else {
         this->setMass(0);
         return mass;
      }
   }
   double getVolume() {
      if (fabs(volume) > EPSILON) { return volume; }
      else {
         this->setVolume(0);
         return volume;
      }
   }
   double getMolarMass() {
      if (fabs(molar_mass) > EPSILON) { return molar_mass; }
      else { 
         this->calc_molarMass();
         return molar_mass;
      }
   }
   double getMoles() {
      if (fabs(moles) > EPSILON) { return moles; }
      else {
         this->setMoles(0);
         return moles;
      }
   }
   double getMolarity() {
      if (fabs(molarity) > EPSILON) { return molarity; }
      else {
         this->setMolarity(0);
         return molarity;
      }
   }
   
   void getCommands() {
      cout << "Get/Set options:" << endl;
      cout << "-Compound  -MolarMass  -Volume  -Moles  -Molarity" << endl << endl;
      cout << "The 'variableName.getReturnOption()' returns the value of the appropriate variable." << endl;
      cout << "If the value should be calculated instead of set, enter '0' into the function call." << endl << endl;
      cout << "The 'variableName.setReturnOption()' returns the value of the appropriate variable." << endl;
      cout << "If the value has not been set yet, the program attempts to calculate it. If that is not possible it displays an error." << endl << endl;
		cout << "NOTE: Molarities smaller than 1.2e-8 are not recordable in the current version of this include file." << endl;
   }
};