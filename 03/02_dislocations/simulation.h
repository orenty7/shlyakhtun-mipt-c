#ifndef SIMULATION_H
#define SIMULATION_H

#include "state.h"
#include "config.h"

void dislocation_moves(Cell (&)[HEIGHT][WIDTH]);
void move(Cell (&)[HEIGHT][WIDTH]);
void freeze(Cell (&)[HEIGHT][WIDTH]);
bool is_end(Cell (&)[HEIGHT][WIDTH]);

#endif
