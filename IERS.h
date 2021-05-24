

#ifndef IERS_H
#define IERS_H

#include "iodkf.h"
#include "globales.h"
#include "Array.h"

void IERS(double Mjd_UTC, char interp, double* x_pole, double* y_pole, double* UT1_UTC, double* LOD, double* dpsi, double* deps, double* dx_pole, double* dy_pole, double* TAI_UTC);


#endif