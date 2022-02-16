#ifndef SIMULATION_H
#define SIMULATION_H

#include "state.h"
#include "config.h"

void dislocation_moves(Cell**, Config);
void move(Cell**, Config);
void freeze(Cell **, Config);
bool is_end(Cell **, Config);

#endif
