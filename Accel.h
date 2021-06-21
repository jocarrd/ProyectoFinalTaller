#ifndef ACCEL_H
#define ACCEL_H

/** @file Accel.h
 *  @brief  Computes the acceleration of an Earth orbiting satellite due to 
%    - the Earth's harmonic gravity field, 
%    - the gravitational perturbations of the Sun and Moon
%    - the solar radiation pressure and
%    - the atmospheric drag
 *
 *  
 *  
 *  
 *
 *  @author Jorge Carrera
 *  
 */






#include <math.h>
#include "Array.h"
#include "Globales.h"
#include "iodkf.h"
#include "IERS.h"
#include "timediff.h"
#include "PrecMatrix.h"
#include "NutMatrix.h"
#include "Mjday_TDB.h"
#include "AccelHarmonic.h"
#include "PoleMatrix.h"
#include "GHAMatrix.h"
#include "AccelPointMass.h"
#include "timediff.h"
#include "JPL_Eph_DE430.h"

double* Accel(double x, double* Y);
/** @brief Computes the acceleration of an Earth orbiting satellite
 *
 *  
 *
 *  @param [in] n …  Mjd_TT  Terrestrial Time (Modified Julian Date)
 *  @param [in] n …Y  Satellite state vector in the ICRF/EME2000 system
 *  @param [out] n … dY Acceleration (a=d^2r/dt^2) in the ICRF/EME2000 system
 *  @return double *
 */





#endif
