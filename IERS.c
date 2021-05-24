#include "IERS.h"



void IERS( double Mjd_UTC, char interp, double* x_pole, double* y_pole, double* UT1_UTC, double* LOD, double* dpsi, double* deps, double* dx_pole, double* dy_pole, double* TAI_UTC) {

    extern double** eopdata;
    double mjd, fixf, mfme;
    double* vv;
    double* preeop,* eop;
    double * nexteop;



	if (interp == '1') {

		 mjd = (floor(Mjd_UTC));
         vv = vector(21413);

         int i;
         for (i = 0; i < 21413; ++i) {
             vv[i]=eopdata[3][i];
         }

         i = find2(vv, 21413, mjd);
         freeVector(vv, 21413);

         preeop = vector(13);
         nexteop = vector(13);
         int j;
         for (j = 0; j < 21413; ++j) {
             preeop[j] = eopdata[j][i];
             nexteop[j] = eopdata[j][i+1];
         }



         mfme = 1440 * (Mjd_UTC - floor(Mjd_UTC));
         fixf = mfme / 1440;

         * x_pole = preeop[4] + (nexteop[4] - preeop[4]) * fixf;
         *y_pole = preeop[5] + (nexteop[5] - preeop[5]) * fixf;
         *UT1_UTC = preeop[6] + (nexteop[6] - preeop[6]) * fixf;
         *LOD = preeop[7] + (nexteop[7] - preeop[7]) * fixf;
         *dpsi = preeop[8] + (nexteop[8] - preeop[8]) * fixf;
         *deps = preeop[9] + (nexteop[9] - preeop[9]) * fixf;
         *dx_pole = preeop[10] + (nexteop[10] - preeop[10]) * fixf;
         *dy_pole = preeop[11] + (nexteop[12] - preeop[12]) * fixf;
         *TAI_UTC = preeop[13];


         *x_pole = *x_pole / (Arcs);
         *y_pole = *y_pole / (Arcs);
         *dpsi = *dpsi / (Arcs);
         *dpsi = *deps / (Arcs);
         *dx_pole = *dx_pole/(Arcs);
         *dy_pole = *dy_pole / (Arcs);




	 }

	if (interp == 'n') {
		
		mjd = floor(Mjd_UTC);
        vv = vector(21413);
        int i;
        for (i = 0; i < 21413; ++i) {
            vv[i] = eopdata[3][i];
        }
        i = find2(vv, 21413, mjd);
        freeVector(vv, 21413);

        eop = vector(13);
        int j;
        for (j = 0; j < 13; ++j) {
            eop[j] = eopdata[j][i];
        }
		

    *x_pole  = eop[5]/(Arcs);  
    *y_pole  = eop[6]/ (Arcs);
	*UT1_UTC = eop[7];             
    *LOD     = eop[8];           
    *dpsi    = eop[9]/ (Arcs);
    *deps    = eop[10]/ (Arcs);
    *dx_pole = eop[11]/ (Arcs);
    *dy_pole = eop[12]/ (Arcs);
	*TAI_UTC = eop[13];            
       






	}


}
