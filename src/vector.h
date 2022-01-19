#pragma once

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    double x;
    double y;
} Vector;

Vector scale_vector(const double, const Vector);
Point add_point_vector(const Point, const Vector);
double points_distance(const Point, const Point);
