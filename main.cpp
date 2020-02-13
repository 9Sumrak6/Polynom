#include <iostream>
#include "Polynom.hpp"

using namespace std;

int main(){
	int n; // степень полинома
	cout << "Enter degree: ";
	cin >> n;
	Polynom polynom(n);
	
	cout << "Enter polynom f(x): ";
	polynom.Read();
	cout << polynom;
	
	double x;
	cout << "Enter x: ";
	cin >> x;
	cout << "f(" << x << ") = " <<  polynom.Evaluate(x) << endl;

	cout << polynom.Derivative() << endl;
}