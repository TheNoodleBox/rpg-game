#include "Player.h"
#include <iostream>
#include "Math.h"

void Player::Initialize()
{

}

void Player::Load()
{
	if (texture.loadFromFile("Assets/Player/Textures/spritesheet.png"))
	{
		std::cout << "Player images loaded!" << std::endl;
		sprite.setTexture(texture);

		int Xindex = 0;
		int Yindex = 0;

		sprite.setTextureRect(sf::IntRect(Xindex * 64, Yindex * 64, 64, 64));
		sprite.scale(sf::Vector2f(3, 3));
		sprite.setPosition(sf::Vector2f(0, 0));
	}
	else
	{
		std::cout << "Player images failed to load :(" << std::endl;
	}
}

void Player::Update(Skeleton& skeleton)
{
	sf::Vector2f position = sprite.getPosition();

	// windows is weird so up is -Y and down is Y
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		sprite.setPosition(position + sf::Vector2f(1, 0));

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		sprite.setPosition(position + sf::Vector2f(-1, 0));

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		sprite.setPosition(position + sf::Vector2f(0, -1));

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		sprite.setPosition(position + sf::Vector2f(0, 1));


	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		bullets.push_back(sf::RectangleShape(sf::Vector2f(50, 25)));

		int i = bullets.size() - 1;
		bullets[i].setPosition(sprite.getPosition());
	}

	for (size_t i = 0; i < bullets.size(); i++)
	{
		sf::Vector2f bulletDirection = skeleton.sprite.getPosition() - bullets[i].getPosition();
		// static function from the Math class to get Math::NormalizeVector to work
		bulletDirection = Math::NormalizeVector(bulletDirection);
		bullets[i].setPosition(bullets[i].getPosition() + bulletDirection * bulletSpeed);
	}
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);

	for (size_t i = 0; i < bullets.size(); i++)
	{
		window.draw(bullets[i]);
	}
}
