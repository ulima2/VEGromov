#include "lab3.h"

Pair::Pair(const double a, const double b)
{
    setA(a);
    setB(b);
}

double Pair::getA() const
{
    return this->a;
}

double Pair::getB() const
{
    return this->b;
}

double Pair::mul() const
{
    return getA() * getB();
}

void Pair::setA(double a)
{
    this->a = a;
}

void Pair::setB(double b)
{
    this->b = b;
}

std::istream& operator>>(std::istream& in, Pair& p)
{
    double a, b;
    in >> a >> b;
    p = Pair(a, b);
    return in;
}

std::ostream& operator<<(std::ostream& out, const Pair& p)
{
    out << "Pair is:  " << p.getA() << ", " << p.getB() << "\nA * B = " << p.mul();
    return out;
}

std::istream& operator>>(std::istream& in, Rectangle& r)
{
    double a, b;
    in >> a >> b;
    r = Rectangle(a, b);
    return in;
}

std::ostream& operator<<(std::ostream& out, const Rectangle& r)
{
    out << "Rectangle sides:  " << r.getSideA() << " X " << r.getSideB()
        << "\nArea: " << r.area() << "\nPerimetr: " << r.perimetr();
    return out;
}

Rectangle::Rectangle(const double a, const double b)
{
    if ((a <= 0) || (b <= 0)) throw "Rectangle doesn`t exist";
    setA(a);
    setB(b);
}

double Rectangle::getSideA() const
{
    return this->a;
}

double Rectangle::getSideB() const
{
    return this->b;
}

void Rectangle::setSideA(double a)
{
    if (a <= 0) throw "invalid value";
    this->a = a;
}

void Rectangle::setSideB(double b)
{
    if (b <= 0) throw "invalid value";
    this->b = b;
}

double Rectangle::area() const
{
    return mul();
}

double Rectangle::perimetr() const
{
    return getSideA() + getSideA() + getSideB() + getSideB();
}
