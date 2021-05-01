#include "geometric_mean.hpp"

#include <cmath>
#include <string>

#include "helpers.hpp"

double geometric_mean(double a, double b) {
    double temp_a;
    double temp_b;

    while(!floating_point_similar(a, b, 5)) {
        temp_a = a;
        temp_b = b;

        a = (temp_a + temp_b) / 2.0;
        b = std::sqrt(temp_a * temp_b);
    }

    return a;
}
