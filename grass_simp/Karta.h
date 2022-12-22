#pragma once
#include "iostream"
class Karta
{
	private:
		int width = 12;
		int height = 8;
		// 2-d array with levels of grass
		int **_world_map;

	public:
		Karta(int map_height, int map_width);
		~Karta();
		void show();
		bool in_area(int x, int y);
		int* getRouteWithoutWall(int start_x, int start_y, int finish_x, int finish_y);
		
};


