#include "AccelPointMass.h"

double* AccelPointMass(double* r, int nr, int ns, double GM) {

	double * d;

	d = sumV(r, nr, esc_x_vec(-1.0, ns, ns), ns);

	return (sumV(esc_x_vec(-GM / pow(norma(d, 3), 3.0), d, ns), ns, esc_x_vec(-GM / pow(norma(ns, 3), 3.0), ns, ns), ns));
}