#ifndef GEODETIC_H
#define GEODETIC_H
/** @file Geodetic.h
 *  @brief  geodetic coordinates (Longitude [rad], latitude [rad], altitude [m])  from given position vector (r [m])
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

void Geodetic(double* r, double* lon, double* lat, double* h);
/** @brief geodetic coordinates (Longitude [rad], latitude [rad], altitude [m])  from given position vector (r [m])
 *
 *
 *
 *  @param [in] n … r  position vector (r [m])
 *  @param [out] n … Longitude [rad]
 * @param [out] n … latitude [rad]
 * @param [out] n … altitude [m]
 * 
 */


#endif