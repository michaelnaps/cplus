// File: polarcoordinate.h
// Created by: Michael Napoli
// Created on: 6/21/2020
// Last modified on: 6/21/2020

/*
   Created for collection and analysis of polar coordinate systems on
   Arduino-based prototype projects.

   Formatted for both Arduino and C++ systems seperately.
*/

#ifndef POLARCOORDINATE
#define POLARCOORDINATE

#include <cmath>
#include <string>

namespace napoli
{

   // MISC. FUNCTIONS:
   float convertAng(const char& oldAngType, const float& angle) {
      if (oldAngType == 'r') {
         return angle * (180.00 / M_PI);
      }
      else if (oldAngType == 'd') {
         return angle * (M_PI / 180.00);
      }
   }

   class PolarCoordinate
   {
   private:
      char ang_type;
      float theta;
      float radius;

   public:
      // POLARCOORDINATE CLASS
      // CONSTRUCTORS:
      PolarCoordinate() : ang_type('d'), theta(0), radius(0) {}
      PolarCoordinate(const char& r_d) : theta(0), radius(0) {
         ang_type = r_d;
      }
      PolarCoordinate(const char& r_d, const float& ang, const float& dist) {
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
      float getTheta() {
         return theta;
      }

      float getRadius() {
         return radius;
      }

      // SET FUNCTIONS:
      bool setTheta(const char& r_d, const float& newAng) {
         if (r_d == ang_type) {
            theta = newAng;
            return true;
         }

         return false;
      }

      bool setRadius(const float& dist) {
         if (dist < 0) {
            return false;  // radius must be positive
         }

         radius = dist;
         return true;
      }

      // MEMBER FUNCTIONS:
      bool switchAngType() {
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

      float getArc() {
         if (ang_type = 'r') {
            return (radius * theta);
         }
         else if (ang_type = 'd') {
            return (radius * convertAng('r', theta));
         }
      }

      void rectCoordinate(float& x, float& y) {
         if (ang_type == 'r') {
            x = radius * cos(theta);
            y = radius * sin(theta);
         }
         else if (ang_type == 'd') {
            x = radius * cos(convertAng('r', theta));
            y = radius * sin(convertAng('r', theta));
         }

         return;  // return nothing
      }

      bool saveCoord(const std::string& filename) {
         return false;
      }
   };
}
#endif
