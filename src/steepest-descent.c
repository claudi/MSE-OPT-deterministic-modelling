#include "function.h"
#include "vector.h"
#include <stdio.h>

const double tolerance = 1E-3;
const unsigned max_iters = 100;

double choose_alpha(const Point p, const Vector d) {
    const double sigma = 0.5;
    const double rho = 0.5;
    double alpha = 1;

    const double scalar_prod = scalar_product(gradient_F(p), d);

    double x = function_F(p);

    Point p_new = add_point_vector(p, scale_vector(alpha, d));
    double x_new = function_F(p);
    while((x_new > x + sigma * alpha * scalar_prod)) {
        alpha *= rho;

        p_new = add_point_vector(p, scale_vector(alpha, d));
        x_new = function_F(p_new);
    }

    return alpha;
}

Point steepest_descent(Point p) {
    Point p_new = p;
    unsigned iter = 0;

    do {
        p = p_new;
        const Vector d = negative_gradient_F(p);
        const double alpha = choose_alpha(p, d);

        p_new = add_point_vector(p, scale_vector(alpha, d));
        printf("%d: %lf %lf\n", iter, p_new.x, p_new.y);

        iter++;
    } while((points_distance(p, p_new) > tolerance) && (iter < max_iters));

    return p_new;
}
