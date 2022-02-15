#include "state.h"

#include <iostream>
#include "config.h"


bool random_cell(float prob) {
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


template<typename T> 
T** init_field(Config config) {
    T **field = new T*[config.height];
    for(int i = 0; i < config.height; i ++)
	field[i] = new T[config.width];    
    return field;
}

template Cell** init_field(Config);
template DirectionCell** init_field(Config);



void fill_field(Cell **field, Config config) {
    for(int y = 0; y < config.height; y ++) {
	for(int x = 0; x < config.width; x ++) {
	    if(random_cell(config.probability))
		field[y][x] = Cell::Floating;
	    else
		field[y][x] = Cell::Empty;
	}
    }
    
}

void print_cell(Cell &cell) {
    switch(cell) {
    case Cell::Empty:
	std::cout << ' ';
	break;
    case Cell::Fixed:
	std::cout << '#';
	break;
    default:
	std::cout << 'O';
    }
}

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



void print_cell(DirectionCell &d_cell) {
    if(d_cell.is_cell) {
	print_cell(d_cell.cell);
    } else {
	print_direction(d_cell.direction);
    }
}


template<typename T>
void print_field(T **field, Config config) {

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


template void print_field<Cell>(Cell **, Config);
template void print_field<DirectionCell>(DirectionCell **, Config);
