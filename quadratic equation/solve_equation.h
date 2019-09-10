#pragma once

#include <math.h>

#define infinity -1

//-------------------------------------------------------------------------------------------------//

int Solve_equation (const double* a, const double* b, const double *c, double* root1, double* root2);

void Solve_linear_equation (const double* b, const double* c, double* root);
int Solve_if_a_is_0 (const double* b, const double* c, double* root);
void Solve_full_quadratic (const double*D, const double* a, const double* b, double* root1, double* root2);