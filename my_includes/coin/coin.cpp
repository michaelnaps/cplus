// File: coin.cpp
// Created by: Michael Napoli
// Created on: 5/24/2020
// Last modified on:

/*
   Purpose:
*/

#include "coin.h"
#include <string>
#include <iostream>

namespace mercury {
   // CONSTRUCTORS:
   Coin::Coin() : name("INVALID NAME"), ind_value(-1), count(0) {}
   Coin::Coin(std::string given_name, double amount) : count(0) {
      name = given_name;
      ind_value = amount;
   }
   Coin::Coin(std::string given_name, double amount, int num) {
      name = given_name;
      ind_value = amount;
      count = num;
   }


   // GET MEMBER FUNCTIONS:
   // return the number of coins of the specified type
   int Coin::getCount() {
      return count;
   }

   // return the current coin's given title
   std::string Coin::getName() {
      return name;
   }

   // return the value of an individual coin of the specified type
   double Coin::getIndValue() {
      return ind_value;
   }

   // return the total (based on coin value and number of coins)
   double Coin::getTotal() {
      return (count * ind_value);
   }

   // OPERATOR FUNCTIONS (FRIEND):
   double operator+(const Coin& var1, const Coin& var2) {
      return ((var1.count * var1.ind_value) + (var2.count * var2.ind_value));
   }

   double operator-(const Coin& var1, const Coin& var2) {
      return ((var1.count * var1.ind_value) - (var2.count * var2.ind_value));
   }

   double operator++(const Coin& var) {
      return ++var.count;
   }

   double operator--(const Coin& var) {
      if (--var.count < 0) {
         std::cout << "ERROR: No " << var.name << "(s) left to withdraw." << std::endl;
         return 0;
      }
      else {
         return --var.count;
      }
   }

   ostream& operator>>(ostream& m_out, const Coin& var) {
      m_out << var.name << ": " << var.ind_value;
      return m_out;
   }
}
