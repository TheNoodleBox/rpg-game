#pragma once
#include <SFML/Graphics.hpp>

class Bullet
{
public:
	float speed;
	sf::Vector2f direction;

private:
	sf::RectangleShape rectangleShape;

public:
	Bullet();
	~Bullet();

	void Initialize(const sf::Vector2f& position, sf::Vector2f& target, float speed);
	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);

	inline const sf::FloatRect& GetGlobalBounds() { return rectangleShape.getGlobalBounds(); }
};

