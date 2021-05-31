
#include "anglesdr.h"
void anglesdr(double az1, double az2, double az3, double el1, double el2, double el3, double Mjd1, double Mjd2, double Mjd3, double* rsite1, double* rsite2, double* rsite3, double* r2, double* v2) {

	
	double magr1in = 1.1 * R_Earth;
	double mgr2in = 1.11 * R_Earth;
	char direct = 'y';
	double tol = pow(10, -8) * R_Earth;

	double pcthg = 0.005;

	double t1 = (Mjd1 - Mjd2) * 86400.0;
	double t3 = (Mjd3 - Mjd2) * 86400.0;

	double * los1 = vector(3);
	double* los2 = vector(3);
	double* los3 = vector(3);

	los1[0] = cos(el1) * sin(az1);
	los1[1] = cos(el1) * cos(az1);
	los1[2] = sin(el1);

	los2[0] = cos(el2) * sin(az2);
	los2[1] = cos(el2) * cos(az2);
	los2[2] = sin(el2);

	los3[0] = cos(el3) * sin(az3);
	los3[1] = cos(el3) * cos(az3);
	los3[2] = sin(el3);


	double* lon1 = vector(3);
	double* lat1 = vector(3);
	double* lon2 = vector(3);
	double* lat2 = vector(3);
	double* lon3 = vector(3);
	double* lat3 = vector(3);
	double* h1 = vector(3);
	double* h2 = vector(3);
	double* h3 = vector(3);

	Geodetic(rsite1, lon1, lat1, h1);
	Geodetic(rsite2, lon2, lat2, h2);
	Geodetic(rsite3, lon3, lat3, h3);


	double ** M1 = LTC(*lon1 ,*lat1);
	double** M2 = LTC(*lon2, *lat2);
	double** M3 = LTC(*lon3, *lat3);


	double Mjd_UTC = Mjd1;






}
