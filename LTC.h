#ifndef LTC_H
#define LTC_H
#include "iodkf.h"
#include "Array.h"

/** @file LTC.h
 *  @brief Transformation from Greenwich meridian system to 
  local tangent coordinates
 *
 *
 *
 *
 *
 *  @author Jorge Carrera
 *
 */

double ** LTC(double lon , double lat);
/** @brief Transformation from Greenwich meridian system to 
  local tangent coordinates
 *
 *
 *
 *  @param [in] n …   lon  -Geodetic East longitude [rad]
 *  @param [in] n … lat  -Geodetic latitude [rad]
 *  @param [out] n … M  -Rotation matrix from the Earth equator and Greenwich meridian to the local tangent (East-North-Zenith) coordinate system
 *  @return double **
 */
#endif 
