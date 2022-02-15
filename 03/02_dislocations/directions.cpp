#include "directions.h"

#include <iostream>


void print_direction(Direction direction) {
    switch(direction) {
    case Direction::Up:
	std::cout << "↑";
	break;
    case Direction::Right:
	std::cout << "→";
	break;
    case Direction::Down:
	std::cout << "↓";
	break;
    default:
	std::cout << "←";
	break;
    }
}

Direction random_direction() {
    switch(rand() % 4) {
    case 0:
	return Direction::Up;
    case 1:
	return Direction::Right;
    case 2:
	return Direction::Down;
    case 3:
	return Direction::Left;
    }
}

