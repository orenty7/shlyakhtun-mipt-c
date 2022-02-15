#ifndef STATE_H
#define STATE_H

#include "config.h"

enum class Cell {Empty, Fixed, Floating};
enum class Direction {Up, Right, Down, Left};

bool random_cell(float);
Direction random_direction();

Cell** init_field(Config);
void fill_field(Cell**, Config);

void print_cell(Cell &);
void print_direction(Direction);
void print_field(Cell **, Config);


#endif
