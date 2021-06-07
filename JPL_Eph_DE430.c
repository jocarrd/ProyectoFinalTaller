#include "JPL_Eph_DE430.h" 
#include "Array.h"
#include "iodkf.h"


void JPL_Eph_DE430( double Mjd_TBD, double *r_Mercury , double *r_Venus,
                    double *r_Earth, double *r_Mars , double *r_Jupiter,
                    double *r_Saturn , double *r_Uranus , double *r_Neptune,
                    double *r_Pluto, double *r_Moon, double *r_Sun)
{
    extern double **PC;
    double JD, * v1, * v2, * PCtemp, t1, dt, * Cx_Earth, * Nutations, * Librations,
            *Cy_Earth,*Cz_Earth, *Cx, *Cy, *Cz; 
    int i, j, *temp;
    double Mjd0, EMRAT, EMRAT1;

    JD = Mjd_TBD + 2400000.5;
       
    v1= vector(2285);
    v2= vector(2285);
   
    for(int j = 0; j<2285;++j){ 
        v1[j]=PC[j][0];
        v1[j]=PC[j][1];
    }
           
    i = find1(v1, 2285, v2, 2285, JD);
    
    freeVector(v1, 2285);
    freeVector(v2, 2285);
    
    PCtemp = vector(1020);
    for(int j = 0; j<2285;++j){
        PCtemp[j]= PC[1][j];}
    
    t1 = PCtemp[0]-2400000.5;
    dt = Mjd_TBD - t1;
    
    temp= vector(4); 
     for(j = 0; j<4;++j){
         temp[j] = 231 + 13*j; }
    

     Cx = vector(3);
     Cy = vector(3);
     Cz = vector(3);

    Cx_Earth = vector(24);  
    Cy_Earth = vector(24);
    Cz_Earth = vector(24);
    
    for(j = 0; j<3;  ++j){
        Cx_Earth[j + 12] = Cx[j];
        Cy_Earth[j + 12] = Cy[j];
        Cz_Earth[j + 12] = Cz[j];
    }
    
    for(j = 0; j < 4; ++j){
        temp[j] += 39;    }
    
   
    
     for(j = 0; j < 12;++j){
        Cx[j] = PCtemp[temp[j]-1];
        Cy[j] = PCtemp[temp[j]-1];
        Cz[j] = PCtemp[temp[j]-1];
    }
    
        for(j = 0; j<12;  ++j){
        Cx_Earth[j + 12] = Cx[j];
        Cy_Earth[j + 12] = Cy[j];
        Cz_Earth[j + 12] = Cz[j];
    }
 
    if  ((0 <=dt)  &&  (dt<=16)){        
        j=0;
        Mjd0 = t1;
    }else if((16<dt) && (dt<=32)){
        j=1;
        Mjd0 = t1+16*j;    
    } 
   

   

        r_Earth = Cheb3D(Mjd_TBD, 13, Mjd0, Mjd0 + 16, &Cx_Earth[13 * j], &Cy_Earth[13 * j], &Cz_Earth[13 * j]);
        for (i = 0; i < 3; i++)
        {
            r_Earth[i] = 1e3 * r_Earth[i];
        }

        freeVector(Cx_Earth, 26);
        freeVector(Cy_Earth, 26);
        freeVector(Cz_Earth, 26);

        double* Cx_Moon, * Cy_Moon, * Cz_Moon;

        for (i = 0; i < 3; i++)
        {
            temp[i] = 441 + 13 * j;
        }

        Cx_Moon = vector(109);
        Cy_Moon = vector(109);
        Cz_Moon = vector(109);

        for (i = 0; i < 13; i++)
        {
            Cx_Moon[i] = PCtemp[temp[0] + i - 1];
            Cy_Moon[i] = PCtemp[temp[1] + i - 1];
            Cz_Moon[i] = PCtemp[temp[2] + i - 1];
        }

        for (i = 0; i < 7; i++)
        {
            for (j = 0; j < 4; j++)
            {
                temp[j] += 39;
            }
            for (j = 0; j < 13; j++)
            {
                Cx[i] = PCtemp[temp[0] + i - 1];
                Cy[i] = PCtemp[temp[1] + i - 1];
                Cz[i] = PCtemp[temp[2] + i - 1];
            }
            for (i = 0; i < 13; i++)
            {
                Cx_Moon[i + 13] = Cx[i];
                Cy_Moon[i + 13] = Cy[i];
                Cz_Moon[i + 13] = Cz[i];
            }
        }

        if ((0 <= dt) && (dt <= 4))
        {
            j = 0;
            Mjd0 = t1;
        }
        else if ((4 < dt) && (dt <= 8))
        {
            j = 1;
            Mjd0 = t1 + 4 * j;
        }
        else if ((8 < dt) && (dt <= 12))
        {
            j = 2;
            Mjd0 = t1 + 4 * j;
        }
        else if ((12 < dt) && (dt <= 16))
        {
            j = 3;
            Mjd0 = t1 + 4 * j;
        }
        else if ((16 < dt) && (dt <= 20))
        {
            j = 4;
            Mjd0 = t1 + 4 * j;
        }
        else if ((20 < dt) && (dt <= 24))
        {
            j = 5;
            Mjd0 = t1 + 4 * j;
        }
        else if ((24 < dt) && (dt <= 28))
        {
            j = 6;
            Mjd0 = t1 + 4 * j;
        }
        else if ((28 < dt) && (dt <= 32))
        {
            j = 7;
            Mjd0 = t1 + 4 * j;
        }

        r_Moon = Cheb3D(Mjd_TBD, 13, Mjd0, Mjd0 + 16, &Cx_Moon[13 * j], &Cy_Moon[13 * j], &Cz_Moon[13 * j]);

        for (i = 0; i < 3; i++)
        {
            r_Moon[i] = 1e3 * r_Moon[i];
        }

        freeVector(Cx_Moon, 26);
        freeVector(Cy_Moon, 26);
        freeVector(Cz_Moon, 26);

        for (i = 0; i < 3; i++)
        {
            temp[i] = 753 + 11 * j;
        }

        double* Cx_Sun, * Cy_Sun, * Cz_Sun;

        Cx_Sun = vector(109);
        Cy_Sun = vector(109);
        Cz_Sun = vector(109);

        for (i = 0; i < 11; i++)
        {
            Cx_Sun[i] = PCtemp[temp[0] + i - 1];
            Cy_Sun[i] = PCtemp[temp[1] + i - 1];
            Cz_Sun[i] = PCtemp[temp[2] + i - 1];
        }

        for (i = 0; i < 4; i++)
        {
            temp[i] += 33;
        }

        for (i = 0; i < 11; i++)
        {
            Cx[i] = PCtemp[temp[0] + i - 1];
            Cy[i] = PCtemp[temp[1] + i - 1];
            Cz[i] = PCtemp[temp[2] + i - 1];
        }

        for (i = 0; i < 11; i++)
        {
            Cx_Sun[i + 11] = Cx[i];
            Cy_Sun[i + 11] = Cy[i];
            Cz_Sun[i + 11] = Cz[i];
        }

        if ((0 <= dt) && (dt <= 16))
        {
            j = 0;
            Mjd0 = t1;
        }
        else if ((16 < dt) && (dt <= 32))
        {
            j = 1;
            Mjd0 = t1 + 16 * j;
        }

        r_Sun = Cheb3D(Mjd_TBD, 11, Mjd0, Mjd0 + 16, &Cx_Sun[11 * j], &Cy_Sun[11 * j], &Cz_Sun[11 * j]);

        for (i = 0; i < 3; i++)
        {
            r_Sun[i] = 1e3 * r_Sun[i];
        }

        freeVector(Cx_Sun, 22);
        freeVector(Cy_Sun, 22);
        freeVector(Cz_Sun, 22);

        for (i = 0; i < 3; i++)
        {
            temp[i] = 3 + 14 * j;
        }

        double* Cx_Mercury, * Cy_Mercury, * Cz_Mercury;

        Cx_Mercury = vector(109);
        Cy_Mercury = vector(109);
        Cz_Mercury = vector(109);

        for (i = 0; i < 14; i++)
        {
            Cx_Mercury[i] = PCtemp[temp[0] + i - 1];
            Cy_Mercury[i] = PCtemp[temp[1] + i - 1];
            Cz_Mercury[i] = PCtemp[temp[2] + i - 1];
        }

        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                temp[j] += 42;
            }
            for (j = 0; j < 14; j++)
            {
                Cx[i] = PCtemp[temp[0] + i - 1];
                Cy[i] = PCtemp[temp[1] + i - 1];
                Cz[i] = PCtemp[temp[2] + i - 1];
            }
            for (i = 0; i < 14; i++)
            {
                Cx_Moon[i + 14] = Cx[i];
                Cy_Moon[i + 14] = Cy[i];
                Cz_Moon[i + 14] = Cz[i];
            }
        }

        if ((0 <= dt) && (dt <= 8))
        {
            j = 0;
            Mjd0 = t1;
        }
        else if ((8 < dt) && (dt <= 16))
        {
            j = 1;
            Mjd0 = t1 + 8 * j;
        }
        else if ((16 < dt) && (dt <= 24))
        {
            j = 2;
            Mjd0 = t1 + 8 * j;
        }
        else if ((24 < dt) && (dt <= 32))
        {
            j = 3;
            Mjd0 = t1 + 8 * j;
        }

        r_Mercury = Cheb3D(Mjd_TBD, 14, Mjd0, Mjd0 + 16, &Cx_Mercury[14 * j], &Cy_Mercury[14 * j], &Cz_Mercury[14 * j]);

        for (i = 0; i < 3; i++)
        {
            r_Mercury[i] = 1e3 * r_Mercury[i];
        }

        freeVector(Cx_Mercury, 28);
        freeVector(Cy_Mercury, 28);
        freeVector(Cz_Mercury, 28);

        for (i = 0; i < 3; i++)
        {
            temp[i] = 171 + 10 * j;
        }

        double* Cx_Venus, * Cy_Venus, * Cz_Venus;

        Cx_Venus = vector(109);
        Cy_Venus = vector(109);
        Cz_Venus = vector(109);

        for (i = 0; i < 10; i++)
        {
            Cx_Venus[i] = PCtemp[temp[0] + i - 1];
            Cy_Venus[i] = PCtemp[temp[1] + i - 1];
            Cz_Venus[i] = PCtemp[temp[2] + i - 1];
        }

        for (i = 0; i < 4; i++)
        {
            temp[i] += 30;
        }

        for (i = 0; i < 10; i++)
        {
            Cx[i] = PCtemp[temp[0] + i - 1];
            Cy[i] = PCtemp[temp[1] + i - 1];
            Cz[i] = PCtemp[temp[2] + i - 1];
        }

        for (i = 0; i < 10; i++)
        {
            Cx_Venus[i + 10] = Cx[i];
            Cy_Venus[i + 10] = Cy[i];
            Cz_Venus[i + 10] = Cz[i];
        }

        if ((0 <= dt) && (dt <= 16))
        {
            j = 0;
            Mjd0 = t1;
        }
        else if ((16 < dt) && (dt <= 32))
        {
            j = 1;
            Mjd0 = t1 + 16 * j;
        }

        r_Venus = Cheb3D(Mjd_TBD, 10, Mjd0, Mjd0 + 16, &Cx_Venus[10 * j], &Cy_Venus[10 * j], &Cz_Venus[10 * j]);

        for (i = 0; i < 3; i++)
        {
            r_Venus[i] = 1e3 * r_Venus[i];
        }

        freeVector(Cx_Venus, 20);
        freeVector(Cy_Venus, 20);
        freeVector(Cz_Venus, 20);

        for (i = 0; i < 3; i++)
        {
            temp[i] = 309 + 11 * j;
        }

        double* Cx_Mars, * Cy_Mars, * Cz_Mars;

        Cx_Mars = vector(109);
        Cy_Mars = vector(109);
        Cz_Mars = vector(109);

        for (i = 0; i < 11; i++)
        {
            Cx_Mars[i] = PCtemp[temp[0] + i - 1];
            Cy_Mars[i] = PCtemp[temp[1] + i - 1];
            Cz_Mars[i] = PCtemp[temp[2] + i - 1];
        }

        j = 0;
        Mjd0 = t1;

        r_Mars = Cheb3D(Mjd_TBD, 11, Mjd0, Mjd0 + 16, &Cx_Mars[11 * j], &Cy_Mars[11 * j], &Cz_Mars[11 * j]);

        for (i = 0; i < 3; i++)
        {
            r_Mars[i] = 1e3 * r_Mars[i];
        }

        freeVector(Cx_Mars, 22);
        freeVector(Cy_Mars, 22);
        freeVector(Cz_Mars, 22);

        for (i = 0; i < 3; i++)
        {
            temp[i] = 342 + 8 * j;
        }

        double* Cx_Jupiter, * Cy_Jupiter, * Cz_Jupiter;

        Cx_Jupiter = vector(109);
        Cy_Jupiter = vector(109);
        Cz_Jupiter = vector(109);

        for (i = 0; i < 8; i++)
        {
            Cx_Jupiter[i] = PCtemp[temp[0] + i - 1];
            Cy_Jupiter[i] = PCtemp[temp[1] + i - 1];
            Cz_Jupiter[i] = PCtemp[temp[2] + i - 1];
        }

        j = 0;
        Mjd0 = t1;

        r_Jupiter = Cheb3D(Mjd_TBD, 8, Mjd0, Mjd0 + 16, &Cx_Jupiter[8 * j], &Cy_Jupiter[8 * j], &Cz_Jupiter[8 * j]);

        for (i = 0; i < 3; i++)
        {
            r_Jupiter[i] = 1e3 * r_Jupiter[i];
        }

        freeVector(Cx_Jupiter, 16);
        freeVector(Cy_Jupiter, 16);
        freeVector(Cz_Jupiter, 16);

        for (i = 0; i < 3; i++)
        {
            temp[i] = 366 + 7 * j;
        }

        double* Cx_Saturn, * Cy_Saturn, * Cz_Saturn;

        Cx_Saturn = vector(109);
        Cy_Saturn = vector(109);
        Cz_Saturn = vector(109);

        for (i = 0; i < 7; i++)
        {
            Cx_Saturn[i] = PCtemp[temp[0] + i - 1];
            Cy_Saturn[i] = PCtemp[temp[1] + i - 1];
            Cz_Saturn[i] = PCtemp[temp[2] + i - 1];
        }

        j = 0;
        Mjd0 = t1;

        r_Saturn = Cheb3D(Mjd_TBD, 7, Mjd0, Mjd0 + 16, &Cx_Saturn[7 * j], &Cy_Saturn[7 * j], &Cz_Saturn[7 * j]);

        for (i = 0; i < 3; i++)
        {
            r_Saturn[i] = 1e3 * r_Saturn[i];
        }

        freeVector(Cx_Saturn, 14);
        freeVector(Cy_Saturn, 14);
        freeVector(Cz_Saturn, 14);

        for (i = 0; i < 3; i++)
        {
            temp[i] = 387 + 6 * j;
        }

        double* Cx_Uranus, * Cy_Uranus, * Cz_Uranus;

        Cx_Uranus = vector(109);
        Cy_Uranus = vector(109);
        Cz_Uranus = vector(109);

        for (i = 0; i < 6; i++)
        {
            Cx_Uranus[i] = PCtemp[temp[0] + i - 1];
            Cy_Uranus[i] = PCtemp[temp[1] + i - 1];
            Cz_Uranus[i] = PCtemp[temp[2] + i - 1];
        }

        j = 0;
        Mjd0 = t1;

        r_Uranus = Cheb3D(Mjd_TBD, 6, Mjd0, Mjd0 + 16, &Cx_Uranus[6 * j], &Cy_Uranus[6 * j], &Cz_Uranus[6 * j]);

        for (i = 0; i < 3; i++)
        {
            r_Uranus[i] = 1e3 * r_Uranus[i];
        }

        freeVector(Cx_Uranus, 12);
        freeVector(Cy_Uranus, 12);
        freeVector(Cz_Uranus, 12);

        for (i = 0; i < 3; i++)
        {
            temp[i] = 405 + 6 * j;
        }

        double* Cx_Neptune, * Cy_Neptune, * Cz_Neptune;

        Cx_Neptune = vector(109);
        Cy_Neptune = vector(109);
        Cz_Neptune = vector(109);

        for (i = 0; i < 6; i++)
        {
            Cx_Neptune[i] = PCtemp[temp[0] + i - 1];
            Cy_Neptune[i] = PCtemp[temp[1] + i - 1];
            Cz_Neptune[i] = PCtemp[temp[2] + i - 1];
        }

        j = 0;
        Mjd0 = t1;

        r_Neptune = Cheb3D(Mjd_TBD, 6, Mjd0, Mjd0 + 16, &Cx_Neptune[6 * j], &Cy_Neptune[6 * j], &Cz_Neptune[6 * j]);

        for (i = 0; i < 3; i++)
        {
            r_Neptune[i] = 1e3 * r_Neptune[i];
        }

        freeVector(Cx_Neptune, 12);
        freeVector(Cy_Neptune, 12);
        freeVector(Cz_Neptune, 12);

        for (i = 0; i < 3; i++)
        {
            temp[i] = 423 + 6 * j;
        }

        double* Cx_Pluto, * Cy_Pluto, * Cz_Pluto;

        Cx_Pluto = vector(109);
        Cy_Pluto = vector(109);
        Cz_Pluto = vector(109);

        for (i = 0; i < 6; i++)
        {
            Cx_Pluto[i] = PCtemp[temp[0] + i - 1];
            Cy_Pluto[i] = PCtemp[temp[1] + i - 1];
            Cz_Pluto[i] = PCtemp[temp[2] + i - 1];
        }

        j = 0;
        Mjd0 = t1;

        r_Pluto = Cheb3D(Mjd_TBD, 6, Mjd0, Mjd0 + 16, &Cx_Pluto[6 * j], &Cy_Pluto[6 * j], &Cz_Pluto[6 * j]);

        for (i = 0; i < 3; i++)
        {
            r_Pluto[i] = 1e3 * r_Pluto[i];
        }

        freeVector(Cx_Pluto, 12);
        freeVector(Cy_Pluto, 12);
        freeVector(Cz_Pluto, 12);

        for (i = 0; i < 3; i++)
        {
            temp[i] = 819 + 10 * j;
        }

        double* Cx_Nutations, * Cy_Nutations;

        Cx_Nutations = vector(109);
        Cy_Nutations = vector(109);

        for (i = 0; i < 10; i++)
        {
            Cx_Nutations[i] = PCtemp[temp[0] + i - 1];
            Cy_Nutations[i] = PCtemp[temp[1] + i - 1];
        }

        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                temp[j] += 20;
            }
            for (j = 0; j < 10; j++)
            {
                Cx[i] = PCtemp[temp[0] + i - 1];
                Cy[i] = PCtemp[temp[1] + i - 1];
            }
            for (i = 0; i < 10; i++)
            {
                Cx_Nutations[i + 10] = Cx[i];
                Cy_Nutations[i + 10] = Cy[i];
            }
        }

        if ((0 <= dt) && (dt <= 8))
        {
            j = 0;
            Mjd0 = t1;
        }
        else if ((8 < dt) && (dt <= 16))
        {
            j = 1;
            Mjd0 = t1 + 8 * j;
        }
        else if ((16 < dt) && (dt <= 124))
        {
            j = 2;
            Mjd0 = t1 + 8 * j;
        }
        else if ((24 < dt) && (dt <= 32))
        {
            j = 3;
            Mjd0 = t1 + 8 * j;
        }

        double* VecZeros = vector(10);
        for (int i = 0; i < 10; i++)
        {
            VecZeros[i] = 0;
        }

        Nutations = Cheb3D(Mjd_TBD, 10, Mjd0, Mjd0 + 16, &Cx_Nutations[10 * j], &Cy_Nutations[10 * j], VecZeros);

        freeVector(Cx_Nutations, 20);
        freeVector(Cy_Nutations, 20);

        for (i = 0; i < 3; i++)
        {
            temp[i] = 899 + 10 * j;
        }

        double* Cx_Librations, * Cy_Librations, * Cz_Librations;

        Cx_Librations = vector(109);
        Cy_Librations = vector(109);
        Cz_Librations = vector(109);

        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                temp[j] += 30;
            }
            for (j = 0; j < 10; j++)
            {
                Cx[i] = PCtemp[temp[0] + i - 1];
                Cy[i] = PCtemp[temp[1] + i - 1];
                Cz[i] = PCtemp[temp[2] + i - 1];
            }
            for (i = 0; i < 10; i++)
            {
                Cx_Librations[i + 10] = Cx[i];
                Cy_Librations[i + 10] = Cy[i];
                Cz_Librations[i + 10] = Cz[i];
            }
        }

        if ((0 <= dt) && (dt <= 8))
        {
            j = 0;
            Mjd0 = t1;
        }
        else if ((8 < dt) && (dt <= 16))
        {
            j = 1;
            Mjd0 = t1 + 8 * j;
        }
        else if ((16 < dt) && (dt <= 24))
        {
            j = 2;
            Mjd0 = t1 + 8 * j;
        }
        else if ((24 < dt) && (dt <= 32))
        {
            j = 3;
            Mjd0 = t1 + 8 * j;
        }

        Librations = Cheb3D(Mjd_TBD, 10, Mjd0, Mjd0 + 16, &Cx_Librations[10 * j], &Cy_Librations[10 * j], &Cz_Librations[10 * j]);

        freeVector(Cx_Librations, 20);
        freeVector(Cy_Librations, 20);
        freeVector(Cz_Librations, 20);

        EMRAT = 81.30056907419062; 
        EMRAT1 = 1 / (1 + EMRAT);

        r_Earth = sumV(r_Earth, 3, esc_x_vec(EMRAT1,r_Moon, 3 ), 3);
        r_Venus = sumV(esc_x_vec( -1 ,r_Earth, 3), 3, r_Venus, 3);
        r_Mars = sumV(esc_x_vec(-1, r_Earth, 3), 3, r_Mars, 3);
        r_Jupiter = sumV(esc_x_vec(-1, r_Earth, 3), 3, r_Jupiter, 3);
        r_Saturn = sumV(esc_x_vec(-1, r_Earth, 3), 3, r_Saturn, 3);
        r_Uranus = sumV(esc_x_vec(-1, r_Earth, 3), 3, r_Uranus, 3);
        r_Neptune = sumV(esc_x_vec(-1, r_Earth, 3), 3, r_Neptune, 3);
        r_Pluto = sumV(esc_x_vec(-1, r_Earth, 3), 3, r_Pluto, 3);
        r_Sun = sumV(esc_x_vec(-1, r_Earth, 3), 3, r_Sun, 3);
    }

    
    
   

 

    