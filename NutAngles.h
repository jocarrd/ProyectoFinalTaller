#ifndef NUTANGELS_H
#define NUTANGELS_H
/** @file NutAngles.h
 *  @brief  Nutation in longitude and obliquity
 *
 *
 *
 *
 *
 *  @author Jorge Carrera
 *
 */


void NutAngles(double Mjd_TT, double *dpsi, double *deps);
/** @brief Nutation in longitude and obliquity
 *
 *
 *
 *  @param [in] n … Mjd_TT     Modified Julian Date (Terrestrial Time)
 *  @param [out] n …  dpsi,deps  Nutation Angles
 *  
 */
#endif /* NUTANGELS_H */

