#include "state.h"

#include "config.h"
#include <iostream>

bool random_bool(float prob) {
    return ((float)rand()) / ((float)RAND_MAX) < prob;
}

Direction random_direction() {
    switch (rand() % 4) {
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

void fill_field(Cell (&field)[HEIGHT][WIDTH], Config &config) {
    for (int i = 0; i < config.dislocations; i++) {
        bool generated = false;
        while (!generated) {
            int x = rand() % WIDTH;
            int y = rand() % HEIGHT;

            if (field[y][x].type == Type::Empty) {
                field[y][x].type = Type::Floating;
                generated = true;
            }
        }
    }
}

void print_type(Type &type) {
    switch (type) {
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
    switch (direction) {
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
    if (cell.is_moving) {
        print_direction(cell.direction);
    } else {
        print_type(cell.type);
    }
}

void print_field(Cell (&field)[HEIGHT][WIDTH]) {

    std::cout << "▗";
    for (int i = 0; i < WIDTH; i++)
        std::cout << "▄";
    std::cout << "▖" << '\n';

    for (int y = 0; y < HEIGHT; y++) {
        std::cout << "▐";
        for (int x = 0; x < WIDTH; x++) {
            print_cell(field[y][x]);
        }
        std::cout << "▌" << '\n';
    }

    std::cout << "▝";
    for (int i = 0; i < WIDTH; i++)
        std::cout << "▀";
    std::cout << "▘" << '\n';
}
