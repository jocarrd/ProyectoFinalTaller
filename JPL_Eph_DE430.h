

#ifndef JPL_EPH_DE430_H
#define JPL_EPH_DE430_H
/** @file JPL_Eph_DE430.h
 *  @brief  Computes the sun, moon, and nine major planets' equatorial               position using JPL Ephemerides
 *
 *
 *
 *
 *
 *  @author Jorge Carrera
 *
 */
#include "Cheb3D.h"
#include "iodkf.h"
#include "Array.h"
#include "globales.h"

void JPL_Eph_DE430( double Mjd_TDB , double *r_Mercury , double *r_Venus,
                    double *r_Earth, double *r_Mars , double *r_Jupiter,
                    double *r_Saturn , double *r_Uranus , double *r_Neptune,
                    double *r_Pluto, double *r_Moon, double *r_Sun);

/** @briefComputes the sun, moon, and nine major planets' equatorial
 *
 *
 *
 *  @param [in] n …   Mjd_TDB         Modified julian date of TDB
 *  
 *  @param [out] n … r_Earth(solar system barycenter (SSB)
 *  @param [out] n … r_Mars
 *  @param [out] n … r_Mercury
 *  @param [out] n … r_Venus
 * @param [out] n … r_Jupiter
 * @param [out] n … r_Saturn
 * @param [out] n … r_Uranus
 * @param [out] n … r_Neptune
 * @param [out] n … r_Pluto
 * @param [out] n … r_Moon
 * @param [out] n … r_Sun
 * 
 */
#endif /* JPL_EPH_DE430_H */

