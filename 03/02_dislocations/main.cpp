#include <iostream>
#include <time.h>

#include "config.h"
#include "simulation.h"
#include "state.h"

using namespace std;

int main() {
    srand(time(NULL));

    Cell field[HEIGHT][WIDTH];

    for(int y = 0; y < HEIGHT; y ++) {
        for(int x = 0; x < WIDTH; x ++) {
            field[y][x] = { .is_moving = false, .type = Type::Empty};
        }
    }

    fill_field(field);
    print_field(field);

    freeze(field);

    while (!is_end(field)) {
        print_field(field);
        dislocation_moves(field);

        print_field(field);

        move(field);

        freeze(field);
    }
    print_field(field);
}
