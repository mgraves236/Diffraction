#include "function.h"

/*Function1D::Function1D (double a, double b, int numPnt) {
	this->size = numPnt;
	this->x = new double [size + 1];
	this->y = new double [size + 1];
	this->yPrime = new double [size + 1];
	this->yPrimePrime = new double [size + 1];
	this->integral = 0.0;
	//calculate values
	double h = (b - a) / (size);

	for (int i = 1; i < size + 1; i++) {
		x[i] = a + (i - 1) * h;
		y[i] = this->value(x[i]);
	}
}*/

Function1D::Function1D(int numPnt) {
	std::ifstream inFile("fTable.bin");
	if (!inFile.is_open()) {
		std::cout << "No such file.";
		exit(1);
	}
	this->size = numPnt;
	this->integral = 0.0;
	this->x = new double [size + 1];
	this->y = new double [size + 1];
	this->yPrime = new double [size + 1];
	this->yPrimePrime = new double [size + 1];
	for (int i = 1; i < this->size + 1; i++) {
		inFile >> this->x[i];
		inFile >> this->y[i];
	}
	inFile.close();
}

double Function1D::value(double x) {
	//define an equation for the function
	return 0;
}

Function1D::~Function1D() {
	//delete [] x;
	//delete [] y;
}

void Function1D::saveFunction () {
	std::ofstream fTable("fTable.bin");
	for (int i = 1; i < this->size + 1; i++) {
		fTable << std::scientific << this->x[i] << "\t" << this->y[i] << std::endl;
	}
	fTable.close();
}

void Function1D::firstDeriv3(double a, double b) {
	double h = (b - a) / (size);
	for (int i = 1; i < size + 1; i++) {
		yPrime[i] = (value(x[i] + h) - value(x[i] - h)) / (2.0 * h);
	}

}

void Function1D::saveFirstDeriv3() {
	std::ofstream file("fFirstDeriv.bin");
	for (int i = 1; i < this->size + 1; i++) {
		file << std::scientific << this->x[i] << "\t" << this->yPrime[i] << std::endl;
	}
	file.close();
}

void Function1D::secondDeriv3(double a, double b) {
	double h = (b - a) / (size);
	for (int i = 1; i < size + 1; i++) {
		yPrimePrime[i] = (value(x[i] + h) + value(x[i] - h)
				- 2.0 * value(x[i])) / (h * h);
	}
}

void Function1D::saveSecondDeriv3() {
	std::ofstream file("fSecondDeriv.bin");
	for (int i = 1; i < this->size + 1; i++) {
		file << std::scientific << this->x[i] << "\t" << this->yPrimePrime[i] << std::endl;
	}
	file.close();
}

void Function1D::firstDeriv5(double a, double b) {
	double h = (b - a) / (size);
	for (int i = 1; i < size + 1; i++) {
		yPrime[i] = 1/(12.0 * h) * (-value(x[i] + 2.0 * h) + 8.0 * value(x[i] + h) - 8.0 * value(x[i] - h) + value(x[i] - 2.0 * h));
	}

}

void Function1D::saveFirstDeriv5() {
	std::ofstream file("fFirstDeriv5.bin");
	for (int i = 1; i < this->size + 1; i++) {
		file << std::scientific << this->x[i] << "\t" << this->yPrime[i] << std::endl;
	}
	file.close();
}

void Function1D::secondDeriv5(double a, double b) {
	double h = (b - a) / (size);
	for (int i = 1; i < size + 1; i++) {
		yPrimePrime[i] = 1 / (12.0 * h * h) * (-value(x[i] - 2.0 * h) + 16.0 * value(x[i] - h) - 30.0 * value(x[i])
				+ 16.0 * value(x[i] + h) - value(x[i] + 2.0 * h));
	}
}

void Function1D::saveSecondDeriv5() {
	std::ofstream file("fSecondDeriv5.bin");
	for (int i = 1; i < this->size + 1; i++) {
		file << std::scientific << this->x[i] << "\t" << this->yPrimePrime[i] << std::endl;
	}
	file.close();
}

void Function1D::simpson(double a, double b) {
	double h = (b - a) / (2.0 * (double)(size));
	double simpson = .0;
	double x = a + h;
	int i = 1;
	while (i < size + 1) {
		simpson = simpson + (value(x + h) + 4.0 * value(x) + value(x - h)) *  h / 3.0;
		x = x + 2.0 * h;
		i = i + 1;
	}
	integral = simpson;
}

void Function1D::saveInt() {
	std::ofstream file("fQuadratPI.bin");
	file << std::fixed << std::setprecision(15) << 4.0 * integral;
	file.close();
}

void Function1D::hDependency (double a, double b) {
	std::ofstream file("fQuadratHDependency.bin");
	int n = 1;
	for (int i = 0; i < 25; i++) {
		Function1D f(a, b, n);
		// Record start time
		auto start = std::chrono::high_resolution_clock::now();
		f.simpson(a, b);
		// Record end time
		auto finish = std::chrono::high_resolution_clock::now();
		file << std::scientific << n << "\t" <<
			f.integral << "\t" << std::chrono::duration_cast<std::chrono::nanoseconds> (finish - start).count()
			<< std::endl;
		n = n * 2;
	}
	file.close();
}

