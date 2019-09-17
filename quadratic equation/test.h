#pragma once

#include <stdio.h>
/*!
 * Contains AssertEquals, prints result of testing
 */
void Test();


/*!
 * Checks the correctness of the solution of the quadratic equation
 * @param a_ param before x^2
 * @param b_ param before x
 * @param c_ free member
 * @param root1_ correct firs root
 * @param root2_ correct second root
 * @param number_of_roots correct number of roots
 * @param line __LINE__
 * @return true or false
 */
int AssertEqual (double a_, double b_, double c_, double root1_, double root2_, int number_of_roots, int line);