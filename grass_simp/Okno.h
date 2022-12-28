#pragma once
#include <SFML/Graphics.hpp>

class Okno
{
	private:
		sf::RenderWindow window;
		//sf::Color colors[5];
		sf::Color green;
	public:
		Okno(int window_height, int window_width);
		void loop();
};

