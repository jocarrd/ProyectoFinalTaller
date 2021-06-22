#ifndef PRECMATRIX_H
#define PRECMATRIX_H
/** @file PrecMatrix.h
 *  @brief   Precession transformation of equatorial coordinates
 *
 *
 *
 *
 *
 *  @author Jorge Carrera
 *
 */
#include "globales.h"
#include "iodkf.h"
#include "Array.h"
#include "R_y.h"
#include "R_z.h"

double ** PrecMatrix(double Mjd_1 , double Mjd_2);
/** @brief  Precession transformation of equatorial coordinates
 *
 *
 *
 *  @param [in] n … Mjd_1     Epoch given (Modified Julian Date TT)
 *  @param [in] n … Epoch to precess to (Modified Julian Date TT)
 *  @param [out] n … PrecMat   Precession transformation matrix
 *  @return double **
 */


#endif