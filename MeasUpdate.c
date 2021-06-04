#include "MeasUpdate.h"

void MeasUpdate(double* x, double z, int nx, double g, double s, double* G, int ng, double** P, int np, int n, double K)
{
    double Inv_W = s; 

    double parte1 = 1 / (Inv_W + dot(G, 6, mat_x_vec(P, 6, 6, G, 6), 6));
    K = vec_x_esc(mat_x_vec(P, 6, 6, G, 6), 6, parte1);
    

    x = sumV(x, 6, esc_x_vec(K, 6, z - g), 6);
   
    P = prod(sum(eye(6), 6, 6, mat_x_esc(crossProd(K, 6, G, 6), 6, -1), 6, 6), 6, 6, P, 6, 6);
    
}