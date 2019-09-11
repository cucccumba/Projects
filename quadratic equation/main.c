//--------------------------------------------------------------------------------------------------------------------//
//!              That is a program for solving a quadratic equation of the form ax^2 + bx + c = 0                    !//
//!                   User need to type three quadratic equation coefficients (a, b, c)                              !//
//!   The program prints how many solutions this quadratic equation has and these solutions, respectively, if any    !//
//!                                                                                                                  !//
//! input:                                                                                                           !//
//! 1) a - x^2                                                                                                       !//
//! 2) b - x                                                                                                         !//
//! 3) c - free member                                                                                               !//
//!                                                                                                                  !//
//! output:                                                                                                          !//
//! 1) number of solutions (0, 1, 2 or infinity)                                                                     !//
//! 2) root 1, if any                                                                                                !//
//! 3) root 2, if any                                                                                                !//
//--------------------------------------------------------------------------------------------------------------------//


#include <stdio.h>
#include "solve_equation.h"
#include "test.h"


int main()
{
    Test ();

    printf("Solving quadratic equation (ax^2 + bx + c = 0).\n\n");
    printf("Enter a, b and c:\n");

    double a = NAN, b = NAN, c = NAN;
    double root1 = empty, root2 = empty;

    if (scanf("%lf %lf %lf", &a, &b, &c) == 3)
    {
        int number_of_solutions = Solve_equation (&a, &b, &c, &root1, &root2);

        switch (number_of_solutions)
        {
            case 0:
            {
                printf("There are no solutions.\n");
                break;
            }
            case 1:
            {
                printf("There is one solution: %.2lf.\n", root1);
                break;
            }
            case 2:
            {
                printf("There are two solutions %.2lf and %.2lf.\n", root1, root2);
                break;
            }
            case infinity:
            {
                printf("There are infinitive number of solutions.\n");
                break;
            }
            default:
            {
                printf("ERROR in function main(). Number of solutions: %d, root1: %.2lf, root2: %.2lf\n",
                        number_of_solutions, root1, root2);
                return 1;
            }
        }
    }
    else
    {
        printf("Wrong input, please use only numbers.\n");
    }
    return 0;
}