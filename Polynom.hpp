#pragma once
#include <iostream>

using namespace std;

class Polynom {
	double *coef; // коэффициенты полинома
	int n; // степень полинома
public:
	Polynom(int n = 0);
	Polynom(const Polynom& polynom);

	Polynom& operator=(const Polynom& polynom);

	void Read();

	double Evaluate(double x) const;
	Polynom Derivative() const;
	int GetDegree() const;

	Polynom operator*(const Polynom& polynom) const;
	Polynom operator+(const Polynom& polynom) const;
	Polynom operator-(const Polynom& polynom) const;
	double operator[](int index) const;

	void SetCoef(int index, double c);

	~Polynom();

	friend ostream& operator<<(ostream& os, const Polynom& polynom);
};

Polynom::Polynom(int n) {
	this->n = n;
	coef = new double[n + 1];

	for (int i = 0; i <= n; i++)
		coef[i] = 0;
}

Polynom::Polynom(const Polynom& polynom) {
	n = polynom.n;
	coef = new double[polynom.n + 1];

	for (int i = 0; i <= polynom.n; i++)
		coef[i] = polynom.coef[i];
}

Polynom& Polynom::operator=(const Polynom& polynom) {
	delete[] coef;
	n = polynom.n;
	coef = new double[polynom.n + 1];

	for (int i = 0; i <= polynom.n; i++)
		coef[i] = polynom.coef[i];

	return *this;
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

int Polynom::GetDegree() const{
	return n;
}

Polynom Polynom::operator*(const Polynom& polynom) const {
	Polynom res(n + polynom.n);

	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= polynom.n; j++)
			res.coef[i + j] += coef[i] * polynom.coef[j];

	return res;
}

Polynom Polynom::operator+(const Polynom& polynom) const {
    Polynom res((n > polynom.n ? n : polynom.n) + 1);

    for (int i = 0; i <= n; i++)
    	res.coef[i] = coef[i];

    for (int i = 0; i <= polynom.n; i++)
    	res.coef[i] += polynom.coef[i];

    return res;
}

Polynom Polynom::operator-(const Polynom& polynom) const {
	Polynom res((n > polynom.n ? n : polynom.n) + 1);

    for (int i = 0; i <= n; i++)
    	res.coef[i] = coef[i];

    for (int i = 0; i <= polynom.n; i++)
    	res.coef[i] -= polynom.coef[i];

    return res;
}

double Polynom::operator[](int index) const {
	return coef[index];
}

void Polynom::SetCoef(int index, double c) {
	coef[index] = c;
}

Polynom::~Polynom() {
	delete[] coef;
}

ostream& operator<<(ostream& os, const Polynom& polynom) {
	bool empty;
	for (int i = 0; i <= polynom.n; i++)
		if (polynom.coef[i] != 0)
			empty = false;

	if (empty || polynom.n == 0)
		cout << "0" << endl;

	else {
		for (int i = polynom.n; i > 0; i--) {

			if (polynom.coef[i] == 0)
				continue;

			if (polynom.coef[i] > 0){
				if (i == 1){
					if (polynom.coef[i] == 1)
						os << "x";
					else
						os << polynom.coef[i] << "x"; 
				}
				else {
					if (polynom.coef[i] == 1)
						os << "x^" << i;
					else
						os << polynom.coef[i] << "x^" << i; 
				}

			}
			else{
				if (i == 1){
					if (polynom.coef[i] == -1)
						os << "-x";
					else
						os << polynom.coef[i] << "x"; 
				}
				else {
					if (polynom.coef[i] == -1)
						os << "-x^" << i;
					else
						os << polynom.coef[i] << "x^" << i; 
				}
			}
			if (polynom.coef[i - 1] > 0)
				cout << "+";
		}
		os << polynom.coef[0];
	}

	return os << endl;
}