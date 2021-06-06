#include "LTC.h"
#include "R_y.h"
#include "R_z.h"

double ** LTC(double log, double lat) {

	double ** M = array(3, 3);

	M = prod(R_y(-1.0 * lat), 3, 3, R_z(log), 3, 3);

	double * aux;
	for (int i = 0; i < 3; i++) {

		aux = M[0, i];
		M[0, i] = M[1, i];
		M[1, i] = M[2, i];
		M[2, i] = aux;
	}
	return M;

}