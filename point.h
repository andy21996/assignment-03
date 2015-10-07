/* ----------------------------------------------------------------------------
* Copyright &copy; 2015 Duy Nguyen <andy21996@fullerton.edu>
* Released under the [MIT License] (http://opensource.org/licenses/MIT)
* ------------------------------------------------------------------------- */

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



