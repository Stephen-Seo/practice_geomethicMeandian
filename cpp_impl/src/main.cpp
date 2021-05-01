#include <cstdlib>
#include <cstdio>

#include "geometric_mean.hpp"
#include "geothmetic_meandian.hpp"

int main(int argc, char **argv) {
    --argc; ++argv;

    std::vector<double> input;
    double temp;

    while(argc > 0) {
        temp = std::strtod(argv[0], nullptr);
        if(temp == 0.0) {
            puts("ERROR: Failed to parse double");
            return 1;
        } else {
            input.push_back(temp);
        }
        --argc; ++argv;
    }

    printf("Got input:\n  ");
    for(double d : input) {
        printf("%f ", d);
    }
    puts("");

    if(input.size() == 2) {
        printf("Geometric Mean of two doubles is %f\n",
            geometric_mean(input[0], input[1]));
    } else if(input.size() > 2) {
        printf("Geomethic Meandian of input is %f\n",
            geothmetic_meandian(input));
    }

    return 0;
}
