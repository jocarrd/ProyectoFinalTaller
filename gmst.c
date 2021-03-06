#include "iodkf.h"
#include "gmst.h"
#include "Frac.h"


double gmst(double Mjd_UT1) {

	double Secs = 86400.0;

	double Mjd_0 = floor(Mjd_UT1);
	double UT1 = Secs * (Mjd_UT1 - Mjd_0);

	double T_0 = (Mjd_0 - MJD_J2000) / 36525.0;
	double T = (Mjd_UT1-MJD_J2000) / 36525.0 ;

	double gmst = 24110.54841 + 8640184.812866 * T_0 + 1.002737909350795 * UT1
		+ (0.093104 - pow(6*10,-6) * T) * T * T;

	return 2 * pi * Frac(gmst / Secs);



}