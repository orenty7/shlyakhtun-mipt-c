#include "config.h"

#include <iostream>
#include <time.h>

Config read_config() {
    int width, height, seed;
    float probability;

    std::cout << "Width: ";
    std::cin >> width;

    std::cout << "Height: ";
    std::cin >> height;

    std::cout << "Seed (0 to use system time): ";
    std::cin >> seed;

    if (!seed) {
        seed = time(NULL);
        std::cout << "Generated seed is: " << seed << '\n';
    }

    std::cout << "Probability of spawn (from 0 to 1): ";
    std::cin >> probability;
    return Config{.width = width,
                  .height = height,

                  .seed = seed,
                  .probability = probability};
}
