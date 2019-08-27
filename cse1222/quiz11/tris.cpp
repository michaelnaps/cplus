/*
  File: tris.cpp
  Created by: Michael Napoli
  Creation Date: 7/26/2019
  Synopsis: Program that takes an inputted triangle dimensions and outpus
  them to an external file.
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>

using namespace std;

class Triangle
{
private:
	double locx, locy;
	double length, height;

public:
	// member functions
	void setBottomLeftX(const double x);
	void setBottomLeftY(const double y);
	void setLength(const double inLength);
	void setHeight(const double inHeight);

	double getBottomLeftX() const;
	double getBottomLeftY() const;
	double getLength() const;
	double getHeight() const;
	
	double area() const;
	void write_file() const;
};

// FUNCTION PROTOTYPES GO HERE:
void read_triangle(Triangle & tri);

int main()
{
	// Define local variables
	Triangle tri;
	
	//Prompt the user for triangle information and fill Class Triangle object, tri,
	//with this information
	read_triangle(tri);
	
	// Write triangle to file information
	tri.write_file();
		
	return 0;
}
		 
// FUNCTION DEFINITIONS GO HERE:
			 
// CLASS MEMBER FUNCTION DEFINITINOS GO HERE:

void Triangle::setBottomLeftX(const double x) 
{
	locx = x;
}

void Triangle::setBottomLeftY(const double y) 
{
	locy = y;
}

void Triangle::setLength(const double inLength) 
{
	length = inLength;
}

void Triangle::setHeight(const double inHeight) 
{
	height = inHeight;
}

double Triangle::getBottomLeftX() const
{
	return locx;
}

double Triangle::getBottomLeftY() const
{
	return locy;
}

double Triangle::getLength() const
{
	return length;
}

double Triangle::getHeight() const
{
	return height;
}

double Triangle::area() const
{
  return (height * length) / 2.0;
}

void Triangle::write_file() const
{
	string fname;    // Name of output file
	ofstream fout;   // Output stream to file fname
  
	// prompt and read the file name to write triangle info into
	cout << "Enter the name of the file to write the triangle: ";
	cin.ignore();	
	getline(cin, fname);
	
	// open the file
	fout.open(fname.c_str(), ios::out);
	
	// check if file is opened for output
	if (!fout.is_open()) {
	  cout << "ERROR: File did not open." << endl;
	  return;  // leave member function
	}
  
	// write new line to the output file
	fout << endl;

	// write dotted line
	fout << "----------------------------------------" << endl;
  
	// write triangle information
	fout << "Lower Left Vertex (" << locx << ", " << locy << ")" << endl;
	fout << "Dimensions (" << length << ", " << height << ")" << endl;
	fout << "Area " << area() << endl;
	
	// write dotted line
	fout << "----------------------------------------" << endl;
  
	// write new line to the output file
	fout << endl;

	// close output file
	fout.close();
        
	return;  // return nothing
}

void read_triangle(Triangle & tri)
{
  double temp_val;

  cout << "Enter bottom left x coordinate: ";
  cin >> temp_val;
  tri.setBottomLeftX(temp_val);

  cout << "Enter bottom left y coordinate: ";
  cin >> temp_val;
  tri.setBottomLeftX(temp_val);

  cout << "Enter length: ";
  cin >> temp_val;
  tri.setLength(temp_val);

  cout << "Enter height: ";
  cin >> temp_val;
  tri.setHeight(temp_val);

  return;  // return nothing
}
