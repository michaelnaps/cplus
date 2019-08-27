// File: RightTriangle_class.cpp
// Created by: Michael Napoli
// Created on: 7/25/19
// Last modifed on: 7/25/19

/* Practice Final CSE 1222 #9 */

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class RightTriangle
{
    private:
        double x;
        double y;
    public:
        double getX() const;
        double getY() const;
        double area() const;
        double hypotenuse() const;

        void setX(double tx);
        void setY(double ty);
};

int main()
{
    RightTriangle rt;
    rt.setX(5.0);
    rt.setY(10.0);

    cout << "x = " << rt.getX() << endl;
    cout << "y = " << rt.getY() << endl;
    cout << "area = " << rt.area() << endl;
    cout << "hypotenuse = " << rt.hypotenuse() << endl;

    return 0;
}

// MEMBER FUNCTION: class RightTriangle

void RightTriangle::setX(double tx)
{
    x = tx;
    return;
}

void RightTriangle::setY(double ty)
{
    y = ty;
    return;
}

double RightTriangle::getX() const
{ return x; }

double RightTriangle::getY() const
{ return y; }

double RightTriangle::area() const
{ return (x * y) / 2.0; }

double RightTriangle::hypotenuse() const
{ return sqrt(x * x + y * y); }