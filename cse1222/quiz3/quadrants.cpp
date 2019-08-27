/*
  File: quadrants.cpp
  Created by: Michael Napoli
  Creation Date: 5/31/2019
  Synopsis: Program that reads in two values as x and y coordinates. Then
  outputs the quadrant or axis they are located on.
*/

#include <iostream>
using namespace std;

int main()
{
  // Variable declarations

  // Point to classify - (x, y)
  int pt_x(0), pt_y(0);

  // Prompt and read in point to classify
  cout << "Enter x-coordinate of point to classify: ";
  cin >> pt_x;

  cout << "Enter y-coordinate of point to classify: ";
  cin >> pt_y;
  cout << endl;

  // Classify point in the Cartesian plane
  if (pt_y == 0 && pt_x > 0)
    {
      cout << "Point is on the +X axis." << endl;
    }
  else if (pt_y == 0 && pt_x < 0)
    {
      cout << "Point is on the -X axis." << endl;
    }
  else if (pt_y > 0 && pt_x == 0)
    {
      cout << "Point is on the +Y axis." << endl;
    }
  else if (pt_y < 0 && pt_x == 0)
    {
      cout << "Point is on the -Y axis." << endl;
    }
  else if (pt_y > 0 && pt_x > 0)
    {
      cout << "Point is in Quadrant I." << endl;
    }
  else if (pt_y > 0 && pt_x < 0)
    {
      cout << "Point is in Quadrant II." << endl;
    }
  else if (pt_y < 0 && pt_x < 0)
    {
      cout << "Point is in Quadrant III." << endl;
    }
  else if (pt_y < 0 && pt_x > 0)
    {
      cout << "Point is in Quadrant IV." << endl;
    }
  else
    {
      cout << "Point is the origin." << endl;
    }

  return 0;
}
