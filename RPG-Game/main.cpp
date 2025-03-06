#include <SFML/Graphics.hpp>
#include <iostream>

int AddTwoNumbers(int a = 5, int b = 10)
{
	return a + b;
}


int main()
{
	std::cout << AddTwoNumbers() << std::endl;

	// INITIALIZE

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(800, 600), "RPG Game", sf::Style::Default, settings);


	// sf::RenderWindow window(sf::VideoMode(800, 600), "RPG Game");
	sf::CircleShape shape(50.0f);
	shape.setFillColor(sf::Color::Red);
	shape.setPosition(sf::Vector2f(100, 100));
	shape.setOutlineThickness(10);
	shape.setOutlineColor(sf::Color::Blue);

	sf::RectangleShape rectangle(sf::Vector2f(100, 60));
	rectangle.setPosition(sf::Vector2f(100, 100));
	rectangle.setFillColor(sf::Color::Yellow);
	rectangle.setOrigin(rectangle.getSize() / 2.0f);
	rectangle.setRotation(45);

	//sf::CircleShape triangle(80, 3);

	//sf::CircleShape square(50, 4);

	//sf::CircleShape octagon(80, 8);
	// INITIALIZE

	// main game loop
	while (window.isOpen())
	{
		

		//-----------------UPDATE----------------
		sf::Event event;
		while (window.pollEvent(event)) 
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		// ---------------UPDATE-------------

		// ----------------DRAW--------------
		window.clear(sf::Color::Black);
		window.draw(shape);
		window.draw(rectangle);
		//window.draw(triangle);
		//window.draw(square);
		//window.draw(octagon);
		window.display();
		// ----------------DRAW--------------
	}

	return 0;
}