#include "state.h"

#include <iostream>
#include "config.h"


bool random_cell(float prob) {
    return ((float) rand()) / ((float) RAND_MAX) < prob;
}

Cell** init_field(Config config) {
    Cell **field = new Cell*[config.height];
    for(int i = 0; i < config.height; i ++)
	field[i] = new Cell[config.width];    
    return field;
}

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