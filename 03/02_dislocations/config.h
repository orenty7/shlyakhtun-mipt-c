#ifndef CONFIG_H

#define CONFIG_H

struct Config {
    int width, height;
    int seed;
    float probability;
};

Config read_config();

#endif
