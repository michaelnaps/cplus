// Homework 3
// File: poly.cpp
// Created by: Michael Napoli
// Created on: 2/4/2020
// Last modified on: 2/11/2020

/*
   Purpose: Test file for the 'Poly' class type
      Polynomial functions will be entered by their coefficient into
      a given array. The indexes of the coefficients within the array
      will be indexed by their degree of polynomial.

      For example:
         If a polynomial is 7x^3 it will be indexed in the 'coeff' array
         as such: "coeff[3] = 7;"

      The user of this class type can use operators to add and subtract
      polynomials. As well as compare polynomials using the boolean '=='

      The user can also output the polynomials in the format (kx^n)
      where k is a coefficient and n is the given degree.
*/

#include <iostream>
using namespace std;

// Default size of the dynamic coefficient array
const int DEFAULTPOLY = 10;

// Do NOT modify the class header.
class Poly
{
private:
   // Data members
   int arraySize;    // size of array
   int *coeff;       // dynamic array

public:
   // CLASS CONSTRUCTORS:

   // Default Class constructor
   // If the user does not declare any values at initialization the
   // 'coeff' array will be initialized to size 10 with all values 0.
   Poly() {
      // set 'arraySize' to default
      arraySize = DEFAULTPOLY;

      // create array of default size
      coeff = new int [arraySize];

      // set all values to 0
      for (int i(0); i < arraySize; ++i) {
         coeff[i] = 0;
      }
   }

   // Non-default (alternate) Class constructor
   // If the user initializes the 'Poly' variable with an integer it
   // automatically sets the array size of 'coeff' to the given value.
   Poly(int size) {
      // set 'arraySize' to given value
      arraySize = size;

      // allocate memory for dynamic array
      coeff = new int [arraySize];

      // set values of array elements to 0
      for (int i(0); i < arraySize; ++i) {
         coeff[i] = 0;
      }
   }

   // Copy constructor
   // If the user initializes a 'Poly' variable with another 'Poly'
   // variable, the new variable is equal to that of the first.
   Poly(const Poly& aPoly) {
      // call '=' operator
      this->operator=(aPoly);
   }

   // CLASS DESTRUCTOR:

   // Automatically called when a 'Poly' variable leaves a local funtion
   // Destroy a poly object by freeing the dynamically allocated array
   ~Poly() {
      // deallocate memory for 'coeff' array and set to NULL
      delete [] coeff;
      coeff = nullptr;
   }

   // Assignment operator
   // Assign 'aPoly' Poly object to 'this' Poly object
   // Note: This function is provided, please do not modify it
   const Poly& operator=(const Poly& aPoly);

   // MEMBER FUNCTIONS:

   // member function: grow()
   // Function that takes the polynomial variable and a new arraysize to
   // increase the number of allocated memory spaces to the new larger value.
   // input:
   // an already initialzed 'Poly' variable
   // 'newSize' - the desired new size of the 'coeff' array
   void grow(int newSize) {
      int oldSize(arraySize);  // variable for the previous size of the coefficient array
      int* temp_arr;  // pointer variable for the temporary coefficient array

      // if the given array size is equal to or less than the current
      if (newSize <= arraySize) {
         return;  // return nothing (no changes)
      }

      // otherwise, allocate memory to the temporary array (old size)
      temp_arr = new int [arraySize];

      // create copy of old array
      for (int i(0); i < arraySize; ++i) {
         temp_arr[i] = coeff[i];
      }

      // deallocate memory from old array
      delete [] coeff;
      coeff = nullptr;

      // set 'arraySize' to the new given size
      arraySize = newSize;

      // set 'coeff' array to the new size given
      coeff = new int [arraySize];

      // initialize new array elements to '0'
      for (int i(0); i < arraySize; ++i) {
         coeff[i] = 0;
      }

      // copy coefficient data back into the original array
      for (int i(0); i < oldSize; ++i) {
         coeff[i] = temp_arr[i];
      }

      // deallocate memory from the temporary array
      delete [] temp_arr;
      temp_arr = nullptr;

      return;  // return nothing
   }

   // member function: degree()
   // Function that returns the largest degree value in the coefficient array.
   // input:
   // an already initialized 'Poly' variable
   // output:
   // largest degree value with a non-zero coefficient
   int degree() const {
      int deg(0);  // variable for the largest polynomial degree in the 'coeff' array

      for (int i(0); i < arraySize; ++i) {
         // if the index value is greater than 'deg'
         if (coeff[i] != 0 && i > deg) {
            deg = i;  // replace the current 'deg' value with the larger polynomial
         }
      }

      return deg;  // return the largest polynomial value
   }

   // member function: setCoeff()
   // Function that takes a coefficient value and the degree index to
   // add to the 'coeff' array.
   // input:
   // an already initialized 'Poly' variable
   // 'value' - the coefficient value to be placed in the array
   // 'i' - the degree of the coefficient, also the index in the 'coeff' array
   void setCoeff(int value, int i) {
      // if 'i' is negative
      if (i < 0) {
         return;  // return without adding coefficient to array
      }

      // if the index given is outside array bounds
      if (i > (arraySize - 1)) {
         this->grow(i + 1);  // grow the array appropriately
      }

      // set the necessary 'coeff' index to the given value
      coeff[i] = value;

      return;  // return nothing
   }

   // member function: getCoeff()
   // Function that returns the coefficient located in the 'coeff' array
   // at the given index with the equal degree value.
   // input:
   // an already initalized 'Poly' variable
   // 'i' - the degree of the coefficient, also the index in the 'coeff' array
   // output:
   // value of the coefficient with the given degree index
   int getCoeff(int i) const {
      // if index is negative
      if (i < 0) {
         return 0;  // return 0
      }

      // if the desired coefficient is not a part of the current array
      if (i > (arraySize - 1)) {
         return 0;
      }

      // if parameters are correct, return the correct coefficient
      return coeff[i];
   }

   // member function: negate()
   // Function that changes all variables in the 'coeff' array to
   // the same value multiplied by -1.
   // input:
   // an already initialized 'Poly' variable
   void negate() {
      // set all coefficients to itself multiplied by -1
      for(int i(0); i < arraySize; ++i) {
         coeff[i] *= -1;
      }

      return;  // return nothing
   }

   // FRIEND FUNCTIONS: (all function definitions located below)

   // addition operator
   friend Poly operator+(const Poly& aPoly, const Poly& bPoly);

   // subtraction operator
   friend Poly operator-(const Poly& aPoly, const Poly& bPoly);

   // equality operator
   friend bool operator==(const Poly& aPoly, const Poly& bPoly);

   // insertion operator for output
   friend ostream& operator<<(ostream& out, const Poly &aPoly);
};

int main(){
   Poly poly1, poly2;  // variables for the testing of the 'Poly' class
   int numCoeff, coeffValue, coeffDegree, x;  // input variables for users

   // prompt user for the number of coefficients
   cout << "How many coefficients for polynomial 1?" << endl;
   cin >> numCoeff;
   for (int i=0; i<numCoeff; ++i){
      cout << "Coefficient " << i+1 << " for polynomial 1:";
      cin >> coeffValue >> coeffDegree;
      poly1.setCoeff(coeffValue, coeffDegree);
   }

   cout << endl << "How many coefficients for polynomial 2?" << endl;
   cin >> numCoeff;
   for (int i=0; i<numCoeff; ++i){
      cout << "Coefficient " << i+1 << " for polynomial 2:";
      cin >> coeffValue >> coeffDegree;
      poly2.setCoeff(coeffValue, coeffDegree);
   }

   // Sample test cases for degree() and operator<<
   cout << endl << "Polynomial 1 = " << poly1 << endl;
   cout << "Polynomial 1 has degree " << poly1.degree() << endl;
   cout << "Polynomial 2 = " << poly2 << endl;
   cout << "Polynomial 2 has degree " << poly2.degree() << endl;

   // Sample test cases for operator+ and operator-
   cout << endl << "Polynomial 1 + Polynomial 2 = " << poly1 + poly2 << endl;
   cout << "Polynomial 1 - Polynomial 2 = " << poly1 - poly2 << endl << endl;

   // Sample test cases for operator==
   if (poly1==poly2)
      cout << "Two polynomials are the same." << endl;
   else
      cout << "Two polynomials are different." << endl;

   // test degree of polynomial when the array size is greater than the polynomial degree
   Poly degree_test(15);  // set size to 15 on initialization
   degree_test.setCoeff(1, 10);  // should return degree 10 on output
   cout << endl << "Degree of test polynomial: " << degree_test.degree() << endl << endl;

   // test the copy operator by initializing to an already declared polynomial
   Poly poly1_copy(poly1);
   if (poly1 == poly1_copy) {
      cout << "SUCCESS: copy of poly1 = " << poly1_copy << endl;
   }
   else {
      cout << "ERROR in the copy constructor" << endl;
   }

   // end program
   return 0;
}

// Do not modify this function
const Poly& Poly::operator=(const Poly& aPoly){
   if (this==&aPoly)
      return *this;

   if (coeff)
      delete [] coeff;
      arraySize = aPoly.arraySize;
      coeff = new int[arraySize];
      for (int i=0; i<arraySize; ++i){
      coeff[i] = aPoly.getCoeff(i);
   }
   return *this;
}

// FRIEND FUNCTION DEFINITIONS:

// '+' operator function
// When called by the user, add the coefficients of two polynomials together.
// input:
// Two already initialized 'Poly' variables
// output:
// A single 'Poly' variables made from the sum of the two given functions
Poly operator+(const Poly& aPoly, const Poly& bPoly) {
   Poly poly_return;  // intialize the return polynomial
   int temp_arraySize(0);  // variable for the maximum array size

   // see which of the two arrays is largest
   // apply largest value to size variable and grow the smaller polynomial to proper size
   if (aPoly.arraySize > bPoly.arraySize) {
      temp_arraySize = aPoly.arraySize;
   }
   else {
      temp_arraySize = bPoly.arraySize;
   }

   // grow 'poly_return' to the largest array size for 'aPoly' and 'bPoly'
   poly_return.grow(temp_arraySize);

   // add appropriate elements of coefficient arrays
   for (int i(0); i < temp_arraySize; ++i) {
      // if the index exceeds any of the constant array bounds
      // make the return coefficient equal to the other polynomial
      if (i > (aPoly.arraySize - 1)) {
         poly_return.coeff[i] = bPoly.coeff[i];
      }
      else if (i > (bPoly.arraySize - 1)) {
         poly_return.coeff[i] = aPoly.coeff[i];
      }
      // otherwise add the polynomial's coefficient values together
      else {
         poly_return.coeff[i] = aPoly.coeff[i] + bPoly.coeff[i];
      }
   }

   // return the new polynomial function
   return poly_return;
}

// '-' operator function
// When the operator is called, all coefficient values will be subtracted from one another.
// input:
// Two already declared 'Poly' variables
// output:
// A single 'Poly' function made from the subtraction of 'bPoly' from 'aPoly'
Poly operator-(const Poly& aPoly, const Poly& bPoly) {
   Poly poly_return;  // intialize the return polynomial
   int temp_arraySize(0);  // variable for the maximum array size

   // see which of the two arrays is largest
   // apply largest value to size variable and grow the smaller polynomial to proper size
   if (aPoly.arraySize > bPoly.arraySize) {
      temp_arraySize = aPoly.arraySize;
   }
   else {
      temp_arraySize = bPoly.arraySize;
   }

   // grow 'poly_return' to the largest array size for 'aPoly' and 'bPoly'
   poly_return.grow(temp_arraySize);

   // subtract appropriate elements of coefficient arrays
   for (int i(0); i < temp_arraySize; ++i) {
      // if the index exceeds any of the constant array bounds
      // make the return coefficient equal to the other polynomial
      if (i > (aPoly.arraySize - 1)) {
         poly_return.coeff[i] = -1 * bPoly.coeff[i];
      }
      else if (i > (bPoly.arraySize - 1)) {
         poly_return.coeff[i] = aPoly.coeff[i];
      }
      // otherwise add the polynomial's coefficient values together
      else {
         poly_return.coeff[i] = aPoly.coeff[i] - bPoly.coeff[i];
      }
   }

   // return the new polynomial function
   return poly_return;
}

// '==' operator function
// When called, will evaluate two 'Poly' variables for equality
// input:
// Two already initialized 'Poly' variables
// output:
// true if the polynomials are equal
// false if the polynomials are not equal
bool operator==(const Poly& aPoly, const Poly& bPoly) {
   int temp_arraySize(0);

   // see which of the two arrays is largest
   // apply largest value to size variable and grow the smaller polynomial to proper size
   if (aPoly.arraySize >= bPoly.arraySize) {
      temp_arraySize = aPoly.arraySize;
   }
   else {
      temp_arraySize = bPoly.arraySize;
   }

   // check that all coefficient values are equal for the two polynomial functions
   for (int i(0); i < temp_arraySize; ++i) {
      // if any value is not equal to the other
      if (aPoly.coeff[i] != bPoly.coeff[i]) {
         return false;  // return false
      }
   }

   // if the loop iterates completely, return true
   return true;
}

// '<<' operator function
// When called, will output the polynomial function given.
// input:
// already initialized 'Poly' variable
// output stream variable
ostream& operator<<(ostream& out, const Poly &aPoly) {
   int count(0);  // variable used to evaluate need for '+' sign

   // iterate from the largest polynomial value 0
   for (int i(aPoly.degree()); i > -1; --i) {
         if (aPoly.coeff[i] != 0) {
            // if this is not the first output, output a '+' sign before the coefficient value
            if (count != 0 && aPoly.coeff[i] > 0) {
               out << '+';
            }

            // if the index is 0, output only the coefficient
            if (i == 0) {
               out << aPoly.coeff[i];
               ++count;
            }
            // or, if the degree is 1, only output 'x' for the polynomial value
            else if (i == 1) {
               out << aPoly.coeff[i] << "x";
               ++count;
            }
            // otherwise, output the coefficient multiplied by x to the appropraite power
            else {
               out << aPoly.coeff[i] << "x^" << i;
               ++count;
            }
      }
   }

   // if there are no non-zero coefficients, output 0
   if (count == 0) {
      out << 0;
   }

   // exit function
   return out;
}
