#ifndef SIMULATION_H
#define SIMULATION_H

#include "state.h"
#include "config.h"

DirectionCell** dislocation_moves(Cell**, Config);
Cell** move(DirectionCell**, Config);
void freeze(Cell **, Config);
bool is_end(Cell **, Config);

#endif
