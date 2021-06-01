
#ifndef GLOBALES_H
#define GLOBALES_H



typedef  struct{ 
    double  Mjd_UTC;
    double Mjd_TT;
    int  n,  m,  sun,  moon,  planets;
} Param;

double **PC, **Cnm, **Snm, **eopdata; 
int n1eqn; 
Param AuxParam; 

#endif 




