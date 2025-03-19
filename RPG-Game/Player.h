#pragma once
#include <SFML/Graphics.hpp>
#include "Skeleton.h"
#include "Bullet.h"

class Player
{
private:
	sf::Texture texture;

	std::vector<Bullet> bullets;
	

	float maxFireRate;
	float fireRateTimer;

	float playerSpeed;

	sf::RectangleShape boundingRectangle;
	sf::Vector2i size;

public:
	sf::Sprite sprite;

public:
	Player();
	~Player();

	void Initialize(); // <- called once app start
	void Load(); // <-  called once per app start
	void Update(float deltaTime, Skeleton& skeleton, sf::Vector2f& mousePosition); // <- called once per frame
	void Draw(sf::RenderWindow& window); // <- called once per frame
};