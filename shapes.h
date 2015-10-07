/* ----------------------------------------------------------------------------
* Copyright &copy; 2015 Duy Nguyen <andy21996@fullerton.edu>
* Released under the [MIT License] (http://opensource.org/licenses/MIT)
* ------------------------------------------------------------------------- */

#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include "Point.h"

using std::cout;
using std::cin;
using std::endl;

class Shape
{
public:
	virtual bool contains(const Point & p) const = 0;
	virtual ~Shape() {}
};

class Rectangle : public Shape 
{
public:
	Rectangle(Point corner = Point(), double length = 0, double width = 0);

	bool contains(const Point & p) const;

private:
	Point corner;
	double length;
	double width;
};

class Square : public Rectangle 
{
public:
	Square(Point corner = Point(), double side = 0);
};

class Ellipse : public Shape
{
public:
	Ellipse(Point foci1 = Point(), Point foci2 = Point(), double distance = 0);

	bool contains(const Point& p) const;

private:
	Point foci1;
	Point foci2;
	double distance;
};

class Circle : public Ellipse
{
public:
	Circle(Point center = Point(), double radius = 0);
};

#endif
