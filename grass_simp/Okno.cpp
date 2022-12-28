#include "Okno.h"
#include "iostream"

Okno::Okno(int window_height, int window_width) {
	//sf::RenderWindow window(sf::VideoMode(window_width, window_height), "Kimulation");

	//sf::Color colors[5] = { sf::Color.new("#1c2638"), sf::Color.new("#23495d"), sf::Color.new("#39707a"), sf::Color.new("#95e0cc"), sf::Color.new("#daf2e9") };
	//colors[5] = {sf::Color("#1c2638"), sf::Color("#23495d"), sf::Color("#39707a"), sf::Color("#95e0cc"), sf::Color("#daf2e9") };
	green = sf::Color(0x23495dff);
}

void Okno::loop() 
{
	
	sf::RenderWindow window(sf::VideoMode(800, 600), "Kimulation");
	sf::RectangleShape square(sf::Vector2f(100.f, 100.f));
	square.setFillColor(green);
	int x = 0, y = 0;
	std::cout << window.isOpen() << '\n';
	while (window.isOpen()) 
	{
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			if (evnt.type == sf::Event::Closed)
				window.close();

			if (evnt.type == sf::Event::KeyPressed)
				if (evnt.key.code == sf::Keyboard::Space)
					square.setPosition(x, y);
					window.draw(square);
					x += 100;
					y += 100;
		}
	}
	
	//window.clear(sf::Color::Black);
	window.display();
}