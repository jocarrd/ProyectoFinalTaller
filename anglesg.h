#ifndef ANGLESG_H
#define ANLGESG_H

#include "globales.h"
#include "iodkf.h"
#include "Array.h"
#include "Geodetic.h"
#include "LTC.h"
#include "IERS.h"
#include "timediff.h"
#include "PrecMatrix.h"
#include "NutMatrix.h"
#include "PoleMatrix.h"
#include "GHAMatrix.h"
#include "rpoly.h"
#include "angl.h"
#include "elements.h"
#include "hgibbs.h"


void anglesg(double az1, double az2, double  az3, double el1, double  el2, double  el3, double  Mjd1, double  Mjd2, double  Mjd3, double* Rs1, double* Rs2, double* Rs3, double* r2, double* v2);


#endif
