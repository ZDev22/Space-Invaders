#ifndef UPGRADES_HPP
#define UPGRADES_HPP

#include "ship.hpp"
#include "SFML/Graphics.hpp"
#include <string>

using namespace std;

void simulateUpgrades(sf::RenderWindow& window, sf::FloatRect shipHitbox);

struct Upgrades {
	float X;
	float Y;
	string upgrade;
};

extern vector<Upgrades> upgrades;

#endif