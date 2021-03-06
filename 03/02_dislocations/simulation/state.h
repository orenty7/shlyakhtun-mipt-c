#ifndef STATE_H
#define STATE_H

#include "config.h"

enum class Type { Empty, Fixed, Floating };
enum class Direction { Up, Right, Down, Left };

struct Point {
    int x, y;
};

struct Cell {
    bool is_moving;
    union {
        Type type;
        Direction direction;
    };
};

bool random_bool(float);
Direction random_direction();

void fill_field(Cell (&)[HEIGHT][WIDTH], Config &);

void print_type(Type &);
void print_direction(Direction &);
void print_cell(Cell &);
void print_field(Cell (&)[HEIGHT][WIDTH]);

#endif
