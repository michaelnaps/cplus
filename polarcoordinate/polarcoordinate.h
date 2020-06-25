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

#include <string>

namespace napoli
{
   class PolarCoordinate
   {
   private:
      char ang_type;
      double theta;
      double radius;

   public:
      // CONSTRUCTORS:
      PolarCoordinate();
      PolarCoordinate(const char& r_d);
      PolarCoordinate(const char& r_d, const double& ang, const double& dist);

      // GET FUNCTIONS:
      double getTheta();
      double getRadius();

      // SET FUNCTIONS:
      bool setTheta(const char& r_d, const double& ang);
      bool setRadius(const double& dist);

      // MEMBER FUNCTIONS:
      bool switchAngType();
      double getArc();
      double getRectCoordinate();

      // SAVE FUNCTION:
      bool saveCoord(const std::string& filename);
   };
}
#endif
