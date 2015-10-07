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
		const int frameSleep = 100;  // milliseconds

	
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

