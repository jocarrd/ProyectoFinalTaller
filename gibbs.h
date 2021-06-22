#ifndef GIBBS_H
#define GIBBS_H
/** @file gibbs.h
 *  @brief  this function performs the gibbs method of orbit determination. 
 this  method determines the velocity at the middle point of the 3 given  position vectors.
 *
 *
 *
 *
 *
 *  @author Jorge Carrera
 *
 */
#include "Array.h"
#include <math.h>
#include "iodkf.h"
#include "unit.h"
#include "angl.h"

void gibbs(double* r1, double* r2, double* r3, double* v2, double theta);
/** @brief this function performs the gibbs method of orbit determination. 
 this  method determines the velocity at the middle point of the 3 given  position vectors.
 *
 *
 *
 *  @param [in] n …  r1          - ijk position vector #1         m
 *  @param [in] n … r2          - ijk position vector #2         m
 *  @param [in] n … r3          - ijk position vector #3         m
 *  @param [out] n … v2          - ijk velocity vector for r2     m/s
 * @param [out] n … theta       - angl between vectors           rad
 *
 *  
 */
#endif