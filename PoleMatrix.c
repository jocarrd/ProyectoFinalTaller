#include "PoleMatrix.h"

double **  PoleMatrix(double xp, double yp) {

	return prod(R_y(-xp), 3, 3, R_x(-yp), 3, 3);
}