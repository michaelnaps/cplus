// File: coin.h
// Created by: Michael Napoli
// Created on: 5/24/2020
// Last modified on:

/*
   Purpose: Class for the declaration and organization of differing types of coins.
*/

#ifndef COIN_H
#define COIN_H

#include <string>
#include <ostream>

namespace mercury {
   class Coin
   {
   private:
      int count;
      std::string name;
      double ind_value;

   public:
      // CONSTRUCTORS:
      Coin();
      Coin(std::string given_name, double amount);
      Coin(std::string given_name, double amount, int num);

      // GET FUNCTIONS:
      int getCount();
      std::string getName();
      double getIndValue();
      double getTotal();

      // OPERATOR FUNCTIONS:
      friend double operator+(const Coin& var1, const Coin& var2);
      friend double operator-(const Coin& var1, const Coin& var2);
      friend double operator++(const Coin& var);
      friend double operator--(const Coin& var);
      friend ostream& operator>>(ostream& m_out, const Coin& var);
   };
}

#endif
