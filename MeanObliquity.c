#include "MeanObliquity.h"
#include "iodkf.h"
#include <math.h>

double MeanObliquity(double Mjd_TT){
    double T, MOblq;
    T = (Mjd_TT - MJD_J2000)/36525.0;
    MOblq = Rad *( 84381.448/3600-(46.8150+(0.00059-0.001813*T)*T)*T/3600 );
    
    return MOblq;
}
