#include "iostream"
#include "Karta.h"

int signp(int x) {
	return (x < 0) ? -1 : 1;
}


Karta::Karta(int height = 12, int width = 8) {
	this->width = width;
	this->height = height;
	this->world_map[height * width] = {};
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			this->world_map[x + y * width] = 1;
		}
	}
}

int Karta::get(int x, int y) {
	return Karta::world_map[x + y * width];
}

void Karta::set(int x, int y, int value) {
	Karta::world_map[x + y * width] = value;
}

void Karta::show() {
	for (int y = 0; y < Karta::height; y++) {
		for (int x = 0; x < Karta::width; x++) {
			std::cout << get(x, y) << '\t';
		}
		std::cout << '\n';
	}
}

bool Karta::in_area(int x, int y) {
	return (x >= 0 && x < Karta::width&& y >= 0 && y < Karta::height);
}


int* Karta::getRoute_withoutwall(int start_x, int start_y, int finish_x, int finish_y) {
	int radius = std::max(std::abs(start_x - finish_x), std::abs(start_y - finish_y));
	int array_len = Karta::height * Karta::width;

	int* obs_ptr = new int[array_len];


	for (int i = 0; i < array_len; i++) {
		*obs_ptr++ = 0;
	}
	obs_ptr -= array_len;
	int* start_obs_ptr = obs_ptr;
	//int r = 1;
	int x_sign = 0;
	int y_sign = 0;
	int sub_x = 0;
	int sub_y = 0;
	//while (true) {
	obs_ptr += start_x + Karta::width * start_y;
	*obs_ptr = 1;
	int obs_x = start_x;
	int obs_y = start_y;
	int min_v = 0;

	bool target_finded = false;
	int roud_len = 0;

	for (int r = 1; r < 15; r++) {
		roud_len++;
		obs_ptr++;
		obs_x++;
		for (int side = 0; side < 4; side++) {
			x_sign = signp(side - 2);
			y_sign = 2 - std::abs(2 * side - 3);
			//std::cout << y_sign << ' ' << x_sign << std::endl;
			for (int i = 0; i < r; i++) {
				//std::cout << obs_x << ", " << obs_y << std::endl;
				if (Karta::in_area(obs_x, obs_y)) {
					obs_ptr++;
					min_v = -1;
					for (int sub_side = 0; sub_side < 4; sub_side++) 
					{
						sub_x = signp(sub_side - 2);
						sub_y = 2 - std::abs(2 * sub_side - 3);
						obs_ptr += sub_x + sub_y * Karta::width;
						//
						if (*obs_ptr != 0 &&
							(min_v == -1 || *obs_ptr < min_v) &&
							Karta::in_area(obs_x + sub_x, obs_y + sub_y))
							min_v = *obs_ptr;
					}
					//
					obs_ptr--;
					//std::cout << obs_x << ", " << obs_y << std::endl;

					//*obs_ptr = 1+i + r*side + 2*r*(r-1);
					*obs_ptr = Karta::get(obs_x, obs_y) + min_v;
				}
				if (obs_x == finish_x && obs_y == finish_y) {
					target_finded = true;
					break;
				}
				obs_x += x_sign;
				obs_y += y_sign;
				obs_ptr += x_sign + y_sign * Karta::width;
				//std::cout << *obs_ptr << ", ";
			}
			if (target_finded) break;
		}
		//std::cout << '\n';
		if (target_finded) break;
	}
	if (!target_finded) throw "target doesn't found";

	int* ptr_roude = new int[roud_len];
	ptr_roude += roud_len-1;
	ptr_roude--;

	for (int i = 0; i < roud_len; i++) {
		obs_ptr++;
		obs_x++;
		min_v = -1;
		for (int side = 0; side < 4; side++) {
			x_sign = signp(side - 2);
			y_sign = 2 - std::abs(2 * side - 3);
			obs_x += x_sign;
			obs_y += y_sign;
			obs_ptr += x_sign + y_sign * Karta::width;
			if (*obs_ptr != 0 &&
				(min_v == -1 || *obs_ptr < min_v) &&
				Karta::in_area(obs_x + sub_x, obs_y + sub_y))
				min_v = *obs_ptr;
		}
		*ptr_roude = min_v;
		ptr_roude--;
		obs_ptr--;
		obs_x--;
	}


	for (int y = 0; y < Karta::height; y++) {
		for (int x = 0; x < Karta::width; x++) {
			std::cout << *start_obs_ptr++ << '\t';
		}
		std::cout << '\n';
	}

	for (int i = 0; i < roud_len; i++) {
		std::cout << *ptr_roude++ << ", ";
	} 
	return 0;
}
