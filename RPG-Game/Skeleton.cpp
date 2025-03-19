#include "Skeleton.h"
#include <iostream>

Skeleton::Skeleton() : 
	health(100) 
{
}

Skeleton::~Skeleton()
{
}

void Skeleton::ChangeHealth(int hp)
{
	health += hp; // reduces health by specified number
	healthText.setString(std::to_string(health));  // updates hp only when chnaged instead of every frame
}

void Skeleton::Initialize()
{
	boundingRectangle.setFillColor(sf::Color::Transparent);
	boundingRectangle.setOutlineColor(sf::Color::Blue);
	boundingRectangle.setOutlineThickness(1);

	size = sf::Vector2i(64, 64);
}

void Skeleton::Load()
{
	if (font.loadFromFile("Assets/Fonts/arial.ttf"))
	{
		std::cout << "Arial.ttf font in Assets has been loaded successfully >^.^<" << std::endl;
		healthText.setFont(font);
		healthText.setString(std::to_string(health));
	}
	else
	{
		std::cout << "Failed to load Arial.ttf font in Assets :(" << std::endl;
	}

	if (texture.loadFromFile("Assets/Skeleton/Textures/spritesheet.png"))
	{
		std::cout << "Skeleton image loaded :D" << std::endl;
		sprite.setTexture(texture);
		sprite.setPosition(sf::Vector2f(1600, 700));

		int Xindex = 0;
		int Yindex = 2;

		sprite.setTextureRect(sf::IntRect(Xindex * size.x, Yindex * size.y, size.x, size.y));
		sprite.scale(sf::Vector2f(3, 3));

		boundingRectangle.setSize(
			sf::Vector2f(size.x * sprite.getScale().x, size.y * sprite.getScale().y)
		);
	}
	else
	{
		std::cout << "Skeleton images failed to load ;-;" << std::endl;
	}
}

void Skeleton::Update(float deltaTime)
{
	if (health > 0)
	{
		boundingRectangle.setPosition(sprite.getPosition());
		healthText.setPosition(sprite.getPosition());
	}
	
}

void Skeleton::Draw(sf::RenderWindow& window)
{
	if (health > 0) 
	{
		window.draw(sprite);
		window.draw(boundingRectangle);
		window.draw(healthText);
	}
}