
#ifndef ACCELHARMONIC_H
#define ACCELHARMONIC_H

/** @file AccelHarmonic.h
 *  @brief   Computes the acceleration due to the harmonic gravity field of the  central body
 *
 *
 *
 *
 *
 *  @author Jorge Carrera
 *
 */


#include "Globales.h"
#include "Array.h"
#include "Legendre.h"
#include <math.h>



double* AccelHarmonic(double* r, double** E, int n_max, int m_max);

/** @brief Computes the acceleration of an Earth orbiting satellite
 *
 *
 *
 *  @param [in] n …  r   Satellite position vector in the inertial system
 *  @param [in] n … E  Transformation matrix to body-fixed system
 *  @param [in] n …  n_max   Maximum degree
 *  @param [in] n … m_max   Maximum order (m_max<=n_max; m_max=0 for zonals, only)
 *  @param [out] n …  a  Acceleration (a=d^2r/dt^2)
 *  @return double *
 */





#endif













