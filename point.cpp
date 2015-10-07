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

