#include "Skeleton.h"
#include <iostream>

void Skeleton::Initialize()
{

}

void Skeleton::Load()
{
	if (texture.loadFromFile("Assets/Skeleton/Textures/spritesheet.png"))
	{
		std::cout << "Skeleton image loaded :D" << std::endl;
		sprite.setTexture(texture);
		sprite.setPosition(sf::Vector2f(1600, 700));

		int Xindex = 0;
		int Yindex = 2;

		sprite.setTextureRect(sf::IntRect(Xindex * 64, Yindex * 64, 64, 64));
		sprite.scale(sf::Vector2f(3, 3));

	}
	else
	{
		std::cout << "Skeleton images failed to load ;-;" << std::endl;
	}
}

void Skeleton::Update()
{

}

void Skeleton::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}