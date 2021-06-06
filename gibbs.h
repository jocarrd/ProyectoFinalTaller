#ifndef GIBBS_H
#define GIBBS_H

#include "Array.h"
#include <math.h>
#include "iodkf.h"
#include "unit.h"
#include "angl.h"

void gibbs(double* r1, double* r2, double* r3, double* v2, double theta);

#endif