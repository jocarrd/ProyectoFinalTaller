#include "elements.h"



void elements(double * y, double* p, double* a, double* e, double* i, double* Omega, double* omega, double* M) {


	double* r = vector(3);
	double* v = vector(3);
	
	r[0] = y[0];
	r[1] = y[1];
	r[2] = y[2];

	v[0] = y[3];
	v[1] = y[4];
	v[2] = y[5];


	double* h = cross(r, v);

	double	magh = norma(h,3);
	*p =  magh * magh / GM_Earth;
	 double H = norma(h,3);

	 *Omega = atan2(h[1], -h[2]);
	* Omega = fmod(*Omega, pi2); 
	 *i = atan2(sqrt(h[1] * h[1] + h[2] * h[2]), h[3]);
	double  u = atan2(r[3] * H, -r[1] * h[2] + r[2] * h[1]); 


	double R = norma(r,3); 

		*a = 1 / (2 / R - dot(v,3, v,3) / GM_Earth);

		 double eCosE = 1 - R / (*a); 
		 double eSinE = dot(r, 3, v, 3) / sqrt(GM_Earth * (*a));   

		double e2 = eCosE * eCosE + eSinE * eSinE;
		*e = sqrt(e2); 
		 double E = atan2(eSinE, eCosE);

		 *M = fmod(E - eSinE, pi2); 

		 double nu = atan2(sqrt(1.0 - e2) * eSinE, eCosE - e2); 

		 *omega = fmod(u - nu, pi2);
	


}






