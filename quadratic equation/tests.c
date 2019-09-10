#include "solve_equation.h"
#include "test.h"

void Test(int func(const double* a, const double* b, const double* c, double* root1, double* root2))
{
    char flag = 1;
    double root1, root2;
    {
        double a = 1, b = 2, c = 1;
        int number_of_solutions = func(&a, &b, &c, &root1, &root2);
        if (number_of_solutions != 1 && root1 != -1 && root2 != -1)
        {
            printf("ERROR, test failed: %.2lfx^2 + %.2lfx + %.2lf = 0, root1: %.2lf, root2: %.2lf\n\n", a, b, c, root1, root2);
            flag = 0;
        }
    }
    {
        double a = 0, b = 0, c = 0;
        int number_of_solutions = func(&a, &b, &c, &root1, &root2);
        if (number_of_solutions != infinity)
        {
            printf("ERROR, test failed: %.2lfx^2 + %.2lfx + %.2lf = 0, root1: %.2lf, root2: %.2lf\n\n", a, b, c, root1, root2);
            flag = 0;
        }
    }
    {
        double a = 2.5, b = 0, c = 0;
        int number_of_solutions = func(&a, &b, &c, &root1, &root2);
        if (number_of_solutions != 1 && root1 != 0)
        {
            printf("ERROR, test failed: %.2lfx^2 + %.2lfx + %.2lf = 0, root1: %.2lf, root2: %.2lf\n\n", a, b, c, root1, root2);
            flag = 0;
        }
    }
    {
        double a = 2.5, b = 7.5, c = 0;
        int number_of_solutions = func(&a, &b, &c, &root1, &root2);
        if (number_of_solutions != 2 && root1 != 0 && root2 != -3)
        {
            printf("ERROR, test failed: %.2lfx^2 + %.2lfx + %.2lf = 0, root1: %.2lf, root2: %.2lf\n\n", a, b, c, root1, root2);
            flag = 0;
        }
    }
    {
        double a = 2.5, b = 0, c = -16.8;
        int number_of_solutions = func(&a, &b, &c, &root1, &root2);
        if (number_of_solutions != 2 && root1 != -2.59 && root2 != 2.59)
        {
            printf("ERROR, test failed: %.2lfx^2 + %.2lfx + %.2lf = 0, root1: %.2lf, root2: %.2lf\n\n", a, b, c, root1, root2);
            flag = 0;
        }
    }
    {
        double a = 0, b = 2.5, c = -16.8;
        int number_of_solutions = func(&a, &b, &c, &root1, &root2);
        if (number_of_solutions != 1 && root1 != 6.72)
        {
            printf("ERROR, test failed: %.2lfx^2 + %.2lfx + %.2lf = 0, root1: %.2lf, root2: %.2lf\n\n", a, b, c, root1, root2);
            flag = 0;
        }
    }
    {
        double a = 1.01, b = 2.4, c = 16.8;
        int number_of_solutions = func(&a, &b, &c, &root1, &root2);
        if (number_of_solutions != 0)
        {
            printf("ERROR, test failed: %.2lfx^2 + %.2lfx + %.2lf = 0, root1: %.2lf, root2: %.2lf\n\n", a, b, c, root1, root2);
            flag = 0;
        }
    }
    {
        double a = 2.5, b = 0, c = 16.8;
        int number_of_solutions = func(&a, &b, &c, &root1, &root2);
        if (number_of_solutions != 0)
        {
            printf("ERROR, test failed: %.2lfx^2 + %.2lfx + %.2lf = 0, root1: %.2lf, root2: %.2lf\n\n", a, b, c, root1, root2);
            flag = 0;
        }
    }
    {
        double a = -2.5, b = 5.4, c = 16.8;
        int number_of_solutions = func(&a, &b, &c, &root1, &root2);
        if (number_of_solutions != 2 && root1 != 3.89 && root2 != -1.73)
        {
            printf("ERROR, test failed: %.2lfx^2 + %.2lfx + %.2lf = 0, root1: %.2lf, root2: %.2lf\n\n", a, b, c, root1, root2);
            flag = 0;
        }
    }
    {
        double a = 0, b = 5.4, c = 0;
        int number_of_solutions = func(&a, &b, &c, &root1, &root2);
        if (number_of_solutions != 1 && root1 != -5.4)
        {
            printf("ERROR, test failed: %.2lfx^2 + %.2lfx + %.2lf = 0, root1: %.2lf, root2: %.2lf\n\n", a, b, c, root1, root2);
            flag = 0;
        }
    }


    if (flag)
    {
        printf("All tests passed successfully\n");
        printf("___________________________________________________________\n\n");
    }
}
