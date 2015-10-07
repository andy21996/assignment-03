/* ----------------------------------------------------------------------------
* Copyright &copy; 2015 Duy Nguyen <andy21996@fullerton.edu>
* Released under the [MIT License] (http://opensource.org/licenses/MIT)
* ------------------------------------------------------------------------- */

#include "Point.h"
#include "Shape.h"
#include <iostream>
#include <chrono>
#include <thread>

using std::cout;
using std::cin;
using std::endl;

void draw(const int count, const Shape * const s[]) 
{
		const double xPixels = 80;
		const double yPixels = 25;

		const double xScale = 1;
		const double yScale = 1.9;

		for (float yp = 0; yp < yPixels; yp++) 
		{
			double y = yp * yScale;

			for (float xp = 0; xp < xPixels; xp++) 
			{
				double x = xp * xScale;

				if (yp == 0 || yp == yPixels - 1) 
				{
					cout << "-";
					continue;
				}

				if (xp == 0 || xp == xPixels - 1) 
				{
					cout << "|";
					continue;
				}

				bool includePoint = false;
				for (int c = 0; c < count; c++)
				if (s[c]->contains(Point(x, y)))
					includePoint = true;

				if (includePoint)
					cout << "*";
				else
					cout << " ";
			}
			cout << endl;
		}
}

int main() 
{
		const int frames = 50;
		const int frameSleep = 100;  

		for (float f = 0; f < frames; f++) 
		{
			Rectangle r(Point(3 + f, 10), 5, 8);
			Square    s(Point(10 - (f / 5), 10 + (f / 2)), 11);
			Ellipse   e(Point(25 - (f / 8), 15 + (f / 3)), Point(50 - (f / 5), 30 + (f / 5)), 28 + f);
			Circle    c(Point(40 + (f / 10), 20), 15);

			Shape * shapes[] = { &r, &s, &e, &c, };

			draw(sizeof(shapes) / sizeof(Shape *), shapes);
			
			std::this_thread::sleep_for(std::chrono::milliseconds(frameSleep));
		}

		return 0;  
}

#ifndef POINT_H
#define POINT_H


#include <string>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
class Point
{
public:
	Point();
	Point(double x, double y);
		
	double GetX() const;
	double GetY() const;
	double distance(const Point & a) const;
	
private:
	double xPos;
	double yPos;
};

#endif

/* ----------------------------------------------------------------------------
* Copyright &copy; 2015 Duy Nguyen <andy21996@fullerton.edu>
* Released under the [MIT License] (http://opensource.org/licenses/MIT)
* ------------------------------------------------------------------------- */
#include <cmath>
using std::pow;
using std::sqrt;
#include "Point.h"


Point::Point()
{
	xPos = 0.0;
	yPos = 0.0;
}
Point::Point(double x, double y)
{
	xPos = x;
	yPos = y;
}
double Point::GetX() const
{
	return xPos;
}
double Point::GetY() const
{
	return yPos;
}
double Point::distance(const Point & a) const
{
	return sqrt(pow(a.xPos - this->xPos, 2) + pow(a.yPos - this->yPos, 2));
}

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

