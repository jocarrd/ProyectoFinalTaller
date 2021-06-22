#ifndef POLEMATRIX_H
#define POLEMATRIX_H

#include "R_x.h"
#include "R_y.h"
#include "Array.h"
/** @file PoleMatrix.h
 *  @brief  Transformation from pseudo Earth-fixed to Earth-fixed coordinates
   for a given date
 *
 *
 *
 *
 *
 *  @author Jorge Carrera
 *
 */
double **  PoleMatrix(double xp, double yp);
/** @brief Transformation from pseudo Earth-fixed to Earth-fixed coordinates
   for a given date
 *
 *
 *
 *  @param [in] n …  Pole coordinte(xp,yp)
 *  @param [out] n … PoleMat   Pole matrix
 *  @return double **
 */
#endif 
