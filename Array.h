#ifndef ARRAY_h_
#define ARRAY_h_



double norma(double* v, int n);
double dot(double* v1, int n1, double* v2, int n2);
double* vector(int n);
void freeVector(double* v, int n);
void printVector(double* v, int n);


double** trasp(double** m, int n);
double** inv(double** m, int n);
double** prod(double** mat1, int nf1, int nc1,
    double** mat2, int nf2, int nc2);
double** eye(int n);
double** sum(double** mat1, int nf1, int nc1,
    double** mat2, int nf2, int nc2);
int compareV(double* v1, int n1, double* v2, int n2);
int compare(double** mat1, int nf1, int nc1,
    double** mat2, int nf2, int nc2);
double** array(int nf, int nc);
void freeArray(double** mat, int nf, int nc);
void printArray(double** mat, int nf, int nc);

#endif

