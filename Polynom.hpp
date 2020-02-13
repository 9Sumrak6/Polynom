#pragma once
#include <iostream>

using namespace std;

class Polynom {
	double *coef; // коэффициенты полинома
	int n; // степень полинома
public:
	Polynom(int n);
	void Read();

	double Evaluate(double x) const;
	Polynom Derivative() const;
	~Polynom();

	friend ostream& operator<<(ostream& os, const Polynom& polynom);
};

Polynom::Polynom(int n) {
	this->n = n;
	coef = new double[n + 1];

	for (int i = 0; i <= n; i++)
		coef[i] = 0;
}

void Polynom::Read() {
	for (int i = n; i >= 0; i--)
		cin >> coef[i];
}

double Polynom::Evaluate(double x) const {
	double sum = 0;
	for (int i = n; i >= 0; i--)
		sum = sum * x + coef[i];

	return sum;
}

Polynom Polynom::Derivative() const {
	Polynom polynom(n - 1);

	for (int i = 1; i <= n; i++)
		polynom.coef[i - 1] = coef[i] * i;

	return polynom;
}


Polynom::~Polynom() {
	delete[] coef;
}

ostream& operator<<(ostream& os, const Polynom& polynom) {
	for (int i = polynom.n; i >= 0; i--)
		os << polynom.coef[i] << " ";

	return os << endl;
}