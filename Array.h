#ifndef ARRAY_h_
#define ARRAY_h_


double* cross(double* v, double* w);
double norma(double* v, int n);
double dot(double* v1, int n1, double* v2, int n2);
double* vector(int n);
void freeVector(double* v, int n);
void printVector(double* v, int n);
double** trasp(double** m, int n);
double** inv(double** m, int n);
double** prod(double** mat1, int nf1, int nc1,  double** mat2, int nf2, int nc2);
double** eye(int n);
double** sum(double** mat1, int nf1, int nc1,
 double** mat2, int nf2, int nc2);
int compareV(double* v1, int n1, double* v2, int n2);
int compare(double** mat1, int nf1, int nc1, double** mat2, int nf2, int nc2);
double** array(int nf, int nc);
void freeArray(double** mat, int nf, int nc);
void printArray(double** mat, int nf, int nc);
double* mat_x_vec(double** m, int nf, int nc, double* v, double n);
double* esc_x_vec(double k, double* v, int n);
int find1(double* v1, int n1, double* v2, int n2, double JD);
int find2(double* v, int n, double JD);
double* sumV(double * a, int i, double* b, int j);
double* restV(double* a, int i, double* b, int j); 
double** mat_x_esc(double** mat, double m, double n, double k);



#endif

