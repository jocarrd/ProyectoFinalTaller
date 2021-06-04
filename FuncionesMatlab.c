
/*
#include "FuncionesMatlab.h"
#include <stdio.h>
#include <stdlib.h>

 void Zero(int **matriz , int filas , int columnas){
	
	
	matriz=(int **) calloc (filas,sizeof(double *));
	int i;
	for(i=0;i<filas;i++){
	
		matriz[i]=(int *) calloc (columnas,sizeof(double));
	}
	
	
	
}

double** multMatriz(double** mat1, int filas, int colum, double** mat2, int filas1, int colum1){
    int i, j;
    double** auxM=matrizIni(filas, colum);
    for(i = 0; i < filas; i++){
        for(j = 0; j < colum; j++){
            double aux=mat1[i][j]*mat2[i][j];
            auxM[i][j]=aux;
        }
    }
    return auxM;
}

void printMatriz(double** mat, int filas, int colum){
    int i, j;

    for(i = 0; i < (filas); i++){
        for(j = 0; j < (colum); j++){
            printf("%5.15lf ", mat[i][j]);
        }
    printf("\n");
    }
}

double** sumaMatriz(double** x1, int filas1, int columnas1, double** x2, int filas2, int columnas2){
    double** mat=matrizIni(filas1, columnas1);
    int i ;
	for(i=0;i<filas1;i++){
        int a;
		for(a=0;a<(columnas1);a++){
            mat[i][a]=x1[i][a]+x2[i][a];
        }
    }
    return mat;
}

double** restaMatriz(double** x1, int filas1, int columnas1, double** x2, int filas2, int columnas2){
    double** mat=matrizIni(filas1, columnas1);
    int i;
	for(i=0;i<(filas1);i++){
       int a;
	    for(a=0;a<(columnas1);a++){
            mat[i][a]=x1[i][a]-x2[i][a];
        }
    }
    return mat;
}


double** traspuesta(double** x, int filas, int columnas){
    double** mat=matrizIni(filas, columnas);
	int i;
	for (i = 0; i < (filas); i++) {
            int j;
			for (j = 0; j < (columnas); j++) {
                if(i!=j){
                    mat[i][j]=x[j][i];
                    mat[j][i]=x[i][j];
                }else{
                    mat[i][j]=x[i][j];
                }
            }
	}
	
	return mat;
}

double** matrizIni(int filas, int colum){
    double **m;
    int i;

    m = (double **) calloc(filas, sizeof(double *));
    for(i = 0; i < filas; i++)
         m[i] = (double *) calloc(colum, sizeof(double));

    return m;
}

void LiberarMatriz(double **mat, int filas, int colum){
    int i;

    for(i = 0; i < filas; i++)
        free(mat[i]);
    free(mat);
}







int find2(double* v, int n, double JD)

{

    int i = 0;



    while (i < n) {

        if (fabs(v[i] - JD) < pow(10, -10)) {

            break;

        }

        ++i;

    }



    return i;

}







int find1(double* v1, int n1, double* v2, int n2, double JD)

{

    int i1 = 0, i2 = 0, ind1 = 0, ind2 = 0;



    if (n1 != n2) {

        printf("find1: n1 != n2\n");

        exit(EXIT_FAILURE);

    }



    while (i1 < n1) {

        if (v1[i1] > JD) {

            ind1 = i1;

            break;

        }

        ++i1;

    }

    while (i2 < n2) {

        if (v2[i2] > JD) {

            ind2 = i2;

            break;

        }

        ++i2;

    }



    return (ind1 < ind2 ? ind1 : ind2);

}

*/