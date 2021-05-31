#include "AzElPa.h"

double  AzElPa(double * s, double * Az, double * El, double * dAds, double * dEds) {

	double rho = sqrt(s[1] * s[1] + s[2] * s[2]);
	*Az = atan2(s[1], s[2]);

	if (*Az < 0.0) {
		*Az = *Az + pi2;
	}
	*El = atan(s[3] / rho);


	//Estas son las dos lineas que faltan
	dAds[0] = s[2] / (rho * rho);
	dAds[1] = -s[1] / (rho * rho);
	dAds[2] = 0.0;

	dEds[0] = -s[1] * s[3] / rho;
	dEds[1] = -s[2] * s[3] / rho;
	dEds[2] = rho / dot(s, s);

	


}