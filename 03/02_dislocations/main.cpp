#include <iostream>

#include "config.h"
#include "simulation.h"
#include "state.h"

using namespace std;

int main() {
    Config config = read_config();

    srand(config.seed);

    Cell **field = init_field(config);

    fill_field(field, config);
    print_field(field, config);

    freeze(field, config);

    while (!is_end(field, config)) {
        print_field(field, config);
        dislocation_moves(field, config);

        print_field(field, config);

        move(field, config);

        freeze(field, config);
    }
    print_field(field, config);
}
