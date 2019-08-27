// File: circles_class.cpp
// Created by: Michael Napoli
// Created on: 7/25/19
// Last modifed on: 7/25/19

/* Practice Final CSE 1222 #9 */

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Circle
{
    private:
        double x;
        double y;
        double r;
    public:
        void setX(double tx);
        void setY(double ty);
        void setR(double tr);

        double getX() const;
        double getY() const;
        double getR() const;
        double area() const;

        void display() const;
};

int main()
{
    Circle c1;
    double temp_x, temp_y, temp_r;

    cout << "Enter the circles midpoint coordinates: ";
    cin >> temp_x >> temp_y;

    cout << "Enter the circles radius: ";
    cin >> temp_r;
    cout << endl;

    c1.setX(temp_x);
    c1.setY(temp_y);
    c1.setR(temp_r);

    c1.display();

    return 0;
}

// MEMBER FUNCTIONS: class Circle
double Circle::getX() const
{ return x; }

double Circle::getY() const
{ return y; }

double Circle::getR() const
{ return r; }

double Circle::area() const
{ return M_PI * r * r; }

void Circle::setX(double tx)
{
    x = tx;
    return;
}

void Circle::setY(double ty)
{
    y = ty;
    return;
}

void Circle::setR(double tr)
{
    r = tr;
    return;
}

void Circle::display() const
{
    cout << "The midpoint is located at (" << x << ", " << y << ")." << endl;
    cout << "The radius is " << r << " units." << endl;

    return;
}