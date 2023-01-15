#pragma once
#include "iostream"
#include "vector"
#include <exception>
#include <string>
#include <sstream>
#include <utility>
#include <stdexcept>
#include "Human.h"
#include "GameComponent.h"



class Karta : public GameComponent
{

public:
	std::vector<std::vector<float>> m_map;
	Karta(int map_height, int map_width);
	int m_height;
	int m_width;

	//~Karta();
	void show();
	std::pair<int, int> sideToDir( int side );
	//float get(int x, int y);
	bool in_area(int y, int x);
	void add(int y, int x, float v);
	//int getRouteWithoutWall(int start_x, int start_y, int finish_x, int finish_y);
	std::vector<int> generatePath(int start_x, int start_y, int finish_x, int finish_y);
};