#include "solve_equation.h"

#include <assert.h>


void Solve_linear_equation (const double* b, const double* c, double* root)
{
    assert (isfinite(*(double*)b));
    assert (isfinite(*(double*)c));


    *(double*)root = -(*(double*)c) / *(double*)b;
}

int Solve_if_a_is_0 (const double* b, const double* c, double* root)
{
    assert (isfinite(*(double*)b));
    assert (isfinite(*(double*)c));


    if (*(double*)b == 0)
    {
        if (*(double*)c == 0)
        {
            return infinity; // There are infinity roots.
        }
        return 0; // There are no roots.
    }
    Solve_linear_equation (b, c, root);
    return 1;
}

void Solve_full_quadratic (const double*D, const double* a, const double* b, double* root1, double* root2)
{
    assert (isfinite(*(double*)a));
    assert (isfinite(*(double*)b));
    assert (isfinite(*(double*)D));
    assert (root1 != root2);

    double D_sqrt = sqrt(*(double*)D);
    *(double*)root1 = (-(*(double*)b) + D_sqrt) / (2 * (*(double*)a));
    *(double*)root2 = (-(*(double*)b) - D_sqrt) / (2 * (*(double*)a));
}



int Solve_equation (const double *a, const double *b, const double *c, double* root1, double* root2)
{
    assert (isfinite(*(double*)a));
    assert (isfinite(*(double*)b));
    assert (isfinite(*(double*)c));
    assert (root1 != root2);


    if (*(double*)a == 0)
    {
        return Solve_if_a_is_0(b, c, root1);
    }
    else if (*(double*)b == 0)
    {
        if (*(double*)c == 0)
        {
            *(double*)root1 = 0;
            return 1;
        }
        if (-(*(double*)c) / *(double*)a > 0)
        {
            *(double*)root1 = sqrt(-(*(double*)c) / *(double*)a);
            *(double*)root2 = -*(double*)root1;
            return 2;
        }
        else // -c / a < 0.
        {
            return 0;
        }
    }
    else
    {
        if (*(double*)c == 0)
        {
            root1 = 0;
            Solve_linear_equation(a, b, root2);
            return 2;
        }
        double D = *(double*)b * (*(double*)b) - 4 * (*(double*)a) * (*(double*)c);
        if (D < 0)
        {
            return 0;
        }
        else if (D == 0)
        {
            *(double*)root1 = -(*(double*)b) / (2 * (*(double*)a));
            return 1;
        }
        else // D > 0.
        {
            Solve_full_quadratic (&D, a, b, root1, root2);
            return 2;
        }
    }
}

