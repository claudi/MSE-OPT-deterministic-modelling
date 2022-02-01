#include "function.h"

double function_F(const Point p) {
    return 100 * (p.x - (p.x * p.x)) * (p.y - (p.x * p.x)) + (1 - p.x) * (1 - p.x);
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
