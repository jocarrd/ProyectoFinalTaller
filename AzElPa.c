#include "AzElPa.h"

double  AzElPa(double * s, double * Az, double * El, double * dAds, double * dEds) {

	double rho = sqrt(s[1] * s[1] + s[2] * s[2]);
	*Az = atan2(s[1], s[2]);

	if (*Az < 0.0) {
		*Az = *Az + pi2;
	}
	*El = atan(s[3] / rho);


	//Estas son las dos lineas que faltan
	dAds = [s[2] / (rho * rho), -s[1] / (rho * rho), 0.0];
	dEds = [-s[1] * s[3] / rho, -s[2] * s[3] / rho, rho] / dot(s, s)];


}