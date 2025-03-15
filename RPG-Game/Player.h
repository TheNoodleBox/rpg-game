#pragma once
#include <SFML/Graphics.hpp>
#include "Skeleton.h"

class Player
{
private:
	sf::Texture texture;

	std::vector<sf::RectangleShape> bullets;
	float bulletSpeed = 0.5f;

public:
	sf::Sprite sprite;

public:
	void Initialize(); // <- called once app start
	void Load(); // <-  called once per app start
	void Update(Skeleton& skeleton); // <- called once per frame
	void Draw(sf::RenderWindow& window); // <- called once per frame
};