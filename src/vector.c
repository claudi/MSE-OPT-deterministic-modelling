#include <math.h>
#include "vector.h"

Vector scale_vector(const double a, const Vector v) {
    return (Vector) {
        .x = a * v.x,
        .y = a * v.y,
    };
}

Point add_point_vector(const Point p, const Vector v) {
    return (Point) {
        .x = p.x + v.x,
        .y = p.y + v.y,
    };
}
