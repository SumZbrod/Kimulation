#include "iostream"
#include "Karta.h"

int signp( int x ) {
	return ( x < 0 ) ? -1 : 1;
}



Karta::Karta( int map_height, int map_width ) {

	height = map_height;
	width = map_width;

	// Memory allocation
	_world_map = new int *[ height ];
	for ( int i = 0; i < height; i++ ) {

		_world_map[ i ] = new int[ width ];

	}
	//

}

Karta::~Karta() {

	for ( int i = 0; i < height; i++ ) {

		delete[] _world_map[ i ];

	}

	delete[] _world_map;

}

int Karta::get( int x, int y ) {
	return _world_map[ y ][ x ];
}

void Karta::set( int x, int y, int value ) {
	_world_map[y][x] = value;
}

void Karta::show() {
	for ( int y = 0; y < height; y++ ) {
		for ( int x = 0; x < width; x++ ) {
			std::cout << _world_map[y][x] << '\t';
			
		}
		std::cout << '\n';
	}
}

bool Karta::in_area( int x, int y ) {
	return ( x >= 0 && x < width &&y >= 0 && y < height );
}


int *Karta::getRoute_withoutwall( int start_x, int start_y, int finish_x, int finish_y ) {
	/// <summary>
	/// Method getRoute_withoutwall get from - to positons, and returns poiter to array of moves
	///0, 1, 2, 3 - right, up, left, down
	/// </summary>

	// obs_ptr - it's pointer to array of numbers showing the amount of minimal force needed to reach each square
	// force equal sum of weights of each square of the minimal route or 0 if we don't know

	int array_len = Karta::height * Karta::width;
	int *obs_ptr = new int[ array_len ];

	// set all value equal 0, because we don't know yet
	for ( int i = 0; i < array_len; i++ ) {
		*obs_ptr++ = 0;
	}
	// return poiter to start
	obs_ptr -= array_len;

	// initialition of values for using in cicle 
	int x_sign = 0;
	int y_sign = 0;
	int sub_x = 0;
	int sub_y = 0;
	int min_v = 0;

	// set pointer to start position 
	obs_ptr += start_x + Karta::width * start_y;

	// it's virtal coords of pointer in the map
	int obs_x = start_x;
	int obs_y = start_y;

	// set the first square's force 
	*obs_ptr = Karta::get( obs_x, obs_y );

	bool target_finded = false;
	int route_len = 0;

	// 
	for ( int r = 1; r < Karta::width + Karta::height; r++ ) {
		route_len++;
		// move right
		obs_ptr++;
		obs_x++;
		// move by sides
		// 0, 1, 2, 3 - quarters
		for ( int side = 0; side < 4; side++ ) {
			x_sign = signp( side - 2 );
			y_sign = 2 - std::abs( 2 * side - 3 );

			for ( int i = 0; i < r; i++ ) {
				//std::cout << obs_x << ", " << obs_y << std::endl;
				if ( Karta::in_area( obs_x, obs_y ) ) {
					obs_ptr++;
					min_v = -1;
					for ( int sub_side = 0; sub_side < 4; sub_side++ )
					{
						sub_x = signp( sub_side - 2 );
						sub_y = 2 - std::abs( 2 * sub_side - 3 );
						obs_ptr += sub_x + sub_y * Karta::width;
						//
						if ( *obs_ptr != 0 &&
							( min_v == -1 || *obs_ptr < min_v ) &&
							Karta::in_area( obs_x + sub_x, obs_y + sub_y ) )
							min_v = *obs_ptr;
					}
					//
					obs_ptr--;
					//std::cout << obs_x << ", " << obs_y << std::endl;

					//*obs_ptr = 1+i + r*side + 2*r*(r-1);
					*obs_ptr = Karta::get( obs_x, obs_y ) + min_v;
				}
				if ( obs_x == finish_x && obs_y == finish_y ) {
					target_finded = true;
					break;
				}
				obs_x += x_sign;
				obs_y += y_sign;
				obs_ptr += x_sign + y_sign * Karta::width;
				//std::cout << *obs_ptr << ", ";
			}
			if ( target_finded ) break;
		}
		//std::cout << '\n';
		if ( target_finded ) break;
	}
	//if (!target_finded) throw "target doesn't found";

	int *ptr_routee = new int[ route_len ];
	ptr_routee += route_len;
	int selected_side = 0;
	int move_x = 0;
	int move_y = 0;

	for ( int i = 0; i < route_len; i++ ) {
		min_v = -1;
		selected_side = -1;

		for ( int side = 0; side < 4; side++ ) {
			sub_x = std::abs( side - 2 ) - 1;
			sub_y = std::abs( side - 1 ) - 1;
			obs_ptr += ( obs_x + sub_x ) + ( obs_y + sub_x ) * Karta::width;
			if ( *obs_ptr != 0 &&
				( min_v == -1 || *obs_ptr < min_v ) &&
				Karta::in_area( obs_x + sub_x, obs_y + sub_x ) ) {
				min_v = *obs_ptr;
				move_x = sub_x;
				move_y = sub_y;
			}
		}
		obs_x += move_x;
		obs_y += move_y;
		obs_ptr += move_x + move_y * Karta::width;

		std::cout << selected_side << '\n';
		std::cout << min_v << '\n';
		std::cout << obs_x << ", " << obs_y << '\n';

		*ptr_routee = selected_side;
		ptr_routee--;

		sub_x = 1 - std::abs( selected_side - 2 );
		sub_y = 1 - std::abs( selected_side - 1 );

	}


	

	return 0;
}
