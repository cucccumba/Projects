#include "solve_equation.h"

#include <assert.h>

int is_equal (double x, double y, double ac)
{
    return (fabs(x - y) <= ac);
}


int Solve_linear_equation (double b, double c, double* root1, double* root2)
{
    assert(isfinite(b) && b != 0);
    assert(isfinite(c));
    assert(root1 != root2);

    *root1 = -c / b;
    *root2 = *root1;
    return 1;
}

int Solve_full_quadratic (double a, double b, double c, double* root1, double* root2)
{
    assert(isfinite(a) && a != 0);
    assert(isfinite(b));
    assert(isfinite(c));
    assert(root1 != root2);

    double D = b * b - 4 * a * c;

    if (is_equal(D, 0, 0.0001))
    {
        *root1 = -b / 2 * a;
        *root2 = *root1;
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

        *root1 = (-b + D_sqrt) / (2 * a);
        *root2 = (-b - D_sqrt) / (2 * a);
        return 2;
    }
}

void make_roots_empty (double* root1, double* root2)
{
    *(double*)root1 = empty;
    *(double*)root2 = empty;
}

int Solve_equation (double a, double b, double c, double* root1, double* root2)
{
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));
    assert(root1 != root2);

    if (a == 0 && b == 0 && c ==0)
    {
        make_roots_empty(root1, root2);
        return infinity;
    }
    else if (a == 0 && b == 0 && c !=0)
    {
        make_roots_empty(root1, root2);
        return 0;
    }
    else if (a == 0 && b != 0 && c ==0)
    {
        *root1 = -b;
        *root2 = -b;
        return 1;
    }
    else if (a == 0 && b != 0 && c !=0)
    {
        return Solve_linear_equation(b, c, root1, root2);
    }
    else if (a != 0 && b == 0 && c ==0)
    {
        *root1 = 0;
        *root2 = 0;
        return 1;
    }
    else if (a != 0 && b == 0 && c !=0)
    {
        if(-(c) / a > 0)
        {
            Solve_full_quadratic(a, b, c, root1, root2);
            return 2;
        }
        make_roots_empty(root1, root2);
        return 0;
    }
    else if (a != 0 && b != 0 && c ==0)
    {
        Solve_linear_equation(a, b, root1, root2);
        *root1 = 0;
        return 2;
    }
    else if (a != 0 &&b != 0 && c !=0)
    {
        return Solve_full_quadratic(a, b, c, root1, root2);
    }
}