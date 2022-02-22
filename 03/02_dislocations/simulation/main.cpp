#include <chrono>
#include <iostream>

#include "config.h"
#include "simulation.h"
#include "state.h"

using namespace std;

struct Result {
    int steps;
};

Result quiet_run(Config &config) {
    int steps = 0;
    Cell field[HEIGHT][WIDTH];

    for (int y = 0; y < HEIGHT; y++)
        for (int x = 0; x < WIDTH; x++)
            field[y][x] = {.is_moving = false, .type = Type::Empty};

    fill_field(field, config);

    freeze(field);

    while (!is_end(field)) {
        dislocation_moves(field);
        move(field);
        freeze(field);
        steps++;
    }
    return {steps};
}

Result run(Config &config) {
    int steps = 0;
    Cell field[HEIGHT][WIDTH];

    for (int y = 0; y < HEIGHT; y++)
        for (int x = 0; x < WIDTH; x++)
            field[y][x] = {.is_moving = false, .type = Type::Empty};

    fill_field(field, config);
    print_field(field);

    freeze(field);

    while (!is_end(field)) {
        print_field(field);
        dislocation_moves(field);

        print_field(field);

        move(field);

        freeze(field);

        steps++;
    }
    print_field(field);
    return {steps};
}

int main() {
    using namespace std::chrono;
    
    Config config = {.dislocations = 0};
#if !QUIET
    cout << "Enter number of dislocations: ";
#endif
    cin >> config.dislocations;

#if !SEED
    auto now = high_resolution_clock::now();
    srand(duration_cast<nanoseconds>(now.time_since_epoch()).count());
#else
    srand(SEED);
#endif

    for (int i = 0; i < RUNS; i++)
#if QUIET
        cout << quiet_run(config).steps << "\n";
#else
        cout << "Steps: " run(config).steps << "\n";
#endif
}
