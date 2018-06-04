#include <iostream>
#include <math.h>
#include <vector>
#include <ctime>

#include "Functions.h"

double calculate_function(std::vector<double> params[3], double *x_values) {
	double tmp =0 ;

//	double *coeff = params[][0];
//	double *powers = params[][2];




	//for (int i = 0;; i++) {
	//	tmp += coeff[i] * pow(x_values[i], powers[i]);
	//}

	for (int i = 0;; i++) {
		tmp += params[0][i] * pow(x_values[i], params[2][i]);
	}

	return tmp;
}