#include "Okno.h"


Okno::Okno(int window_width, int window_height, int cell_diameter)
	: m_width(window_width), m_height(window_height), m_cell_diameter(cell_diameter), m_world(Karta(4, 4))
{
	int h = m_width / m_cell_diameter, w = m_height / m_cell_diameter;
	m_world = Karta(w, h);
	m_person = Person(w/2, h/2);
}

void Okno::draw_person(sf::RenderWindow& window)
{
	sf::CircleShape point(m_cell_diameter / 4);
	point.setPosition(m_person.x_pos * m_cell_diameter + m_cell_diameter / 4, m_person.y_pos * m_cell_diameter + m_cell_diameter / 4);
	point.setFillColor(sf::Color::Yellow);
	window.draw(point);
}

sf::Color Okno::getGrassColor(float level)
{
	// int index = level * grassColor.size(); Хватит пользоваться нейросетью =(
	int index = static_cast<int>(level * grassColors.size());
	if (index >= grassColors.size()) index = grassColors.size() - 1;
	sf::Color res_clr = grassColors[index];
	return res_clr;
}

void Okno::loop()
{
	sf::RenderWindow window(sf::VideoMode(m_height, m_width), "Kimulation");

	sf::RectangleShape square(sf::Vector2f(m_cell_diameter, m_cell_diameter));
	
	int x = 0, y = 0;
	window.clear(sf::Color::Black);
	window.setFramerateLimit(10);
	int r = 0;
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
				square.setPosition(x * m_cell_diameter, y * m_cell_diameter);
				//square.setFillColor(sf_palette[int(m_world.world_map[y][x] * palette_len)]);
				square.setFillColor(getGrassColor(m_world.world_map[y][x]));
				window.draw(square);
				m_world.add(x, y, .0001);
			}
		}
		m_person.update(&m_world);
		for (int x_0 = -r; x_0 < r; x_0++)
		{
			for (int y_0 = -r; y_0 < r; y_0++)
			{	
				m_world.add(m_person.x_pos + x_0, m_person.y_pos + y_0, -.01);

			}
		}
		m_world.add(m_person.x_pos, m_person.y_pos, -.1);

		draw_person(window);
		window.display();
	
	}
}