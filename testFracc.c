#include <assert.h>
#include "Array.h"
#include <float.h>
#include <stdio.h>
#include "Frac.h"


#define FAIL() printf("\nfailure in %s() line %d\n", __func__, __LINE__)
#define _assert(test) do { if (!(test)) { FAIL(); return 1; } } while(0)
#define _verify(test) do { int r=test(); tests_run++; if(r) return r; } while(0)

int tests_run = 0;


int test_fracc() {
    
   double f= Frac(5.1);
  
   _assert(f == 0.1000);
   
   return 0;


}


int all_tests() {


	_verify(test_fracc);
	return 0;

}





int main() {

    int result = all_tests();

    if (result == 0)
        printf("PASSED\n");

    printf("Tests run: %d\n", tests_run);

    return result != 0;


}