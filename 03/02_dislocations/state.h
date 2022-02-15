#ifndef STATE_H
#define STATE_H

#include "config.h"

enum class Cell {Empty, Fixed, Floating};

bool random_cell(float);
Cell** init_field(Config);
void fill_field(Cell**, Config);

void print_cell(Cell &);
void print_field(Cell **, Config);


#endif
