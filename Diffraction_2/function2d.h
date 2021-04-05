//
// Created by Magda on 03.03.2021.
//

#ifndef FIRST_STEPS_FUNCTION2D_H
#define FIRST_STEPS_FUNCTION2D_H

#include <fstream>
#include <iostream>
#include <cmath>
#include <iomanip>

class Function2D {

public:
	//constructor
	/*Function2D(double, double, double, double, int);
	Function2D(int);*/
	//destructor
	~Function2D();
	double value(double, double);
	void saveFunction();
	double phase(double);

	double* x;
	double* y;
	double* z;
	int size;
	double integral;
};

#endif //FIRST_STEPS_FUNCTION2D_H
