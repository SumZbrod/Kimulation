#include "Karta.h"


int signp(int x) {
	return (x < 0) ? -1 : 1;
}

Karta::Karta(int map_width, int map_height) 
	: m_width(map_width), m_height(map_height)

{
	world_map = std::vector < std::vector<float> >(m_height, std::vector<float>(m_width, 1.f));

	v_hum.push_back( new Human( { 2,5 } ) );
	
}

//Karta::~Karta() {
	//std::vector<float>().swap(world_map);
	//delete world_map;

//}

/// <summary>		
/// print all value of map in console
/// </summary>
/// Подлежит удалению.
void Karta::show() {
	for (int y = 0; y < m_width; y++) {
		for (int x = 0; x < m_height; x++) {
			//std::cout << get(y, x) << '\t';
			std::cout << world_map[y][x] << '\t';
		}
		std::cout << '\n';
	}
}

//Перенести в отдельный класс логики.
std::pair<int, int> Karta::sideToDir( int side )
{

	int x = std::abs( side - 2 ) - 1; // this math function works how cos(pi/2 * sub_side): 0, 1, 2, 3 -> 1, 0, -1, 0
	int y = std::abs( side - 1 ) - 1; // this math function works how	sin(pi/2 * sub_side): 0, 1, 2, 3 -> 0, -1, 0, 1

	return std::pair<int, int>(x,y);

}

//Пенис
bool Karta::in_area(int x, int y) {
	
	// function return the true if x and y in the area
	
	return (y >= 0 && y < m_height&& x >= 0 && x < m_width);
}


void Karta::add(int x, int y, float v) {
	if (in_area(x, y))
	{
		float old_v = world_map[y][x];
		world_map[y][x] = std::min(1.f, std::max(0.f, v + old_v));
	}

}

//int* Karta::getRouteWithoutWall(int start_x, int start_y, int finish_x, int finish_y) {
std::vector<int> Karta::generatePath(int start_x, int start_y, int finish_x, int finish_y) {
	/// <summary>
	/// Method getRoute_withoutwall get from - to positons, and returns poiter to array of moves
	/// 0, 1, 2, 3 - right, up, left, down
	/// </summary>
	
	// obs_ptr - it's pointer to array of numbers showing the amount of minimal force needed to reach each square
	// force equal sum of weights of each square of the minimal route or 0 if we don't know

	
	/*int** obs_array =  new int* [width];
	for (int i = 0; i < height; i++) {
		obs_array[i] = new int[height]();
	}*/

	//std::vector<float> obs_array(width * height, 0.f);
	std::vector<std::vector<float>> obs_array(m_width, std::vector<float>(m_height, 0.f));

	// initialition of values for using in cicle 
	int x_sign = 0;
	int y_sign = 0;
	int sub_x = 0;
	int sub_y = 0;
	float min_v = 0.f;
	float cell_value = 0.f;

	// it's virtal coords of pointer in the map
	int obs_x = start_x;
	int obs_y = start_y;

	// set the first square's force 
	//obs_array[obs_y][obs_x] = Karta::world_map[obs_y][obs_x];
	//obs_array[obs_y][obs_x] = Karta::world_map[obs_x + obs_y * height];
	
	obs_array[obs_y][obs_x] = world_map[obs_y][obs_x];

	bool target_finded = false;
	int route_len = 0;

	// loop iterates through the array by spiral and fills it by force
	for (int r = 1; r < m_height+ m_width; r++) {
		// first loop set the value for r-radius of observation circle radius
		// in this metric circle it's a squre rotated on 45 degree
		// and r - its length of side this square

		
		// increase lenght of route
		route_len++;

		// move right for start of square observation
		obs_x++;

		for (int side = 0; side < 4; side++) {

			// side it's number of square's side
			// 0, 1, 2, 3, - NE, NW, SW, SE: side
			x_sign = signp(side - 2); // this math function convert : 0, 1, 2, 3 -> -1, -1, 1, 1
			y_sign = 2 - std::abs(2 * side - 3); // this math function convert : 0, 1, 2, 3 -> -1, 1, 1, -1
			for (int i = 0; i < r; i++) {
				// this cycle goes around one side
				
				// check coords in the the area
				if (in_area(obs_x, obs_y)) {
					min_v = -1.f;
					for (int sub_side = 0; sub_side < 4; sub_side++) {
						// finding the smallest value other than 0 around a cell in coords in obs_x, obs_y 
						// sub_side it's right, up, left, down - 0, 1, 2, 3

						// sub_x and sub_y it's shift around cell 
						sub_x = std::abs(sub_side - 2) - 1; // this math function works how cos(pi/2 * sub_side): 0, 1, 2, 3 -> 1, 0, -1, 0
						sub_y = std::abs(sub_side - 1) - 1; // this math function works how	sin(pi/2 * sub_side): 0, 1, 2, 3 -> 0, -1, 0, 1
						// and this sub's move coords arount cell like: (1, 0) - right; (0, -1) - up; (-1, 0) - left; (0, 1) - down 
						//std::cout << 117 << '\t' << obs_y << ", " << obs_x << '\n';
						//std::cout << 118 << '\t' << obs_y + sub_y << ", " << obs_x + sub_x << '\n';
						if (in_area(obs_x + sub_x, obs_y + sub_y)){
							//std::cout << 120 << '\t' << obs_y + sub_y << ", " << obs_x + sub_x << '\n';
							cell_value = obs_array[obs_y + sub_y][obs_x + sub_x];
							if (cell_value != 0 && (min_v == -1 || cell_value < min_v)) {
			 					min_v = cell_value;
							}
						}
						// find minimal value
					}	
					//	
					//std::cout << 129 << '\t' << obs_y << ", " << obs_x << '\n';
					//obs_array[obs_y*height+obs_x] = get(obs_y, obs_x) + min_v;
					obs_array[obs_y][obs_x] = world_map[obs_y][obs_x] + min_v;
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

	if (!target_finded) throw "target doesn't found";

	// after reaching the goal, the reverse pathfinding algorithm goes

	// ptr_route - it's poiter show to arrai with directions for moving to goal
	//int* route_array = new int[route_len];
	std::vector<int> route_array(route_len, -1);
	int selected_side = 0;
	int move_x = 0;
	int move_y = 0;
	
	// the variable el alternates between 1 and 0 it's needed to change the sign less than and the sign less than or equal to. This is necessary so that there is an alternation of direction. 
	int el = 0;
	// loop iterates through the aaray by spiral and fills it by force
	for (int i = route_len-1; i >= 0; --i) {
		min_v = -1.f;
		selected_side = -1;
		for (int sub_side = 0; sub_side < 4; sub_side++) {
			sub_x = std::abs(sub_side - 2) - 1;
			sub_y = std::abs(sub_side - 1) - 1;
			if (in_area(obs_x + sub_x, obs_y + sub_y)) {
				//std::cout << 162 << obs_y + sub_y << ", " << obs_x + sub_x << '\n';
				//cell_value = obs_array[obs_y + sub_y][obs_x + sub_x];
				//obs_coord = height* (obs_y + sub_y) + obs_x + sub_x;
				//cell_value = obs_array[obs_coord];
				cell_value = obs_array[obs_y + sub_y][obs_x + sub_x];
				if (cell_value != 0 && (min_v == -1 || cell_value < min_v + el)) {
					min_v = cell_value;
					move_x = sub_x;
					move_y = sub_y;
					selected_side = sub_side;
				}
			}
		}
		//0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3,
		obs_x += move_x;
		obs_y += move_y;
		
		// we should turn around numers 0 <-> 2 and 1 <-> 3
		//std::cout << 176 << "i = " << i << '\n';
		route_array[i] = (2 + selected_side) % 4;
		el = 1 - el;
	}

	for (int y = 0; y < m_width; y++) {
		for (int x = 0; x < m_height; x++) {
			//std::cout << obs_array[y * height+ x] << '\t';
			std::cout << obs_array[y][x] << '\t';
		}
		std::cout << '\n';
	}

	for (int i = 0; i < route_len; i++) {
		std::cout << route_array[i] << ", ";
	} 
	std::cout << '\n';
	//rebild_to_vector
	/*for (int i = 0; i < width; i++) {
		delete[] obs_array[i];
	}*/
	//std::vector<float>().swap(obs_array);

	//delete &obs_array;
	return route_array;
}