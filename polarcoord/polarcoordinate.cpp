// File: polarcoordinate.cpp
// Created by: Michael Napoli
// Created on: 6/21/2020
// Last modified on: 6/21/2020

/*
   For description see header file.
*/

#include "polarcoordinate.h"
#include <iostream>
#include <string>

namespace napoli
{
   PolarCoordinate::PolarCoordinate() : type('d'), theta(0), radius(0) {}
   PolarCoordinate::PolarCoordinate(const char& r_d) : theta(0), radius(0) {
      type = r_d;
   }
   PolarCoordinate::PolarCoordinate(const char& r_d, const double& ang, const double& dist) {
      if (r_d == 'r' || r_d == 'd') {
         type = r_d;
      }
      else {
         type = 'd';  // default type - degrees
      }

      theta = ang;
      radius = dist;
   }
}
