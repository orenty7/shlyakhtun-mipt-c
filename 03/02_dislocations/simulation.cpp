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


void move_cell(Cell **field, Config config, Point start) {
    Cell cell = field[start.y][start.x];
    if(!cell.is_moving)
	return;

    Direction direction = cell.direction;

    Point end;
    end = start;
    
    if(direction == Direction::Up) {
	end.y -= 1; 
    } else if (direction == Direction::Down) {
	end.y += 1;
    } else if (direction == Direction::Left) {
	end.x -= 1;
    } else {
	end.x += 1;
    }

    if(end.y < 0 || end.y >= config.height || \
       end.x < 0 || end.x >= config.width ) {
	std::cerr << "Something went wrong. Cell near to border didn't freezed, but it must have\n";
	return;	
    }

    if(field[end.y][end.x].is_moving) {
	std::cerr << "Something went wrong. Two moving cell near to one another.";
	std::cerr << "They must be freezed, but it don't\n";
	return;
    }

    if(field[end.y][end.x].type == Type::Empty) {		    		    
	field  [end.y]  [end.x] = { .is_moving = false, .type = Type::Floating};
	field[start.y][start.x] = { .is_moving = false, .type = Type::Empty };		    
    } else {
	field[start.y][start.x] = { .is_moving = false, .type = Type::Fixed };
    }		    	    	
    
}

void move(Cell **field, Config config) {
    
    for(int y = 0; y < config.height; y ++) {
	for(int x = 0; x < config.width; x ++) {
	    move_cell(field, config, {x, y});
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
