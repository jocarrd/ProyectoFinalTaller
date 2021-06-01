#include "VarEqn.h"

double* VarEqn(double x, double* yPhi) {

	extern  Param;

	double* x_pole = vector(1);
	double* y_pole = vector(1);
	double* UT1_UTC = vector(1);
	double* LOD = vector(1);
	double* dpsi = vector(1);
	double* deps = vector(1);
	double* dx_pole = vector(1);
	double* dy_pole = vector(1);
	double* TAI_UTC = vector(1);




	IERS(eopdata, AuxParam.Mjd_UTC, 'l', x_pole, y_pole, UT1_UTC, LOD, dpsi, deps, dx_pole, dy_pole, TAI_UTC);

	double* UT1_GPS = vector(1);
	double* TT_UTC = vector(1);
	double* GPS_UTC = vector(1);
	
	timediff(UT1_UTC, TAI_UTC, UT1_GPS, TT_UTC, GPS_UTC);

	 double Mjd_UT1 = AuxParam.Mjd_TT + (UT1_UTC - TT_UTC) / 86400;


	 double** P = PrecMatrix(MJD_J2000, AuxParam.Mjd_TT + x / 86400);
	 double** N = NutMatrix(AuxParam.Mjd_TT + x / 86400);
	 double** T = prod(N, 3, 3, P, 3, 3);
	 double** E = prod(PoleMatrix(*x_pole, *y_pole), 3, 3, prod(GHAMatrix(Mjd_UT1), 3, 3, T, 3, 3), 3, 3);

	 double* r = vector(3);
	 double* v = vector(3);

	 r[0] = yPhi[0];
	 r[1] = yPhi[1];
	 r[2] = yPhi[2];
	 v[3]= yPhi[3];
	 v[4]= yPhi[4];
	 v[5]= yPhi[5];

	 double** Phi = array(6, 6);
	 int i;
	 for (i = 0; i < 5; i++) {
		 
		// Phi(:, j) = yPhi(6 * j + 1:6 * j + 6);
	 }

	double * a = AccelHarmonic(r, E, AuxParam.n, AuxParam.m);
	double ** G = G_AccelHarmonic(r, E, AuxParam.n, AuxParam.m);

	 double **yPhip = array(42,1);
	 double **dfdy = array(6,6);

	 for (i = 0; i < 2; i++) {
		 int j;
		 for (j = 0; j < 2; j++) {
			 dfdy[i][j] = 0.0;
			 dfdy[i + 3][ j] = G[i] [j];

			 if (i == j) {
				 dfdy[i] [j + 3] = 1;
			 }
			 else {
				 dfdy[i][ j + 3] = 0;
			 }

			 dfdy[i + 3][ j + 3] = 0.0;
		 }

	 }

	double ** Phip = prod(dfdy,6,6, Phi,6,6);

	for (i = 0; i < 2; i++) {
		*yPhip[i] =  v[i];
		*yPhip[i + 3] = a[i];
	}


	for (i = 0; i < 5; i++) {
		int j;
		for (j = 0; j < 5; j++) {

			*yPhip[6 * j + i] = Phip[i][ j];
		}

	}



	 
	return yPhip;



}