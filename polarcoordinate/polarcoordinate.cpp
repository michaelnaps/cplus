// File: polarcoordinate.cpp
// Created by: Michael Napoli
// Created on: 6/21/2020
// Last modified on: 6/21/2020

/*
   For description see header file.
*/

#include "polarcoordinate.h"
#include <iostream>
#include <cmath>
#include <string>

namespace napoli
{
   // NON-MEMBER FUNCTIONS:
   double convertAng(const char& oldAngType, const double& angle) {
      if (oldAngType == 'r') {
         return angle * (180.00 / M_PI);
      }
      else if (oldAngType == 'd') {
         return angle * (M_PI / 180.00);
      }
   }

   // CONSTRUCTORS:
   PolarCoordinate::PolarCoordinate() : ang_type('d'), theta(0), radius(0) {}
   PolarCoordinate::PolarCoordinate(const char& r_d) : theta(0), radius(0) {
      ang_type = r_d;
   }
   PolarCoordinate::PolarCoordinate(const char& r_d, const double& ang, const double& dist) {
      if (r_d == 'r' || r_d == 'd') {
         ang_type = r_d;
      }
      else {
         ang_type = 'd';  // default ang_type - degrees
      }

      theta = ang;
      radius = dist;

      return;  // end function
   }

   // GET FUNCTIONS:
   double PolarCoordinate::getTheta() {
      return theta;
   }

   double PolarCoordinate::getRadius() {
      return radius;
   }

   // SET FUNCTIONS:
   bool PolarCoordinate::setTheta(const char& r_d, const double& newAng) {
      if (r_d == ang_type) {
         theta = newAng;
         return true;
      }

      return false;
   }

   bool PolarCoordinate::setRadius(const double& dist) {
      if (dist < 0) {
         return false;  // radius must be positive
      }

      radius = dist;
      return true;
   }

   // MEMBER FUNCTIONS:
   bool PolarCoordinate::switchAngType() {
      if (ang_type == 'r') {
         theta *= (180.00 / M_PI);
         ang_type = 'd';
         return true;
      }
      else if (ang_type == 'd') {
         theta *= (M_PI / 180.00);
         ang_type = 'r';
         return true;
      }

      return false;  // if angle not switch not performed
   }

   double PolarCoordinate::getArc() {
      if (ang_type = 'r') {
         return (radius * theta);
      }
      else if (ang_type = 'd') {
         return (radius * convertAng(ang_type, theta));
      }
   }
}
