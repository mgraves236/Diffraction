//
// Created by Magda on 02.04.2021.
//

#include "Imaginary.h"


Imaginary::Imaginary (double a, double b, double c, double d, int numPnt,
			double dDif, double k, double amp) {
	this->size = numPnt;
	this->x = new double [size + 1];
	this->y = new double [size + 1];
	this->z = new double [size * size];
	//calculate values
	double hx = (b - a) / (size - 1);
	double hy = (d - c) / (size - 1);
	for (int i = 1; i < size + 1; i++) { //arrays start at one because of i - 1
		x[i] = a + (i - 1) * hx;
		for (int j = 1; j < size + 1; j++) {
			y[j] = c + (j - 1) * hy;
			z[j + (i - 1) * size] = this->value(x[i], y[j], dDif, k, amp);
		}
	}
}

double Imaginary::value (double x, double y, double d, double k, double amp) {
	double r = sqrt(d * d + (y - x) * (y - x));
	return amp * sin(k * r + phase(r)) / sqrt(r);
}

void Imaginary::simpson(double a, double b, double y, double d, double k, double amp, double size) {
	double h = (b - a) / (2.0 * (double)(size));
	double simpson = .0;
	double x = a + h;

	int i = 1;
	while (i < size + 1) {
		simpson = simpson + (value(x + h, y, d, k, amp) +
				4.0 * value(x, y, d, k, amp) + value(x - h, y, d, k, amp))
						*  h / 3.0;
		x = x + 2.0 * h;
		i = i + 1;
	}
	integral = simpson;
}

void Imaginary::saveInt() {
	std::ofstream file("fQuadrat.bin");
	file << std::fixed << std::setprecision(15) << 4.0 * integral;
	file.close();
}