#pragma once
#include <SFML/Graphics.hpp>
#include "Karta.h"

class Person
{
public:
	Person(int y = 0, int x = 0);

	//void update(int field_width, int field_height);
	void update(Karta* field);
	int x_pos;
	int y_pos;
	
	//Мув принмает направление ходить 
	// 0 право
	// 1 верх
	// 2 влево
	// 3 низ
	// должено менять направление 
	// метод апдате
	// Выдавать случайный пунк назначения, после достижения которого процесс повторяется.
	//

	void move(int direction);

private:
	

	bool in_area(int y, int x);
};

