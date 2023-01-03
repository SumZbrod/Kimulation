#pragma once
#include <SFML/Graphics.hpp>
#include "Karta.h"
#include "Person.h"
#include <vector>
#include "iostream"

class Okno
{
	public:
		Okno(int window_height, int window_width, int cell_diameter);
		Karta m_world;
		Person m_person;
		void loop();
		void draw_person(sf::RenderWindow& window);
	
	private:
		int m_height, m_width, m_cell_diameter;
		sf::RenderWindow window;
		sf::Color getGrassColor(float level);
		//sf::Color sf_palette[];
		//sf::Color green;
		//int hex_colors[5] = {0x1c2638ff, 0x23495dff, 0x39707aff, 0x95e0ccff, 0xdaf2e9ff};
		std::vector<sf::Color> grassColors = {
			sf::Color(0xdaffe9ff), // very dark green
			sf::Color(0x95efccff), // dark green
			sf::Color(0x397f7aff), // green
			sf::Color(0x234f5dff), // light green
			sf::Color(0x1c2f38ff)  // bright green
		};
};


