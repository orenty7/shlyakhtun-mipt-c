#include <iostream>

#include "config.h"
#include "state.h"
#include "simulation.h"

using namespace std;

int main() {
    Config config = read_config();
    
    srand(config.seed);
    
    Cell **field = init_field(config);

    
    fill_field(field, config);
    print_field(field, config);
    freeze(field, config);
    
    while(!is_end(field, config)) {	   
	print_field(field, config);
	DirectionCell **d_field = dislocation_moves(field, config);

	print_field(d_field, config);
	
	field = move(d_field, config);

	freeze(field, config);
    }
    print_field(field, config);
}
