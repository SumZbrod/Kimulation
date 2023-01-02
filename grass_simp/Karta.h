#pragma once
#include "iostream"
#include "vector"

class Karta
{
	//private:
	//	// 2-d array with levels of grass
	//	//std::vector<float> world_map;

	public:
		std::vector<std::vector<float>> world_map;
		Karta(int map_height, int map_width);
		int m_height;
		int m_width;
		//~Karta();
		void show();
		//float get(int x, int y);
		bool in_area(int y, int x);

		//int getRouteWithoutWall(int start_x, int start_y, int finish_x, int finish_y);
		std::vector<int> generatePath(int start_x, int start_y, int finish_x, int finish_y);
};


