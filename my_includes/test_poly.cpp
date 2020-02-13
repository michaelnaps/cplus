// File: test_poly.cpp
// Created by: Michael Napoli
// Created on: 2/12/2020
// Last modified on:

/* Program to test the functionality of the 'Poly' class type. */

#include <iostream>
#include "Poly.h"
using namespace std;

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
