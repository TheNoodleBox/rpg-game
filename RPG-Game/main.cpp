#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <math.h>

void NormalizeVector(sf::Vector2f vector)
{
	std::sqrt(vector.x * vector.x + vector.y * vector.y);
}

int main()
{
	//Top ten tomar moments

	std::vector<std::string> topTenTomarMoments;
	topTenTomarMoments.reserve(10);

	topTenTomarMoments.push_back("Final Fantasy XV 1");
	topTenTomarMoments.push_back("Final Fantasy XV 2");

	std::cout << topTenTomarMoments[0] << std::endl; // FFXV
	std::cout << topTenTomarMoments[1] << std::endl; // FFXV

	std::cout << "Count" << topTenTomarMoments.size() << std::endl; // 1
	std::cout << "Capacity" << topTenTomarMoments.capacity() << std::endl; // 4


	// INITIALIZE----------------------------------------------

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "RPG Game", sf::Style::Default, settings);

	// INITIALIZE------------------------------------------------

	sf::RectangleShape bullet(sf::Vector2f(50, 25));
	bullet.setPosition(sf::Vector2f(50, 50));
	

	// Load-------------------------------------------------------------

	// Skeleton ---------------------------------------------------------
	sf::Texture skeletonTexture;
	sf::Sprite skeletonSprite;

	if (skeletonTexture.loadFromFile("Assets/Skeleton/Textures/spritesheet.png"))
	{
		std::cout << "Enemy image loaded :D" << std::endl;
		skeletonSprite.setTexture(skeletonTexture);
		skeletonSprite.setPosition(sf::Vector2f(400, 100));

		// starting point, size of wanted sprite
		// x, y, Width, Height
		int Xindex = 2;
		int Yindex = 3;

		skeletonSprite.setTextureRect(sf::IntRect(Xindex * 64, Yindex * 64, 64, 64));
		skeletonSprite.scale(sf::Vector2f(3, 3));

	}
	else
	{
		std::cout << "Skeleton images failed to load ;-;" << std::endl;
	}
	// Skeleton ---------------------------------------------------------




	// Player ---------------------------------------------------------
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
		playerSprite.scale(sf::Vector2f(3, 3));
		playerSprite.setPosition(sf::Vector2f(1650, 800));
	}
	else
	{
		std::cout << "PLayer images failed to load :(" << std::endl;
	}
	// Player ---------------------------------------------------------




	// Load

	// calculate the direction of the bullet ----------------------------
	
	sf::Vector2f direction = skeletonSprite.getPosition() - bullet.getPosition();
	

	// calculate the direction of the bullet ----------------------------


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

		bullet.setPosition(bullet.getPosition() + direction * 0.0001f);

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
		window.draw(skeletonSprite);
		window.draw(playerSprite);
		window.draw(bullet);
		window.display();
		// ----------------DRAW--------------
	}

	return 0;
}