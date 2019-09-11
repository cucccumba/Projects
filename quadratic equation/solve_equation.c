#include "solve_equation.h"

#include <assert.h>

int Solve_linear_equation (const double* b, const double* c, double* root1, double* root2)
{
    assert(isfinite(*(double*)b));
    assert(isfinite(*(double*)c));
    assert(root1 != root2);

    *(double*)root1 = -(*(double*)c) / *(double*)b;
    *(double*)root2 = *(double*)root1;
    return 1;
}

int Solve_full_quadratic (const double* a, const double* b, const double* c, double* root1, double* root2)
{
    assert(isfinite(*(double*)a));
    assert(isfinite(*(double*)b));
    assert(isfinite(*(double*)c));
    assert(root1 != root2);


    double D = (*(double*)b) * (*(double*)b) - 4 * (*(double*)a) * (*(double*)c);
    if (D == 0)
    {
        *(double*)root1 = -(*(double*)b) / 2 * (*(double*)a);
        *(double*)root2 = *(double*)root1;
        return 1;
    }
    else if (D < 0)
    {
        make_roots_empty(root1, root2);
        return 0;
    }
    else
    {
        double D_sqrt = sqrt(D);
        *(double*)root1 = ((-*(double*)b) + D_sqrt) / 2 * (*(double*)a);
        *(double*)root2 = ((-*(double*)b) - D_sqrt) / 2 * (*(double*)a);
        return 2;
    }
}

void make_roots_empty (double* root1, double* root2)
{
    assert(root1 != root2);

    *(double*)root1 = empty;
    *(double*)root2 = empty;
}

int Solve_equation (const double* a, const double* b, const double *c, double* root1, double* root2)
{
    assert(isfinite(*(double*)a));
    assert(isfinite(*(double*)b));
    assert(isfinite(*(double*)c));
    assert(root1 != root2);

    if (*(double*)a == 0 && *(double*)b == 0 && *(double*)c ==0)
    {
        make_roots_empty(root1, root2);
        return infinity;
    }
    if (*(double*)a == 0 && *(double*)b == 0 && *(double*)c !=0)
    {
        make_roots_empty(root1, root2);
        return 0;
    }
    if (*(double*)a == 0 && *(double*)b != 0 && *(double*)c ==0)
    {
        *(double*)root1 = -(*(double*)b);
        *(double*)root2 = -(*(double*)b);
        return 1;
    }
    if (*(double*)a == 0 && *(double*)b != 0 && *(double*)c !=0)
    {
        return Solve_linear_equation(b, c, root1, root2);
    }
    if (*(double*)a != 0 && *(double*)b == 0 && *(double*)c ==0)
    {
        *(double*)root1 = 0;
        *(double*)root2 = 0;
        return 1;
    }
    if (*(double*)a != 0 && *(double*)b == 0 && *(double*)c !=0)
    {
        if(-(*(double*)c) / *(double*)a > 0)
        {
            *(double*)root2 = sqrt(-(*(double*)c) / *(double*)a);
            *(double*)root1 = -(*(double*)root2);
            return 2;
        }
        make_roots_empty(root1, root2);
        return 0;
    }
    if (*(double*)a != 0 && *(double*)b != 0 && *(double*)c ==0)
    {
        Solve_linear_equation(a, b, root1, root2);
        *(double*)root1 = 0;
        return 2;
    }
    if (*(double*)a != 0 && *(double*)b != 0 && *(double*)c !=0)
    {
        return Solve_full_quadratic(a, b, c, root1, root2);
    }

    /*
    if (*(double*)a == 0)
    {
        if (*(double*)b == 0)
        {
            if (*(double*)c == 0)
            {
                *(double*)root1 = empty;
                *(double*)root2 = empty;
                return infinity;
            }
            // c != 0.
            *(double*)root1 = empty;
            *(double*)root2 = empty;
            return 0;
        }
        if (*(double*)c == 0)
        {
            *(double*)root1 = -(*(double*)b);
            *(double*)root2 = -(*(double*)b);
            return 1;
        }
        // if b and c != 0.
        return Solve_linear_equation(b, c, root1, root2);
    }
    else if (*(double*)b == 0)
    {
        if (*(double*)c == 0)
        {
            *(double*)root1 = 0;
            *(double*)root2 = 0;
            return 1;
        }
        else
        {
            if(-(*(double*)c) / *(double*)a > 0)
            {
                *(double*)root2 = sqrt(-(*(double*)c) / *(double*)a);
                *(double*)root1 = -(*(double*)root2);
                return 2;
            }
            *(double*)root1 = empty;
            *(double*)root2 = empty;
            return 0;
        }
    }
    else if (*(double*)c == 0)
    {
        Solve_linear_equation(a, b, root1, root2);
        *(double*)root1 = 0;
        return 2;
    }
    else if (*(double*)c != 0)
    {
        return Solve_full_quadratic(a, b, c, root1, root2);
    }
     */
}
