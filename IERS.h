

#ifndef IERS_H
#define IERS_H

/** @file IERS.h
 *  @brief  IERS: Management of IERS time and polar motion data
%
 *
 *
 *
 *
 *
 *  @author Jorge Carrera
 *
 */
#include "iodkf.h"
#include "globales.h"
#include "Array.h"

void IERS(double Mjd_UTC, char interp, double* x_pole, double* y_pole, double* UT1_UTC, double* LOD, double* dpsi, double* deps, double* dx_pole, double* dy_pole, double* TAI_UTC);
/** @brief IERS: Management of IERS time and polar motion data
 *
 *
 *
 *  @param [in] n …  Mjd_TT  Terrestrial Time (Modified Julian Date)
 *  @param [in] n …Y  Satellite state vector in the ICRF/EME2000 system
 *  @param [out] n … dY Acceleration (a=d^2r/dt^2) in the ICRF/EME2000 system
 *  @return double *
 */

#endif