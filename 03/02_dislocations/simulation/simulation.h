#ifndef SIMULATION_H
#define SIMULATION_H

#include "config.h"
#include "state.h"

void dislocation_moves(Cell (&)[HEIGHT][WIDTH]);
void move(Cell (&)[HEIGHT][WIDTH]);
void freeze(Cell (&)[HEIGHT][WIDTH]);
bool is_end(Cell (&)[HEIGHT][WIDTH]);

#endif
