
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Array.h"
#include "Mjday.h"
#include "position.h"
#include "ode.h"
#include "timediff.h"
#include <math.h>
#include "iodkf.h"
#include "globales.h"
#include "LTC.h"
#include "IERS.h"
#include "VarEqn.h"
#include "Accel.h"
#include "gmst.h"
#include "TimeUpdate.h"
#include "AzElPa.h"
#include "MeasUpdate.h"

#pragma warning (disable : 4996)

int main() {

    extern double **PC, **Cnm, **Snm, **eopdata;
    extern int n1eqn;
    extern Param;
    
   
    double **obs, aux1, aux2, ss, az, el, Dist, sigma_range, sigma_az, sigma_el, lat, lon, alt, *Rs, *Y0_apr, Mjd0, Mjd_UTC;
    FILE *fp;
    int f, c, n, m, nobs, i, Y, M, D, hh, mm, T;
    char line[55], y[5], mo[3], d[3], h[3], mi[3], s[7], a[9], e[9], di[10];

    double* Azim = vector(1);
    double* Elev = vector(1);
    double* dAds = vector(3);
    double* dEds = vector(3);






    PC = array(2285, 1020);
    fp = fopen("../Data/DE430Coeff.txt", "r");

    if (fp == NULL) {
        printf("Fail open DE430Coeff.txt file \n");
        exit(EXIT_FAILURE);
    }

    for (n = 0; n <= 180; ++n) {
        for (m = 0; m <= n; ++m) {
            fscanf(fp, "%d%d%lf%lf%lf%lf", &f, &c, &Cnm[n + 1][m + 1], &Snm[n + 1][m + 1], &aux1, aux2);
        }
    }
    fclose(fp);
   
    eopdata = array(13, 21413); 
    fp = fopen("../Data/eop19620101.txt", "r");  //lectura de fichero binario

    if (fp == NULL) {
        printf("Fail open eop19620101.txt file \n");
        exit(EXIT_FAILURE);
    }

    for (f = 0; f <= 21413; ++f) {
        fscanf(fp, "%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf", &eopdata[0][f], &eopdata[1][f], &eopdata[2][f], &eopdata[3][f], &eopdata[4][f],
                &eopdata[5][f], &eopdata[6][f], &eopdata[7][f], &eopdata[8][f], &eopdata[9][f], &eopdata[10][f], &eopdata[11][f], &eopdata[12][f]);
    }
    fclose(fp);

    nobs = 46;
    obs = array(nobs, 4);

    fp = fopen("../Data/GEOS3.txt", "r");

    if (fp == NULL) {
        printf("Fail open GEOS3.txt file \n");
        exit(EXIT_FAILURE);
    }

    
    for (i = 0; i <= nobs; ++i) {
        fgets(line, sizeof (line) + 2, fp);
       
        strncpy(y, &line[0], 4);
        y[4] = '\0';
        Y = atoi(y);
        
        strncpy(mo, &line[5], 2);
        mo[2] = '\0';
        M = atoi(mo);
       
        strncpy(d, &line[8], 2);
        d[2] = '\0';
        D = atoi(d);
       
        strncpy(h, &line[12], 2);
        h[2] = '\0';
        hh = atoi(h);
       
        strncpy(mi, &line[15], 2);
        mi[2] = '\0';
        mm = atoi(mi);
        
        strncpy(s, &line[18], 6);
        s[6] = '\0';
        ss = atof(s);
        
        strncpy(a, &line[25], 8);
        a[8] = '\0';
        az = atof(a);
      
        strncpy(e, &line[35], 8);
        e[8] = '\0';
        el = atof(e);
        
        strncpy(di, &line[44], 9);
        di[9] = '\0';
        Dist = atof(di);
      

        obs[i][0] = Mjday(T, M, D, hh, mm, ss);
        obs[i][1] = Rad*az;
        obs[i][2] = Rad*el;
        obs[i][3] = 1e3 * Dist;
    }
    fclose(fp);

    sigma_range = 92.5; 
    sigma_az = 0.0224 * Rad;
    sigma_el = 0.0139 * Rad; 

    
    lat = Rad * 21.5748; 
    lon = Rad * (-158.2706); 
    alt = 300.20; 

    Rs = vector(3);
    Rs = position(lon, lat, alt);

   
    Y0_apr = vector(6);
    Y0_apr[0]= 6221397.62857869;
    Y0_apr[1]= 2867713.77965741;
    Y0_apr[2]= 3006155.9850995;
    Y0_apr[3]= 4645.0472516175;
    Y0_apr[4]=-2752.21591588182;
    Y0_apr[5]=-7507.99940986939;
  
    
    Mjd0 = Mjday(1995,1,29,02,38,0);
    
    Mjd_UTC = obs[8][0];
    
   
    
    AuxParam.Mjd_UTC = Mjd_UTC;
    AuxParam.n = 20;
    AuxParam.m = 20;
    AuxParam.sun = 1;
    AuxParam.moon = 1;
    AuxParam.planets = 1;
    n1eqn = 6;


    

    Y = DEInteg(Accel,0,-(obs[9][1]-Mjd0)*86400.0,1e-13,1e-6,6,Y0_apr);




    double** P = array(6, 6);


   
    for (i = 0; i < 3; i++) {

        P[i][i] = 1e8;
    }

    for (i = 4; i < 6; i++) {

        P[i][i] = 1e3;
    }


    double ** LT = LTC(lon, lat);

   double ** yPhi = array(42, 1);
   double *  Phi = vector(6);


  int  t = 0;


  double* x_pole = vector(1);
  double* y_pole = vector(1);
  double* UT1_UTC = vector(1);
  double* LOD = vector(1);
  double* dpsi = vector(1);
  double* deps = vector(1);
  double* dx_pole = vector(1);
  double* dy_pole = vector(1);
  double* TAI_UTC = vector(1);


  double* UT1_TAI = vector(1);
  double* UTC_GPS = vector(1);
  double* UT1_GPS = vector(1);
  double* TT_UTC = vector(1);
  double* GPS_UTC = vector(1);

  for (i = 0; i < nobs; i++) {

     double  t_old = t;
     double ** Y_old = Y;

     
          Mjd_UTC = obs[i][ 1];
          t = (Mjd_UTC - Mjd0) * 86400.0;

       IERS( Mjd_UTC, 'l', x_pole, y_pole, UT1_UTC, LOD, dpsi, deps, dx_pole, dy_pole, TAI_UTC);
       timediff(*UT1_UTC,* TAI_UTC, UT1_TAI, UTC_GPS, UT1_GPS, TT_UTC, GPS_UTC);
     double  Mjd_TT = Mjd_UTC + *TT_UTC / 86400;
     double  Mjd_UT1 = Mjd_TT + (UT1_UTC - TT_UTC) / 86400.0;
      AuxParam.Mjd_UTC = Mjd_UTC;
      AuxParam.Mjd_TT = Mjd_TT;
      int ii;
      for (i = 0; i < 5; i++) {
          yPhi[ii] = Y_old[ii];
          int j;
          for (j=0;j<5;j++)
              if (ii == j)
                  yPhi[6 * j + ii] = 1;
              else
                  yPhi[6 * j + ii] = 0;
        
             
      }
          yPhi = DEInteg(VarEqn, 0, t - t_old, 1e-13, 1e-6, 42, yPhi);
          int j;
          for (j =0 ; j < 6; j++) {
              
               //   Phi(:, j) = yPhi[6 * j + 1][6 * j + 6];
          }

          double *Y = DEInteg(Accel, 0, t - t_old, 1e-13, 1e-6, 6, Y_old);

      
          double theta = gmst(Mjd_UT1);
          double **U = R_z(theta);
          double* r = vector(3);
         
          r[0] = Y[0];
          r[1] = Y[1];
          r[2] = Y[2];


       //   s = LT * (U * r - Rs);



         
          P = TimeUpdate(P, Phi,0);

  
           AzElPa(s, Azim, Elev, dAds, dEds);
         //  double *dAdY = [dAds * LT * U, zeros(1, 3)];
           double K;
      

           // [K, Y, P] = MeasUpdate ( Y, obs(i,2), Azim, sigma_az, dAdY, P, 6 );
   
         //  MeasUpdate(Y, obs[i][2], Azim, sigma_az, dAdY, 6, P,6,6,K);

     
           r[0] = Y[0];
           r[1] = Y[1];
           r[2] = Y[2];

         // s = LT * (U * r - Rs);

         AzElPa(s, Azim, Elev, dAds, dEds);
        //  dEdY = [dEds * LT * U, zeros(1, 3)];

     //[K, Y, P] = MeasUpdate ( Y, obs(i,3), Elev, sigma_el, dEdY, P, 6 );
    
    //      MeasUpdate(Y, obs[i][ 3], Elev, sigma_el, dEdY, P, 6,Y, P,6,6,K);

     
          r[0] = Y[0];
          r[1] = Y[1];
          r[2] = Y[2];

        //   s = LT * (U * r - Rs);
          Dist = norma(s,3); 
         // dDds = (s / Dist)'';
          //dDdY = [dDds * LT * U, zeros(1, 3)];

      
       // MeasUpdate(Y, obs[i][4], Dist, sigma_range, dDdY, P, 6, Y, P,6,6,K);

  }



  IERS( obs[46][ 1], 'l', x_pole, y_pole, UT1_UTC, LOD, dpsi, deps, dx_pole, dy_pole, TAI_UTC);
   timediff(*UT1_UTC, *TAI_UTC, UT1_TAI, UTC_GPS, UT1_GPS, TT_UTC, GPS_UTC);
  double Mjd_TT = Mjd_UTC + *TT_UTC / 86400;
  AuxParam.Mjd_UTC = Mjd_UTC;
  AuxParam.Mjd_TT = Mjd_TT;

  double *Y0 = DEInteg(Accel, 0, -(obs[46][ 1] - obs[1][ 1]) * 86400.0, 1e-13, 1e-6, 6, Y);

  double Y_true [] = { 5753.173e3, 2673.361e3, 3440.304e3, 4.324207e3, -1.924299e3, -5.728216e3 };

  printf("\nError of Position Estimation\n");
  printf("dX%10.1f [m]\n", Y0[0] - Y_true[0]);
  printf("dY%10.1f [m]\n", Y0[1] - Y_true[1]);
  printf("dZ%10.1f [m]\n", Y0[2] - Y_true[2]);
  printf("\nError of Velocity Estimation\n");
  printf("dVx%8.1f [m/s]\n", Y0[3] - Y_true[3]);
  printf("dVy%8.1f [m/s]\n", Y0[4] - Y_true[4]);
  printf("dVz%8.1f [m/s]\n", Y0[5] - Y_true[5]);









    
 
    freeArray(PC,2285,1020);
    freeArray(Cnm,182,182);
    freeArray(Snm,182,182);
    freeArray(eopdata,13,21413);
    freeArray(obs, nobs,4);
            
            
            
            




}

