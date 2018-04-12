#include "Point.h"
#include <iostream>
using namespace std;

int main(){
	Point P(0,0);
	
	P.SetAbsis(1);
	P.Move(2,3);
	cout << "x : " << P.GetAbsis() << endl;
	cout << "y : " << P.GetOrdinat() << endl;
	cout << "Kuadran : " << P.Kuadran() << endl;
	
	Point P1 = P.HasilPindah(-10,-5);
	cout << "x : " << P1.GetAbsis() << endl;
	cout << "y : " << P1.GetOrdinat() << endl;
	cout << "Kuadran : " << P1.Kuadran() << endl;
	
	return 0;
}