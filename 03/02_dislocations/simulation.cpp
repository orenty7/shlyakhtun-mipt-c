#include "simulation.h"

#include <iostream>
#include "state.h"


void dislocation_moves(Cell **field, Config config) {        
    for(int y = 0; y < config.height; y ++) {
	for(int x = 0; x < config.width; x ++) {
	    if(field[y][x].is_moving || field[y][x].type != Type::Floating)
		continue;
	    
	    field[y][x] = {.is_moving = true, .direction = random_direction()};	    
	}
    }	    
}


void move(Cell **field, Config config) {
    
    for(int y = 0; y < config.height; y ++) {
	for(int x = 0; x < config.width; x ++) {
	    Cell cell = field[y][x];

	    if(!cell.is_moving)
		continue;

	    Direction direction = cell.direction;
	    
	    if(direction == Direction::Up) {
		if(field[y - 1][x].is_moving || field[y - 1][x].type != Type::Empty) {
		    field[y][x] = { .is_moving = false, .type = Type::Fixed};
		} else {
		    field[y - 1][x] = { .is_moving = false, .type = Type::Floating};
		    field[y][x] = { .is_moving = false, .type = Type::Empty };
		}		    	    
	    } else if(direction == Direction::Down) {
		if(field[y + 1][x].is_moving || field[y + 1][x].type != Type::Empty) {
		    field[y][x] = { .is_moving = false, .type = Type::Fixed};
		} else {
		    field[y + 1][x] = { .is_moving = false, .type = Type::Floating};
		    field[y][x] = { .is_moving = false, .type = Type::Empty };
		}		    	    
	    } else if(direction == Direction::Right) {
		if(field[y][x + 1].is_moving || field[y][x + 1].type != Type::Empty) {
		    field[y][x] = { .is_moving = false, .type = Type::Fixed};
		} else {
		    field[y][x + 1] = { .is_moving = false, .type = Type::Floating};
		    field[y][x] = { .is_moving = false, .type = Type::Empty };
		}		    	    
	    } else {
		if(field[y][x - 1].is_moving || field[y][x - 1].type != Type::Empty) {
		    field[y][x] = { .is_moving = false, .type = Type::Fixed};
		} else {
		    field[y][x + 1] = { .is_moving = false, .type = Type::Floating};
		    field[y][x] = { .is_moving = false, .type = Type::Empty };
		}		    	    
	    }
	}
    }
}


void freeze(Cell **field, Config config) {
    for(int x = 0; x < config.width; x ++) 
	if(field[0][x].type == Type::Floating)
	    field[0][x].type = Type::Fixed;
    
    for(int x = 0; x < config.width; x ++) 
	if(field[config.height - 1][x].type == Type::Floating)
	    field[config.height - 1][x].type = Type::Fixed;

    for(int y = 0; y < config.height; y ++) 
	if(field[y][0].type == Type::Floating)
	    field[y][0].type = Type::Fixed;

    for(int y = 0; y < config.height; y ++) 
	if(field[y][config.width - 1].type == Type::Floating)
	    field[y][config.width - 1].type = Type::Fixed;


    for(int y = 1; y < config.height - 1; y ++) {
	for(int x = 1; x < config.width - 1; x ++) {
	    if(field[y][x].type != Type::Floating)
		continue;
	    
	    if(field[y - 1][x].type != Type::Empty)
		field[y][x].type = Type::Fixed;
	    else if(field[y + 1][x].type != Type::Empty)
		field[y][x].type = Type::Fixed;
	    else if(field[y][x + 1].type != Type::Empty)
		field[y][x].type = Type::Fixed;
	    else if(field[y][x - 1].type != Type::Empty)
		field[y][x].type = Type::Fixed;	    
	}
    }
}

bool is_end(Cell **field, Config config) {
    for(int y = 0; y < config.height; y ++) 
	for(int x = 0; x < config.width; x ++) 
	    if(field[y][x].type == Type::Floating) 
		return false;

    return true;
}
