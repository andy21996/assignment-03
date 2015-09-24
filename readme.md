/* ----------------------------------------------------------------------------
* Copyright &copy; 2015 Duy Nguyen <andy21996@fullerton.edu>
* Released under the [MIT License] (http://opensource.org/licenses/MIT)
* ------------------------------------------------------------------------- */
//main.cpp
#include "Point.h"
#include "Shape.h"
#include <iostream>

//using namespace std;
using std::cout;
using std::cin;
using std::endl;

int main()
{
	Point p = Point(10.3, 5.9);
	rectangle * r = new rectangle(5.1,7.6,p);
	r->draw();
	r->printRectangle();

	p = Point(20.3, 5.6);
	square * s = new square(10.8, p);
	s->draw();
	s->printSquare();

	cout << endl << endl;
	system("Pause");
	return 0;
}

//Point.h
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
	void SetX(double x);
	double GetY() const;
	void SetY(double y);
	void printPoint() const;
	
private:
	double xPos;
	double yPos;
};

#endif

//Shape.h
#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include "Point.h"

using std::cout;
using std::cin;
using std::endl;

class shape
{
public:
	virtual bool contains(const Point & p) const = 0;
	virtual ~shape() {}
protected:
	Point p;
};

class rectangle : public shape
{
public:
	rectangle();
	rectangle(double l, double w, Point upLeft);
	bool contains(const Point & p) const;
	~rectangle();

	double GetL() const;
	double GetW() const;
	Point GetUpLeft() const;
	void printRectangle() const;
	void draw() const;

private:
	double length;
	double width;
	Point p;
};

class square : public rectangle
{
public:
	square();
	square(double s, Point upLeft);
	~square();

	double GetSide() const;
	Point GetUpLeft() const;
	void printSquare() const;
	void draw() const;

private:
	double side;
	Point p; //upper left point
};

class ellipse : public shape
{
public:
	ellipse();
	ellipse(double x, double y);
	bool contains(const Point & p) const;
	~ellipse();

	double GetX() const;
	double GetY() const;
	void printEllipse() const;
	void draw() const;

private:
	double radius;
};

class circle : public ellipse
{
public:
	circle();
	circle(double x, double y);
	~circle();

	double GetX() const;
	double GetY() const;
	void printCircle() const;
	void draw() const;

private:
	double radius;
};

#endif

//Point.cpp
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
void Point::SetX(double x)
{
	xPos = x;
}
double Point::GetY() const
{
	return yPos;
}
void Point::SetY(double y)
{
	yPos = y;
}
void Point::printPoint() const
{
	cout << "(" << GetX() << ", " << GetY() << ")" << endl;
}

//Shape.cpp

#include "Shape.h"
#include <math.h>

rectangle::rectangle()
{
	length = 0;
	width = 0;
	p.SetX(0);
	p.SetY(0);
}
rectangle::rectangle(double l, double w, Point upLeft)
{
	length = l;
	width = w;
	p.SetX(upLeft.GetX());
	p.SetY(upLeft.GetY());
}
bool rectangle::contains(class Point const &) const 
{
	return true;
}
rectangle::~rectangle() {}
double rectangle::GetL() const
{
	return length;
}
double rectangle::GetW() const
{
	return width;
}
Point rectangle::GetUpLeft() const
{
	return p;
}
void rectangle::printRectangle() const
{
	cout << "This is a rectangle: " << endl
		<< "with upper left corner at ";
		p.printPoint();
		cout << "Length = " << length << ", Width = " << width << endl;

}
void rectangle::draw() const
{
	Point p = GetUpLeft();
	int x = static_cast<int>(round(p.GetX() * 1.9)),
		y = static_cast<int>(round(p.GetY())),
		w = static_cast<int>(round(GetW())),
		l = static_cast<int>(round(GetL() * 1.9));

	for (int i = 0; i < y - 1; i++)
		cout << endl;
	for (int i = y; i < y + w; i++)
	{
		for (int j = 0; j < x - 1; j++)
			cout << " ";
		for (int j = x; j < x + l; j++)
			cout << "*";
		cout << endl;
	}
}

square::square()
{
	side = 0;
	p.SetX(0);
	p.SetY(0);
}
square::square(double s, Point upLeft)
{
	side = s;
	p.SetX(upLeft.GetX());
	p.SetY(upLeft.GetY());
}
square::~square() {}
double square::GetSide() const
{
	return side;
}
Point square::GetUpLeft() const
{
	return p;
}
void square::printSquare() const
{
	cout << "This is a square: " << endl
		<< "with upper left corner at (" << p.GetX() << "," << p.GetY() << ")" << endl
		<< "Side: " << side << endl;
}
void square::draw() const
{
	Point p = GetUpLeft();
	int x = static_cast<int>(round(p.GetX() * 1.9)),
		y = static_cast<int>(round(p.GetY())),
		w = static_cast<int>(round(GetSide())),
		l = static_cast<int>(round(GetSide() * 1.9));

	for (int i = 0; i < y - 1; i++)
		cout << endl;
	for (int i = y; i < y + w; i++)
	{
		for (int j = 0; j < x - 1; j++)
			cout << " ";
		for (int j = x; j < x + l; j++)
			cout << "*";
		cout << endl;
	}
}

ellipse::ellipse()
{

}
ellipse::ellipse(double x, double y)
{
	
}
bool ellipse::contains(class Point const &) const 
{
	return true;
}
ellipse::~ellipse() {}
double ellipse::GetX() const
{
	return 0;
}
double ellipse::GetY() const
{
	return 0;
}
void ellipse::printEllipse() const
{

}
void ellipse::draw() const
{

}

circle::circle()
{

}
circle::circle(double x, double y)
{

}
circle::~circle() {}
double circle::GetX() const
{
	return 0;
}
double circle::GetY() const
{
	return 0;
}
void circle::printCircle() const
{

}
void circle::draw() const
{

}
