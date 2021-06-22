#ifndef G_ACCELHARMONIC_H
#define G_ACCELHARMONIC_H
/** @file G_AccelHarmonic.h
 *  @brief  Computes the gradient of the Earth's harmonic gravity field 
 *
 *
 *
 *
 *
 *  @author Jorge Carrera
 *
 */
#include "Array.h"
#include "AccelHarmonic.h"

double** G_AccelHarmonic(double* r, double** U, double n_max, double m_max);
/** @brief Computes the gradient of the Earth's harmonic gravity field 
 *
 *
 *
 *  @param [in] n …   r Satellite position vector in the true-of-date system
 *  @param [in] n …   U Transformation matrix to body-fixed system
 * @param [in] n …    n Gravity model degree
 * @param [in] n …    m Gravity model order
 * 
 *  @return double **
 */


#endif 
