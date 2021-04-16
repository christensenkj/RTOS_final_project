// physics model header file

#include <stdint.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>

double dthetadt(double w);
double dxdt(double v);
double dwdt(double F, double theta, double w, double M, double m, double g, double L);
double dvdt(double F, double theta, double w, double M, double m, double g, double L);
void semiImplicitEuler_theta(double *x0, double v0, double *theta0, double w0 , double dt, double *t, double F, double M, double m, double g, double L);
void semiImplicitEuler_time(double *x0, double v0, double *theta0, double w0 , double dt, double *t, double F, double M, double m, double g, double L, double t_f);