#ifndef VAREQN_H
#define VAREQN										_H


#include <math.h>
#include "iodkf.h"
#include "globales.h"
#include "Array.h"
#include "AccelHarmonic.h"
#include "IERS.h"
#include "timediff.h"
#include "PrecMatrix.h"
#include "NutMatrix.h"
#include "G_AccelHarmonic.h"
#include "PoleMatrix.h"
#include "GHAMatrix.h"
/** @file VarEqn.h
 *  @brief  Computes the variational equations, i.e. the derivative of the state vector
  and the state transition matrix
 *
 *
 *
 *
 *
 *  @author Jorge Carrera
 *
 */

double* VarEqn(double x, double* yPhi);
/** @brief Computes the variational equations, i.e. the derivative of the state vector
  and the state transition matrix
 *
 *
 *
 *  @param [in] n …  x  Time since epoch in [s]
 *  @param [in] n …yPhi        (6+36)-dim vector comprising the state vector (y) and the
     state transition matrix (Phi) in column wise storage order
 *  @param [out] n … yPhip       Derivative of yPhi
 *  @return double *
 */

#endif
