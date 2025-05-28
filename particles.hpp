#ifndef PARTICLES_HPP
#define PARTICLES_HPP

#include "SFML/Graphics.hpp"

void simulateParticles(sf::RenderWindow& window);


struct Particle {
	float X;
	float Y;
	float dir;
	short speed;
	short life;
	std::string texture;
	sf::Vector2f scale;
};

extern std::vector<Particle> particles;

#endif