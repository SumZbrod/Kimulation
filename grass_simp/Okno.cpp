#include "Okno.h"

Okno::Okno(int window_height, int window_width, Karta world)
	: m_height(window_height), m_width(window_width), m_world(world)
{	
	//std::cout << m_height << ' ' << m_world.m_height << ' ' << m_width << ' ' << m_world.m_width << '\n';
	std::cout << m_height / m_world.m_height << ' ' << m_width / m_world.m_width << '\n';

	cell_diameter = std::min(m_height / m_world.m_height, m_width / m_world.m_width);
	Person m_person();
}

void Okno::draw_person(sf::RenderWindow& window)
{
	sf::CircleShape point(cell_diameter / 4);
	point.setPosition(m_person.x_pos * cell_diameter + cell_diameter / 2, m_person.y_pos * cell_diameter + cell_diameter / 2);
	point.setFillColor(sf::Color::Yellow);
	window.draw(point);
}

void Okno::loop()
{
	sf::RenderWindow window(sf::VideoMode(m_height, m_width), "Kimulation");
	sf::RectangleShape square(sf::Vector2f(cell_diameter, cell_diameter));
	int x = 0, y = 0;
	window.clear(sf::Color::Black);
	window.setFramerateLimit(60);

	while (window.isOpen()) 
	{
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			if (evnt.type == sf::Event::Closed)
				window.close();

		}
		window.clear(sf::Color::Black);

		for (float y = 0; y < m_world.m_height; y++) 
		{
			for (float x = 0; x < m_world.m_width; x++) 
			{
				square.setPosition(x * cell_diameter, y * cell_diameter);
				square.setFillColor(sf_palette[int(m_world.world_map[y][x]*4)]);
				window.draw(square);
			}
		}
		m_person.update(&m_world);
		draw_person(window);
		window.display();
	
	}
}