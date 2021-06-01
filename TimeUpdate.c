#include "TimeUpdate.h"


double** TimeUpdate(double** P, double** Phi, double** Qdt) {



	return sum(prod(prod(Phi,6,6,P,6,6), 6,6, trasp(Phi, 6), 6, 6), 6, 6, Qdt, 6, 6);

}
