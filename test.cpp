#include <iostream>
#include <cassert>
#include "Polynom.hpp"

using namespace std;

void MainTests() {
	cout << "MainTests: ";

	Polynom p; // 0
	assert(p.GetDegree() == 0);
	assert(p[0] == 0);

	Polynom a(2);
	a.SetCoef(0, 1);
	a.SetCoef(1, 2);
	a.SetCoef(2, -3);

	assert(a.GetDegree() == 2);
	assert(a[0] == 1);
	assert(a[1] == 2);
	assert(a[2] == -3);

	assert(a.Evaluate(0) == 1);
	assert(a.Evaluate(1) == 0);
	assert(a.Evaluate(-1) == -4);

	Polynom da = a.Derivative();

	assert(da.GetDegree() == 1);
	assert(da[0] == 2);
	assert(da[1] == -6);

	cout << "OK" << endl;
}

int main(){
	MainTests();
}