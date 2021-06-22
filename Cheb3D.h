#pragma once
#ifndef CHEB3D_H
#define CHEB3D_H
/** @file Cheb3D.h
 *  @brief  Chebyshev approximation of 3-dimensional vectors
 *
 *
 *
 *
 *
 *  @author Jorge Carrera
 *
 */

#include "Array.h"

double* Cheb3D(double t, double N, double Ta, double Tb, double* Cx, double* Cy, double* Cz);

/** @brief Chebyshev approximation of 3-dimensional vectors
 *
 *
 *
 *  @param [in] n …  N       Number of coefficients
 *  @param [in] n …  Ta      Begin interval
 *  @param [in] n …  Tb      End interval
 *  @param [in] n …  Cx      Coefficients of Chebyshev polyomial (x-coordinate)
 *  @param [in] n …  Cy      Coefficients of Chebyshev polyomial (y-coordinate)
 *  @param [in] n …  Cz      Coefficients of Chebyshev polyomial (z-coordinate)
 *  @return double *
 */

#endif
