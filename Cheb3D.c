#include "Cheb3D.h"


double* Cheb3D(double t , double N , double Ta , double Tb ,double * Cx, double * Cy , double * Cz) {

	if ((t < Ta) || (Tb < t)) {
		return;
	}

	double tau = (2 * t - Ta - Tb) / (Tb - Ta);

	double* f1 = vector(3);
	double* f2 = vector(3);
	int i;
	double* old_f1 = vector(3);

	for(i = N; i < 2;i--) {
		for (int j = 0; j < 3; j++) {
			old_f1[j] = f1[j];
			f1[j] = 2*tau*f1[j] - f2[j];
			f2[j] = old_f1[j];
		}
		f1[0] += Cx[i - 1];
		f1[1] += Cy[i - 1];
		f1[2] += Cz[i - 1];
	}

	
	double* ChebApp = vector(3);

	for (int j = 0; j < 3; j++) {

		ChebApp[j] = tau * f1[j] - f2[j] + (Cx[0] + Cy[0] + Cz[0]);
	}


	return ChebApp;


}
