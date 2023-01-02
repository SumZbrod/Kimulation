#ifndef OKNO_H
#define OKNO_H
#include <SFML/Graphics.hpp>
#include "Karta.h"
#include "Person.h"
#include <vector>
#include "iostream"


class Okno
{
	public:
		Okno(int window_height, int window_width, Karta m_world);
		Karta m_world;
		Person m_person;
		void loop();
		void draw_person(sf::RenderWindow& window);
	
	private:
		int m_height, m_width, cell_diameter;
		sf::RenderWindow window;
		//sf::Color sf_palette[];
		//sf::Color green;
		//int hex_colors[5] = {0x1c2638ff, 0x23495dff, 0x39707aff, 0x95e0ccff, 0xdaf2e9ff};
		std::vector<sf::Color> sf_palette = {sf::Color(0xdaf2e9ff), sf::Color(0x95e0ccff), sf::Color(0x39707aff), sf::Color(0x23495dff), sf::Color(0x1c2638ff) };
};


#endif 