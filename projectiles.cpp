#include "projectiles.hpp"
#include "enemy.hpp"
#include "particles.hpp"
#include "upgrades.hpp"
#include <iostream>

sf::Texture projectileTexture("projectile1.png");
sf::Sprite projectileSprite(projectileTexture);

sf::Sprite enemyCollision(projectileTexture);

int i;

void simulateProjectiles(sf::RenderWindow& window, sf::FloatRect ship) {
	enemyCollision.setScale(sf::Vector2f(4.f, 4.f));

	for (i = projectiles.size() - 1; i >= 0; --i) {

		projectileSprite.setScale(sf::Vector2f(1.f, 1.f));

		if (projectiles[i].isEnemy) {

			projectiles[i].Y += projectiles[i].speed;

			if (projectiles[i].Y > 720) {
				projectiles.erase(projectiles.begin() + i);
				continue;
			}

			projectileSprite.setPosition(sf::Vector2f(projectiles[i].X, projectiles[i].Y));

			if (ship.findIntersection(projectileSprite.getGlobalBounds())) {
				playerHealth -= 1;
				projectiles.erase(projectiles.begin() + i);

				Particle particle;
				particle.X = projectileSprite.getPosition().x;
				particle.Y = projectileSprite.getPosition().y;
				particle.life = 30;
				particle.speed = 4;
				particle.texture = "particleProjectile.png";
				particle.scale = sf::Vector2f(2.f, 2.f);

				particle.dir = 0.f;
				particles.push_back(particle);
				particle.dir = 45.f;
				particles.push_back(particle);
				particle.dir = 90.f;
				particles.push_back(particle);
				particle.dir = 135.f;
				particles.push_back(particle);
				particle.dir = 180.f;
				particles.push_back(particle);
				particle.dir = 225.f;
				particles.push_back(particle);
				particle.dir = 270.f;
				particles.push_back(particle);
				particle.dir = 315.f;
				particles.push_back(particle);
			}
			else if (projectiles[i].texture == "bossAttack.png") { projectileSprite.setScale(sf::Vector2f(0.85f, 10.f)); }
		}
		else {
			projectiles[i].Y -= projectiles[i].speed;

			if (projectiles[i].Y < 0) {
				projectiles.erase(projectiles.begin() + i);
				continue;
			}

			projectileSprite.setPosition(sf::Vector2f(projectiles[i].X, projectiles[i].Y));
			for (auto enemy = enemies.begin(); enemy != enemies.end(); ++enemy) {
				if (!enemy->dead) {
					enemyCollision.setPosition(sf::Vector2f(enemy->X, enemy->Y));
					if (projectileSprite.getGlobalBounds().findIntersection(enemyCollision.getGlobalBounds())) {
						projectiles.erase(projectiles.begin() + i);

						Particle particle;
						particle.X = projectileSprite.getPosition().x;
						particle.Y = projectileSprite.getPosition().y;
						particle.life = 30;
						particle.speed = 4;
						particle.texture = "particleProjectile.png";
						particle.scale = sf::Vector2f(2.f, 2.f);

						particle.dir = 0.f;
						particles.push_back(particle);
						particle.dir = 45.f;
						particles.push_back(particle);
						particle.dir = 90.f;
						particles.push_back(particle);
						particle.dir = 135.f;
						particles.push_back(particle);
						particle.dir = 180.f;
						particles.push_back(particle);
						particle.dir = 225.f;
						particles.push_back(particle);
						particle.dir = 270.f;
						particles.push_back(particle);
						particle.dir = 315.f;
						particles.push_back(particle);
						

						enemy->health -= projectiles[i].damage;
						if (enemy->health < 1) {
							enemy->dead = true;

							if (generateRandomNumber(1, 20) == 1) {

								Upgrades upgrade;
								upgrade.X = enemy->X;
								upgrade.Y = enemy->Y;

								switch (generateRandomNumber(1, 4)) {
								case 1: upgrade.upgrade = "ship1.png"; break;
								case 2: upgrade.upgrade = "ship2.png"; break;
								case 3: upgrade.upgrade = "ship2.png"; break;
								case 4: upgrade.upgrade = "ship3.png"; break;
								}

								upgrades.push_back(upgrade);
							}
							else if (generateRandomNumber(1, 15) == 1) {

								Upgrades upgrade;
								upgrade.X = enemy->X;
								upgrade.Y = enemy->Y;
								upgrade.upgrade = "health.png";

								upgrades.push_back(upgrade);
							}

							enemies.erase(enemy);
							Particle particle;
							particle.X = projectileSprite.getPosition().x;
							particle.Y = projectileSprite.getPosition().y;
							particle.life = 30;
							particle.speed = 4;
							particle.texture = "particleObject.png";
							particle.scale = sf::Vector2f(3.f, 3.f);

							particle.dir = 20.f;
							particles.push_back(particle);
							particle.dir = 65.f;
							particles.push_back(particle);
							particle.dir = 110.f;
							particles.push_back(particle);
							particle.dir = 155.f;
							particles.push_back(particle);
							particle.dir = 200.f;
							particles.push_back(particle);
							particle.dir = 245.f;
							particles.push_back(particle);
							particle.dir = 290.f;
							particles.push_back(particle);
							particle.dir = 335.f;
							particles.push_back(particle);
						}
						break;
					}
				}
			}
		}
		projectileTexture.loadFromFile(projectiles[i].texture);
		projectileSprite.setTexture(projectileTexture);
		window.draw(projectileSprite);
	}
}