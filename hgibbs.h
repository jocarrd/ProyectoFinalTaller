#ifndef HGIBBS_H
#define HGIBBS_H
/** @file hgibbs.h
 *  @brief  this function implements the herrick-gibbs approximation for orbit  determination, and finds the middle velocity vector for the 3 given
 position vectors.
 *
 *
 *
 *
 *
 *  @author Jorge Carrera
 *
 */
double* hgibbs(double* r1, double* r2, double* r3, double Mjd1, double Mjd2, double Mjd3, char  error[]);
/** @brief this function implements the herrick-gibbs approximation for orbit  determination, and finds the middle velocity vector for the 3 given
 position vectors.
 *
 *
 *
 *  @param [in] n … r1          - ijk position vector #1         m
 *  @param [in] n …r2          - ijk position vector #2         m
 * @param [in] n …r3          - ijk position vector #3         m
 * @param [in] n …Mjd1        - julian date of 1st sighting    days from 4713 bc
 * @param [in] n … Mjd2        - julian date of 2nd sighting    days from 4713 bc
 * @param [in] n … Mjd3        - julian date of 3rd sighting    days from 4713 bc
 * 
 *  @param [out] n … v2          - ijk velocity vector for r2     m/s
 *  @param [out] n … theta       - angl between vectors           rad
 *  @return double *
 */
#endif
