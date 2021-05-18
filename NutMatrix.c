#include <stdio.h>
#include <math.h>
#include "Array.h"
#include "iodkf.h"
#include "R_x.h"
#include "R_y.h"
#include "R_z.h"
#include "NutAngles.h"
#include "MeanObliquity.h"
#include "NutMatrix.h"

double **NutMatrix(double Mjd_TT) {
    
    
    double eps, dpsi, deps;

   
    eps = MeanObliquity(Mjd_TT);

   
     NutAngles(Mjd_TT, &dpsi, &deps);

    
    return(prod(R_x(-eps-deps),3,3,prod(R_z(-dpsi),3,3,R_x(eps),3,3),3,3));
}