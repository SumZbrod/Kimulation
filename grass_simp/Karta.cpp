#include "Karta.h"

int signp(int x) {
	return (x < 0) ? -1 : 1;
}

Karta::Karta(int map_height, int map_width) {

	height = map_height;
	width = map_width;

	// Memory allocation
	_world_map = new int* [height];
	for (int i = 0; i < height; i++) {
		_world_map[i] = new int[width];
		for (int j = 0; j < width; j++) _world_map[i][j] = 1;
	}
}

Karta::~Karta() {

	for (int i = 0; i < height; i++) {

		delete[] _world_map[i];

	}

	delete[] _world_map;

}


/// <summary>
/// print all value of map in console
/// </summary>
void Karta::show() {
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			std::cout << _world_map[y][x] << '\t';

		}
		std::cout << '\n';
	}
}

bool Karta::in_area(int y, int x) {
	/// <summary>
	/// function return the true if x and y in the area
	/// </summary>
	return (x >= 0 && x < Karta::width&& y >= 0 && y < Karta::height);
}


int* Karta::getRouteWithoutWall(int start_x, int start_y, int finish_x, int finish_y) {
	/// <summary>
	/// Method getRoute_withoutwall get from - to positons, and returns poiter to array of moves
	/// 0, 1, 2, 3 - right, up, left, down
	/// </summary>
	
	// obs_ptr - it's pointer to array of numbers showing the amount of minimal force needed to reach each square
	// force equal sum of weights of each square of the minimal route or 0 if we don't know

	int array_len = Karta::height * Karta::width;
	int** obs_array =  new int* [height];
	for (int i = 0; i < width; i++) {
		obs_array[i] = new int[width]();
	}

	// initialition of values for using in cicle 
	int x_sign = 0;
	int y_sign = 0;
	int sub_x = 0;
	int sub_y = 0;
	int min_v = 0;
	int cell_value = 0;
	// it's virtal coords of pointer in the map
	int obs_x = start_x;
	int obs_y = start_y;

	// set the first square's force 
	obs_array[obs_y][obs_x] = Karta::_world_map[obs_y][obs_x];

	bool target_finded = false;
	int route_len = 0;

	// loop iterates through the array by spiral and fills it by force
	for (int r = 1; r < width + height; r++) {
		// first loop set the value for r-radius of observation circle radius
		// in this metric circle it's a squre rotated on 45 degree
		// and r - its length of side this square
		
		std::cout << 2;
		// increase lenght of route
		route_len++;

		// move right for start of square observation
		obs_x++;

		for (int side = 0; side < 4; side++) {
			std::cout << 3;

			// side it's number of square's side
			// 0, 1, 2, 3, - NE, NW, SW, SE: side
			x_sign = signp(side - 2); // this math function convert : 0, 1, 2, 3 -> -1, -1, 1, 1
			y_sign = 2 - std::abs(2 * side - 3); // this math function convert : 0, 1, 2, 3 -> -1, 1, 1, -1
			for (int i = 0; i < r; i++) {
				std::cout << 4;
				// this cycle goes around one side
				
				// check coords in the the area
				if (Karta::in_area(obs_x, obs_y)) {
					min_v = -1;
					for (int sub_side = 0; sub_side < 4; sub_side++) {
						std::cout << 5;
						// finding the smallest value other than 0 around a cell in coords in obs_x, obs_y 
						// sub_side it's right, up, left, down - 0, 1, 2, 3

						// sub_x and sub_y it's shift around cell 
						sub_x = std::abs(sub_side - 2) - 1; // this math function works how cos(pi/2 * sub_side): 0, 1, 2, 3 -> 1, 0, -1, 0
						sub_y = std::abs(sub_side - 1) - 1; // this math function works how	sin(pi/2 * sub_side): 0, 1, 2, 3 -> 0, -1, 0, 1
						// and this sub's move coords arount cell like: (1, 0) - right; (0, -1) - up; (-1, 0) - left; (0, 1) - down 
						cell_value = obs_array[obs_y + sub_y][obs_x + sub_x];
						// find minimal value
						if (cell_value != 0 &&
							(min_v == -1 || cell_value < min_v) &&
							Karta::in_area(obs_y + sub_y, obs_x + sub_x))
			 				min_v = cell_value;
							
					}	
					//	
					obs_array[obs_y][obs_x] = _world_map[obs_y][obs_x] + min_v;
				}		
				// check whether the obs coordinates match the target
				if (obs_x == finish_x && obs_y == finish_y) {
					target_finded = true;
					break;
				}
				// move coords by side
				obs_x += x_sign;
				obs_y += y_sign;
			}
			if (target_finded) break;
		}
		if (target_finded) break;
	}

	std::cout << 1;
	if (!target_finded) throw "target doesn't found";
	std::cout << 2;

	// after reaching the goal, the reverse pathfinding algorithm goes

	// ptr_route - it's poiter show to arrai with directions for moving to goal
	int* route_array = new int[route_len];
	int selected_side = 0;
	int move_x = 0;
	int move_y = 0;

	// loop iterates through the aaray by spiral and fills it by force
	for (int i = 0; i < route_len; i++) {
		min_v = -1;
		selected_side = -1;
		for (int sub_side = 0; sub_side < 4; sub_side++) {
			sub_x = std::abs(sub_side - 2) - 1;
			sub_y = std::abs(sub_side - 1) - 1;
			cell_value = obs_array[obs_y + sub_y][obs_x + sub_x];

			if (cell_value != 0 &&
				(min_v == -1 || cell_value < min_v) &&
				in_area(obs_x + sub_x, obs_y + sub_x)) {
				min_v = cell_value;
				move_x = sub_x;
				move_y = sub_y;
				selected_side = sub_side;
			}
		}
		obs_x += move_x;
		obs_y += move_y;
		
		// we should turn around numers 0 <-> 2 and 1 <-> 3
		route_array[route_len-i] = (2 - selected_side) % 4;
	}

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			std::cout << obs_array[y][x]<< '\t';
		}
		std::cout << '\n';
	}
	for (int i = 0; i < route_len; i++) {
		std::cout << route_array[i] << ", ";
	} 
	std::cout << '\n';

	for (int i = 0; i < width; i++) {
		delete[] obs_array[i];
	}
	delete[] obs_array;

	return route_array;
}

