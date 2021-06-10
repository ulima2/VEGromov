#include "lab4.h"

double Figure::getArea() const
{
	return this->_area;
}

double Figure::getPerimetr() const
{
	return this->_perimeter;
}

void Figure::setArea(const double a)
{
	this->_area = a;
}

void Figure::setPerimetr(const double p)
{
	this->_perimeter = p;
}



double Ellipse::getR1() const
{
	return this->_r1;
}

double Ellipse::getR2() const
{
	return this->_r2;
}

void Ellipse::setR1(const double r1)
{
	this->_r1 = r1;
}

void Ellipse::setR2(const double r2)
{
	this->_r2 = r2;
}

Ellipse::Ellipse(const double r1, const double r2)
{
	if ((r1 <= 0) || (r2 <= 0)) throw "Incorrect value";
	setR1(r1);
	setR2(r2);
	perimeter();
	area();
}

double Ellipse::perimeter() {
	setPerimetr( 2 * M_PI * sqrt((getR1() * getR1() + getR2() * getR2()) / 2));
	return getPerimetr();
}

double Ellipse::area() {
	setArea(M_PI * getR1() * getR2());
	return getArea();
}
std::ostream& operator<<(std::ostream& out, const Figure& f)
{
	out << "Area: " << f.getArea() << "\nPerimetr: " << f.getPerimetr();
	return out;
}
std::istream& operator>>(std::istream& in, Ellipse& e)
{
	double r1, r2;
	in >> r1 >> r2;
	e = Ellipse(r1, r2);
	return in;
}

std::istream& operator>>(std::istream& in, Trapezoid& t)
{
	double b1, b2, h;
	in >> b1 >> b2 >> h;
	t = Trapezoid(b1, b2, h);
	return in;
}

std::istream& operator>>(std::istream& in, Square& s)
{
	double a;
	in >> a;
	s = Square(a);
	return in;
}

double Trapezoid::getBase1() const
{
	return this->_base1;
}

double Trapezoid::getBase2() const
{
	return this->_base2;
}

double Trapezoid::getHeight() const
{
	return this->_height;
}

void Trapezoid::setBase1(const double b)
{
	this->_base1 = b;
}

void Trapezoid::setBase2(const double b)
{
	this->_base2 = b;
}

void Trapezoid::setHeight(const double h)
{
	this->_height = h;
}

Trapezoid::Trapezoid(const double b1, const double b2, const double h)
{
	if ((b1 <= 0) || (b2 <= 0) || (h <= 0)) throw "Incorrect value";
	setBase1(b1);
	setBase2(b2);
	setHeight(h);
	area();
	perimeter();
}

double Trapezoid::perimeter()
{
	setPerimetr(getBase1() + getBase2() + 2 * sqrt(pow(getHeight(), 2) + pow((abs(getBase1() - getBase2()) / 2), 2)));
	return getPerimetr();
}

double Trapezoid::area()
{
	setArea(getHeight() * ((getBase1() + getBase2()) / 2));
	return getArea();
}

double Square::getA() const
{
	return this->_a;
}

void Square::setA(const double a)
{
	this->_a = a;
}

Square::Square(const double a)
{
	if (a <= 0) throw "Incorrect value";
	setA(a);
	area();
	perimeter();
}

double Square::perimeter()
{
	setPerimetr(4 * getA());
	return getPerimetr();
}

double Square::area()
{
	setArea(getA() * getA());
	return getArea();
}
