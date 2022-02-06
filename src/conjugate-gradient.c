#include <math.h>
#include <stdio.h>
#include "function.h"
#include "vector.h"

static const double tolerance = 1E-6;
static const unsigned max_iters = 1000;

double conjugate_gradient_beta(const double sg1, const double sg2) {
    return sg1 / sg2;
}

Point conjugate_gradient(Point p) {
    unsigned iter = 0;

    Vector g = negative_gradient_F(p);
    double sg = scalar_product(g, g);

    Vector d = g;
    double alpha = choose_alpha(p, d);

    Point p_new = add_point_vector(p, scale_vector(alpha, d));
    // printf("%d: %lf %lf\n", iter, p_new.x, p_new.y);

    Vector d_prev = d;
    double sg_prev = sg;
    iter++;
    do {
        p = p_new;
        g = negative_gradient_F(p);
        sg = scalar_product(g, g);

        d = add_vectors(g, scale_vector(conjugate_gradient_beta(sg, sg_prev), d_prev));
        alpha = choose_alpha(p, d);

        p_new = add_point_vector(p, scale_vector(alpha, d));
        // printf("%d: %lf %lf\n", iter, p_new.x, p_new.y);

        d_prev = d;
        sg_prev = sg;
        iter++;
    } while((points_distance(p, p_new) > tolerance) && (iter < max_iters));

    printf("Conjugate Gradient total iters: %d\n", iter);

    return p_new;
}
