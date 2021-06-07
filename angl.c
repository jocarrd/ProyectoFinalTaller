#include "angl.h"





double angl(double* vec1, double* vec2) {


    double small = 0.00000001;
    double undefined = 999999.1;

    double	magv1 = norma(vec1,3);
    double magv2 = norma(vec2,3);
    double temp;
    double theta = undefined;


    if ((magv1 * magv2) > pow(small , 2)) {
        temp = dot(vec1,3, vec2,3) / (magv1 * magv2);

        if (abs(temp) > 1.0) {
            temp = sign(temp,temp) * 1.0;
        }
        else { theta = undefined; }

        theta = acos(temp);

    }

    return theta;

}