#include "Accel.h"


double* Accel(double x, double * Y) {

	double * dY = vector(3);
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


	IERS(AuxParam.Mjd_UTC + x / 864, 'l',  x_pole, y_pole,  UT1_UTC,  LOD,  dpsi,  deps, dx_pole,  dy_pole, TAI_UTC);

	double* UT1_GPS = vector(1);
	double* TT_UTC= vector(1);
	double* GPS_UTC= vector(1);

	double GPS_UTC= timediff(UT1_UTC, TAI_UTC,UT1_GPS,TT_UTC,GPS_UTC);


	double Mjd_UT1 = AuxParam.Mjd_UTC + x / 86400 + (*UT1_UTC) / 86400;
	double Mjd_TT = AuxParam.Mjd_UTC + x / 86400 + (*TT_UTC) / 86400;


	 double ** P =PrecMatrix(MJD_J2000, Mjd_TT);
	 double ** N = NutMatrix(Mjd_TT);
	 double ** T=prod(P, 3, 3, N, 3, 3);
	 double** E = prod(PoleMatrix(*x_pole, *y_pole), 3, 3, prod(GHAMatrix(Mjd_UT1),3,3,T,3,3), 3, 3);


	 double* r_Mercury;
	 double* r_Venus;
	 double* r_Earth;
	 double* r_Mars;
	 double* r_Jupiter;
	 double* r_Saturn;
	 double* r_Uranus;
	 double* r_Neptune;
	 double* r_Pluto; 
	 double* r_Moon;
	 double* r_Sun;

	double  MJD_TDB = Mjday_TDB(Mjd_TT);

	JPL_Eph_DE430(MJD_TDB, r_Mercury, r_Venus, r_Earth,  r_Mars, r_Jupiter,r_Saturn,  r_Uranus, r_Neptune, r_Pluto, r_Moon, r_Sun);

	double * ww = vector(3);
	ww[0] = Y[0];
	ww[1] = Y[1];
	ww[2] = Y[2];

	double *a = AccelHarmonic(ww, E, AuxParam.n, AuxParam.m);


	//Revisar a partir de aqui

	if (AuxParam.sun) 	a = sumV(a,3, AccelPointMass(ww,3, r_Sun, GM_Sun),3);
	if (AuxParam.moon) a = sumV(a,3, AccelPointMass(ww,3, r_Moon,GM_Moon),3);

	if (AuxParam.planets) {
		
		
		a = sumV(a,3, AccelPointMass(ww,3, r_Mercury, GM_Mercury),3);
		a = sumV(a, 3, AccelPointMass(ww, 3, r_Venus, GM_Venus),3);
		a = sumV(a, 3, AccelPointMass(ww, 3, r_Mars, GM_Mars), 3);
		a = sumV(a, 3, AccelPointMass(ww, 3, r_Jupiter, GM_Jupiter), 3);
		a = sumV(a, 3, AccelPointMass(ww, 3, r_Saturn, GM_Saturn), 3);
		a = sumV(a, 3, AccelPointMass(ww, 3, r_Uranus, GM_Uranus), 3);
		a = sumV(a, 3, AccelPointMass(ww, 3, r_Neptune, GM_Neptune), 3);
		a = sumV(a, 3, AccelPointMass(ww, 3, r_Pluto, GM_Pluto), 3);
	}

	int i;
	for (i = 0; i < 3; i++) {
		dY[i] = Y[3 + i];
	}
	for (i = 0; i < 3; i++) {
		dY[i + 3] = a[i];
	}

	return dY;


		
}