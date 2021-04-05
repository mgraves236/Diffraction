#include "function2d.h"

/*Function2D::Function2D (double a, double b, double c, double d, int numPnt) {
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
			z[j + (i - 1) * size] = this->value(x[i], y[j]);
		}
	}
}*/

double Function2D::value(double x, double y) {
	//define an equation for the function
	return 0;
}

Function2D::~Function2D() {
	//delete [] x;
	//delete [] y;
	//delete [] z;
}

void Function2D::saveFunction () {
	std::ofstream fTable("fTable2.bin");
	for (int i = 1; i < this->size + 1; i++) {
		for (int j = 1; j < this->size + 1; j++) {
			fTable << std::fixed << std::setprecision(10)<< this->x[i] << "\t"
		    << this->y[j] << "\t" << this->z[j + (i - 1) * size] << std::endl;
		}
		fTable << std::endl;
	}
	fTable.close();
}

/*void Function2D::simpson(double a, double b, double y) {
	double h = (b - a) / (2.0 * (double)(size));
	double simpson = .0;
	double x = a + h;
	int i = 1;
	while (i < size + 1) {
		simpson = simpson + (value(x + h, y) + 4.0 * value(x, y) + value(x - h, y)) *  h / 3.0;
		x = x + 2.0 * h;
		i = i + 1;
	}
	integral = simpson;
}

void Function2D::saveInt() {
	std::ofstream file("fQuadrat.bin");
	file << std::fixed << std::setprecision(15) << 4.0 * integral;
	file.close();
}*/

double Function2D::phase(double r) {
	return M_PI * r;
}