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

double points_distance(const Point p1, const Point p2) {
    const double x = p2.x - p1.x;
    const double y = p2.y - p1.y;

    return sqrt((x * x) + (y * y));
}

double scalar_product(const Vector v1, const Vector v2) {
    const double x = v1.x * v2.x;
    const double y = v1.y * v2.y;

    return x + y;
}
