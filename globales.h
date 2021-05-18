
#ifndef GLOBALES_H
#define GLOBALES_H

#ifdef __cplusplus

typedef  struct{ 
    double  Mjd_UTC;
    int  n,  m,  sun,  moon,  planets;
} Param;

double **PC, **Cnm, **Snm, **eopdata; 
int n1eqn; 
Param AuxParam; 

#endif 

#endif

