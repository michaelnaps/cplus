// Homework 3
// File: poly.cpp
// Created by: Michael Napoli
// Created on: 2/4/2020
// Last modified on:

/*
   Purpose: Test file for the polynomial class type 'Poly'
      This class type will utilize a dynamic array and member functions to maintain
      the data for a given polynomial function.
*/

#include <iostream>
using namespace std;

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
   // Allocate an array of DEFAULTPOLY elements and initialize it to the constant 0
   // post: Class object is initialized to degree-0 polynomial of 0
   Poly() {
      // set 'arraySize' to default size 10
      arraySize = 10;

      // create array of default size
      coeff = new int [arraySize];

      // set all values to 0
      for (int i(0); i < arraySize; ++i) {
         coeff[i] = 0;
      }
   }

   // Non-default (alternate) Class constructor
   // Allocate an array of 'size' elements and initializes it to the constant 0
   // post: Class object is initialized to degree-0 polynomial of 0
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
   // Construct a new Poly that is a copy of an existing Poly
   // post: Class object is initialized to be a copy of the argument Poly
   Poly(const Poly& aPoly) {
      this->operator=(aPoly);
   }

   // CLASS DESTRUCTOR:

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
   // This method will allow us to increase the size of the dynamically allocated
   // array by allocating a new array of the desired size, copying the data from
   // the old array to the new array, and then releasing the old array.
   // If the newSize is less than or equal to the current size, then no actions
   // are taken.
   // Note: the maximum degree of a polynomial is one less than the size of the
   // array. The parameter newSize represents the size of the array.
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
   // Finds the degree of a polynomial (the highest power with a non-zero
   // coefficient)
   // pre: Class object exists
   // post: Returns the degree of the polynomial object.
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
   // Sets a term, value*x^i, in a polynomial, growing the array if necessary.
   // pre: Class object has been initialized. i is a non-negative integer.
   // post: In the polynomial, the term with power i has coefficient
   //       value. The polynomical was grown if required.
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
   // Finds the coefficient of the x^i term in poly
   // pre: Class object has been initialized. i is a non-negative integer.
   // post: Returns the value of the coefficient of the term with power i
   // note: If the object does not contain a term with power i (e.g.,
   //       i >= arraySize), a coefficient value of zero is returned.
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
   // Negate a polynomial
   // pre: The class object has been initialized.
   // post: The polynomial has been changed to represent its
   //       multiplication by -1.
   void negate() {
      // set all coefficients to itself multiplied by -1
      for(int i(0); i < arraySize; ++i) {
         coeff[i] *= -1;
      }

      return;  // return nothing
   }

   // FRIEND FUNCTIONS:

   // addition operator
   // Add two polynomials together and return a new polynomial that is the result
   // pre: Both class objects have been initialized
   // post: The sum of two polynomials is stored in a new polynomial which is returned.
   //       The parameter polynomials are not changed.
   friend Poly operator+(const Poly& aPoly, const Poly& bPoly);

   // subtraction operator
   // Subtracts one polynomial from another and return a new polynomial that is the result
   // pre: Both class objects have been initialized
   // post: The difference of two polynomials is stored in a new polynomial which is returned.
   //       The parameter polynomials are not changed.
   friend Poly operator-(const Poly& aPoly, const Poly& bPoly);

   // equality operator
   // Compare two polynomials and return true if they are the same, false otherwise
   // pre: Both class objects have been initialized
   // post: A boolean value indicating whether two polynomials are the same is returned.
   //       The parameter polynomials are not changed.
   friend bool operator==(const Poly& aPoly, const Poly& bPoly);

   // insertion operator for output
   // Print polynomials
   // pre: The class object has been initialized
   // post: several values representing the polynomial are inserted into the output stream
   friend ostream& operator<<(ostream& out, const Poly &aPoly);
};

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
