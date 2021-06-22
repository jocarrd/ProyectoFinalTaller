#ifndef NUTMATRIX_H
#define NUTMATRIX_H
/** @file NutMatrix.h
 *  @brief  Transformation from mean to true equator and equinox
 *
 *
 *
 *
 *
 *  @author Jorge Carrera
 *
 */
double **NutMatrix(double Mjd_TT);
/** @brief Transformation from mean to true equator and equinox
 *
 *
 *
 *  @param [in] n …  Mjd_TT    Modified Julian Date (Terrestrial Time)
 *  @param [out] n … NutMat    Nutation matrix
 *  @return double **
 */
#endif /* NUTMATRIX_H */

