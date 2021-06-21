#ifndef ACCELPOINTMASS_H
#define ACCELPOINTMASS_H
/** @file AccelPointMass.h
 *  @brief   Computes the perturbational acceleration due to a point mass
 *
 *
 *
 *
 *
 *  @author Jorge Carrera
 *
 */
#include "iodkf.h"
#include "Array.h"

double* AccelPointMass(double* r, int nr, int ns, double GM);
/** @brief  Computes the perturbational acceleration due to a point mass
 *
 *
 *
 *  @param [in] n …  r   Satellite position vector 
 *  @param [in] n …  s  Point mass position vector
 *  @param [in] n …  GM  Gravitational coefficient of point mass
 *  @param [out] n …  a  Acceleration (a=d^2r/dt^2)
 *  @return double *
 */


#endif
