
#ifndef GHAMATRIX_H
#define GHAMATRIX_H
/** @file GHAMatrix.h
 *  @brief Transformation from true equator and equinox to Earth equator and 
   Greenwich meridian system 
 *
 *
 *
 *
 *
 *  @author Jorge Carrera
 *
 */

#include "R_z.h"

double** GHAMatrix(double Mjd_UT1);
/** @brief Transformation from true equator and equinox to Earth equator and    Greenwich meridian system
 *
 *
 *
 *  @param [in] n …  Mjd_UT1   Modified Julian Date UT1
 *  
 *  @return double **
 */
#endif