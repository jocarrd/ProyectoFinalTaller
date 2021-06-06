#include "anglesg.h"


void anglesg(double az1, double az2, double  az3, double el1, double  el2, double  el3, double  Mjd1, double  Mjd2, double  Mjd3, double* Rs1, double* Rs2, double* Rs3, double* r2, double* v2) {


   
    
    double* L1 = vector(3);
    double* L2 = vector(3);
    double* L3 = vector(3);
    L1[0] = cos(el1) * sin(az1);
    L1[1] = cos(el1) * cos(az1);
    L1[2] = sin(el1);

    L2[0] = cos(el2) * sin(az2);
    L2[1] = cos(el2) * cos(az2);
    L2[2] = sin(el2);

    L3[0] = cos(el3) * sin(az3);
    L3[1] = cos(el3) * cos(az3);
    L3[2] = sin(el3);

    double* lon1 = vector(1);
    double* lat1 = vector(1);
    double* h1 = vector(1);

    double* lon2 = vector(1);
    double* lat2 = vector(1);
    double* h2 = vector(1);

    double* lon3 = vector(1);
    double* lat3 = vector(1);
    double* h3 = vector(1);

  
    Geodetic(Rs1, lon1, lat1, h1);
    Geodetic(Rs2, lon2, lat2, h2);
    Geodetic(Rs3, lon3, lat3, h3);

    
    double **M1= LTC(*lon1, *lat1);
    double** M2 = LTC(*lon2, *lat2);
    double** M3 = LTC(*lon3, *lat3);

    double** Lb1 = prod(trasp(M1, 3), 3, 3, L1, 3, 3);
    double** Lb2 = prod(trasp(M2, 3), 3, 3, L2, 3, 3);
    double** Lb3 = prod(trasp(M3, 3), 3, 3, L3, 3, 3);
    
     double Mjd_UTC = Mjd1;

     double* x_pole = vector(1);
     double* y_pole = vector(1);
     double* UT1_UTC = vector(1);
     double* LOD = vector(1);
     double* dpsi = vector(1);
     double* deps = vector(1);
     double* dx_pole = vector(1);
     double* dy_pole = vector(1);
     double* TAI_UTC = vector(1);

    IERS( Mjd_UTC, 'l', x_pole, y_pole, UT1_UTC, LOD, dpsi, deps, dx_pole, dy_pole, TAI_UTC);


    double* UT1_TAI = vector(1);
    double* UTC_GPS = vector(1);
    double* UT1_GPS = vector(1);
    double* TT_UTC = vector(1);
    double* GPS_UTC = vector(1);

    timediff(*UT1_UTC, *TAI_UTC, UT1_TAI, UTC_GPS, UT1_GPS, TT_UTC, GPS_UTC);
     double Mjd_TT = Mjd_UTC + *TT_UTC / 86400;
    double Mjd_UT1 = Mjd_TT + (UT1_UTC - TT_UTC) / 86400;
    double ** P= PrecMatrix(MJD_J2000, Mjd_TT);
    double **N = NutMatrix(Mjd_TT);
    double** T = prod(N, 3, 3, P, 3, 3);
    double **E =  prod(prod(PoleMatrix(*x_pole, *y_pole),3,3, GHAMatrix(Mjd_UT1),3,3),3,3 , T,3,3);
    double **Lm1 = prod(trasp(E,3),3,3,Lb1,3,3);
    Rs1 = prod(trasp(E,3),3,3,Rs1,3,3);
    Mjd_UTC = Mjd2;


    IERS(Mjd_UTC, 'l', x_pole, y_pole, UT1_UTC, LOD, dpsi, deps, dx_pole, dy_pole, TAI_UTC);
    timediff(*UT1_UTC, *TAI_UTC, UT1_TAI, UTC_GPS, UT1_GPS, TT_UTC, GPS_UTC);
    Mjd_TT = Mjd_UTC + *TT_UTC / 86400;
    Mjd_UT1 = Mjd_TT + (UT1_UTC - TT_UTC) / 86400;
     P = PrecMatrix(MJD_J2000, Mjd_TT);
     N = NutMatrix(Mjd_TT);
    T = prod(N, 3, 3, P, 3, 3);
     E = prod(prod(PoleMatrix(*x_pole, *y_pole), 3, 3, GHAMatrix(Mjd_UT1), 3, 3), 3, 3, T, 3, 3);
    double **Lm2 = prod(trasp(E, 3), 3, 3, Lb1, 3, 3);
    Rs2 = prod(trasp(E, 3), 3, 3, Rs1, 3, 3);
    Mjd_UTC = Mjd3;




    IERS(Mjd_UTC, 'l', x_pole, y_pole, UT1_UTC, LOD, dpsi, deps, dx_pole, dy_pole, TAI_UTC);
    timediff(*UT1_UTC, *TAI_UTC, UT1_TAI, UTC_GPS, UT1_GPS, TT_UTC, GPS_UTC);
    Mjd_TT = Mjd_UTC + *TT_UTC / 86400;
    Mjd_UT1 = Mjd_TT + (UT1_UTC - TT_UTC) / 86400;
    P = PrecMatrix(MJD_J2000, Mjd_TT);
    N = NutMatrix(Mjd_TT);
    T = prod(N, 3, 3, P, 3, 3);
    E = prod(prod(PoleMatrix(*x_pole, *y_pole), 3, 3, GHAMatrix(Mjd_UT1), 3, 3), 3, 3, T, 3, 3);
    double** Lm3 = prod(trasp(E, 3), 3, 3, Lb1, 3, 3);
    Rs3 = prod(trasp(E, 3), 3, 3, Rs1, 3, 3);


    double tau1 = (Mjd1 - Mjd2) * 86400;
    double tau3 = (Mjd3 - Mjd2) * 86400;
    double a1 = tau3 / (tau3 - tau1);
    double a3 = -tau1 / (tau3 - tau1);
    double  b1 = tau3 / (6 * (tau3 - tau1)) * (pow(tau3 - tau1, 2) - pow(tau3,2));
    double b3 = -tau1 / (6 * (tau3 - tau1)) * (pow(tau3 - tau1, 2) - pow(tau1,2));

    double** D = array(3, 3);



    //D = inv([Lm1,Lm2,Lm3])*[Rs1,Rs2,Rs2];


    double d1s = D[2][1] * a1 - D[2][2] + D[2][3] * a3;
     double   d2s = D[2][1] * b1 + D[2][3] * b3;


  double Ccye = 2 * dot(Lm2,3,3, Rs2,3,3);

  double* poly = vector(9);


  poly[1] = 1.0;
   poly[2] = 0.0;
  poly[3] = (pow(-d1s,2) + d1s * Ccye + ( pow(norma(Rs2,3) , 2)));
  poly[4] = 0.0;
  poly[5] = 0.0;
  poly[6] = -GM_Earth * (d2s * Ccye + 2 * d1s * d2s);
  poly[7] = 0.0;
  poly[8] = 0.0;
  poly[9] =  pow(-GM_Earth ,2) * pow(d2s,2);

  struct rpoly_state* polini = real_poly_alloc(8);
  double* rootarr;
  double reales[8];
  double imaginarios[8];

  real_poly_roots_compute(poly, 8, polini, reales, imaginarios);

  rootarr = reales;

   double bigr2 = -99999990.0;

   int j;
   for (j = 0; j < 7; j++){
       if ((rootarr[j] > bigr2) && (isreal(rootarr[j]))) bigr2 = rootarr[j];     
   }

    double u = GM_Earth / pow(bigr2,3);

   double  C1 = a1 + b1 * u;
    double C2 = -1;
    double C3 = a3 + b3 * u;

    double* temp;

    double* cx = vector(3);
    cx[0] = C1;
    cx[1] = C2;
    cx[2] = C3;

    temp = esc_x_vec(-1, mat_x_vec(D,3,3,cx,3),3);
     double rho1 = temp[1] / (a1 + b1 * u);
    double rho2 = -temp[2];
    double rho3 = temp[3] / (a3 + b3 * u);

   double rhoold1 = rho1;
   double rhoold2 = rho2;
   double  rhoold3 = rho3;

   rho2 = 99999999.9;
   double ll = 0;

   double* r1=vector(3);
   double* r3 = vector(3);

   while ((abs(rhoold2 - rho2) > 1e-12) && (ll <= 0)) {
       ll = ll + 1;
       rho2 = rhoold2;

       r1 =sumV( Rs1,3 ,esc_x_vec(rho1,Lm1,3),3);
       r2 = sumV(Rs2, 3, esc_x_vec(rho2, Lm2, 3), 3);
       r3 = sumV(Rs3, 3, esc_x_vec(rho3, Lm3, 3), 3);

       double magr1 = norma(r1,3);
       double magr2 = norma(r2,3);
       double magr3 = norma(r3,3);
       

       double* v2;
       double* theta;
       double* theta1;
       double* copa;
       double* error;

      gibbs(r1, r2, r3, v2, theta, theta1, copa, error);

       if ((error == 'ok') & (*copa < pi / 180)) {
            hgibbs(r1, r2, r3, Mjd1, Mjd2, Mjd3, v2, theta, theta1, copa, error);
       }

       double* entrada = vector(6);
       entrada[0] = r2[0];
       entrada[1] = r2[1];
       entrada[2] = r2[2];
       entrada[3] = v2[0];
       entrada[4] = v2[1];
       entrada[5] = v2[2];


       double* p = vector(1);
       double* a = vector(1);
       double* e = vector(1);
       double* i = vector(1);
       double* Omega = vector(1);
       double* omega = vector(1);
       double* M = vector(1);

         elements(entrada, p, a, e, i, Omega, omega, M);

         double f1, g1, f3, g3;

           if (ll <= 8) {
               u = GM_Earth / pow(magr2,3);
              double rdot = dot(r2,3, v2,3) / magr2;
              double udot = (-3 * GM_Earth * rdot) / pow(magr2 , 4);

               double tausqr = tau1 * tau1;
              double  f1 = 1 - 0.5 * u * tausqr - (1 / 6) * udot * tausqr * tau1 - (1 / 24) * u * u * tausqr * tausqr - (1 / 30) * u * udot * tausqr * tausqr * tau1;
              double  g1 = tau1 - (1 / 6) * u * tau1 * tausqr - (1 / 12) * udot * tausqr * tausqr - (1 / 120) * u * u * tausqr * tausqr * tau1 - (1 / 120) * u * udot * tausqr * tausqr * tausqr;
               tausqr = tau3 * tau3;
              double  f3 = 1 - 0.5 * u * tausqr - (1 / 6) * udot * tausqr * tau3  - (1 / 24) * u * u * tausqr * tausqr  - (1 / 30) * u * udot * tausqr * tausqr * tau3;
              double  g3 = tau3 - (1 / 6) * u * tau3 * tausqr - (1 / 12) * udot * tausqr * tausqr  - (1 / 120) * u * u * tausqr * tausqr * tau3  - (1 / 120) * u * udot * tausqr * tausqr * tausqr;
           }
           else {

               double theta = angl(r1, r2);
               double theta1 = angl(r2, r3);

                f1 = 1 - ((magr1 * (1 - cos(theta)) / *p));
                g1 = (magr1 * magr2 * sin(-theta)) / sqrt(*p);
                f3 = 1 - ((magr3 * (1 - cos(theta1)) / *p));
                g3 = (magr3 * magr2 * sin(theta1)) / sqrt(*p);
           }

               C1 = g3 / (f1 * g3 - f3 * g1);
               C2 = -1;
               C3 = -g1 / (f1 * g3 - f3 * g1);

              double  H1 = GM_Earth * tau3 / 12;
               double H3 = -GM_Earth * tau1 / 12;
              double  H2 = H1 - H3;

               double G1 = -tau3 / (tau1 * (tau3 - tau1));
               double G3 = -tau1 / (tau3 * (tau3 - tau1));
               double G2 = G1 - G3;

              double  D1 = G1 + H1 / pow(magr1,3);
              double  D2 = G2 + H2 / pow(magr2,3);
              double  D3 = G3 + H3 / pow(magr3,3);


              double* Dx = vector(3);
              Dx[0] = D1;
              Dx[1] = D2;
              Dx[2] = D3;

                  
                  
              double* Cx = vector(3);
              Cx[0] = C1;
              Cx[1] = C2;
              Cx[2] = C3;


              double** temp2 = array(3, 3);


            //double **temp2 = -[D1 D2 D3] * [C1 C2 C3]'';  
                double temp3 = temp2[0][0];
                rhoold1 = temp3 / (a1 + b1 * u);
               rhoold2 = - *temp;
               rhoold3 = *temp / (a3 + b3 * u);



               r1 = sumV(Rs1, 3, esc_x_vec(rhoold1, Lm1, 3),3);
               r2 = sumV(Rs2, 3, esc_x_vec(rhoold2, Lm2, 3),3);
               r3 = sumV(Rs3, 3, esc_x_vec(rhoold2, Lm3, 3),3);

           

   }

                   r1 = sumV(Rs1, 3, esc_x_vec(rho1, Lm1, 3), 3);
                   r2 = sumV(Rs2, 3, esc_x_vec(rho2, Lm2, 3), 3);
                   r3 = sumV(Rs3, 3, esc_x_vec(rho3, Lm3, 3), 3);


 }
















