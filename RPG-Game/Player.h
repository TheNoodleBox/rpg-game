#pragma once
#include <SFML/Graphics.hpp>
#include "Skeleton.h"

class Player
{
private:
	sf::Texture texture;

	std::vector<sf::RectangleShape> bullets;
	float bulletSpeed = 0.5f;
	float playerSpeed = 2.0f;

	sf::RectangleShape boundingRectangle;
	sf::Vector2i size;
public:
	sf::Sprite sprite;

public:
	Player();
	~Player();
	void Initialize(); // <- called once app start
	void Load(); // <-  called once per app start
	void Update(float deltaTime, Skeleton& skeleton); // <- called once per frame
	void Draw(sf::RenderWindow& window); // <- called once per frame
};