

#ifndef MEASUPDATE_H
#define MEASUPDATE_H



#include <stdio.h>
#include <math.h>
#include "Array.h"
#include "Globales.h"


void MeasUpdate(double* x, double z, int nx, double g, double s, double* G, int ng, double** P, int np, int n, double* K);



#endif