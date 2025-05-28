#include "particles.hpp"
#include <cmath>
#include <iostream>

std::vector<Particle> particles;
sf::Texture particleTexture("particleProjectile.png");
sf::Sprite particleSprite(particleTexture);

int q;
float radians;

void simulateParticles(sf::RenderWindow& window) {
	for (q = particles.size() - 1; q >= 0; --q) {
		particles[q].life -= 1;
		if (particles[q].life <= 0) {particles.erase(particles.begin() + q);}
		else {
			particleSprite.setScale(particles[q].scale);
			radians = particles[q].dir * .0174532925f; //Convert degrees to radians

			particles[q].X += std::cos(radians) * particles[q].speed;
			particles[q].Y += std::sin(radians) * particles[q].speed;

			particleSprite.setPosition(sf::Vector2f(particles[q].X, particles[q].Y));
			particleTexture.loadFromFile(particles[q].texture);
			particleSprite.setTexture(particleTexture);

			window.draw(particleSprite);
		}
	}
}