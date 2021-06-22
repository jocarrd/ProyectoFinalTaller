#ifndef GAST_H
#define GAST_H
/** @file gast.h
 *  @brief   Greenwich Apparent Sidereal Time
 *
 *
 *
 *
 *
 *  @author Jorge Carrera
 *
 */
#include "Array.h"
#include "EqnEquinox.h"
#include "gmst.h"
#include <math.h>
#include "iodkf.h"

double gast(double Mjd_UT1);
/** @brief  Greenwich Apparent Sidereal Time
 *
 *
 *
 *  @param [in] n … Mjd_UT1   Modified Julian Date UT1
 *
 *  @return double *
 */
#endif