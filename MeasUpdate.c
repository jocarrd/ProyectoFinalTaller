#include "MeasUpdate.h"

void MeasUpdate(double* x, double z, int nx, double g, double s, double* G, int ng, double** P, int np, int n, double * K)
{
    double Inv_W = s; 

    double parte1 = 1 / (Inv_W + dot(G, 6, mat_x_vec(P, 6, 6, G, 6), 6));
     K = esc_x_vec(parte1,mat_x_vec(P, 6, 6, G, 6), 6);

    

    x = sumV(x, 6, esc_x_vec(z - g,K, 6), 6);
   
    P = prod(sum(eye(6), 6, 6, esc_x_vec( -1, cross(K, 6, G, 6), 6), 6, 6), 6, 6, P, 6, 6);
    



    
}