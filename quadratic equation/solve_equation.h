#pragma once

#include <math.h>

#define infinity -1
#define empty NAN



int Solve_equation (const double* a, const double* b, const double *c, double* root1, double* root2);

int Solve_linear_equation (const double* b, const double* c, double* root1, double* root2);
int Solve_full_quadratic (const double* a, const double* b, const double* c, double* root1, double* root2);
void make_roots_empty (double* root1, double* root2);