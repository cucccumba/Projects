#include "solve_equation.h"
#include "test.h"


int AssertEqual (double a_, double b_, double c_, double root1_, double root2_, int number_of_roots, int line)
{
    double root1 = NAN, root2 = NAN;
    int number_of_solutions = Solve_equation(a_, b_, c_, &root1, &root2);

    if (number_of_solutions == 0 || number_of_solutions == infinity)
    {
        if (number_of_solutions != number_of_roots)
        {
            printf("ERROR, test failed, line %d: %.2lfx^2 + %.2lfx + %.2lf = 0, number of roots: %d\n",
                    line, a_, b_, c_, number_of_solutions);
            printf("Must be: number of roots: %d\n\n",number_of_roots);
            return 0;
        }
        else
            return 1;
    }
    else if (is_equal(root1, root1_, 0.0001) && is_equal(root2, root2_, 0.0001) && number_of_solutions == number_of_roots)
        return 1;
    else
    {
        printf("ERROR, test failed, line %d: %.2lfx^2 + %.2lfx + %.2lf = 0, number of roots: %d,"
               " root1: %.2lf, root2: %.2lf\n", line, a_, b_, c_, number_of_solutions, root1, root2);
        printf("Must be: number of roots: %d, root1: %.2lf, root2: %.2lf\n\n",number_of_roots, root1_, root2_);
        return 0;
    }
}

void Test()
{
    int flag = 1;
    flag *= AssertEqual(1, 2, 1, -1, -1, 1, __LINE__);
    flag *= AssertEqual(0, 0, 0, empty, empty, infinity, __LINE__);
    flag *= AssertEqual(2.5, 0, 0, 0, 0, 1, __LINE__);
    flag *= AssertEqual(2.5, 7.5, 0, 0, -3, 2, __LINE__);
    flag *= AssertEqual(2.3, 0, -9.2, 2, -2, 2, __LINE__);
    flag *= AssertEqual(0, 2.6, -20.8, 8, 8, 1, __LINE__);
    flag *= AssertEqual(1.01, 2.4, 16.8, empty, empty, 0, __LINE__);
    flag *= AssertEqual(2.5, 0, 16.8, empty, empty, 0, __LINE__);
    flag *= AssertEqual(-1, 2, 3, -1, 3, 2, __LINE__);
    flag *= AssertEqual(0, 5.4, 0, -5.4, -5.4, 1, __LINE__);
    flag *= AssertEqual(0, 0, 12.8, empty, empty, 0, __LINE__);

    if (flag)
    {
        printf("All tests passed successfully\n");
        printf("___________________________________________________________\n\n");
    }
}