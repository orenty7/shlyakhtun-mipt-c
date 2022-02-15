#ifndef STATE_H
#define STATE_H

#include "config.h"

enum class Cell {Empty, Fixed, Floating};
enum class Direction {Up, Right, Down, Left};

struct DirectionCell {
    bool is_cell;
    union {
	Cell cell;
	Direction direction;
    };
};


bool random_cell(float);
Direction random_direction();

template<typename T>
T** init_field(Config);


void fill_field(Cell**, Config);


void print_cell(Cell &);
void print_direction(Direction);

template<typename T>
void print_field(T **, Config);

#endif
