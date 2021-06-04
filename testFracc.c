#include <assert.h>
#include "Array.h"
#include <float.h>
#include <stdio.h>
#include "Frac.h"


#define FAIL() printf("\nfailure in %s() line %d\n", __func__, __LINE__)
#define _assert(test) do { if (!(test)) { FAIL(); return 1; } } while(0)
#define _verify(test) do { int r=test(); tests_run++; if(r) return r; } while(0)

int tests_run = 0;


int test_fracc1() {
    
   double f= Frac(5.1);

  
   _assert(esIgual(f,0.10000));

   
   return 0;


}

int test_fracc2() {
    
   double f= Frac(6);

  
   _assert(esIgual(f,0));

   
   return 0;


}


int all_tests() {


	_verify(test_fracc1);
	_verify(test_fracc2);
	return 0;

}

int esIgual(double c , double b){


if(c==b){
return 0;
}
return 1;
}




int main() {

    int result = all_tests();

    if (result == 0)
        printf("PASSED\n");

    printf("Tests run: %d\n", tests_run);

    return result != 0;


}
