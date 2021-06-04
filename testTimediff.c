#include <assert.h>
#include "Array.h"
#include <float.h>
#include <stdio.h>
#include "timediff.h"
#include <math.h>


#define FAIL() printf("\nfailure in %s() line %d\n", __func__, __LINE__)
#define _assert(test) do { if (!(test)) { FAIL(); return 1; } } while(0)
#define _verify(test) do { int r=test(); tests_run++; if(r) return r; } while(0)

int tests_run = 0;

int esIgual(double c, double b) {

    printf("Tests run: %f\n", c);
    printf("Tests run: %f\n", b);

    if (c == b) {  
        return 0;
    }
    return 1;
}





int test_Timediff1() {

    double* UT1_GPS = vector(1);
    double* TT_UTC=vector(1);
    double* GPS_UTC = vector(1);


     timediff(20,22,UT1_GPS,TT_UTC,GPS_UTC);
     
   

     printf("Tests run: %f\n", *UT1_GPS);
     printf("Tests run: %f\n", *TT_UTC);
     printf("Tests run: %f\n", *GPS_UTC);
   

    _assert(esIgual(*UT1_GPS, 17.000000));
    _assert(esIgual(*TT_UTC, 54.184000));
    _assert(esIgual(*GPS_UTC, 3.000000));



    return 0;


}




int all_tests() {


    _verify(test_Timediff1);


    return 0;

}


int main() {

    int result = all_tests();

    if (result == 0)
        printf("PASSED\n");

    printf("Tests run: %d\n", tests_run);

    return result != 0;


}
