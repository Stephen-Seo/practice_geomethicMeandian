#include "geothmetic_meandian.hpp"

#include <array>
#include <numeric>
#include <cmath>
#include <algorithm>

#include "helpers.hpp"

bool is_all_equal(const std::array<double, 3> &values) {
//    return std::all_of(values.begin(), values.end(), floating_point_similar);

    /*
    double first = values.at(0);
    for(std::size_t i = 1; i < values.size(); ++i) {
        if(values[i] != first) {
            return false;
        }
    }
    return true;
    */
    return floating_point_similar(values[0], values[1], 5)
        && floating_point_similar(values[1], values[2], 5);
}

double geothmetic_meandian(std::vector<double> values) {
    if(values.empty()) {
        return 0.0;
    } else if(values.size() == 1) {
        return values[0];
    }

    std::sort(values.begin(), values.end());

    std::array<double, 3> current, temp;
    bool isFirstIteration = true;

    do {
        if(isFirstIteration) {
            // mean
            current[0] = std::accumulate(
                    values.begin(),
                    values.end(),
                    0.0)
                        / values.size();
            // geometric mean
            current[1] = std::accumulate(
                    values.begin(),
                    values.end(),
                    1.0,
                    [] (const auto &a, const auto &b) {
                        return a * b;
                    });
            current[1] = std::pow(current[1], 1.0 / (double)values.size());
            // median
            current[2] = values[values.size() / 2];
            isFirstIteration = false;
        } else {
            temp = current;

            // mean
            current[0] = std::accumulate(
                    temp.begin(),
                    temp.end(),
                    0.0)
                        / temp.size();
            // geometric mean
            current[1] = std::accumulate(
                    temp.begin(),
                    temp.end(),
                    1.0,
                    [] (const auto &a, const auto &b) {
                        return a * b;
                    });
            current[1] = std::pow(current[1], 1.0 / (double)temp.size());
            // median
            std::sort(temp.begin(), temp.end());
            current[2] = temp[temp.size() / 2];
        }
    } while(!is_all_equal(current));

    return current[0];
}
