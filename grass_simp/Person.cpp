#include <iostream>
#include <stdlib.h> 
#include "Person.h"
#include "time.h"
#include "Okno.h"

int sigm(int x, int l = 0, int h = 1)
{
	return std::max(l, std::min(h, x));
}


//Person::Person(int y, int x) : y_pos(y), x_pos(x)
Person::Person(int x, int y)
{
	// Начальная позиция
	y_pos = y; 
	x_pos = x;
}

//void Person::update(int field_width, int field_height)
void Person::update(Karta* field)
{	 	
	// Chose a random direction to move in 
	int dy = rand() % 3 - 1;
	int dx = rand() % 3 - 1;

	// Update the person's position
	y_pos += dy;
	x_pos += dx;

	// Clamp the person's position to the field boundaries  
	y_pos = sigm(y_pos, 0, field->m_height - 1);
	x_pos = sigm(x_pos, 0, field->m_width - 1);
}



void move(int direction)
{

}

