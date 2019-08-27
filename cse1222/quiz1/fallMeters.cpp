// File: fallMeters.cpp
// Created by: Michael Napoli
// Created on: 5-17-19

/*Compute the distance an object falls in meters.*/

#include <iostream>
using namespace std;

int main()
{
  double g = 32.185 * .3048;  //adjust feet per second^2 to meters per second^2
  double t;                   // time (in seconds)
  double velocity;            // velocity after time t
  double distance;            // distance after time t

  cout << "Enter the time: ";
  cin >> t;

  //compute the velocuty and distance (with new meters value)
  velocity = g * t;
  distance = velocity * 0.5 * t;

  cout << "After " << t << " seconds, the velocity is "
       << velocity << " meters per second." << endl;
  cout << "After " << t << " seconds, the falling distance is "
       << distance << " meters." << endl;

  return 0;
}
