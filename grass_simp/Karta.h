#pragma once
class Karta
{
	private:
		int width = 12;
		int height = 8;

	public:
		int world_map[];
		Karta(int height, int width);
		int get(int x, int y);
		void set(int x, int y, int value);
		void show();
		bool in_area(int x, int y);
		int* getRoute_withoutwall(int start_x, int start_y, int finish_x, int finish_y);

};

