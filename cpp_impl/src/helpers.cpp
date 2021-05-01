#include "helpers.hpp"

#include <string>

bool floating_point_similar(double a, double b, unsigned char decimal) {
    std::string astr = std::to_string(a);
    std::string bstr = std::to_string(b);

    auto a_index = astr.find_last_of('.');
    astr = astr.substr(0, a_index + decimal);

    auto b_index = bstr.find_last_of('.');
    bstr = bstr.substr(0, b_index + decimal);

    return astr == bstr;
}
