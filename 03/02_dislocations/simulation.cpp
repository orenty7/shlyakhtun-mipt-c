#include "simulation.h"

#include <iostream>
#include "state.h"


DirectionCell** dislocation_moves(Cell **field, Config config) {
    DirectionCell **d_field = init_field<DirectionCell>(config);
        
    for(int y = 0; y < config.height; y ++) {
	for(int x = 0; x < config.width; x ++) {
	    if(field[y][x] != Cell::Floating) {
		d_field[y][x] = {.is_cell = true, .cell = field[y][x]};
	    } else {
		d_field[y][x] = {.is_cell = false, .direction = random_direction()};
	    }
	}
    }	    

    return d_field;
}


Cell** move(DirectionCell **d_field, Config config) {
    
    for(int y = 0; y < config.height; y ++) {
	for(int x = 0; x < config.width; x ++) {
	    DirectionCell d_cell = d_field[y][x];
	    if(d_cell.is_cell)
		continue;
	    Direction direction = d_cell.direction;
	    
	    if(direction == Direction::Up) {
		if(d_field[y - 1][x].is_cell && d_field[y - 1][x].cell == Cell::Empty) {
		    d_field[y - 1][x] = { .is_cell = true, .cell = Cell::Floating};
		    d_field[y][x] = { .is_cell = true, .cell = Cell::Empty };
		} else {
		    d_field[y][x] = { .is_cell = true, .cell = Cell::Fixed};
		}		    	    
	    } else if(direction == Direction::Down) {
		if(d_field[y + 1][x].is_cell && d_field[y + 1][x].cell == Cell::Empty) {
		    d_field[y + 1][x] = { .is_cell = true, .cell = Cell::Floating};
		    d_field[y][x] = { .is_cell = true, .cell = Cell::Empty };
		} else {
		    d_field[y][x] = { .is_cell = true, .cell = Cell::Fixed};
		}		    	    
	    } else if(direction == Direction::Right) {
		if(d_field[y][x + 1].is_cell && d_field[y][x + 1].cell == Cell::Empty) {
		    d_field[y][x + 1] = { .is_cell = true, .cell = Cell::Floating};
		    d_field[y][x] = { .is_cell = true, .cell = Cell::Empty };
		} else {
		    d_field[y][x] = { .is_cell = true, .cell = Cell::Fixed};
		}		    	    
	    } else {
		if(d_field[y][x - 1].is_cell && d_field[y][x - 1].cell == Cell::Empty) {
		    d_field[y][x - 1] = { .is_cell = true, .cell = Cell::Floating};
		    d_field[y][x] = { .is_cell = true, .cell = Cell::Empty };
		} else {
		    d_field[y][x] = { .is_cell = true, .cell = Cell::Fixed};
		}		    	    

	    }

	}
    }

    Cell **field = init_field<Cell>(config);

    for(int y = 0; y < config.height; y ++) {
	for(int x = 0; x < config.width; x ++) {
	    field[y][x] = d_field[y][x].cell;

	    if(!d_field[y][x].is_cell) {
		std::cerr << "Something went wrong\n";
	    }
	}
    }

    return field;    
}


void freeze(Cell **field, Config config) {
    for(int x = 0; x < config.width; x ++) 
	if(field[0][x] == Cell::Floating)
	    field[0][x] = Cell::Fixed;
    
    for(int x = 0; x < config.width; x ++) 
	if(field[config.height - 1][x] == Cell::Floating)
	    field[config.height - 1][x] = Cell::Fixed;

    for(int y = 0; y < config.height; y ++) 
	if(field[y][0] == Cell::Floating)
	    field[y][0] = Cell::Fixed;

    for(int y = 0; y < config.height; y ++) 
	if(field[y][config.width - 1] == Cell::Floating)
	    field[y][config.width - 1] = Cell::Fixed;


    for(int y = 1; y < config.height - 1; y ++) {
	for(int x = 1; x < config.width - 1; x ++) {
	    if(field[y][x] != Cell::Floating)
		continue;
	    
	    if(field[y - 1][x] != Cell::Empty)
		field[y][x] = Cell::Fixed;
	    else if(field[y + 1][x] != Cell::Empty)
		field[y][x] = Cell::Fixed;
	    else if(field[y][x + 1] != Cell::Empty)
		field[y][x] = Cell::Fixed;
	    else if(field[y][x - 1] != Cell::Empty)
		field[y][x] = Cell::Fixed;	    
	}
    }
}

bool is_end(Cell **field, Config config) {
    for(int y = 0; y < config.height; y ++) 
	for(int x = 0; x < config.width; x ++) 
	    if(field[y][x] == Cell::Floating) 
		return false;

    return true;
}
