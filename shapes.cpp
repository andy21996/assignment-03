/* ----------------------------------------------------------------------------
* Copyright &copy; 2015 Duy Nguyen <andy21996@fullerton.edu>
* Released under the [MIT License] (http://opensource.org/licenses/MIT)
* ------------------------------------------------------------------------- */
#include <cmath>
using std::abs;

#include "Shape.h"

Rectangle::Rectangle(Point corner, double length, double width) : corner(corner), length(length), width(width) {}
bool Rectangle::contains(const Point & p) const
{
	return abs(p.GetX() - corner.GetX()) <= length && abs(p.GetY() - corner.GetY()) <= width;
}

Square::Square(Point corner, double side)
{

}

Ellipse::Ellipse(Point foci1, Point foci2, double distance) : foci1(foci1), foci2(foci2), distance(distance) {}
bool Ellipse::contains(const Point& p) const
{
	return p.distance(foci1) + p.distance(foci2) <= distance;
}

Circle::Circle(Point center, double radius) : Ellipse(center, center, radius) 
{
}
