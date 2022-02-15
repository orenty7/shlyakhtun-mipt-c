#ifndef DIRECTIONS_H
#define DIRECTIONS_H


enum class Direction {
    Up, Right, Down, Left
};

void print_direction(Direction);
Direction random_direction();

#endif
