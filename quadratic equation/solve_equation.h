#pragma once

#include <math.h>

#define infinity -1
#define empty NAN

/*!
 * Solves full quadratic equation
 * @param a param before x^2
 * @param b param before x
 * @param c free member
 * @param root1 address of first root
 * @param root2 address of second root
 * @return count of roots
 */
int Solve_equation (double a, double b, double c, double* root1, double* root2);

/*!
 * Solves equation with type bx + c = 0, makes two equal roots
 * @param b param before x
 * @param c free member
 * @param root1 address of root1
 * @param root2 address of root2
 * @return count of roots
 */
int Solve_linear_equation (double b, double c, double* root1, double* root2);

/*!
 * Solves full quadratic equation (a != 0)
 * @param a param before x^2
 * @param b param before x
 * @param c free member
 * @param root1 address of first root
 * @param root2 address of second root
 * @return count of roots
 */
int Solve_full_quadratic (double a, double b, double c, double* root1, double* root2);

/*!
 * Just makes roots NAN
 * @param root1 first root
 * @param root2 second root
 */
void make_roots_empty (double* root1, double* root2);

/*!
 * Checks equality with specified accuracy
 * @param x first param
 * @param y second param
 * @param ac accuracy
 * @return true or false
 */
int is_equal (double x, double y, double ac);