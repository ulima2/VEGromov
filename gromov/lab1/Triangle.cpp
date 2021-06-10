#include "Triangle.h"
#include <cmath>
double Triangle::getA() const
{
	return this->_a;
}

double Triangle::getB() const
{
	return this->_b;
}

double Triangle::getC() const
{
	return this->_c;
}

void Triangle::setA(const double a)
{
	this->_a = a;
}

void Triangle::setB(const double b)
{
	this->_b = b;
}

void Triangle::setC(const double c)
{
	this->_c = c;
}

double Triangle::getArea() const
{
	double p = getPerimetr() / AREA_CONST;
	return sqrt(p * (p - getA()) * (p - getB()) * (p - getC()));
}

double Triangle::getPerimetr() const
{
	return getA() + getB() + getC();
}

double Triangle::getHeightA() const
{
	return AREA_CONST * getArea() / getA();
}

double Triangle::getHeightB() const
{
	return  AREA_CONST * getArea() / getB();;
}

double Triangle::getHeightC() const
{
	return  AREA_CONST * getArea() / getC();;
}

std::string Triangle::getType() const
{
	if (checkEquilateral()) return "Equilateral";
	else if (checkIsosceles() && checkRectangular())return "Isosceles & Rectangular";
	else {
		if (checkIsosceles())return "Isosceles";
		else if (checkRectangular())return "Rectangular";
		else return "Normal";
	}
}

bool Triangle::checkEquilateral() const
{
	if (getA() == getB() && getA() == getC()) return true;
	else return false;
}

bool Triangle::checkIsosceles() const
{
	if ((getA() == getB()) || (getA() == getC()) || (getB() == getC())) return true;
	else return false;
}

bool Triangle::checkRectangular() const
{
	if ((pow(getA(), 2) + pow(getB(), 2) == pow(getC(), 2)) || (pow(getA(), 2) + pow(getC(), 2) == pow(getB(), 2)) || (pow(getC(), 2) + pow(getB(), 2) == pow(getA(), 2))) return true;
	else return false;
}

Triangle::Triangle(const double a, const double b, const double c)
{
	if ((a + b <= c) || (a + c <= b) || (b + c <= a))throw "triangle does not exist";
    if ((a <= 0) || (b <= 0) || (c <= 0)) throw "incorrect value";
	setA(a);
	setB(b);
	setC(c);
}

std::istream& operator>>(std::istream& in, Triangle& t)
{
	double a, b, c;

	in >> a >> b >> c;
	t = Triangle(a, b, c);
	return in;
}

std::ostream& operator<<(std::ostream& out, const Triangle& t)
{
	out << "Triangle sides: " << t.getA() << ", " << t.getB() << ", " << t.getC()
		<< "\nArea: " << t.getArea() << "\nPerimetr: " << t.getPerimetr()
		<< "\nHeights: for A: " << t.getHeightA()
		<< ", for B: " << t.getHeightB()
		<< ", for C: " << t.getHeightC()
		<< "\nType: " << t.getType();
	return out;
}
