#ifndef ACCEL_H
#define ACCEL_H


#include <math.h>
#include "Array.h"
#include "Globales.h"
#include "iodkf.h"
#include "IERS.h"
#include "timediff.h"
#include "PrecMatrix.h"
#include "NutMatrix.h"
#include "Mjday_TDB.h"
#include "AccelHarmonic.h"
#include "PoleMatrix.h"
#include "GHAMatrix.h"
#include "AccelPointMass.h"
#include "timediff.h"
#include "JPL_Eph_DE430.h"

double* Accel(double x, double* Y);





#endif
