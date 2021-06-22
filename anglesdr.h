
#ifndef ANGLESDR_H
#define ANGLESDR_H
#include "iodkf.h"
#include "LTC.h"
#include "Geodetic.h"

/** @file anglesdr.h
 *  @brief  this function solves the problem of orbit determination using three optical sightings.
 *
 *
 *
 *
 *
 *  @author Jorge Carrera
 *
 */

void anglesdr(double az1,double az2 , double az3, double el1 , double el2 , double el3 , double Mjd1 , double Mjd2 , double Mjd3 , double * rsite1 , double * rsite2 , double * rsite3,double * r2 , double * v2);
/** @brief this function solves the problem of orbit determination using three optical sightings.
 *
 *
 *
 *  
 *  
 * @param [in] n …  az1      - azimuth at t1               rad
 *  @param [in] n …   az2      - azimuth at t2               rad
 *   @param [in] n …   az3      - azimuth at t3               rad
*   @param [in] n …   el1      - elevation at t1             rad
*  @param [in] n …    el2      - elevation at t2             rad
*  @param [in] n …   el3      - elevation at t3             rad
*   @param [in] n …   Mjd1     - Modified julian date of t1
*  @param [in] n …    Mjd2     - Modified julian date of t2
*   @param [in] n …   Mjd3     - Modified julian date of t3
*   @param [in] n …  rsite1   - ijk site1 position vector   m
*   @param [in] n …   rsite2   - ijk site2 position vector   m
*   @param [in] n …   rsite3   - ijk site3 position vector   m
*
*  
*  @param [out] n …  r        - ijk position vector at t2   m
*  @param [out] n … v        - ijk velocity vector at t2   m/s
 * 
 * 
 *  
 */
#endif 