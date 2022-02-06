#include "function.h"

double function_F(const Point p) {
    return 100 * (p.y - (p.x * p.x)) * (p.y - (p.x * p.x)) + (1 - p.x) * (1 - p.x);
}

Vector gradient_F(const Point p) {
    return (Vector) {
        .x = 2 * ((200 * p.x * p.x * p.x) - (200 * p.x * p.y) + p.x - 1),
        .y = 200 * (p.y - p.x * p.x),
    };
}

Vector negative_gradient_F(const Point p) {
    return (Vector) {
        .x = -2 * ((200 * p.x * p.x * p.x) - (200 * p.x * p.y) + p.x - 1),
        .y = -200 * (p.y - p.x * p.x),
    };
}

double choose_alpha(const Point p, const Vector d) {
    const double sigma = 0.5;
    const double rho = 0.25;
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
