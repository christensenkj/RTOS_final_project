/*
 Solver for a system of n first order Ordinary Differential Equations 
 (initial value problem)
 Method: calls 4th-order Runge-Kutta
 Can be used for solving a system of n/2 second order ODE

 Demo version for 2D projectile motion
 AG: Last revision October 2009
*/
#include "physics_model.h"

double dthetadt(double w) {
    return w;
}

double dxdt(double v) {
    return v;
}

double dwdt(double F, double theta, double w, double M, double m, double g, double L) {
    return ( 1/((M+m) - m*cos(theta)*cos(theta)) * (F*cos(theta)/L + (g/L)*((M+m)*sin(theta)) - m*w*w*sin(theta)*cos(theta)) );
}

double dvdt(double F, double theta, double w, double M, double m, double g, double L) {
    return ( 1/( cos(theta)*cos(theta) - (M+m)/(m)) * ( (w*w*L*sin(theta) - F/(m) - g*sin(theta)*cos(theta)) ) );
}

// Finds value of y for a given x using step size h
// and initial value y0 at x0.
void semiImplicitEuler_theta(double *x0, double v0, double *theta0, double w0 , double dt, double *time, double F, double M, double m, double g, double L)
{
    double x = *x0, v = v0, theta = *theta0, w = w0;
    double t = 0;

    // calculate estimated F for the previous timestep to use as the current timestep
    while ( fabs(theta) < 1.57 ) {
        // Roses are red. Violets are blue. I love C. How about U?
        v = v + dt * dvdt(F, theta, w, M, m, g, L);
        // In semi-implicit Euler, update the position coordinate using the
        // velocity at the new time.
        x = x + dt * dxdt(v);
        // Similarly for the angles.
        w = w + dt * dwdt(F, theta, w, M, m, g, L);
        theta = theta + dt * dthetadt(w);
        t = t+dt;
    }

    *time = t;
    *x0 = x;
    *theta0 = theta;
}

// Finds value of y for a given x using step size h
// and initial value y0 at x0.
void semiImplicitEuler_time(double *x0, double v0, double *theta0, double w0 , double dt, double *time, double F, double M, double m, double g, double L, double t_f)
{
    double x = *x0, v = v0, theta = *theta0, w = w0;
    double t = 0;

    // calculate estimated F for the previous timestep to use as the current timestep
    while ( t < t_f ) {
        // Roses are red. Violets are blue. I love C. How about U?
        v = v + dt * dvdt(F, theta, w, M, m, g, L);
        // In semi-implicit Euler, update the position coordinate using the
        // velocity at the new time.
        x = x + dt * dxdt(v);
        // Similarly for the angles.
        w = w + dt * dwdt(F, theta, w, M, m, g, L);
        theta = theta + dt * dthetadt(w);
        t = t+dt;
    }

    *time = t;
    *x0 = x;
    *theta0 = theta;
}