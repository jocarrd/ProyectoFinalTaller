#include "GHAMatrix.h"

double** GHAMatrix(double Mjd_UT1) {

	return (R_z(gast(Mjd_UT1)));
}