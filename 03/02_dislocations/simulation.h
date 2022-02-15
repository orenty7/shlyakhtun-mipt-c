#ifndef SIMULATION_H
#define SIMULATION_H

#include "state.h"
#include "config.h"

struct DirectionCell {
    bool is_cell;
    union {
	Cell cell;
	Direction direction;
    };
};


DirectionCell** dislocation_moves(Cell**, Config);
Cell** move(DirectionCell**, Config);
void freeze(Cell **, Config);
bool is_end(Cell **, Config);

void print_field(DirectionCell**, Config);

#endif
