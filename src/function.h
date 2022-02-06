#pragma once
#include "vector.h"

double function_F(const Point);
Vector gradient_F(const Point);
Vector negative_gradient_F(const Point);
double choose_alpha(const Point, const Vector);
