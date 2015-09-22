/* ----------------------------------------------------------------------------
* Copyright &copy; 2015 Duy Nguyen <andy21996@fullerton.edu>
* Released under the [MIT License] (http://opensource.org/licenses/MIT)
* ------------------------------------------------------------------------- */

#include "Point.h"

#include <iostream>

//using namespace std;
using std::cout;
using std::cin;
using std::endl;

int main()
{
	Point *p = new Point(1.0, 1.2);
	cout << p->GetX() << endl;
	cout << p->GetY() << endl;

	p->SetX(5.0);
	p->SetY(2.3);

	cout << p->GetX() << endl;
	cout << p->GetY() << endl;

	p->printPoint();

	cout << endl << endl;
	system("Pause");
	return 0;

}
