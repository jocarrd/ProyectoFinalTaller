#ifndef ELEMENTS_H
#define ELEMENTS_H
/** @file elements.h
 *  @brief  Computes the osculating Keplerian elements from the satellite state
   vector for elliptic orbits
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
#include "iodkf.h"


void elements(double * y, double* p, double* a, double* e, double* i, double* Omega, double* omega, double* M);
/** @brief Computes the osculating Keplerian elements from the satellite state  vector for elliptic orbits
 *
 *
 *
 *  @param [in] n …  y        State vector (x,y,z,vx,vy,vz)
 *  @param [out] n … p        semilatus rectum [m]
 * @param [out] n …  a        Semimajor axis 
 * @param [out] n …  e        Eccentricity 
 * @param [out] n …  i        Inclination [rad]
 * @param [out] n …  Omega    Longitude of the ascending node [rad]
 * @param [out] n …  omega    Argument of pericenter [rad]
 * @param [out] n …  M        Mean anomaly [rad]
 *  @return double *
 */
#endif