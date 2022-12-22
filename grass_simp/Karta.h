#pragma once
class Karta
{
	private:
		int width = 12;
		int height = 8;
		int **_world_map;

	public:
		
		Karta(int height, int width);
		~Karta();
		
		int get(int x, int y);
		void set(int x, int y, int value);
		void show();
		bool in_area(int x, int y);
		int* getRoute_withoutwall(int start_x, int start_y, int finish_x, int finish_y);

		
};


