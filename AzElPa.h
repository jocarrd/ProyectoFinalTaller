#ifndef AZELPA_H
#define AZELPA_H
/** @file AzElPa.h
 *  @brief   Computes azimuth, elevation and partials from local tangent coordinates
 *
 *
 *
 *
 *
 *  @author Jorge Carrera
 *
 */
#include "iodkf.h"
#include <math.h>
#include "ode.h"

double  AzElPa(double *s, double * Az,double * El , double * dAds, double * dEds);
/** @brief  Computes azimuth, elevation and partials from local tangent coordinates
 *
 *
 *
 *  @param [in] n …  s Topocentric local tangent coordinates (East-North-Zenith frame)
 * 
 *  @param [out] n …  A      Azimuth [rad]
 * @param [out] n …   E      Elevation [rad]
 * @param [out] n …   dAds   Partials of azimuth w.r.t. s
 * @param [out] n …   dEds   Partials of elevation w.r.t. s
 * 
 *  
 */
#endif