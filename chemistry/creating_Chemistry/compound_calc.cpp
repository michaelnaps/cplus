// File: compound_calc.cpp
// Created by: Michael Napoli
// Created on: 7/26/2019
// Last modified on: 

/* 
Program that evaluates a given compound and computes the following:
-molar mass
-moles of compound present
-molarity with given volume
then writes the results to the user. 
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>
using namespace std;

class Periodic_table
{
private:
    vector<string> elements;
    vector<double> atomic_mass_units;

public:   // FINISH FIXING VECTOR CREATION ERRORS
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
    void create_MM_vect() {
        ifstream fin_MM;
        double temp_MM;
        
        fin_MM.open("MM_list.txt");

        if (!fin_MM.is_open()) { 
            cout << "ERROR: The molar mass file did NOT open." << endl;
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
};

class Chemistry
{
private:
    string compound;  // inputted compound
    double volume;  // volume of solution
    double mass;  // mass of sample size
    double molar_mass;  // molar mass of compound
    double moles;  // moles of sample size
    double molarity;  // molarity of sample solution
    Periodic_table PT;

public:
    void read_values();
    void setC(string temp_comp);
    void setM(double temp_mass);
    void setV(double temp_vol);

    void calc_molarMass();  // function at bottom of member function list
    void calc_moles();
    void calc_molarity();

    string getC() const;
    double getV() const;
    double getMM() const;
    double getMoles() const;
    double getMolatiry() const;

    void check_el(string el, double el_mass);  // helper function to 'calc_molarMass'
    int multiple_for_el(string el, int el_loc);  // helper function 'for check_el'
    
    void print_data();
};

int main()
{
    Chemistry comp;

    comp.read_values();

    comp.calc_molarMass();
    comp.calc_moles();
    comp.calc_molarity();

    comp.print_data();
 
    return 0;
}

// 'SET' MEMBER FUNCTIONS

// MEMBER FUNCTION (Chemsitry): read_values()
// member function that modifies the parameters of the given class type variable
void Chemistry::read_values()
{
    cout << "Enter compound: ";  // user-inputted compound
    cin >> compound;

    cout << "Enter mass: ";  // user-inputted mass
    cin >> mass;

    cout << "Enter volume: ";  // user-inputted volume
    cin >> volume;

    return;  // return nothing
}
// MEMBER FUNCTION (Chemsitry): setC()
void Chemistry::setC(string temp_comp)
{
    compound = temp_comp;  // use 'temp_comp' to assign value to 'compound'
    return;  // return nothing
}
// MEMBER FUNCTION (Chemsitry): setM()
void Chemistry::setM(double temp_mass)
{
    mass = temp_mass;  // use 'temp_mass' to assign value to 'mass'
    return;  // return nothing
}
// MEMBER FUNCTION (Chemsitry): setV()
void Chemistry::setV(double temp_vol)
{
    volume = temp_vol;  // use 'temp_vol' to assign value to 'volume'
    return;  // return nothing
}

// CALCULATION BASED MEMBER FUNCTION: calc_moles()
// member function that calculates moles
void Chemistry::calc_moles()
{ 
    moles = (mass / molar_mass);  // calculate moles using user-input values
    return;  // return nothing
}
// CALCULATION BASED MEMBER FUNCTION: calc_molarity()
// member function that calculates molarity
void Chemistry::calc_molarity()
{ 
    molarity = (moles / volume);  // calculate molarity using user-input values
    return;  // return nothing 
}

// 'GET' MEMBER FUNCTIONS
string Chemistry::getC() const
{ return compound; }  // return the string value of the compound

double Chemistry::getV() const
{ return volume; }  // return the volume inputted by the user

double Chemistry::getMM() const
{ return molar_mass; }  // return the molar mass of the inputted compound

double Chemistry::getMoles() const
{ return moles; }  // return the calculated value of moles

double Chemistry::getMolatiry() const
{ return molarity; }  // return the value of the molarity of the solution

// MOLAR MASS CALCULATOR AND HELPER FUNCTIONS
// takes the compound intputted by the user's Class variable
/*
    Runs a specific element and molar mass through the 'check_el' helper function
    which checks for the element within the compound string along with the amount of atoms
    of said element. This molar mass is added to the compound's molar mass for a total
    molar mass.
*/
void Chemistry::calc_molarMass()
{
    const EL_NUM(118);
    molar_mass = 0;
    PT.create_el_vect();
    PT.create_MM_vect();

    for (int i(0); i < EL_NUM; ++i) {
        check_el(PT.getEl(i), PT.getAMU(i));
    }

    return;  // return nothing
}

void Chemistry::check_el(string el, double el_mass)
{
    int multiple(1);  // multiple (1 if not otherwise specified)
    int el_loc;  // given elements location in the given compound

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

    return;  // return nothing
}

int Chemistry::multiple_for_el(string el, int el_loc)
{
    int multiple(1);
    stringstream num_out;  // stream variable for transferring between string and integer variable types

    if (isdigit(compound[el_loc + el.length()]))
    { 
        num_out << compound[el_loc + el.length()];
        num_out >> multiple; 
    }

    return multiple;
}

// Print data for the given compound variable
void Chemistry::print_data()
{
    cout << "--------------------------------" << endl;
    cout << setw(15) << left << "Compound: " << setw(20) << compound << endl;
    cout << setw(15) << left << "Molar Mass: " << setw(20) << molar_mass << endl;
    cout << setw(15) << left << "Mass Given: " << setw(20) << mass << endl;
    cout << setw(15) << left << "Moles: " << setw(20) << moles << endl;
    cout << setw(15) << left << "Volume: " << setw(20) << volume << endl;
    cout << setw(15) << left << "Molarity: " << setw(20) << molarity << endl;
    cout << "--------------------------------" << endl << endl;

    return;  // return nothing
}