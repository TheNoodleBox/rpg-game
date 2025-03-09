#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	// INITIALIZE

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(800, 600), "RPG Game", sf::Style::Default, settings);

	// INITIALIZE

	// Load
	sf::Texture playerTexture;
	sf::Sprite playerSprite;

	if (playerTexture.loadFromFile("Assets/Player/Textures/spritesheet.png"))
	{
		std::cout << "Player images loaded!" << std::endl;
		playerSprite.setTexture(playerTexture);

		// starting point, size of wanted sprite
		// x, y, Width, Height
		int Xindex = 0;
		int Yindex = 0;

		playerSprite.setTextureRect(sf::IntRect(Xindex * 64, Yindex * 64, 64, 64));
	}
	else
	{
		std::cout << "PLayer images failed to load :(" << std::endl;
	}

	// Load

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

		sf::Vector2f position = playerSprite.getPosition();

		// windows is weird so up is -Y and down is Y
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			playerSprite.setPosition(position + sf::Vector2f(1, 0));
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			playerSprite.setPosition(position + sf::Vector2f(-1, 0));
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			playerSprite.setPosition(position + sf::Vector2f(0, -1));
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			playerSprite.setPosition(position + sf::Vector2f(0, 1));

		// ---------------UPDATE-------------

		// ----------------DRAW--------------
		window.clear(sf::Color::Black);
		window.draw(playerSprite);
		window.display();
		// ----------------DRAW--------------
	}

	return 0;
}