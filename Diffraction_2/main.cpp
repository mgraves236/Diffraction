#include <iostream>
#include <cmath>

#include "Real.h"
#include "Imaginary.h"

int main() {
	/* initial parameters*/
	double c = -10000.0;
	double d = 10000.0;
	double a = 2.0;
	double dDif = 20000.0;
	double amp = 10.0;
	int numPnt = 5000;
	int numInt = 100;
	double lambda = 50.0;
	int numSlit = 10;
	double s = 10.0; //distance between two slits

	double k = 2.0 * M_PI / lambda;
	double complexAmp[numPnt + 1];

	Real fReal(-a / 2.0, a / 2.0, c, d, numPnt, dDif, k, amp);
	Imaginary fIm(-a / 2.0, a / 2.0, c, d, numPnt, dDif, k, amp);

	double real[numSlit * numPnt];
	double im[numPnt * numSlit];
	// double slit
	std::ofstream file2("wave2.bin");
	for (int i = 1; i <= numPnt; i++) {
		for (int j = 1; j <= numSlit; j++) {
			fReal.simpson(2 * (j - 1) * s - a / 2.0, 2 * (j - 1) * s + a / 2.0, fReal.y[i], dDif, k, amp, numInt);
			fIm.simpson(2 * (j - 1) * s - a / 2.0, 2 * (j - 1) * s + a / 2.0, fIm.y[i], dDif, k, amp, numInt);
			real[i] = real[i] + fReal.integral;
			im[i] = im[i] + fIm.integral;
		}
		complexAmp[i] = real[i] * real[i] + im[i] * im[i];
		file2 << fReal.y[i] << "\t" << complexAmp[i] << std::endl;
	}
	file2.close();
	// integration
	std::ofstream file("wave.bin");
	for (int i = 1; i <= numPnt; i++) {
		fReal.simpson(s - a / 2.0, s + a / 2.0, fReal.y[i], dDif, k, amp, numInt);
		fIm.simpson(s - a / 2.0, s + a / 2.0, fIm.y[i], dDif, k, amp, numInt);
		complexAmp[i] = fReal.integral * fReal.integral +
						fIm.integral * fIm.integral;
		file << fReal.y[i] << "\t" << complexAmp[i] << std::endl;
	}
	file.close();
	std::cout << std::endl;
	return 0;
}
