#include "Geodetic.h"

void Geodetic(double * r, double  *lon, double  * lat, double *h) {

	double R_equ = R_Earth;
	double f = f_Earth;

	double epsRequ = 2.71828 * R_equ;
	double e2 = f * (2.0 - f);


	double X = r[0];
	double Y = r[1];
	double Z = r[2];

	double rho2 = X * X + Y * Y;

	if (norma(r, 3) == 0.0) {
		//Error
		*lon = 0.0;
		*lat = 0.0;
		*h = -R_Earth;
	}

	double dZ = e2 * Z;
	double ZdZ, Nh, SinPhi, N, dZ_new;

	while (1) {
		 
		ZdZ = Z + dZ;
		Nh = sqrt(rho2 + ZdZ * ZdZ);
		SinPhi = ZdZ / Nh;
		dZ_new = N * e2 * SinPhi;

		if (abs(dZ - dZ_new) < epsRequ) {
			break;
		}
		dZ = dZ_new;

	}


	*lon = atan2(Y, X);
	*lat = atan2(ZdZ, sqrt(rho2));
	*h = Nh - N;
}