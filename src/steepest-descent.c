#include <stdio.h>
#include "function.h"
#include "vector.h"

static const double tolerance = 1E-6;
static const unsigned max_iters = 10000;

Point steepest_descent(Point p) {
    Point p_new = p;
    unsigned iter = 0;

    do {
        p = p_new;
        const Vector d = negative_gradient_F(p);
        const double alpha = choose_alpha(p, d);

        p_new = add_point_vector(p, scale_vector(alpha, d));
        // printf("%d: %lf %lf\n", iter, p_new.x, p_new.y);

        iter++;
    } while((points_distance(p, p_new) > tolerance) && (iter < max_iters));

    printf("Steepest descent total iters: %d\n", iter);

    return p_new;
}
