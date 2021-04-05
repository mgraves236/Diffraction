//
// Created by Magda on 02.04.2021.
//

#ifndef DIFFRACTION_REAL_H
#define DIFFRACTION_REAL_H

#include "function2d.h"

class Real : public Function2D {
	public:
		Real(double, double, double, double, int, double, double, double);
		double	value(double, double, double, double, double);
		void simpson(double, double, double, double, double, double, double);
		void saveInt();

};


#endif //DIFFRACTION_REAL_H
