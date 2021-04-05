//
// Created by Magda on 02.04.2021.
//

#ifndef DIFFRACTION_IMAGINARY_H
#define DIFFRACTION_IMAGINARY_H


#include "function2d.h"

class Imaginary : public Function2D {
	public:
		Imaginary(double, double, double, double, int, double, double, double);
		double	value(double, double, double, double, double);
		void simpson(double, double, double, double, double, double, double);
		void saveInt();
};



#endif //DIFFRACTION_IMAGINARY_H
