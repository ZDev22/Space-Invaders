#ifndef SHIP_HPP
#define SHIP_HPP

#include <SFML/Graphics.hpp>
#include "main.hpp"

using namespace std;

void simulateShip(sf::RenderWindow& window);

struct Projectiles {
	float X;
	float Y;
	short damage;
	short speed;
	string texture;
	bool isEnemy;
};

extern vector<Projectiles> projectiles;

#endif