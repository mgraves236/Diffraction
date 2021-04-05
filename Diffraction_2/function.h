//
// Created by Magda on 03.03.2021.
//

#ifndef FIRST_STEPS_FUNCTION_H
#define FIRST_STEPS_FUNCTION_H

#include <fstream>
#include <iostream>
#include <cmath>
#include <chrono>
#include <iomanip>

class Function1D {

public:
	//destructor
	~Function1D();
	double value(double);
	void saveFunction();
	void saveFirstDeriv3();
	void saveSecondDeriv3();
	void firstDeriv3(double, double);
	void secondDeriv3(double, double);
	void saveFirstDeriv5();
	void saveSecondDeriv5();
	void firstDeriv5(double, double);
	void secondDeriv5(double, double);
	void simpson(double, double);
	void saveInt();
	void hDependency (double, double);

	double * x;
	double* y;
	double* yPrime;
	double* yPrimePrime;
	double integral;
	int size;
};

#endif //FIRST_STEPS_FUNCTION_H
