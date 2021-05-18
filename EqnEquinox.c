
#include "iodkf.h"
#include "MeanObliquity.h"
#include "NutAngles.h"
#include "Array.h"



 double EqnEquinox(double Mjd_TT) {

	double* dpsi = vector(1);
	double* deps = vector(1);

	NutAngles(Mjd_TT, dpsi, deps);
	return ((*dpsi)*cos(MeanObliquity(Mjd_TT)));


}