#include <stdio.h>
#include "conjugate-gradient.h"
#include "function.h"
#include "steepest-descent.h"

int main(void) {
    Point p = (Point) { .x = -1.5, .y = -1 };
    Point result = conjugate_gradient(p);
    printf("Result: f(%lf, %lf) = %lf\n", result.x, result.y, function_F(result));

    result = steepest_descent(p);
    printf("Result: f(%lf, %lf) = %lf\n", result.x, result.y, function_F(result));

    printf("f(1, 1) = %lf\n", function_F((Point) {1, 1}));

    return 0;
}
