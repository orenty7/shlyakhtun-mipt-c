#include "state.h"

#include <iostream>
#include "config.h"


bool random_bool(float prob) {
    return ((float) rand()) / ((float) RAND_MAX) < prob;
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



Cell** init_field(Config config) {
    Cell **field = new Cell*[config.height];
    for(int i = 0; i < config.height; i ++)
	field[i] = new Cell[config.width];    
    return field;
}


void fill_field(Cell **field, Config config) {
    for(int y = 0; y < config.height; y ++) 
	for(int x = 0; x < config.width; x ++)
	    if(random_bool(config.probability))
		field[y][x] = { .is_moving = false, .type = Type::Floating };
	    else
		field[y][x] = { .is_moving = false, .type = Type::Empty };

    
}

void print_type(Type &type) {
    switch(type) {
    case Type::Empty:
	std::cout << ' ';
	break;
    case Type::Fixed:
	std::cout << '#';
	break;
    default:
	std::cout << 'O';
    }
}

void print_direction(Direction &direction) {
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



void print_cell(Cell &cell) {
    if(cell.is_moving) {
	print_direction(cell.direction);
    } else {
	print_type(cell.type);
    }
}


void print_field(Cell **field, Config config) {

    std::cout << "▗";
    for(int i = 0; i < config.width; i ++)
	std::cout << "▄";
    std::cout << "▖" << '\n';
    
    for(int y = 0; y < config.height; y ++) {
	std::cout << "▐";
	for(int x = 0; x < config.width; x ++) {
	    print_cell(field[y][x]);
	}
	std::cout << "▌" << '\n';
    }	    

    std::cout << "▝";
    for(int i = 0; i < config.width; i ++)
	std::cout << "▀";
    std::cout << "▘" << '\n';    
}
