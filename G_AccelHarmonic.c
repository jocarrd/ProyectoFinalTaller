#include "G_AccelHarmonic.h"

double** G_AccelHarmonic(double * r, double **U, double n_max, double m_max) {

	double d = 1.0;
	double** G = array(3, 3);
	double* dr = vector(3);
	int i;
	for (i = 0; i < 2; i++) {

		dr[i] = d;
		double* da =  restV(AccelHarmonic(sumV(r, 3 ,dr, 3), U, n_max, m_max),3, AccelHarmonic(restV(r, 3, dr, 3) , U, n_max, m_max),3);
		int j;
		for (j = 0; j < 2; j++) {
			G[j][i] = da[j] / d;
		}
		

		  
	}


}